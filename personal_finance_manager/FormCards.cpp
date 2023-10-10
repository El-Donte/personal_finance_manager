#include "FormCards.h"
#include "ADRCards.h"
#include "DeleteCards.h"
#include "ChangeCards.h"
#include "AddBalance.h"

System::Void personalfinancemanager::FormCards::FormCards_Load(System::Object^ sender, System::EventArgs^ e)
{
    String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();

    String^ query = "SELECT * FROM [Cards]";

    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
    OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

    while (dbReader->Read()) {
        Cards->Rows->Add(dbReader["id"],dbReader["Number"], dbReader["Type"], dbReader["Balance"]);
    }


    dbReader->Close();
    dbConnection->Close();
}

System::Void personalfinancemanager::FormCards::button_Add_Click(System::Object^ sender, System::EventArgs^ e)
{
	ADRCards^ form = gcnew ADRCards(this);
	form->BringToFront();
	form->Show();
}

System::Void personalfinancemanager::FormCards::button_Change_Click(System::Object^ sender, System::EventArgs^ e)
{
	ChangeCards^ form = gcnew ChangeCards();
	form->BringToFront();
	form->Show();
}

System::Void personalfinancemanager::FormCards::button_Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
    DeleteCards^ form = gcnew DeleteCards();
    form->BringToFront();
    form->Show();
}

System::Void personalfinancemanager::FormCards::button_Balance_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddBalance^ form = gcnew AddBalance();
	form->BringToFront();
	form->Show();
}

System::Void personalfinancemanager::FormCards::button_Update_Click(System::Object^ sender, System::EventArgs^ e)
{
    Cards->Rows->Clear();

    String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();

    String^ query = "SELECT * FROM [Cards]";

    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
    OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

    while (dbReader->Read()) {
        Cards->Rows->Add(dbReader["id"], dbReader["Number"], dbReader["Type"], dbReader["Balance"]);
    }

    dbReader->Close();
    dbConnection->Close();
}



