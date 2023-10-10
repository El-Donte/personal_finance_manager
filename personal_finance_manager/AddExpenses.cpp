#include "AddExpenses.h"

System::Void personalfinancemanager::AddExpenses::datePick_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
    textNumber->Visible = true;
    label_Number->Visible = true;
}

System::Void personalfinancemanager::AddExpenses::textNumber_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    label_Category->Visible = true;
    textCategory->Visible = true;
}

System::Void personalfinancemanager::AddExpenses::textCategory_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    label_Summ->Visible = true;
    textSumm->Visible = true;
}

System::Void personalfinancemanager::AddExpenses::button_Ok_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
		int count = 0;
		date = datePick->Value;
		number = textNumber->Text;
		summ = textSumm->Text;
		category = textCategory->Text;

        if (category == nullptr) {
            throw "Категория не введена";
        }
        if (summ == nullptr) {
            throw "Сумма не введена";
        }
        if (number == nullptr) {
            throw "Номер карты не введен";
        }

        this->Hide();

		String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

		dbConnection->Open();

		String^ query = "SELECT Balance FROM [Cards] where id =" + number;
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
		OleDbDataReader^ rdr = dbCommand->ExecuteReader();

		if (rdr->HasRows == false) {
			MessageBox::Show("Ошибка данных карты", "Error");
			rdr->Close();
			dbConnection->Close();
			return;
		}

		query = "SELECT ID FROM [Expenses]";
		dbCommand = gcnew OleDbCommand(query, dbConnection);
		OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

		while (dbReader->Read()) {
			count++;
		}
		String^ id = (count + 1).ToString();

		query = "INSERT INTO [Expenses] VALUES (?,?,?,?,?)";
		dbCommand = gcnew OleDbCommand(query, dbConnection);

		dbCommand->Parameters->AddWithValue("Number",number);
		dbCommand->Parameters->AddWithValue("Category", category);
		dbCommand->Parameters->AddWithValue("Summ", summ);
		dbCommand->Parameters->AddWithValue("Dater", date.Date);
		dbCommand->Parameters->AddWithValue("ID", id);

		if (dbCommand->ExecuteNonQuery() != 1) {
			MessageBox::Show("Ошибка данных", "Error");
			dbReader->Close();
			dbConnection->Close();
			return;
		}

		query = "UPDATE [Cards] SET Balance=" + "Balance" + "-" + summ + " WHERE id =" + number;
		dbCommand = gcnew OleDbCommand(query, dbConnection);

		if (dbCommand->ExecuteNonQuery() != 1) {
			MessageBox::Show("Ошибка данных", "Error");
			dbReader->Close();
			dbConnection->Close();
			return;
		}
		else {
			MessageBox::Show("Данные успешно добавлены и баланс карты изменен", "Готово!!");
		}
		dbReader->Close();
		dbConnection->Close();
    }
    catch (String^ ex) {
        MessageBox::Show(this, ex, "Eror", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}


