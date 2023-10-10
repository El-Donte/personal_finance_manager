#pragma once

namespace personalfinancemanager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class personal_finance_manager : public System::Windows::Forms::Form
	{
	public:
		personal_finance_manager(void)
		{
			InitializeComponent();
		}

	protected:
		~personal_finance_manager()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Form^ activeForm;

	private: System::Windows::Forms::Panel^ panelMenu;
	private: System::Windows::Forms::Panel^ panelLogo;
	private: System::Windows::Forms::Button^ btnCrads;


	private: System::Windows::Forms::Button^ btnRatings;


	private: System::Windows::Forms::Button^ btnExpenses;
	private: System::Windows::Forms::Panel^ panelTitle;
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::Panel^ DesktopPanel;



	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(personal_finance_manager::typeid));
			this->panelMenu = (gcnew System::Windows::Forms::Panel());
			this->btnRatings = (gcnew System::Windows::Forms::Button());
			this->btnExpenses = (gcnew System::Windows::Forms::Button());
			this->btnCrads = (gcnew System::Windows::Forms::Button());
			this->panelLogo = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panelTitle = (gcnew System::Windows::Forms::Panel());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->DesktopPanel = (gcnew System::Windows::Forms::Panel());
			this->panelMenu->SuspendLayout();
			this->panelLogo->SuspendLayout();
			this->panelTitle->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelMenu
			// 
			this->panelMenu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panelMenu->Controls->Add(this->btnRatings);
			this->panelMenu->Controls->Add(this->btnExpenses);
			this->panelMenu->Controls->Add(this->btnCrads);
			this->panelMenu->Controls->Add(this->panelLogo);
			this->panelMenu->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelMenu->Location = System::Drawing::Point(0, 0);
			this->panelMenu->Name = L"panelMenu";
			this->panelMenu->Size = System::Drawing::Size(220, 531);
			this->panelMenu->TabIndex = 0;
			// 
			// btnRatings
			// 
			this->btnRatings->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnRatings->FlatAppearance->BorderSize = 0;
			this->btnRatings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRatings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnRatings->ForeColor = System::Drawing::Color::Gainsboro;
			this->btnRatings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRatings.Image")));
			this->btnRatings->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnRatings->Location = System::Drawing::Point(0, 200);
			this->btnRatings->Name = L"btnRatings";
			this->btnRatings->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->btnRatings->Size = System::Drawing::Size(220, 60);
			this->btnRatings->TabIndex = 2;
			this->btnRatings->Text = L"   Рейтинги";
			this->btnRatings->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnRatings->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnRatings->UseVisualStyleBackColor = true;
			this->btnRatings->Click += gcnew System::EventHandler(this, &personal_finance_manager::btnRatings_Click);
			// 
			// btnExpenses
			// 
			this->btnExpenses->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnExpenses->FlatAppearance->BorderSize = 0;
			this->btnExpenses->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnExpenses->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnExpenses->ForeColor = System::Drawing::Color::Gainsboro;
			this->btnExpenses->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnExpenses.Image")));
			this->btnExpenses->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnExpenses->Location = System::Drawing::Point(0, 140);
			this->btnExpenses->Name = L"btnExpenses";
			this->btnExpenses->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->btnExpenses->Size = System::Drawing::Size(220, 60);
			this->btnExpenses->TabIndex = 1;
			this->btnExpenses->Text = L"   Затраты";
			this->btnExpenses->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnExpenses->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnExpenses->UseVisualStyleBackColor = true;
			this->btnExpenses->Click += gcnew System::EventHandler(this, &personal_finance_manager::btnExpenses_Click);
			// 
			// btnCrads
			// 
			this->btnCrads->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->btnCrads->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnCrads->FlatAppearance->BorderSize = 0;
			this->btnCrads->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCrads->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnCrads->ForeColor = System::Drawing::Color::Gainsboro;
			this->btnCrads->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCrads.Image")));
			this->btnCrads->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCrads->Location = System::Drawing::Point(0, 80);
			this->btnCrads->Name = L"btnCrads";
			this->btnCrads->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->btnCrads->Size = System::Drawing::Size(220, 60);
			this->btnCrads->TabIndex = 0;
			this->btnCrads->Text = L"   Карты и счета";
			this->btnCrads->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCrads->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnCrads->UseVisualStyleBackColor = false;
			this->btnCrads->Click += gcnew System::EventHandler(this, &personal_finance_manager::btnCrads_Click);
			// 
			// panelLogo
			// 
			this->panelLogo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panelLogo->Controls->Add(this->label1);
			this->panelLogo->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelLogo->Location = System::Drawing::Point(0, 0);
			this->panelLogo->Name = L"panelLogo";
			this->panelLogo->Size = System::Drawing::Size(220, 80);
			this->panelLogo->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::LightGray;
			this->label1->Location = System::Drawing::Point(18, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(187, 40);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Персональный \r\nфинансовый помощник";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panelTitle
			// 
			this->panelTitle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panelTitle->Controls->Add(this->labelTitle);
			this->panelTitle->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelTitle->Location = System::Drawing::Point(220, 0);
			this->panelTitle->Name = L"panelTitle";
			this->panelTitle->Size = System::Drawing::Size(805, 80);
			this->panelTitle->TabIndex = 1;
			// 
			// labelTitle
			// 
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelTitle->ForeColor = System::Drawing::Color::White;
			this->labelTitle->Location = System::Drawing::Point(379, 26);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(72, 25);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"HOME";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// DesktopPanel
			// 
			this->DesktopPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DesktopPanel->Location = System::Drawing::Point(220, 80);
			this->DesktopPanel->Name = L"DesktopPanel";
			this->DesktopPanel->Size = System::Drawing::Size(805, 451);
			this->DesktopPanel->TabIndex = 2;
			// 
			// personal_finance_manager
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1025, 531);
			this->Controls->Add(this->DesktopPanel);
			this->Controls->Add(this->panelTitle);
			this->Controls->Add(this->panelMenu);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"personal_finance_manager";
			this->Text = L"personal_finance_manager";
			this->panelMenu->ResumeLayout(false);
			this->panelLogo->ResumeLayout(false);
			this->panelLogo->PerformLayout();
			this->panelTitle->ResumeLayout(false);
			this->panelTitle->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void ActivateButton(Button^ btnSender);
	private: void DisableButton(Button^ _btnCrads, Button^ _btnExpenses, Button^ _btnRatings);
	private: void OpenForm(Form^ form, Button^ btnSender);

	private: System::Void btnCrads_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnExpenses_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnRatings_Click(System::Object^ sender, System::EventArgs^ e);

};
}
