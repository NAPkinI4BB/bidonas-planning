#pragma once

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
	private: System::Windows::Forms::Button^ load_button;
	private: System::Windows::Forms::DataGridView^ grid;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Time;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Task;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dTime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SP;
	private: System::Windows::Forms::Button^ push_button;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::Button^ clear_button;
	private: System::Windows::Forms::Button^ selected;
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
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->plan = (gcnew System::Windows::Forms::TabPage());
			this->selected = (gcnew System::Windows::Forms::Button());
			this->clear_button = (gcnew System::Windows::Forms::Button());
			this->load_button = (gcnew System::Windows::Forms::Button());
			this->grid = (gcnew System::Windows::Forms::DataGridView());
			this->Time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Task = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SP = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->push_button = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->plan->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabPage1
			// 
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(968, 490);
			this->tabPage1->TabIndex = 2;
			this->tabPage1->Text = L"Информация";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// plan
			// 
			this->plan->Controls->Add(this->selected);
			this->plan->Controls->Add(this->clear_button);
			this->plan->Controls->Add(this->load_button);
			this->plan->Controls->Add(this->grid);
			this->plan->Controls->Add(this->push_button);
			this->plan->Location = System::Drawing::Point(4, 22);
			this->plan->Name = L"plan";
			this->plan->Padding = System::Windows::Forms::Padding(3);
			this->plan->Size = System::Drawing::Size(968, 490);
			this->plan->TabIndex = 0;
			this->plan->Text = L"Планер";
			this->plan->UseVisualStyleBackColor = true;
			// 
			// selected
			// 
			this->selected->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->selected->Location = System::Drawing::Point(559, 460);
			this->selected->Name = L"selected";
			this->selected->Size = System::Drawing::Size(152, 24);
			this->selected->TabIndex = 4;
			this->selected->Text = L"Clear selected";
			this->selected->UseVisualStyleBackColor = true;
			this->selected->Click += gcnew System::EventHandler(this, &Form1::clearSelected);
			// 
			// clear_button
			// 
			this->clear_button->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->clear_button->Location = System::Drawing::Point(384, 460);
			this->clear_button->Name = L"clear_button";
			this->clear_button->Size = System::Drawing::Size(152, 24);
			this->clear_button->TabIndex = 3;
			this->clear_button->Text = L"Clear form";
			this->clear_button->UseVisualStyleBackColor = true;
			this->clear_button->Click += gcnew System::EventHandler(this, &Form1::clearForm);
			// 
			// load_button
			// 
			this->load_button->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->load_button->Location = System::Drawing::Point(208, 460);
			this->load_button->Name = L"load_button";
			this->load_button->Size = System::Drawing::Size(152, 24);
			this->load_button->TabIndex = 2;
			this->load_button->Text = L"Load";
			this->load_button->UseVisualStyleBackColor = true;
			this->load_button->Click += gcnew System::EventHandler(this, &Form1::load_button_Click);
			// 
			// grid
			// 
			this->grid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Time, this->Task,
					this->dTime, this->SP
			});
			this->grid->Location = System::Drawing::Point(23, 11);
			this->grid->Name = L"grid";
			this->grid->Size = System::Drawing::Size(920, 443);
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
			// push_button
			// 
			this->push_button->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->push_button->Location = System::Drawing::Point(39, 460);
			this->push_button->Name = L"push_button";
			this->push_button->Size = System::Drawing::Size(152, 24);
			this->push_button->TabIndex = 0;
			this->push_button->Text = L"PUSH!";
			this->push_button->UseVisualStyleBackColor = true;
			this->push_button->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->plan);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->ItemSize = System::Drawing::Size(125, 18);
			this->tabControl1->Location = System::Drawing::Point(2, 2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(976, 516);
			this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
			this->tabControl1->TabIndex = 1;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(990, 530);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SanDen planning";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->plan->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->EndInit();
			this->tabControl1->ResumeLayout(false);
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

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void clearForm(System::Object^ sender, System::EventArgs^ e);

	private: System::Void clearSelected(System::Object^ sender, System::EventArgs^ e);
};

}
