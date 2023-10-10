#pragma once

namespace personalfinancemanager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ChangeCards : public System::Windows::Forms::Form
	{
	public:
		ChangeCards(void)
		{
			InitializeComponent();
		}

	protected:
		~ChangeCards()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::Button^ button_Ok;
		System::Windows::Forms::Label^ label_Type;
		System::Windows::Forms::RadioButton^ radioDebit;
		System::Windows::Forms::RadioButton^ radioCredit;
		System::Windows::Forms::TextBox^ textBox_Balance;
		System::Windows::Forms::Label^ label_Balance;
		System::Windows::Forms::Label^ label_Number;
		System::Windows::Forms::TextBox^ text_Number;
		System::ComponentModel::Container ^components;
		System::Windows::Forms::TextBox^ text_ID;
		System::Windows::Forms::Label^ label2;

	private:
		String^ type;
		String^ balance;
		String^ number;
		String^ id;
		String^ newNumber;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_Ok = (gcnew System::Windows::Forms::Button());
			this->label_Type = (gcnew System::Windows::Forms::Label());
			this->radioDebit = (gcnew System::Windows::Forms::RadioButton());
			this->radioCredit = (gcnew System::Windows::Forms::RadioButton());
			this->textBox_Balance = (gcnew System::Windows::Forms::TextBox());
			this->label_Balance = (gcnew System::Windows::Forms::Label());
			this->label_Number = (gcnew System::Windows::Forms::Label());
			this->text_Number = (gcnew System::Windows::Forms::TextBox());
			this->text_ID = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button_Ok
			// 
			this->button_Ok->Enabled = false;
			this->button_Ok->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Ok->Location = System::Drawing::Point(46, 292);
			this->button_Ok->Name = L"button_Ok";
			this->button_Ok->Size = System::Drawing::Size(190, 29);
			this->button_Ok->TabIndex = 28;
			this->button_Ok->Text = L"Подтвердить";
			this->button_Ok->UseVisualStyleBackColor = true;
			this->button_Ok->Visible = false;
			this->button_Ok->Click += gcnew System::EventHandler(this, &ChangeCards::button_Ok_Click);
			// 
			// label_Type
			// 
			this->label_Type->AutoSize = true;
			this->label_Type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Type->Location = System::Drawing::Point(42, 144);
			this->label_Type->Name = L"label_Type";
			this->label_Type->Size = System::Drawing::Size(126, 22);
			this->label_Type->TabIndex = 27;
			this->label_Type->Text = L"Выберите тип";
			this->label_Type->Visible = false;
			// 
			// radioDebit
			// 
			this->radioDebit->AutoSize = true;
			this->radioDebit->Enabled = false;
			this->radioDebit->Location = System::Drawing::Point(46, 201);
			this->radioDebit->Name = L"radioDebit";
			this->radioDebit->Size = System::Drawing::Size(81, 17);
			this->radioDebit->TabIndex = 26;
			this->radioDebit->Text = L"Дебитовая";
			this->radioDebit->UseVisualStyleBackColor = true;
			this->radioDebit->Visible = false;
			this->radioDebit->CheckedChanged += gcnew System::EventHandler(this, &ChangeCards::radioDebit_CheckedChanged);
			// 
			// radioCredit
			// 
			this->radioCredit->AutoSize = true;
			this->radioCredit->Enabled = false;
			this->radioCredit->Location = System::Drawing::Point(46, 178);
			this->radioCredit->Name = L"radioCredit";
			this->radioCredit->Size = System::Drawing::Size(79, 17);
			this->radioCredit->TabIndex = 25;
			this->radioCredit->Text = L"Кредитная";
			this->radioCredit->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->radioCredit->UseVisualStyleBackColor = true;
			this->radioCredit->Visible = false;
			this->radioCredit->CheckedChanged += gcnew System::EventHandler(this, &ChangeCards::radioCredit_CheckedChanged);
			// 
			// textBox_Balance
			// 
			this->textBox_Balance->Enabled = false;
			this->textBox_Balance->Location = System::Drawing::Point(46, 266);
			this->textBox_Balance->Name = L"textBox_Balance";
			this->textBox_Balance->Size = System::Drawing::Size(190, 20);
			this->textBox_Balance->TabIndex = 24;
			this->textBox_Balance->Visible = false;
			this->textBox_Balance->TextChanged += gcnew System::EventHandler(this, &ChangeCards::textBox_Balance_TextChanged);
			// 
			// label_Balance
			// 
			this->label_Balance->AutoSize = true;
			this->label_Balance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Balance->Location = System::Drawing::Point(42, 231);
			this->label_Balance->Name = L"label_Balance";
			this->label_Balance->Size = System::Drawing::Size(200, 22);
			this->label_Balance->TabIndex = 23;
			this->label_Balance->Text = L"Введите баланс карты";
			this->label_Balance->Visible = false;
			// 
			// label_Number
			// 
			this->label_Number->AutoSize = true;
			this->label_Number->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Number->Location = System::Drawing::Point(42, 78);
			this->label_Number->Name = L"label_Number";
			this->label_Number->Size = System::Drawing::Size(194, 22);
			this->label_Number->TabIndex = 30;
			this->label_Number->Text = L"Введите номер карты";
			this->label_Number->Visible = false;
			// 
			// text_Number
			// 
			this->text_Number->Enabled = false;
			this->text_Number->Location = System::Drawing::Point(46, 112);
			this->text_Number->Name = L"text_Number";
			this->text_Number->Size = System::Drawing::Size(190, 20);
			this->text_Number->TabIndex = 29;
			this->text_Number->Visible = false;
			this->text_Number->TextChanged += gcnew System::EventHandler(this, &ChangeCards::textBox1_TextChanged);
			// 
			// text_ID
			// 
			this->text_ID->Location = System::Drawing::Point(46, 55);
			this->text_ID->Name = L"text_ID";
			this->text_ID->Size = System::Drawing::Size(190, 20);
			this->text_ID->TabIndex = 31;
			this->text_ID->TextChanged += gcnew System::EventHandler(this, &ChangeCards::text_ID_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(59, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(155, 22);
			this->label2->TabIndex = 32;
			this->label2->Text = L"Введите id карты";
			// 
			// ChangeCards
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 333);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->text_ID);
			this->Controls->Add(this->label_Number);
			this->Controls->Add(this->text_Number);
			this->Controls->Add(this->button_Ok);
			this->Controls->Add(this->label_Type);
			this->Controls->Add(this->radioDebit);
			this->Controls->Add(this->radioCredit);
			this->Controls->Add(this->textBox_Balance);
			this->Controls->Add(this->label_Balance);
			this->Name = L"ChangeCards";
			this->Text = L"Изменить карту";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void text_ID_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void radioCredit_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void radioDebit_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox_Balance_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Ok_Click(System::Object^ sender, System::EventArgs^ e);
};
}
