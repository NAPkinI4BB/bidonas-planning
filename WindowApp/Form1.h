#pragma once

#include "IsValidFormat.h"

namespace WindowApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabPage^ tabPage1;
	protected:
	private: System::Windows::Forms::TabPage^ plan;

	private: System::Windows::Forms::DataGridView^ grid;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Time;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Task;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dTime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SP;
	private: System::Windows::Forms::Button^ push_button;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::Button^ clear_button;
	private: System::Windows::Forms::Button^ selected;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Data::DataSet^ dataSet1;
	private: System::Windows::Forms::Button^ addRow;
	private: System::Windows::Forms::Button^ load_button;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;






	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->plan = (gcnew System::Windows::Forms::TabPage());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->push_button = (gcnew System::Windows::Forms::Button());
			this->selected = (gcnew System::Windows::Forms::Button());
			this->clear_button = (gcnew System::Windows::Forms::Button());
			this->addRow = (gcnew System::Windows::Forms::Button());
			this->load_button = (gcnew System::Windows::Forms::Button());
			this->grid = (gcnew System::Windows::Forms::DataGridView());
			this->Time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Task = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SP = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->dataSet1 = (gcnew System::Data::DataSet());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->tabPage1->SuspendLayout();
			this->plan->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->BeginInit();
			this->tabControl1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->BeginInit();
			this->flowLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->flowLayoutPanel2);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(902, 474);
			this->tabPage1->TabIndex = 2;
			this->tabPage1->Text = L"Информация";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &Form1::tabPage1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(628, 54);
			this->label1->TabIndex = 0;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// plan
			// 
			this->plan->Controls->Add(this->flowLayoutPanel1);
			this->plan->Controls->Add(this->grid);
			this->plan->Controls->Add(this->dateTimePicker1);
			this->plan->Location = System::Drawing::Point(4, 22);
			this->plan->Name = L"plan";
			this->plan->Padding = System::Windows::Forms::Padding(3);
			this->plan->Size = System::Drawing::Size(902, 474);
			this->plan->TabIndex = 0;
			this->plan->Text = L"Планер";
			this->plan->UseVisualStyleBackColor = true;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->flowLayoutPanel1->Controls->Add(this->push_button);
			this->flowLayoutPanel1->Controls->Add(this->selected);
			this->flowLayoutPanel1->Controls->Add(this->clear_button);
			this->flowLayoutPanel1->Controls->Add(this->addRow);
			this->flowLayoutPanel1->Controls->Add(this->load_button);
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::RightToLeft;
			this->flowLayoutPanel1->Location = System::Drawing::Point(40, 432);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(752, 36);
			this->flowLayoutPanel1->TabIndex = 6;
			// 
			// push_button
			// 
			this->push_button->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->push_button->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9.75F, System::Drawing::FontStyle::Bold));
			this->push_button->Location = System::Drawing::Point(620, 3);
			this->push_button->Margin = System::Windows::Forms::Padding(7, 3, 7, 3);
			this->push_button->Name = L"push_button";
			this->push_button->Size = System::Drawing::Size(125, 25);
			this->push_button->TabIndex = 0;
			this->push_button->Text = L"Синхронизировать!";
			this->push_button->UseVisualStyleBackColor = true;
			this->push_button->Click += gcnew System::EventHandler(this, &Form1::push);
			// 
			// selected
			// 
			this->selected->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->selected->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->selected->Location = System::Drawing::Point(481, 3);
			this->selected->Margin = System::Windows::Forms::Padding(7, 3, 7, 3);
			this->selected->Name = L"selected";
			this->selected->Size = System::Drawing::Size(125, 25);
			this->selected->TabIndex = 4;
			this->selected->Text = L"Очистить выдел.";
			this->selected->UseVisualStyleBackColor = true;
			this->selected->Click += gcnew System::EventHandler(this, &Form1::clearSelected);
			// 
			// clear_button
			// 
			this->clear_button->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->clear_button->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9.75F, System::Drawing::FontStyle::Bold));
			this->clear_button->Location = System::Drawing::Point(342, 3);
			this->clear_button->Margin = System::Windows::Forms::Padding(7, 3, 7, 3);
			this->clear_button->Name = L"clear_button";
			this->clear_button->Size = System::Drawing::Size(125, 25);
			this->clear_button->TabIndex = 3;
			this->clear_button->Text = L"Очистить форму";
			this->clear_button->UseVisualStyleBackColor = true;
			this->clear_button->Click += gcnew System::EventHandler(this, &Form1::clearForm);
			// 
			// addRow
			// 
			this->addRow->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9.75F, System::Drawing::FontStyle::Bold));
			this->addRow->Location = System::Drawing::Point(203, 3);
			this->addRow->Margin = System::Windows::Forms::Padding(7, 3, 7, 3);
			this->addRow->Name = L"addRow";
			this->addRow->Size = System::Drawing::Size(125, 25);
			this->addRow->TabIndex = 5;
			this->addRow->Text = L"Добавить строку";
			this->addRow->UseVisualStyleBackColor = true;
			this->addRow->Click += gcnew System::EventHandler(this, &Form1::add_Row_click);
			// 
			// load_button
			// 
			this->load_button->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->load_button->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9.75F, System::Drawing::FontStyle::Bold));
			this->load_button->Location = System::Drawing::Point(64, 3);
			this->load_button->Margin = System::Windows::Forms::Padding(7, 3, 7, 3);
			this->load_button->Name = L"load_button";
			this->load_button->Size = System::Drawing::Size(125, 25);
			this->load_button->TabIndex = 2;
			this->load_button->Text = L"Загрузить с БД";
			this->load_button->UseVisualStyleBackColor = true;
			this->load_button->Click += gcnew System::EventHandler(this, &Form1::load_button_Click);
			// 
			// grid
			// 
			this->grid->AllowUserToAddRows = false;
			this->grid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->grid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Time, this->Task,
					this->dTime, this->SP
			});
			this->grid->Location = System::Drawing::Point(6, 29);
			this->grid->Name = L"grid";
			this->grid->Size = System::Drawing::Size(890, 388);
			this->grid->TabIndex = 1;
			this->grid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView1_CellContentClick);
			// 
			// Time
			// 
			this->Time->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Time->HeaderText = L"Время";
			this->Time->Name = L"Time";
			this->Time->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// Task
			// 
			this->Task->HeaderText = L"Задача";
			this->Task->Name = L"Task";
			// 
			// dTime
			// 
			this->dTime->HeaderText = L"Время на выполнение";
			this->dTime->Name = L"dTime";
			// 
			// SP
			// 
			this->SP->HeaderText = L"Story points";
			this->SP->Name = L"SP";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dateTimePicker1->Location = System::Drawing::Point(3, 3);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(896, 20);
			this->dateTimePicker1->TabIndex = 2;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &Form1::dateTimePicker1_ValueChanged);
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->plan);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->ItemSize = System::Drawing::Size(125, 18);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(910, 500);
			this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
			this->tabControl1->TabIndex = 1;
			// 
			// dataSet1
			// 
			this->dataSet1->DataSetName = L"NewDataSet";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(231, 448);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(400, 13);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Создано для профилактики прироста мамона заботливым студентом ФГиГа";
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->flowLayoutPanel2->Controls->Add(this->label1);
			this->flowLayoutPanel2->Location = System::Drawing::Point(119, 61);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(681, 183);
			this->flowLayoutPanel2->TabIndex = 3;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(947, 524);
			this->Controls->Add(this->tabControl1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Bidonas planning";
			this->Load += gcnew System::EventHandler(this, &Form1::form_load);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->plan->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->EndInit();
			this->tabControl1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->EndInit();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void load_button_Click(System::Object^ sender, System::EventArgs^ e);


	private: System::Void clearForm(System::Object^ sender, System::EventArgs^ e);

	private: System::Void clearSelected(System::Object^ sender, System::EventArgs^ e);


	private: System::Void Test(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void push(System::Object^ sender, System::EventArgs^ e);

	private: System::Void add_Row_click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void form_load(System::Object^ sender, System::EventArgs^ e);
};

}
