#include "Form1.h"

// Подключаем пространства имен 
using namespace System;
using namespace Windows::Forms;
using namespace Data::OleDb; // Для работы с БД


void setNulls(DataGridView^ grid)
{
	for each (DataGridViewRow ^ row in grid->Rows)
	{
		for each (DataGridViewCell ^ cell in row->Cells) {
			if (cell->Value == nullptr || cell->Value->ToString()->Trim() == "") {
				cell->Value = "-";
			}
		}
	}
}

System::String^ getDate(DateTimePicker^ dtp)
{
	DateTime dt = dtp->Value;
	return dt.ToString("dd-MM-yyyy");
}



[STAThreadAttribute] // Запуск отдельного потока
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	WindowApp::Form1 form;
	Application::Run(% form);
	return 0;
}

System::Void WindowApp::Form1::load_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Подключение
	String^ conStr = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=planDB.accdb";
	OleDbConnection^ accessConn = gcnew OleDbConnection(conStr);
	
	try
	{
		String^ tableName = getDate(dateTimePicker1);
		// Запрос
		accessConn->Open(); // Открыли соединение

		String^ checkQuery = "SELECT 1 FROM MSysObjects WHERE Type = 1 AND Name = ?";
		OleDbCommand^ checkCommand = gcnew OleDbCommand(checkQuery, accessConn);
		checkCommand->Parameters->AddWithValue("?", tableName);
		bool isTable = Convert::ToBoolean(checkCommand->ExecuteScalar());

		if (!isTable) return System::Void();

		String^ query = String::Format("SELECT * FROM [{0}]", tableName);
		OleDbCommand^ command = gcnew OleDbCommand(query, accessConn);
		OleDbDataReader^ reader = command->ExecuteReader();

		while (reader->Read())
		{
			grid->Rows->Add(reader["Time"], reader["Task"], reader["TimeToDo"], reader["SP"]);
		}

		reader->Close();
	}
	catch (OleDbException^ e) {
		// Перехват исключений, связанных непосредственно с БД
		MessageBox::Show(e->Message, "OleDbException", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	catch (InvalidOperationException^ e) {
		// Перехват исключений, связанных с неправильными операциями
		MessageBox::Show(e->Message, "InvalidOperationException", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	catch (Exception^ e) {
		// Все остальное
		MessageBox::Show(e->Message, "Exception", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally
	{
		accessConn->Close();
	}


	return System::Void();
}


System::Void WindowApp::Form1::dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	clear_button->PerformClick();
	load_button->PerformClick();
	return System::Void();
}


System::Void WindowApp::Form1::push(System::Object^ sender, System::EventArgs^ e)
{
	String^ conStr = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=planDB.accdb;Mode=ReadWrite;";
	OleDbConnection^ accessConn = gcnew OleDbConnection(conStr);

	try
	{
		String^ tableName = getDate(dateTimePicker1);

		accessConn->Open();
		String^ checkQuery = "SELECT 1 FROM MSysObjects WHERE Type = 1 AND Name = ?";
		OleDbCommand^ checkCommand = gcnew OleDbCommand(checkQuery, accessConn);
		checkCommand->Parameters->AddWithValue("?", tableName);
		bool isTable = Convert::ToBoolean(checkCommand->ExecuteScalar());

		setNulls(grid);

		//Создадим таблицу по данной дате, если не создана
		if (!isTable)
		{
			String^ createQuery = String::Format("CREATE TABLE [{0}] ([Time] VARCHAR(50), Task VARCHAR(100), TimeToDo VARCHAR(50), SP VARCHAR(15))", tableName);
			OleDbCommand^ commandCr = gcnew OleDbCommand(createQuery, accessConn);
			commandCr->ExecuteNonQuery();
		}

		// Очистим таблицу
		String^ delQuery = String::Format("DELETE FROM [{0}]", tableName);
		OleDbCommand^ commandD = gcnew OleDbCommand(delQuery, accessConn);
		commandD->ExecuteNonQuery();



		// Перебор введенного содержимого и запись его в БД
		for (int i = 0; i < grid->Rows->Count; i++)
		{
			String^ time = grid->Rows[i]->Cells[0]->Value->ToString();
			if (!isValidTime(time))
			{
				String^ messageTime = String::Format("Строка {0}, ячейка 1. Неправильный формат времени. \
Время может иметь формат ЧЧ-ММ, ЧЧ ММ, ЧЧ:ММ или ЧЧ.ММ", i+1);
				throw gcnew Exception(messageTime);
			}

			String^ task = grid->Rows[i]->Cells[1]->Value->ToString();
			String^ dT = grid->Rows[i]->Cells[2]->Value->ToString();
			String^ sp = grid->Rows[i]->Cells[3]->Value->ToString();
			if (!isValidSP(sp))
			{
				String^ messageSP = String::Format("Строка {0}, ячейка 4. Неправильный формат story points. Введите число",
					i+1);
				throw gcnew Exception(messageSP);
			}

			String^ oneRowQuery = String::Format("INSERT INTO [{0}] ([Time], Task, TimeToDo, SP) VALUES ('{1}', '{2}', '{3}', '{4}')",
				tableName, time, task, dT, sp);
			OleDbCommand^ commandPush = gcnew OleDbCommand(oneRowQuery, accessConn);
			commandPush->ExecuteNonQuery();
		}
	}
	catch (OleDbException^ e) {
		MessageBox::Show(e->Message, "OleDbException", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	catch (InvalidOperationException^ e) {
		MessageBox::Show(e->Message, "InvalidOperationException", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	catch (Exception^ e) {
		MessageBox::Show(e->Message, "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally
	{
		accessConn->Close();
	}
	return System::Void();
}

System::Void WindowApp::Form1::add_Row_click(System::Object^ sender, System::EventArgs^ e)
{
	grid->Rows->Add();
	return System::Void();
}

System::Void WindowApp::Form1::form_load(System::Object^ sender, System::EventArgs^ e)
{
	load_button->PerformClick();
	return System::Void();
}

System::Void WindowApp::Form1::clearForm(System::Object^ sender, System::EventArgs^ e)
{
	// Очистка формы по кнопке
	grid->Rows->Clear();

	return System::Void();
}



System::Void WindowApp::Form1::clearSelected(System::Object^ sender, System::EventArgs^ e)
{
	for (int i = 0; i < grid->Rows->Count; i++)
	{
		if (grid->Rows[i]->Selected)
		{
			grid->Rows->RemoveAt(i);
			continue;
		}
		for (int j = 0; j < grid->Rows[i]->Cells->Count; j++)
		{
			if (grid->Rows[i]->Cells[j]->Selected) grid->Rows[i]->Cells[j]->Value = nullptr;
		}
	}
	return System::Void();
}



