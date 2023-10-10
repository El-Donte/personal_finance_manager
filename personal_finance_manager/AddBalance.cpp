#include "AddBalance.h"


System::Void personalfinancemanager::AddBalance::NumberBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    label_Balance->Visible = true;
    textBox_Balance->Visible = true;
}

System::Void personalfinancemanager::AddBalance::button_Ok_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        if (NumberBox->Text == "") {
            throw "Номер карты не введен";
        }
        if (textBox_Balance->Text == "") {
            throw "Баланс не введен";
        }

        balance = textBox_Balance->Text;
        number = NumberBox->Text;
    
        String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
        OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

        dbConnection->Open();
        String^ query = "UPDATE [Cards] SET Balance=" + "Balance" + "+" + balance + " WHERE Number =" + "'"+number+"'";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);


        if (dbCommand->ExecuteNonQuery() != 1) {
            MessageBox::Show("Ошибка данных", "Error");
        }
        else {
            MessageBox::Show("Баланс пополнен", "Готово!!");
        }

        dbConnection->Close();

        this->Hide();
    }
    catch (String^ ex) {
        MessageBox::Show(this, ex, "Eror", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
