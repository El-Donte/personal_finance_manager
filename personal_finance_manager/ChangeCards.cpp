#include "ChangeCards.h"
#include "FormCards.h"


System::Void personalfinancemanager::ChangeCards::text_ID_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    label_Number->Visible = true;
    text_Number->Visible = true;
    text_Number->Enabled = true;
}

System::Void personalfinancemanager::ChangeCards::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    label_Type->Visible = true;
    radioCredit->Visible = true;
    radioCredit->Enabled = true;
    radioDebit->Visible = true;
    radioDebit->Enabled = true;
}

System::Void personalfinancemanager::ChangeCards::radioCredit_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    type = "Кредитная";
    label_Balance->Visible = true;
    textBox_Balance->Visible = true;
    textBox_Balance->Enabled = true;
}

System::Void personalfinancemanager::ChangeCards::radioDebit_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    type = "Дебитовая";
    label_Balance->Visible = true;
    textBox_Balance->Visible = true;
    textBox_Balance->Enabled = true;
}

System::Void personalfinancemanager::ChangeCards::textBox_Balance_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    button_Ok->Visible = true;
    button_Ok->Enabled = true;
}

System::Void personalfinancemanager::ChangeCards::button_Ok_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        balance = textBox_Balance->Text;
        number = text_Number->Text;
        id = text_ID->Text;

        this->Hide();
        if (type    ==   nullptr||
            number  ==   nullptr||
            balance ==   nullptr||
            id      ==   nullptr) {
            throw "Ошибка данных";
        }

        String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        dbConnection->Open();
        String^ query = "UPDATE [Cards] SET [Number] = '"+number+"', Type='" +type + "', Balance = " + balance + " WHERE ID = " + id;
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);


        if (dbCommand->ExecuteNonQuery() != 1) {
            MessageBox::Show("Ошибка данных", "Error");
        }
        else {
            MessageBox::Show("Данные изменены", "Готово!!");
        }

        dbConnection->Close();
    }
    catch (String^ ex) {
        MessageBox::Show(this, ex, "Eror", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}



