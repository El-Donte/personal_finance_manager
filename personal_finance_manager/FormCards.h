#pragma once

namespace personalfinancemanager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;
	
	public ref class FormCards : public System::Windows::Forms::Form
	{
	public:
		FormCards(void)
		{
			InitializeComponent();
	
		}

	protected:
		~FormCards()
		{
			if (components)
			{
				delete components;
			}
		}

	private: 
		System::Windows::Forms::DataGridView^ Cards;
		System::Windows::Forms::Button^ button_Add;
		System::Windows::Forms::Button^ button_Delete;
		System::Windows::Forms::Button^ button_Balance;
		System::Windows::Forms::Button^ button_Change;
		System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
		System::Windows::Forms::DataGridViewTextBoxColumn^ number;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Type;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Balance;
		System::ComponentModel::Container ^components;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Button^ button_Update;

	private:
		Form^ activeForm;
		int index;
	public:
		int count = 0;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormCards::typeid));
			this->Cards = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Balance = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button_Add = (gcnew System::Windows::Forms::Button());
			this->button_Delete = (gcnew System::Windows::Forms::Button());
			this->button_Balance = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_Change = (gcnew System::Windows::Forms::Button());
			this->button_Update = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Cards))->BeginInit();
			this->SuspendLayout();
			// 
			// Cards
			// 
			this->Cards->AllowUserToAddRows = false;
			this->Cards->AllowUserToDeleteRows = false;
			this->Cards->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->ID, this->number,
					this->Type, this->Balance
			});
			this->Cards->Location = System::Drawing::Point(241, 99);
			this->Cards->MinimumSize = System::Drawing::Size(494, 252);
			this->Cards->Name = L"Cards";
			this->Cards->ReadOnly = true;
			this->Cards->Size = System::Drawing::Size(533, 350);
			this->Cards->TabIndex = 0;
			// 
			// ID
			// 
			this->ID->HeaderText = L"id";
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			// 
			// number
			// 
			this->number->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->number->HeaderText = L"Номер карты";
			this->number->Name = L"number";
			this->number->ReadOnly = true;
			// 
			// Type
			// 
			this->Type->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Type->HeaderText = L"Тип";
			this->Type->Name = L"Type";
			this->Type->ReadOnly = true;
			// 
			// Balance
			// 
			this->Balance->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Balance->HeaderText = L"Баланс";
			this->Balance->Name = L"Balance";
			this->Balance->ReadOnly = true;
			this->Balance->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// button_Add
			// 
			this->button_Add->Location = System::Drawing::Point(71, 115);
			this->button_Add->Name = L"button_Add";
			this->button_Add->Size = System::Drawing::Size(128, 51);
			this->button_Add->TabIndex = 1;
			this->button_Add->Text = L"Добавить карту";
			this->button_Add->UseVisualStyleBackColor = true;
			this->button_Add->Click += gcnew System::EventHandler(this, &FormCards::button_Add_Click);
			// 
			// button_Delete
			// 
			this->button_Delete->Location = System::Drawing::Point(71, 260);
			this->button_Delete->Name = L"button_Delete";
			this->button_Delete->Size = System::Drawing::Size(128, 51);
			this->button_Delete->TabIndex = 2;
			this->button_Delete->Text = L"Удалить карту";
			this->button_Delete->UseVisualStyleBackColor = true;
			this->button_Delete->Click += gcnew System::EventHandler(this, &FormCards::button_Delete_Click);
			// 
			// button_Balance
			// 
			this->button_Balance->Location = System::Drawing::Point(71, 332);
			this->button_Balance->Name = L"button_Balance";
			this->button_Balance->Size = System::Drawing::Size(128, 51);
			this->button_Balance->TabIndex = 3;
			this->button_Balance->Text = L"Пополнить баланс";
			this->button_Balance->UseVisualStyleBackColor = true;
			this->button_Balance->Click += gcnew System::EventHandler(this, &FormCards::button_Balance_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(310, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(441, 44);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Карты и Счета";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button_Change
			// 
			this->button_Change->Location = System::Drawing::Point(71, 185);
			this->button_Change->Name = L"button_Change";
			this->button_Change->Size = System::Drawing::Size(128, 51);
			this->button_Change->TabIndex = 5;
			this->button_Change->Text = L"Изменить карту";
			this->button_Change->UseVisualStyleBackColor = true;
			this->button_Change->Click += gcnew System::EventHandler(this, &FormCards::button_Change_Click);
			// 
			// button_Update
			// 
			this->button_Update->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Update.Image")));
			this->button_Update->Location = System::Drawing::Point(241, 60);
			this->button_Update->Name = L"button_Update";
			this->button_Update->Size = System::Drawing::Size(40, 30);
			this->button_Update->TabIndex = 6;
			this->button_Update->UseVisualStyleBackColor = true;
			this->button_Update->Click += gcnew System::EventHandler(this, &FormCards::button_Update_Click);
			// 
			// FormCards
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(786, 466);
			this->Controls->Add(this->button_Update);
			this->Controls->Add(this->button_Change);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_Balance);
			this->Controls->Add(this->button_Delete);
			this->Controls->Add(this->button_Add);
			this->Controls->Add(this->Cards);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FormCards";
			this->Text = L"Карты и Счета";
			this->Load += gcnew System::EventHandler(this, &FormCards::FormCards_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Cards))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void FormCards_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Add_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Change_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Delete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Balance_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Update_Click(System::Object^ sender, System::EventArgs^ e);
};
}
