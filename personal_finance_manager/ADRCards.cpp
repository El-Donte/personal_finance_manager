#include "ADRCards.h"


System::Void personalfinancemanager::ADRCards::radioCredit_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    type = "���������";
    label_Number->Visible = true;
    NumberBox->Visible = true;
}

System::Void personalfinancemanager::ADRCards::radioDebit_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    type = "���������";
    label_Number->Visible = true;
    NumberBox->Visible = true;
}

System::Void personalfinancemanager::ADRCards::NumberBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    label_Balance->Visible = true;
    textBox_Balance->Visible = true;
}

System::Void personalfinancemanager::ADRCards::button_Ok_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        if (NumberBox->Text == "") {
            throw "����� ����� �� ������";
        }
        if (textBox_Balance->Text == "") {
            throw "������ �� ������";
        }

        balance = textBox_Balance->Text;
        number = NumberBox->Text;

        this->Hide();
        if (type == nullptr ||
            number == nullptr ||
            balance == nullptr) {
            MessageBox::Show("������", "Error");
            return;
        }

        String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
        dbConnection->Open();

        String^ query = "SELECT ID FROM [Cards]";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

        while (dbReader->Read()) {
            form->count++;
        }
        String^ id = (form->count + 1).ToString();

        query = "INSERT INTO [Cards] VALUES (?,?,?,?)";
        dbCommand = gcnew OleDbCommand(query, dbConnection);
        dbCommand->Parameters->AddWithValue("Number", number);
        dbCommand->Parameters->AddWithValue("Type", type);
        dbCommand->Parameters->AddWithValue("Balance", balance);
        dbCommand->Parameters->AddWithValue("ID",id);

        if (dbCommand->ExecuteNonQuery() != 1) {
            MessageBox::Show("������ ������", "Error");
        }
        else {
            MessageBox::Show("������� ���������", "������!!");
        }

        dbConnection->Close();
    }
    catch (String^ ex) {
        MessageBox::Show(this, ex, "Eror", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}



