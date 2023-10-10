#include "FormExpenses.h"
#include "AddExpenses.h"
#include "EditExpenses.h"
#include "DeleteExpenses.h"
#include "CreateReport.h"

System::Void personalfinancemanager::FormExpenses::FormExpenses_Load(System::Object^ sender, System::EventArgs^ e)
{
    String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();

    String^ query = "SELECT * FROM [Expenses]";

    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
    OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

    while (dbReader->Read()) {
        Expenses->Rows->Add(dbReader["ID"],dbReader["Dater"],dbReader["Number"], dbReader["Category"], dbReader["Summ"]);
    }

    dbReader->Close();
    dbConnection->Close();
}

System::Void personalfinancemanager::FormExpenses::button_Add_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddExpenses^ form = gcnew AddExpenses();
	form->BringToFront();
	form->Show();
}
System::Void personalfinancemanager::FormExpenses::button_Edit_Click(System::Object^ sender, System::EventArgs^ e)
{
	EditExpenses^ form = gcnew EditExpenses();
	form->BringToFront();
	form->Show();
}
System::Void personalfinancemanager::FormExpenses::button_Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	DeleteExpenses^ form = gcnew DeleteExpenses();
	form->BringToFront();
	form->Show();
}
System::Void personalfinancemanager::FormExpenses::button_Create_Click(System::Object^ sender, System::EventArgs^ e)
{
	CreateReport^ form = gcnew CreateReport(this);
	form->BringToFront();
	form->Show();
}

System::Void personalfinancemanager::FormExpenses::buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e)
{
    Expenses->Rows->Clear();
    String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();

    String^ query = "SELECT * FROM [Expenses]";

    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
    OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

    while (dbReader->Read()) {
        Expenses->Rows->Add(dbReader["ID"], dbReader["Dater"], dbReader["Number"], dbReader["Category"], dbReader["Summ"]);
    }

    dbReader->Close();
    dbConnection->Close();
}

System::Void personalfinancemanager::FormExpenses::button_Save_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (queryForSave == nullptr) {
		MessageBox::Show("Ошибка данных", "Error");
		return;
	}

	saveToFile->Filter = "(*.txt)|*.txt";
	saveToFile->Title = "Save an File";
	saveToFile->ShowDialog();

	if (saveToFile->FileName != "")
	{
		System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(saveToFile->FileName);

		String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
		dbConnection->Open();
		OleDbCommand^ dbCommand = gcnew OleDbCommand(queryForSave, dbConnection);
		OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

		while (dbReader->Read()) {
			sw->WriteLine(String::Format("{0}, {1},{2},{3}", dbReader["Number"],dbReader["Dater"], dbReader["Category"], dbReader["Summ"]));
		}

		sw->Close();
		dbReader->Close();
		dbConnection->Close();

		queryForSave = nullptr;
	}
}



