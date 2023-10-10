#pragma once
#include "FormCards.h"

namespace personalfinancemanager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AddBalance : public System::Windows::Forms::Form
	{

	public:
		AddBalance()
		{
			InitializeComponent();
		}

	protected:

		~AddBalance()
		{
			if (components)
			{
				delete components;
			}
		}

	private: 
		System::Windows::Forms::Button^ button_Ok;
		System::Windows::Forms::TextBox^ textBox_Balance;
		System::Windows::Forms::Label^ label_Balance;
		System::Windows::Forms::Label^ label_Number;
		System::Windows::Forms::TextBox^ NumberBox;
		System::ComponentModel::Container ^components;

	private:
		String^ balance;
		String^ number;
		

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddBalance::typeid));
			this->button_Ok = (gcnew System::Windows::Forms::Button());
			this->textBox_Balance = (gcnew System::Windows::Forms::TextBox());
			this->label_Balance = (gcnew System::Windows::Forms::Label());
			this->label_Number = (gcnew System::Windows::Forms::Label());
			this->NumberBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button_Ok
			// 
			this->button_Ok->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Ok->Location = System::Drawing::Point(16, 165);
			this->button_Ok->Name = L"button_Ok";
			this->button_Ok->Size = System::Drawing::Size(190, 29);
			this->button_Ok->TabIndex = 25;
			this->button_Ok->Text = L"Подтвердить";
			this->button_Ok->UseVisualStyleBackColor = true;
			this->button_Ok->Click += gcnew System::EventHandler(this, &AddBalance::button_Ok_Click);
			// 
			// textBox_Balance
			// 
			this->textBox_Balance->Location = System::Drawing::Point(16, 135);
			this->textBox_Balance->Name = L"textBox_Balance";
			this->textBox_Balance->Size = System::Drawing::Size(190, 20);
			this->textBox_Balance->TabIndex = 24;
			this->textBox_Balance->Visible = false;
			// 
			// label_Balance
			// 
			this->label_Balance->AutoSize = true;
			this->label_Balance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Balance->Location = System::Drawing::Point(26, 80);
			this->label_Balance->Name = L"label_Balance";
			this->label_Balance->Size = System::Drawing::Size(167, 44);
			this->label_Balance->TabIndex = 23;
			this->label_Balance->Text = L"Сумма на которую\r\n хотите пополнить\r\n";
			this->label_Balance->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label_Balance->Visible = false;
			// 
			// label_Number
			// 
			this->label_Number->AutoSize = true;
			this->label_Number->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Number->Location = System::Drawing::Point(12, 9);
			this->label_Number->Name = L"label_Number";
			this->label_Number->Size = System::Drawing::Size(194, 22);
			this->label_Number->TabIndex = 22;
			this->label_Number->Text = L"Введите номер карты";
			// 
			// NumberBox
			// 
			this->NumberBox->Location = System::Drawing::Point(16, 43);
			this->NumberBox->Name = L"NumberBox";
			this->NumberBox->Size = System::Drawing::Size(190, 20);
			this->NumberBox->TabIndex = 21;
			this->NumberBox->TextChanged += gcnew System::EventHandler(this, &AddBalance::NumberBox_TextChanged);
			// 
			// AddBalance
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(227, 221);
			this->Controls->Add(this->button_Ok);
			this->Controls->Add(this->textBox_Balance);
			this->Controls->Add(this->label_Balance);
			this->Controls->Add(this->label_Number);
			this->Controls->Add(this->NumberBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddBalance";
			this->Text = L"AddBalance";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void NumberBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Ok_Click(System::Object^ sender, System::EventArgs^ e);
};
}
