#include "CreateReport.h"
#include "FormExpenses.h"

using namespace System::Data::OleDb;

System::Void personalfinancemanager::CreateReport::ButtonExpenses_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (ButtonExpenses->Checked) {
        label1->Visible = true;
        label1->Enabled = true;

        ButtonDay->Enabled = true;
        ButtonDay->Visible = true;

        ButtonWeek->Enabled = true;
        ButtonWeek->Visible = true;

        ButtonMonth->Enabled = true;
        ButtonMonth->Visible = true;

        textCategory->Visible = false;
        textCategory->Enabled = false;

        label2->Visible = false;
        label2->Enabled = false;

        dateDay->Visible = false;
        dateDay->Enabled = false;

        dateWeek->Visible = false;
        dateWeek->Enabled = false;


        dateMonth->Visible = false;
        dateMonth->Enabled = false;

        button_Ok->Visible = false;
        button_Ok->Enabled = false;

        type = 1;
    } 
}

System::Void personalfinancemanager::CreateReport::ButtonCategory_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (ButtonCategory->Checked) {
        label1->Visible = false;
        label1->Enabled = false;

        ButtonDay->Enabled = false;
        ButtonDay->Visible = false;

        ButtonWeek->Enabled = false;
        ButtonWeek->Visible = false;

        ButtonMonth->Enabled = false;
        ButtonMonth->Visible = false;

        textCategory->Visible = true;
        textCategory->Enabled = true;

        label2->Visible = false;
        label2->Enabled = false;

        dateDay->Visible = false;
        dateDay->Enabled = false;

        dateWeek->Visible = false;
        dateWeek->Enabled = false;



        dateMonth->Visible = false;
        dateMonth->Enabled = false;

        button_Ok->Visible = false;
        button_Ok->Enabled = false;

        type = 2;
    }
    
}

System::Void personalfinancemanager::CreateReport::textCategory_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    label1->Visible = true;
    label1->Enabled = true;

    ButtonDay->Enabled = true;
    ButtonDay->Visible = true;

    ButtonWeek->Enabled = true;
    ButtonWeek->Visible = true;

    ButtonMonth->Enabled = true;
    ButtonMonth->Visible = true;
}

System::Void personalfinancemanager::CreateReport::ButtonDay_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    label2->Visible = true;
    label2->Enabled = true;

    dateDay->Visible = true;
    dateDay->Enabled = true;


    dateWeek->Visible = false;
    dateWeek->Enabled = false;

    
    dateMonth->Visible = false;
    dateMonth->Enabled = false;

    button_Ok->Visible = true;
    button_Ok->Enabled = true;

    key = "день";
}

System::Void personalfinancemanager::CreateReport::ButtonWeek_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    label2->Visible = true;
    label2->Enabled = true;

    dateDay->Visible = false;
    dateDay->Enabled = false;

    dateWeek->Visible = true;
    dateWeek->Enabled = true;

    dateMonth->Visible = false;
    dateMonth->Enabled = false;

    button_Ok->Visible = true;
    button_Ok->Enabled = true;

    key = "недел€";
}
System::Void personalfinancemanager::CreateReport::ButtonMonth_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    label2->Visible = true;
    label2->Enabled = true;

    dateDay->Visible = false;
    dateDay->Enabled = false;

    dateWeek->Visible = false;
    dateWeek->Enabled = false;

    dateMonth->Visible = true;
    dateMonth->Enabled = true;

    button_Ok->Visible = true;
    button_Ok->Enabled = true;

    key = "мес€ц";
}

