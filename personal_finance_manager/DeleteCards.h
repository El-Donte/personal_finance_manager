#pragma once

namespace personalfinancemanager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class DeleteCards : public System::Windows::Forms::Form
	{
	public:
		DeleteCards(void)
		{
			InitializeComponent();
		}

	protected:
		~DeleteCards()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::Button^ button_Ok;
		System::Windows::Forms::Label^ label_ID;
		System::Windows::Forms::TextBox^ text_ID;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DeleteCards::typeid));
			this->button_Ok = (gcnew System::Windows::Forms::Button());
			this->label_ID = (gcnew System::Windows::Forms::Label());
			this->text_ID = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button_Ok
			// 
			this->button_Ok->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Ok->Location = System::Drawing::Point(47, 126);
			this->button_Ok->Name = L"button_Ok";
			this->button_Ok->Size = System::Drawing::Size(190, 29);
			this->button_Ok->TabIndex = 23;
			this->button_Ok->Text = L"Подтвердить";
			this->button_Ok->UseVisualStyleBackColor = true;
			this->button_Ok->Click += gcnew System::EventHandler(this, &DeleteCards::button_Ok_Click);
			// 
			// label_ID
			// 
			this->label_ID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_ID->Location = System::Drawing::Point(47, 36);
			this->label_ID->Name = L"label_ID";
			this->label_ID->Size = System::Drawing::Size(190, 44);
			this->label_ID->TabIndex = 22;
			this->label_ID->Text = L"Введите id карты";
			this->label_ID->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// text_ID
			// 
			this->text_ID->Location = System::Drawing::Point(47, 91);
			this->text_ID->Name = L"text_ID";
			this->text_ID->Size = System::Drawing::Size(190, 20);
			this->text_ID->TabIndex = 21;
			// 
			// DeleteCards
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 188);
			this->Controls->Add(this->button_Ok);
			this->Controls->Add(this->label_ID);
			this->Controls->Add(this->text_ID);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"DeleteCards";
			this->Text = L"Удалить карту";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button_Ok_Click(System::Object^ sender, System::EventArgs^ e);
};
}
