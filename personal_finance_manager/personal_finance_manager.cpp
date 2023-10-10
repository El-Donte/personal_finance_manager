#include "personal_finance_manager.h"
#include "FormExpenses.h"
#include "FormRatings.h"
#include "FormCards.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	personalfinancemanager::personal_finance_manager form;
	Application::Run(% form);
}

void personalfinancemanager::personal_finance_manager::ActivateButton(Button^ btnSender)
{   
	DisableButton(btnCrads,btnExpenses,btnRatings);
	if (btnSender != nullptr) {
		btnSender->BackColor = System::Drawing::Color::FromArgb(128, 128, 255);
		btnSender->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
	}

}

void personalfinancemanager::personal_finance_manager::DisableButton(Button^ _btnCrads,Button^ _btnExpenses,Button^ _btnRatings)
{
	if (_btnCrads->BackColor == System::Drawing::Color::FromArgb(128, 128, 255)) {
		_btnCrads->BackColor = System::Drawing::Color::FromArgb(51, 51, 76);
		_btnCrads->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
	}
	else if (_btnExpenses->BackColor == System::Drawing::Color::FromArgb(128, 128, 255)) {
		_btnExpenses->BackColor = System::Drawing::Color::FromArgb(51, 51, 76);
		_btnExpenses->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
	}
	else if (_btnRatings->BackColor == System::Drawing::Color::FromArgb(128, 128, 255)) {
		_btnRatings->BackColor = System::Drawing::Color::FromArgb(51, 51, 76);
		_btnRatings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
	}
}

void personalfinancemanager::personal_finance_manager::OpenForm(Form^ form, Button^ btnSender)
{
	if (activeForm != nullptr) {
		activeForm->Close();
	}
	ActivateButton(btnSender);
	activeForm = form;
	form->TopLevel = false;
	form->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
	form->Dock = DockStyle::Fill;
	this->DesktopPanel->Controls->Add(form);
	this->DesktopPanel->Tag = form;
	form->BringToFront();
	form->Show();
	labelTitle->Text = form->Text;
}

System::Void personalfinancemanager::personal_finance_manager::btnCrads_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenForm(gcnew FormCards(),btnCrads);
}

System::Void personalfinancemanager::personal_finance_manager::btnExpenses_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenForm(gcnew FormExpenses(), btnExpenses);
}

System::Void personalfinancemanager::personal_finance_manager::btnRatings_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenForm(gcnew FormRatings(), btnRatings);
}


