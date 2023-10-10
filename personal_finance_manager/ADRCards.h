#pragma once
#include "FormCards.h"

namespace personalfinancemanager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ADRCards : public System::Windows::Forms::Form
	{

		FormCards^ form;
	public:
		ADRCards(FormCards^ fr)
		{
			this->form = fr;
			InitializeComponent();
		}

	protected:
		~ADRCards()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_Type;
			 System::Windows::Forms::RadioButton^ radioDebit;
			 System::Windows::Forms::RadioButton^ radioCredit;
			 System::Windows::Forms::TextBox^ textBox_Balance;
			 System::Windows::Forms::Label^ label_Balance;
			 System::Windows::Forms::Label^ label_Number;
			 System::Windows::Forms::TextBox^ NumberBox;
			 System::ComponentModel::Container ^components;
			 System::Windows::Forms::Button^ button_Ok;

	private:
		String^ type;
		String^ balance;
		String^ number;
	
		   

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ADRCards::typeid));
			this->label_Type = (gcnew System::Windows::Forms::Label());
			this->radioDebit = (gcnew System::Windows::Forms::RadioButton());
			this->radioCredit = (gcnew System::Windows::Forms::RadioButton());
			this->textBox_Balance = (gcnew System::Windows::Forms::TextBox());
			this->label_Balance = (gcnew System::Windows::Forms::Label());
			this->label_Number = (gcnew System::Windows::Forms::Label());
			this->NumberBox = (gcnew System::Windows::Forms::TextBox());
			this->button_Ok = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label_Type
			// 
			this->label_Type->AutoSize = true;
			this->label_Type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Type->Location = System::Drawing::Point(59, 19);
			this->label_Type->Name = L"label_Type";
			this->label_Type->Size = System::Drawing::Size(126, 22);
			this->label_Type->TabIndex = 19;
			this->label_Type->Text = L"Выберите тип";
			// 
			// radioDebit
			// 
			this->radioDebit->AutoSize = true;
			this->radioDebit->Location = System::Drawing::Point(63, 67);
			this->radioDebit->Name = L"radioDebit";
			this->radioDebit->Size = System::Drawing::Size(81, 17);
			this->radioDebit->TabIndex = 18;
			this->radioDebit->Text = L"Дебитовая";
			this->radioDebit->UseVisualStyleBackColor = true;
			this->radioDebit->CheckedChanged += gcnew System::EventHandler(this, &ADRCards::radioDebit_CheckedChanged);
			// 
			// radioCredit
			// 
			this->radioCredit->AutoSize = true;
			this->radioCredit->Location = System::Drawing::Point(63, 44);
			this->radioCredit->Name = L"radioCredit";
			this->radioCredit->Size = System::Drawing::Size(79, 17);
			this->radioCredit->TabIndex = 17;
			this->radioCredit->Text = L"Кредитная";
			this->radioCredit->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->radioCredit->UseVisualStyleBackColor = true;
			this->radioCredit->CheckedChanged += gcnew System::EventHandler(this, &ADRCards::radioCredit_CheckedChanged);
			// 
			// textBox_Balance
			// 
			this->textBox_Balance->Location = System::Drawing::Point(63, 210);
			this->textBox_Balance->Name = L"textBox_Balance";
			this->textBox_Balance->Size = System::Drawing::Size(190, 20);
			this->textBox_Balance->TabIndex = 16;
			this->textBox_Balance->Visible = false;
			// 
			// label_Balance
			// 
			this->label_Balance->AutoSize = true;
			this->label_Balance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Balance->Location = System::Drawing::Point(59, 174);
			this->label_Balance->Name = L"label_Balance";
			this->label_Balance->Size = System::Drawing::Size(200, 22);
			this->label_Balance->TabIndex = 15;
			this->label_Balance->Text = L"Введите баланс карты";
			this->label_Balance->Visible = false;
			// 
			// label_Number
			// 
			this->label_Number->AutoSize = true;
			this->label_Number->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Number->Location = System::Drawing::Point(59, 103);
			this->label_Number->Name = L"label_Number";
			this->label_Number->Size = System::Drawing::Size(194, 22);
			this->label_Number->TabIndex = 14;
			this->label_Number->Text = L"Введите номер карты";
			this->label_Number->Visible = false;
			// 
			// NumberBox
			// 
			this->NumberBox->Location = System::Drawing::Point(63, 137);
			this->NumberBox->Name = L"NumberBox";
			this->NumberBox->Size = System::Drawing::Size(190, 20);
			this->NumberBox->TabIndex = 13;
			this->NumberBox->Visible = false;
			this->NumberBox->TextChanged += gcnew System::EventHandler(this, &ADRCards::NumberBox_TextChanged);
			// 
			// button_Ok
			// 
			this->button_Ok->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Ok->Location = System::Drawing::Point(63, 247);
			this->button_Ok->Name = L"button_Ok";
			this->button_Ok->Size = System::Drawing::Size(190, 29);
			this->button_Ok->TabIndex = 20;
			this->button_Ok->Text = L"Подтвердить";
			this->button_Ok->UseVisualStyleBackColor = true;
			this->button_Ok->Click += gcnew System::EventHandler(this, &ADRCards::button_Ok_Click);
			// 
			// ADRCards
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(305, 300);
			this->Controls->Add(this->button_Ok);
			this->Controls->Add(this->label_Type);
			this->Controls->Add(this->radioDebit);
			this->Controls->Add(this->radioCredit);
			this->Controls->Add(this->textBox_Balance);
			this->Controls->Add(this->label_Balance);
			this->Controls->Add(this->label_Number);
			this->Controls->Add(this->NumberBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ADRCards";
			this->Text = L"Добавление карты";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void radioCredit_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void radioDebit_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void NumberBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Ok_Click(System::Object^ sender, System::EventArgs^ e);
};
}
