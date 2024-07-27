#include "Form1.h"

// Подключаем пространства имен 
using namespace System;
using namespace Windows::Forms;
using namespace Data::OleDb; // Для работы с БД

[STAThreadAttribute] // Запуск отдельного потока (изучить)
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
		// Запрос
		accessConn->Open(); // Открыли соединение
		String^ query = "SELECT * FROM [table1]";
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


System::Void WindowApp::Form1::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ conStr = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=planDB.accdb";
	OleDbConnection^ accessConn = gcnew OleDbConnection(conStr);

	try
	{
		accessConn->Open();

		// Очистим таблицу
		String^ delQuery = "DELETE FROM [table1]";
		OleDbCommand^ command = gcnew OleDbCommand(delQuery, accessConn);
		command->ExecuteNonQuery();



		// Перебор введенного содержимого и запись его в БД
		for (int i = 0; i < grid->Rows->Count - 1; i++)
		{
			if (grid->Rows[i]->Cells[0]->Value == nullptr ||
				grid->Rows[i]->Cells[1]->Value == nullptr ||
				grid->Rows[i]->Cells[2]->Value == nullptr ||
				grid->Rows[i]->Cells[3]->Value == nullptr) throw gcnew Exception("Введи все данные, придурок блять");

			//TODO придумать обработку сообщения о введенных не всех данных
			String^ time = grid->Rows[i]->Cells[0]->Value->ToString();
			String^ task = grid->Rows[i]->Cells[1]->Value->ToString();
			String^ dT = grid->Rows[i]->Cells[2]->Value->ToString();
			String^ sp = grid->Rows[i]->Cells[3]->Value->ToString();


			String^ oneRowQuery = String::Format("INSERT INTO [table1] ([Time], Task, TimeToDo, SP) VALUES ('{0}', '{1}', '{2}', '{3}')",
				time, task, dT, sp);
			//String^ oneRowQuery = "INSERT INTO [table1] VALUES ('" + i + "', '" + time + "', '" + task + "', '" + dT + "', '" + sp + "')";
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
		MessageBox::Show(e->Message, "Exception", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally
	{
		accessConn->Close();
	}
	return System::Void();
}

System::Void WindowApp::Form1::clearForm(System::Object^ sender, System::EventArgs^ e)
{
	// Очистка формы по кнопке
	/*for (int i = 0; i < grid->Rows->Count - 1; i++)
	{
		for (int j = 0; j < grid->Rows[i]->Cells->Count; j++)
		{
			grid->Rows[i]->Cells[j]->Value = nullptr;
		}
	}*/
	grid->Rows->Clear();

	return System::Void();
}

bool areCellsFilled(DataGridView^ grid)
{
	for each (DataGridViewRow^ row in grid->Rows)
	{
		if (!row->IsNewRow) {
			for each (DataGridViewCell ^ cell in row->Cells) {
				if (cell->Value == nullptr || cell->Value->ToString()->Trim() == "") {
					return false;
				}
			}
		}
	}
	return true;
}

System::Void WindowApp::Form1::clearSelected(System::Object^ sender, System::EventArgs^ e)
{
	for (int i = 0; i < grid->Rows->Count - 1; i++)
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