System::Void personalfinancemanager::CreateReport::button_Ok_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        if (key == nullptr) {
            throw "отсутствует тип";
        }

        switch (type)
        {
        case 1:
            this->Hide();
            CreateReportEx(key);
            break;
        case 2:
            this->Hide();
            CreateReportCa(key);
            break;
        default:
            break;
        }

    }
    catch (String^ ex)
    {
        MessageBox::Show(this, ex, "Eror", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

void personalfinancemanager::CreateReport::CreateReportEx(String^ type)
{
    if (type == nullptr) {
        MessageBox::Show("ќшибка", "Error");
        return;
    }

    if (type == "мес€ц") {
        date = dateMonth->Value;
        form->labelReports->Text = "ќтчеты по затратам за мес€ц";
        form->Reports->Rows->Clear();

        String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        dbConnection->Open();

        String^ query = "SELECT Number, Dater, Category, Summ FROM [Expenses] WHERE ((DatePart('m', [Dater]) = " + date.Month + ")) ORDER BY Summ DESC";

        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

        form->queryForSave = query;

        if (dbReader->HasRows == false) {
            MessageBox::Show("ќшибка данных", "Error");
            form->queryForSave = nullptr;
            dbReader->Close();
            dbConnection->Close();
            return;
        }

        while (dbReader->Read()) {
            form->Reports->Rows->Add(dbReader["Dater"], dbReader["Number"], dbReader["Category"], dbReader["Summ"]);
        }

        dbReader->Close();
        dbConnection->Close();
    }
    else if (type == "день") {
        form->labelReports->Text = "ќтчеты по затратам за день";
        form->Reports->Rows->Clear();
        date = dateDay->Value;

        String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        dbConnection->Open();

        String^ query = "SELECT Number, Dater, Category, Summ FROM [Expenses] WHERE (((Expenses.Dater)=#" + date.Month + "/" + date.Day + "/" + date.Year + "#)) ORDER BY Summ DESC";

        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

        form->queryForSave = query;

        if (dbReader->HasRows == false) {
            form->queryForSave = nullptr;
            MessageBox::Show("ќшибка данных", "Error");
            dbReader->Close();
            dbConnection->Close();
            return;
        }

        while (dbReader->Read()) {
            form->Reports->Rows->Add(dbReader["Dater"], dbReader["Number"], dbReader["Category"], dbReader["Summ"]);
        }

        dbReader->Close();
        dbConnection->Close();
    }
    else if (type == "недел€") {
        form->labelReports->Text = "ќтчеты по затратам за неделю";
        form->Reports->Rows->Clear();
        date = dateWeek->Value;

        String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        dbConnection->Open();

        String^ query = "SELECT Number, Dater, Category, Summ FROM [Expenses] WHERE ((DatePart(" + "'ww'" + ",[Dater])=DatePart(" + "'ww'" + ",#" + date.Month
            + "/" + date.Day + "/" + date.Year + "#) And Year([Dater])=Year(Date())))";

        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

        form->queryForSave = query;

        if (dbReader->HasRows == false) {
            form->queryForSave = nullptr;
            MessageBox::Show("ќшибка данных", "Error");
            dbReader->Close();
            dbConnection->Close();
            return;
        }

        while (dbReader->Read()) {
            form->Reports->Rows->Add(dbReader["Dater"], dbReader["Number"], dbReader["Category"], dbReader["Summ"]);
        }

        dbReader->Close();
        dbConnection->Close();
    }
}

void personalfinancemanager::CreateReport::CreateReportCa(String^ type)
{
    category = textCategory->Text;

    if (category == nullptr ||
        type == nullptr) {
        MessageBox::Show("ќшибка", "Error");
        return;
    }
    
    if (type == "мес€ц") {
        form->labelReports->Text = "ќтчеты по категори€м за мес€ц";
        form->Reports->Rows->Clear();
        date = dateMonth->Value;

        String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        dbConnection->Open();

        String^ query = "SELECT Number, Dater, Category, Summ FROM [Expenses] WHERE ((DatePart(" + "'m'" + ", [Dater]) =" + date.Month + ")) AND (Category ='" + category + "') ORDER BY Summ DESC";

        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

        form->queryForSave = query;

        if (dbReader->HasRows == false) {
            form->queryForSave = nullptr;
            MessageBox::Show("ќшибка данных", "Error");
            dbReader->Close();
            dbConnection->Close();
            return;
        }

        while (dbReader->Read()) {
            form->Reports->Rows->Add(dbReader["Dater"], dbReader["Number"], dbReader["Category"], dbReader["Summ"]);
        }

        dbReader->Close();
        dbConnection->Close();
    }
    else if (type == "день") {

        form->labelReports->Text = "ќтчеты по категори€м за день";
        form->Reports->Rows->Clear();
        date = dateDay->Value;

        String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        dbConnection->Open();

        String^ query = "SELECT Number, Dater, Category, Summ FROM [Expenses] WHERE (((Expenses.Dater)=#" +
            date.Month + "/" + date.Day + "/" + date.Year + "#)) AND (Category ='" + category + "') ORDER BY Summ DESC";

        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

        form->queryForSave = query;

        if (dbReader->HasRows == false) {
            form->queryForSave = nullptr;
            MessageBox::Show("ќшибка данных", "Error");
            dbReader->Close();
            dbConnection->Close();
            return;
        }

        while (dbReader->Read()) {
            form->Reports->Rows->Add(dbReader["Dater"], dbReader["Number"], dbReader["Category"], dbReader["Summ"]);
        }

        dbReader->Close();
        dbConnection->Close();
    }
    else if (type == "недел€") {
        form->labelReports->Text = "ќтчеты по категори€м за неделю";
        form->Reports->Rows->Clear();
        date = dateWeek->Value;

        String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        dbConnection->Open();

        String^ query = "SELECT Number, Dater, Category, Summ FROM [Expenses] WHERE ((DatePart(" + "'ww'" + ",[Dater])=DatePart(" + "'ww'" + ",#" + date.Month
            + "/" + date.Day + "/" + date.Year + "#) And Year([Dater])=Year(Date()))) AND (Category ='" + category + "')";

        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

        form->queryForSave = query;

        if (dbReader->HasRows == false) {
            form->queryForSave = nullptr;
            MessageBox::Show("ќшибка данных", "Error");
            dbReader->Close();
            dbConnection->Close();
            return;
        }

        while (dbReader->Read()) {
            form->Reports->Rows->Add(dbReader["Dater"], dbReader["Number"], dbReader["Category"], dbReader["Summ"]);
        }

        dbReader->Close();
        dbConnection->Close();
    }
}