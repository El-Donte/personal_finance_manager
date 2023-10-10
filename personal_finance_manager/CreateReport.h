#pragma once
#include "FormExpenses.h"
namespace personalfinancemanager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class CreateReport : public System::Windows::Forms::Form
	{
		FormExpenses^ form;
	public:
		CreateReport(FormExpenses^ fr)
		{
			InitializeComponent();
			this->form = fr;
		}

	protected:

		~CreateReport()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::RadioButton^ ButtonDay;
		System::Windows::Forms::RadioButton^ ButtonWeek;
		System::Windows::Forms::RadioButton^ ButtonMonth;
		System::Windows::Forms::DateTimePicker^ dateDay;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Button^ button_Ok;
		System::Windows::Forms::RadioButton^ ButtonExpenses;
		System::Windows::Forms::RadioButton^ ButtonCategory;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::TextBox^ textCategory;
		System::Windows::Forms::DateTimePicker^ dateMonth;
		System::Windows::Forms::DateTimePicker^ dateWeek;
		System::ComponentModel::Container^ components;
		System::Windows::Forms::GroupBox^ groupBox1;

	private:
		int type;
		String^ key;
		String^ category;
		DateTime date;


		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CreateReport::typeid));
			this->ButtonDay = (gcnew System::Windows::Forms::RadioButton());
			this->ButtonWeek = (gcnew System::Windows::Forms::RadioButton());
			this->ButtonMonth = (gcnew System::Windows::Forms::RadioButton());
			this->dateDay = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button_Ok = (gcnew System::Windows::Forms::Button());
			this->ButtonExpenses = (gcnew System::Windows::Forms::RadioButton());
			this->ButtonCategory = (gcnew System::Windows::Forms::RadioButton());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textCategory = (gcnew System::Windows::Forms::TextBox());
			this->dateMonth = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateWeek = (gcnew System::Windows::Forms::DateTimePicker());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ButtonDay
			// 
			this->ButtonDay->AutoSize = true;
			this->ButtonDay->Enabled = false;
			this->ButtonDay->Location = System::Drawing::Point(38, 133);
			this->ButtonDay->Name = L"ButtonDay";
			this->ButtonDay->Size = System::Drawing::Size(49, 17);
			this->ButtonDay->TabIndex = 0;
			this->ButtonDay->TabStop = true;
			this->ButtonDay->Text = L"день";
			this->ButtonDay->UseVisualStyleBackColor = true;
			this->ButtonDay->Visible = false;
			this->ButtonDay->CheckedChanged += gcnew System::EventHandler(this, &CreateReport::ButtonDay_CheckedChanged);
			// 
			// ButtonWeek
			// 
			this->ButtonWeek->AutoSize = true;
			this->ButtonWeek->Enabled = false;
			this->ButtonWeek->Location = System::Drawing::Point(38, 170);
			this->ButtonWeek->Name = L"ButtonWeek";
			this->ButtonWeek->Size = System::Drawing::Size(61, 17);
			this->ButtonWeek->TabIndex = 1;
			this->ButtonWeek->TabStop = true;
			this->ButtonWeek->Text = L"неделя";
			this->ButtonWeek->UseVisualStyleBackColor = true;
			this->ButtonWeek->Visible = false;
			this->ButtonWeek->CheckedChanged += gcnew System::EventHandler(this, &CreateReport::ButtonWeek_CheckedChanged);
			// 
			// ButtonMonth
			// 
			this->ButtonMonth->AutoSize = true;
			this->ButtonMonth->Enabled = false;
			this->ButtonMonth->Location = System::Drawing::Point(38, 203);
			this->ButtonMonth->Name = L"ButtonMonth";
			this->ButtonMonth->Size = System::Drawing::Size(57, 17);
			this->ButtonMonth->TabIndex = 2;
			this->ButtonMonth->TabStop = true;
			this->ButtonMonth->Text = L"месяц";
			this->ButtonMonth->UseVisualStyleBackColor = true;
			this->ButtonMonth->Visible = false;
			this->ButtonMonth->CheckedChanged += gcnew System::EventHandler(this, &CreateReport::ButtonMonth_CheckedChanged);
			// 
			// dateDay
			// 
			this->dateDay->Enabled = false;
			this->dateDay->Location = System::Drawing::Point(220, 129);
			this->dateDay->Name = L"dateDay";
			this->dateDay->Size = System::Drawing::Size(200, 20);
			this->dateDay->TabIndex = 4;
			this->dateDay->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Enabled = false;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(217, 103);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(116, 18);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Выберите дату:";
			this->label2->Visible = false;
			// 
			// button_Ok
			// 
			this->button_Ok->Enabled = false;
			this->button_Ok->Location = System::Drawing::Point(121, 243);
			this->button_Ok->Name = L"button_Ok";
			this->button_Ok->Size = System::Drawing::Size(177, 42);
			this->button_Ok->TabIndex = 6;
			this->button_Ok->Text = L"Подтвердить";
			this->button_Ok->UseVisualStyleBackColor = true;
			this->button_Ok->Visible = false;
			this->button_Ok->Click += gcnew System::EventHandler(this, &CreateReport::button_Ok_Click);
			// 
			// ButtonExpenses
			// 
			this->ButtonExpenses->AutoSize = true;
			this->ButtonExpenses->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->ButtonExpenses->Location = System::Drawing::Point(6, 13);
			this->ButtonExpenses->Name = L"ButtonExpenses";
			this->ButtonExpenses->Size = System::Drawing::Size(94, 18);
			this->ButtonExpenses->TabIndex = 7;
			this->ButtonExpenses->TabStop = true;
			this->ButtonExpenses->Text = L"по затратам";
			this->ButtonExpenses->UseVisualStyleBackColor = true;
			this->ButtonExpenses->CheckedChanged += gcnew System::EventHandler(this, &CreateReport::ButtonExpenses_CheckedChanged);
			// 
			// ButtonCategory
			// 
			this->ButtonCategory->AutoSize = true;
			this->ButtonCategory->Location = System::Drawing::Point(6, 37);
			this->ButtonCategory->Name = L"ButtonCategory";
			this->ButtonCategory->Size = System::Drawing::Size(100, 17);
			this->ButtonCategory->TabIndex = 8;
			this->ButtonCategory->TabStop = true;
			this->ButtonCategory->Text = L"по категориям";
			this->ButtonCategory->UseVisualStyleBackColor = true;
			this->ButtonCategory->CheckedChanged += gcnew System::EventHandler(this, &CreateReport::ButtonCategory_CheckedChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(35, 19);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(230, 18);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Выбирете какой отчет сделать:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Enabled = false;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(35, 103);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(159, 18);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Выбирете тип отчета:";
			this->label1->Visible = false;
			// 
			// textCategory
			// 
			this->textCategory->Enabled = false;
			this->textCategory->Location = System::Drawing::Point(220, 72);
			this->textCategory->Name = L"textCategory";
			this->textCategory->Size = System::Drawing::Size(200, 20);
			this->textCategory->TabIndex = 11;
			this->textCategory->Visible = false;
			this->textCategory->TextChanged += gcnew System::EventHandler(this, &CreateReport::textCategory_TextChanged);
			// 
			// dateMonth
			// 
			this->dateMonth->CustomFormat = L"MMMM ";
			this->dateMonth->Enabled = false;
			this->dateMonth->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateMonth->Location = System::Drawing::Point(220, 203);
			this->dateMonth->Name = L"dateMonth";
			this->dateMonth->Size = System::Drawing::Size(200, 20);
			this->dateMonth->TabIndex = 12;
			this->dateMonth->Value = System::DateTime(2023, 8, 26, 14, 26, 29, 0);
			this->dateMonth->Visible = false;
			// 
			// dateWeek
			// 
			this->dateWeek->Enabled = false;
			this->dateWeek->Location = System::Drawing::Point(220, 166);
			this->dateWeek->Name = L"dateWeek";
			this->dateWeek->Size = System::Drawing::Size(200, 20);
			this->dateWeek->TabIndex = 13;
			this->dateWeek->Visible = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->ButtonExpenses);
			this->groupBox1->Controls->Add(this->ButtonCategory);
			this->groupBox1->Location = System::Drawing::Point(31, 40);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(156, 60);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			// 
			// CreateReport
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(441, 303);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dateWeek);
			this->Controls->Add(this->dateMonth);
			this->Controls->Add(this->textCategory);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button_Ok);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dateDay);
			this->Controls->Add(this->ButtonMonth);
			this->Controls->Add(this->ButtonWeek);
			this->Controls->Add(this->ButtonDay);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CreateReport";
			this->Text = L"CreateReport";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void ButtonExpenses_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ButtonCategory_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void textCategory_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ButtonDay_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void ButtonWeek_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ButtonMonth_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void button_Ok_Click(System::Object^ sender, System::EventArgs^ e);

	private: void CreateReportEx(String^ type);
	private: void CreateReportCa(String^ type);
};
}
