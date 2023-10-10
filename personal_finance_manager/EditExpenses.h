#pragma once

namespace personalfinancemanager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class EditExpenses : public System::Windows::Forms::Form
	{
	public:
		EditExpenses(void)
		{
			InitializeComponent();
		}

	protected:
		~EditExpenses()
		{
			if (components)
			{
				delete components;
			}
		}

	private: 
		System::Windows::Forms::Button^ button_Ok;
		System::Windows::Forms::Label^ label_Summ;
		System::Windows::Forms::TextBox^ textSumm;
		System::Windows::Forms::Label^ label_Category;
		System::Windows::Forms::TextBox^ textCategory;
		System::Windows::Forms::Label^ label_Number;
		System::Windows::Forms::TextBox^ textNumber;
		System::Windows::Forms::Label^ label_Date;
		System::Windows::Forms::DateTimePicker^ datePick;
		System::Windows::Forms::Label^ label_ID;
		System::Windows::Forms::TextBox^ textID;
		System::ComponentModel::Container ^components;

	private:
		String^ number;
		String^ summ;
		String^ category;
		String^ id;
		DateTime date;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EditExpenses::typeid));
			this->button_Ok = (gcnew System::Windows::Forms::Button());
			this->label_Summ = (gcnew System::Windows::Forms::Label());
			this->textSumm = (gcnew System::Windows::Forms::TextBox());
			this->label_Category = (gcnew System::Windows::Forms::Label());
			this->textCategory = (gcnew System::Windows::Forms::TextBox());
			this->label_Number = (gcnew System::Windows::Forms::Label());
			this->textNumber = (gcnew System::Windows::Forms::TextBox());
			this->label_Date = (gcnew System::Windows::Forms::Label());
			this->datePick = (gcnew System::Windows::Forms::DateTimePicker());
			this->label_ID = (gcnew System::Windows::Forms::Label());
			this->textID = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button_Ok
			// 
			this->button_Ok->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Ok->Location = System::Drawing::Point(51, 334);
			this->button_Ok->Name = L"button_Ok";
			this->button_Ok->Size = System::Drawing::Size(190, 29);
			this->button_Ok->TabIndex = 28;
			this->button_Ok->Text = L"Подтвердить";
			this->button_Ok->UseVisualStyleBackColor = true;
			this->button_Ok->Click += gcnew System::EventHandler(this, &EditExpenses::button_Ok_Click);
			// 
			// label_Summ
			// 
			this->label_Summ->AutoSize = true;
			this->label_Summ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Summ->Location = System::Drawing::Point(38, 271);
			this->label_Summ->Name = L"label_Summ";
			this->label_Summ->Size = System::Drawing::Size(212, 22);
			this->label_Summ->TabIndex = 27;
			this->label_Summ->Text = L"Введите сумму затраты\r\n";
			this->label_Summ->Visible = false;
			// 
			// textSumm
			// 
			this->textSumm->Location = System::Drawing::Point(51, 308);
			this->textSumm->Name = L"textSumm";
			this->textSumm->Size = System::Drawing::Size(190, 20);
			this->textSumm->TabIndex = 26;
			this->textSumm->Visible = false;
			// 
			// label_Category
			// 
			this->label_Category->AutoSize = true;
			this->label_Category->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Category->Location = System::Drawing::Point(57, 202);
			this->label_Category->Name = L"label_Category";
			this->label_Category->Size = System::Drawing::Size(173, 22);
			this->label_Category->TabIndex = 25;
			this->label_Category->Text = L"Введите категорию\r\n";
			this->label_Category->Visible = false;
			// 
			// textCategory
			// 
			this->textCategory->Location = System::Drawing::Point(51, 236);
			this->textCategory->Name = L"textCategory";
			this->textCategory->Size = System::Drawing::Size(190, 20);
			this->textCategory->TabIndex = 24;
			this->textCategory->Visible = false;
			this->textCategory->TextChanged += gcnew System::EventHandler(this, &EditExpenses::textCategory_TextChanged);
			// 
			// label_Number
			// 
			this->label_Number->AutoSize = true;
			this->label_Number->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Number->Location = System::Drawing::Point(12, 144);
			this->label_Number->Name = L"label_Number";
			this->label_Number->Size = System::Drawing::Size(260, 22);
			this->label_Number->TabIndex = 23;
			this->label_Number->Text = L"Введите номер карты оплаты\r\n";
			this->label_Number->Visible = false;
			// 
			// textNumber
			// 
			this->textNumber->Location = System::Drawing::Point(51, 179);
			this->textNumber->Name = L"textNumber";
			this->textNumber->Size = System::Drawing::Size(190, 20);
			this->textNumber->TabIndex = 22;
			this->textNumber->Visible = false;
			this->textNumber->TextChanged += gcnew System::EventHandler(this, &EditExpenses::textNumber_TextChanged);
			// 
			// label_Date
			// 
			this->label_Date->AutoSize = true;
			this->label_Date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Date->Location = System::Drawing::Point(74, 77);
			this->label_Date->Name = L"label_Date";
			this->label_Date->Size = System::Drawing::Size(136, 22);
			this->label_Date->TabIndex = 30;
			this->label_Date->Text = L"Выберите дату";
			this->label_Date->Visible = false;
			// 
			// datePick
			// 
			this->datePick->CustomFormat = L"";
			this->datePick->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->datePick->Location = System::Drawing::Point(51, 111);
			this->datePick->Name = L"datePick";
			this->datePick->Size = System::Drawing::Size(190, 20);
			this->datePick->TabIndex = 31;
			this->datePick->Value = System::DateTime(2023, 9, 23, 0, 0, 0, 0);
			this->datePick->Visible = false;
			this->datePick->ValueChanged += gcnew System::EventHandler(this, &EditExpenses::datePick_ValueChanged);
			// 
			// label_ID
			// 
			this->label_ID->AutoSize = true;
			this->label_ID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_ID->Location = System::Drawing::Point(38, 19);
			this->label_ID->Name = L"label_ID";
			this->label_ID->Size = System::Drawing::Size(225, 22);
			this->label_ID->TabIndex = 33;
			this->label_ID->Text = L"Введите номер операции\r\n";
			// 
			// textID
			// 
			this->textID->Location = System::Drawing::Point(51, 44);
			this->textID->Name = L"textID";
			this->textID->Size = System::Drawing::Size(190, 20);
			this->textID->TabIndex = 32;
			this->textID->TextChanged += gcnew System::EventHandler(this, &EditExpenses::textID_TextChanged);
			// 
			// EditExpenses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 375);
			this->Controls->Add(this->label_ID);
			this->Controls->Add(this->textID);
			this->Controls->Add(this->datePick);
			this->Controls->Add(this->label_Date);
			this->Controls->Add(this->button_Ok);
			this->Controls->Add(this->label_Summ);
			this->Controls->Add(this->textSumm);
			this->Controls->Add(this->label_Category);
			this->Controls->Add(this->textCategory);
			this->Controls->Add(this->label_Number);
			this->Controls->Add(this->textNumber);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"EditExpenses";
			this->Text = L"Изменить затраты";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void textID_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void datePick_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textNumber_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textCategory_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Ok_Click(System::Object^ sender, System::EventArgs^ e);

};
}
