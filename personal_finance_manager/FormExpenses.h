#pragma once

namespace personalfinancemanager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;

	public ref class FormExpenses : public System::Windows::Forms::Form
	{
	public:
		FormExpenses(void)
		{
			InitializeComponent();

		}
	protected:
		~FormExpenses()
		{
			if (components)
			{
				delete components;
			}
		}

	private: 
		System::Windows::Forms::DataGridView^ Expenses;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Button^ button_Add;
		System::Windows::Forms::Button^ button_Delete;
		System::Windows::Forms::Button^ button_Edit;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::DataGridViewTextBoxColumn^ DateReport;
		System::Windows::Forms::DataGridViewTextBoxColumn^ id2;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Category2;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Summ2;
		System::Windows::Forms::Button^ buttonUpdate;
		System::Windows::Forms::Button^ button_Save;
		System::Windows::Forms::SaveFileDialog^ saveToFile;
		System::ComponentModel::Container^ components;
		System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Date;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Number;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Category;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Summ;

	public:
		int count = 0;
		String^ queryForSave = nullptr;
		System::Windows::Forms::DataGridView^ Reports;
		System::Windows::Forms::Label^ labelReports;



		
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormExpenses::typeid));
			this->Expenses = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Category = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Summ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Reports = (gcnew System::Windows::Forms::DataGridView());
			this->DateReport = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->id2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Category2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Summ2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelReports = (gcnew System::Windows::Forms::Label());
			this->button_Add = (gcnew System::Windows::Forms::Button());
			this->button_Delete = (gcnew System::Windows::Forms::Button());
			this->button_Edit = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->buttonUpdate = (gcnew System::Windows::Forms::Button());
			this->button_Save = (gcnew System::Windows::Forms::Button());
			this->saveToFile = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Expenses))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Reports))->BeginInit();
			this->SuspendLayout();
			// 
			// Expenses
			// 
			this->Expenses->AllowUserToAddRows = false;
			this->Expenses->AllowUserToDeleteRows = false;
			this->Expenses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Expenses->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->ID, this->Date,
					this->Number, this->Category, this->Summ
			});
			this->Expenses->Location = System::Drawing::Point(238, 32);
			this->Expenses->Name = L"Expenses";
			this->Expenses->ReadOnly = true;
			this->Expenses->Size = System::Drawing::Size(538, 167);
			this->Expenses->TabIndex = 0;
			// 
			// ID
			// 
			dataGridViewCellStyle1->Format = L"N0";
			dataGridViewCellStyle1->NullValue = nullptr;
			this->ID->DefaultCellStyle = dataGridViewCellStyle1;
			this->ID->HeaderText = L"Номер операции";
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			// 
			// Date
			// 
			dataGridViewCellStyle2->Format = L"d";
			dataGridViewCellStyle2->NullValue = nullptr;
			this->Date->DefaultCellStyle = dataGridViewCellStyle2;
			this->Date->HeaderText = L"Дата";
			this->Date->Name = L"Date";
			this->Date->ReadOnly = true;
			// 
			// Number
			// 
			this->Number->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			dataGridViewCellStyle3->Format = L"N0";
			dataGridViewCellStyle3->NullValue = nullptr;
			this->Number->DefaultCellStyle = dataGridViewCellStyle3;
			this->Number->HeaderText = L"Номер карты оплаты";
			this->Number->Name = L"Number";
			this->Number->ReadOnly = true;
			// 
			// Category
			// 
			this->Category->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			dataGridViewCellStyle4->NullValue = nullptr;
			this->Category->DefaultCellStyle = dataGridViewCellStyle4;
			this->Category->HeaderText = L"Категория";
			this->Category->Name = L"Category";
			this->Category->ReadOnly = true;
			// 
			// Summ
			// 
			this->Summ->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			dataGridViewCellStyle5->Format = L"C0";
			dataGridViewCellStyle5->NullValue = nullptr;
			this->Summ->DefaultCellStyle = dataGridViewCellStyle5;
			this->Summ->HeaderText = L"Сумма";
			this->Summ->Name = L"Summ";
			this->Summ->ReadOnly = true;
			// 
			// Reports
			// 
			this->Reports->AllowUserToAddRows = false;
			this->Reports->AllowUserToDeleteRows = false;
			this->Reports->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Reports->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->DateReport, this->id2,
					this->Category2, this->Summ2
			});
			this->Reports->Location = System::Drawing::Point(238, 236);
			this->Reports->Name = L"Reports";
			this->Reports->ReadOnly = true;
			this->Reports->Size = System::Drawing::Size(538, 197);
			this->Reports->TabIndex = 1;
			// 
			// DateReport
			// 
			dataGridViewCellStyle6->Format = L"d";
			dataGridViewCellStyle6->NullValue = nullptr;
			this->DateReport->DefaultCellStyle = dataGridViewCellStyle6;
			this->DateReport->HeaderText = L"Дата";
			this->DateReport->Name = L"DateReport";
			this->DateReport->ReadOnly = true;
			// 
			// id2
			// 
			this->id2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->id2->HeaderText = L"Номер карты";
			this->id2->Name = L"id2";
			this->id2->ReadOnly = true;
			// 
			// Category2
			// 
			this->Category2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Category2->HeaderText = L"Категория";
			this->Category2->Name = L"Category2";
			this->Category2->ReadOnly = true;
			// 
			// Summ2
			// 
			this->Summ2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Summ2->HeaderText = L"Сумма";
			this->Summ2->Name = L"Summ2";
			this->Summ2->ReadOnly = true;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(321, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(455, 23);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Затраты";
			// 
			// labelReports
			// 
			this->labelReports->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelReports->Location = System::Drawing::Point(280, 210);
			this->labelReports->Name = L"labelReports";
			this->labelReports->Size = System::Drawing::Size(455, 23);
			this->labelReports->TabIndex = 3;
			this->labelReports->Text = L"Отчеты по затратам";
			// 
			// button_Add
			// 
			this->button_Add->Location = System::Drawing::Point(35, 53);
			this->button_Add->Name = L"button_Add";
			this->button_Add->Size = System::Drawing::Size(156, 51);
			this->button_Add->TabIndex = 4;
			this->button_Add->Text = L"Добавить затраты";
			this->button_Add->UseVisualStyleBackColor = true;
			this->button_Add->Click += gcnew System::EventHandler(this, &FormExpenses::button_Add_Click);
			// 
			// button_Delete
			// 
			this->button_Delete->Location = System::Drawing::Point(35, 196);
			this->button_Delete->Name = L"button_Delete";
			this->button_Delete->Size = System::Drawing::Size(156, 51);
			this->button_Delete->TabIndex = 5;
			this->button_Delete->Text = L"Удалить затраты";
			this->button_Delete->UseVisualStyleBackColor = true;
			this->button_Delete->Click += gcnew System::EventHandler(this, &FormExpenses::button_Delete_Click);
			// 
			// button_Edit
			// 
			this->button_Edit->Location = System::Drawing::Point(35, 124);
			this->button_Edit->Name = L"button_Edit";
			this->button_Edit->Size = System::Drawing::Size(156, 51);
			this->button_Edit->TabIndex = 6;
			this->button_Edit->Text = L"Изменить затраты";
			this->button_Edit->UseVisualStyleBackColor = true;
			this->button_Edit->Click += gcnew System::EventHandler(this, &FormExpenses::button_Edit_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(35, 268);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(156, 51);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Создать отчет ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormExpenses::button_Create_Click);
			// 
			// buttonUpdate
			// 
			this->buttonUpdate->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonUpdate.Image")));
			this->buttonUpdate->Location = System::Drawing::Point(238, 2);
			this->buttonUpdate->Name = L"buttonUpdate";
			this->buttonUpdate->Size = System::Drawing::Size(34, 30);
			this->buttonUpdate->TabIndex = 9;
			this->buttonUpdate->UseVisualStyleBackColor = true;
			this->buttonUpdate->Click += gcnew System::EventHandler(this, &FormExpenses::buttonUpdate_Click);
			// 
			// button_Save
			// 
			this->button_Save->Location = System::Drawing::Point(35, 335);
			this->button_Save->Name = L"button_Save";
			this->button_Save->Size = System::Drawing::Size(156, 51);
			this->button_Save->TabIndex = 10;
			this->button_Save->Text = L"Сохранить отчет ";
			this->button_Save->UseVisualStyleBackColor = true;
			this->button_Save->Click += gcnew System::EventHandler(this, &FormExpenses::button_Save_Click);
			// 
			// FormExpenses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 445);
			this->Controls->Add(this->button_Save);
			this->Controls->Add(this->buttonUpdate);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button_Edit);
			this->Controls->Add(this->button_Delete);
			this->Controls->Add(this->button_Add);
			this->Controls->Add(this->labelReports);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Reports);
			this->Controls->Add(this->Expenses);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FormExpenses";
			this->Text = L"Отчеты и Затраты";
			this->Load += gcnew System::EventHandler(this, &FormExpenses::FormExpenses_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Expenses))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Reports))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FormExpenses_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Add_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Edit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Delete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Create_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Save_Click(System::Object^ sender, System::EventArgs^ e);
};
}
