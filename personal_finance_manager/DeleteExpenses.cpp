#include "DeleteExpenses.h"
#include "FormExpenses.h"

System::Void personalfinancemanager::DeleteExpenses::button_Ok_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
		String^ id = IDbox->Text;

        if (id == nullptr) {
            throw "Номер операции не введен";
        }

        this->Hide();

		String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

		dbConnection->Open();

		String^ query = "SELECT Summ FROM [Expenses] WHERE ID =" + id;
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

		auto summ = dbCommand->ExecuteScalar()->ToString();

		query = "SELECT Number FROM [Expenses] WHERE ID =" + id;
		dbCommand = gcnew OleDbCommand(query, dbConnection);

		auto number = dbCommand->ExecuteScalar()->ToString();

		query = "DELETE FROM [Expenses] WHERE ID =" + id;
		dbCommand = gcnew OleDbCommand(query, dbConnection);

		if (dbCommand->ExecuteNonQuery() != 1) {
			MessageBox::Show("Ошибка данных", "Error");
			dbConnection->Close();
			return;
		}

		query = "UPDATE [Cards] SET Balance=" + "Balance" + "+" + summ + " WHERE Number =" + "'"+number+"'";
		dbCommand = gcnew OleDbCommand(query, dbConnection);

		if (dbCommand->ExecuteNonQuery() != 1) {
			MessageBox::Show("Ошибка данных", "Error");
			dbConnection->Close();
			return;
		}
		else {
			MessageBox::Show("Успешно удалено", "Готово!!");
		}

		dbConnection->Close();
    }
    catch (String^ ex) {
        MessageBox::Show(this, ex, "Eror", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
