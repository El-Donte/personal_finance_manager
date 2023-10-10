#include "EditExpenses.h"
#include "FormExpenses.h"

System::Void personalfinancemanager::EditExpenses::textID_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	datePick->Visible = true;
	label_Date->Visible = true;
}

System::Void personalfinancemanager::EditExpenses::datePick_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	textNumber->Visible = true;
    label_Number->Visible = true;
}

System::Void personalfinancemanager::EditExpenses::textNumber_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    label_Category->Visible = true;
    textCategory->Visible = true;
}

System::Void personalfinancemanager::EditExpenses::textCategory_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    label_Summ->Visible = true;
    textSumm->Visible = true;
}

System::Void personalfinancemanager::EditExpenses::button_Ok_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
		number = textNumber->Text;
		summ = textSumm->Text;
		category = textCategory->Text;
		id = textID->Text;
		date = datePick->Value;

        if (category == "") {
            throw "Категория не введена";
        }
        if (summ == "") {
            throw "Сумма не введена";
        }
        if (number == "") {
            throw "Номер карты не введен";
        }
        if (id == "") {
            throw "Номер карты не введен";
        }


        this->Hide();

		String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

		dbConnection->Open();

		String^ query = "SELECT Balance FROM [Cards] WHERE Number =" +"'"+ number + "'";
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
		OleDbDataReader^ rdr = dbCommand->ExecuteReader();

		if (rdr->HasRows == false) {
			MessageBox::Show("Ошибка данных карты", "Error");
			dbConnection->Close();
			return;
		}


		query = "SELECT Summ FROM [Expenses] WHERE id =" + id;
		dbCommand = gcnew OleDbCommand(query, dbConnection);

		auto prevsumm = dbCommand->ExecuteScalar()->ToString();

		query = "SELECT Number FROM [Expenses] WHERE id =" + id;
		dbCommand = gcnew OleDbCommand(query, dbConnection);

		auto prevnumber = dbCommand->ExecuteScalar()->ToString();

		query = "UPDATE [Expenses] SET [Number]= ?, Category = ?, Summ = ?, Dater = ? WHERE ID=" + id;
		dbCommand = gcnew OleDbCommand(query, dbConnection);
		dbCommand->Parameters->AddWithValue("Number", number);
		dbCommand->Parameters->AddWithValue("Category", category);
		dbCommand->Parameters->AddWithValue("Summ", summ);
		dbCommand->Parameters->AddWithValue("Dater", date.Date);


		if (dbCommand->ExecuteNonQuery() != 1) {
			MessageBox::Show("Ошибка данных", "Error");
			dbConnection->Close();
			return;
		}

		query = "UPDATE [Cards] SET Balance=" + "Balance" + "+" + prevsumm + " WHERE Number =" + "'"+prevnumber+"'";
		dbCommand = gcnew OleDbCommand(query, dbConnection);
		dbCommand->ExecuteNonQuery();

		query = "UPDATE [Cards] SET Balance=" + "Balance" + "-" + summ + " WHERE Number =" + "'" + number + "'";
		dbCommand = gcnew OleDbCommand(query, dbConnection);

		if (dbCommand->ExecuteNonQuery() != 1) {
			MessageBox::Show("Ошибка данных", "Error");
			dbConnection->Close();
			return;
		}
		else {
			MessageBox::Show("Данные суммы карты изменены", "Готово!!");
		}

		dbConnection->Close();
    }
    catch (String^ ex) {
        MessageBox::Show(this, ex, "Eror", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}




