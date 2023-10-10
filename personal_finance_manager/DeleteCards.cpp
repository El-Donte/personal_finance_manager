#include "DeleteCards.h"
#include "FormCards.h"

System::Void personalfinancemanager::DeleteCards::button_Ok_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        if (text_ID->Text == "") {
            throw "����� ����� �� ������";
        }

        this->Hide();
		String^ id = text_ID->Text;

		if (id == nullptr) {
			MessageBox::Show("������", "Error");
			return;
		}

		String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

		dbConnection->Open();
		String^ query = "DELETE FROM [Cards] WHERE ID =" + id;
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);


		if (dbCommand->ExecuteNonQuery() != 1) {
			MessageBox::Show("������ ������", "Error");
		}
		else {
			MessageBox::Show("������� �������", "������!!");
		}

		dbConnection->Close();
    }
    catch (String^ ex) {
        MessageBox::Show(this, ex, "Eror", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
