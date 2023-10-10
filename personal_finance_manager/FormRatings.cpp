#include "FormRatings.h"

using namespace System::Windows::Forms::DataVisualization::Charting;

System::Void personalfinancemanager::FormRatings::button_OK_Click(System::Object^ sender, System::EventArgs^ e)
{
	FillChart(type, type_date, d);
}

System::Void personalfinancemanager::FormRatings::button_Category_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	button_week->Visible = true;
	button_week->Enabled = true;
	button_month->Visible = true;
	button_month->Enabled = true;
	type = 1;
}

System::Void personalfinancemanager::FormRatings::button_Expenses_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	button_week->Visible = true;
	button_week->Enabled = true;
	button_month->Visible = true;
	button_month->Enabled = true;
	type = 2;
}

System::Void personalfinancemanager::FormRatings::Button_week_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (button_week->Checked) {
		DatePickWeek->Visible = true;
		DatePickWeek->Enabled = true;
		type_date = "неделя";
	}
	else {
		DatePickWeek->Visible = false;
		DatePickWeek->Enabled = false;
		button_OK->Visible = false;
		button_OK->Enabled = false;
	}
	
}

System::Void personalfinancemanager::FormRatings::button_month_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (button_month->Checked) {
		DatePickMonth->Visible = true;
		DatePickMonth->Enabled = true;
		type_date = "месяц";
	}
	else {
		DatePickMonth->Visible = false;
		DatePickMonth->Enabled = false;
		button_OK->Visible = false;
		button_OK->Enabled = false;
	}
	
}

System::Void personalfinancemanager::FormRatings::DatePick_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	button_OK->Visible = true;
	button_OK->Enabled = true;
	d = DatePickMonth->Value;
}

System::Void personalfinancemanager::FormRatings::DatePickWeek_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	button_OK->Visible = true;
	button_OK->Enabled = true;
	d = DatePickWeek->Value;
}

System::Void personalfinancemanager::FormRatings::saveToFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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

		String^ connectionString ="provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
		dbConnection->Open();
		OleDbCommand^ dbCommand = gcnew OleDbCommand(queryForSave, dbConnection);
		OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

		for (int ii = 0; ii < 3; ii++) {
			if (dbReader->Read()) {
				sw->WriteLine(String::Format("{0}, {1}",dbReader["Category"],dbReader["Summ"]));
			}
		}
		sw->Close();
		dbReader->Close();
		dbConnection->Close();

		queryForSave = nullptr;
	}
	

}

void personalfinancemanager::FormRatings::FillChart(int type, String^ type_date, DateTime date)
{
	switch (type)
	{
	case 1:
		if (type_date == "месяц") {

			chart->Series->Clear();
			Series^ series1 = (gcnew Series());
			series1->Name = " ";
			series1->IsValueShownAsLabel = true;
			chart->Series->Add(series1);
			Series^ series2 = (gcnew Series());
			series2->Name = "  ";
			series2->IsValueShownAsLabel = true;
			chart->Series->Add(series2);
			Series^ series3 = (gcnew Series());
			series3->Name = "   ";
			series3->IsValueShownAsLabel = true;
			chart->Series->Add(series3);

			chart->Legends[0]->Title = "Категории";
			chart->Titles[0]->Text = L"Категории за месяц";

			String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
			OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

			dbConnection->Open();
			String^ query = "SELECT Category, SUM(Summ) AS [Summ] FROM [Expenses] WHERE ((DatePart('m', [Dater]) = " + 
				date.Month + "))GROUP BY Category ORDER BY SUM(Summ) DESC";
			OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
			OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

			queryForSave = query;

			if (dbReader->HasRows == false) {
				MessageBox::Show("Ошибка данных", "Error");
				dbReader->Close();
				dbConnection->Close();
				return;
			}

			for (int ii = 0; ii < 3; ii++) {
				if (dbReader->Read()) {
					chart->Series[ii]->Points->Clear();
					String^ name = dbReader["Category"]->ToString();
					chart->Series[ii]->Name = name;
					chart->Series[ii]->Points->AddY(dbReader["Summ"]);
				}
			}

			dbReader->Close();
			dbConnection->Close();
		}
		else if (type_date == "неделя") {
			chart->Series->Clear();
			Series^ series1 = (gcnew Series());
			series1->Name = " ";
			series1->IsValueShownAsLabel = true;
			chart->Series->Add(series1);
			Series^ series2 = (gcnew Series());
			series2->Name = "  ";
			series2->IsValueShownAsLabel = true;
			chart->Series->Add(series2);
			Series^ series3 = (gcnew Series());
			series3->Name = "   ";
			series3->IsValueShownAsLabel = true;
			chart->Series->Add(series3);

			chart->Legends[0]->Title = "Категории";
			chart->Titles[0]->Text = L"Категории за неделю";

			String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
			OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

			dbConnection->Open();
			String^ query = "SELECT Category, SUM(Summ) AS [Sum-Summ] FROM [Expenses] WHERE((DatePart(" + "'ww'" + ", [Dater]) = DatePart(" + "'ww'" + ", #" + date.Month
				+ "/" + date.Day + "/" + date.Year + "#) And Year([Dater])=Year(Date()))) GROUP BY Category ORDER BY SUM(Summ) DESC";
			OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
			OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

			queryForSave = query;

			if (dbReader->HasRows == false) {
				MessageBox::Show("Ошибка данных", "Error");
				dbReader->Close();
				dbConnection->Close();
				return;
			}

			for (int ii = 0; ii < 3; ii++) {
				if (dbReader->Read()) {
					chart->Series[ii]->Points->Clear();
					String^ name = dbReader["Category"]->ToString();
					chart->Series[ii]->Name = name;
					chart->Series[ii]->Points->AddY( dbReader["Sum-Summ"]);
				}
			}

			dbReader->Close();
			dbConnection->Close();
		}
		break;
	case 2:
		if (type_date == "месяц") {
			chart->Series->Clear();
			Series^ series1 = (gcnew Series());
			series1->Name = " ";
			series1->IsValueShownAsLabel = true;
			chart->Series->Add(series1);
			Series^ series2 = (gcnew Series());
			series2->Name = "  ";
			series2->IsValueShownAsLabel = true;
			chart->Series->Add(series2);
			Series^ series3 = (gcnew Series());
			series3->Name = "   ";
			series3->IsValueShownAsLabel = true;
			chart->Series->Add(series3);

			chart->Legends[0]->Title = "Номер затраты";
			chart->Titles[0]->Text = L"Затраты за месяц";

			String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
			OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

			dbConnection->Open();
			String^ query = "SELECT ID,Category, Summ FROM [Expenses] WHERE ((DatePart('m', [Dater]) = " + date.Month + ")) ORDER BY Summ DESC";
			OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
			OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

			queryForSave = query;

			if (dbReader->HasRows == false) {
				MessageBox::Show("Ошибка данных", "Error");
				dbReader->Close();
				dbConnection->Close();
				return;
			}

			for (int ii = 0; ii < 3; ii++) {
				if (dbReader->Read()) {
					chart->Series[ii]->Points->Clear();
					String^ name = dbReader["ID"]->ToString();
					chart->Series[ii]->Name = name;
					chart->Series[ii]->Points->AddY(dbReader["Summ"]);
				}
			}

			dbReader->Close();
			dbConnection->Close();
		}
		else if (type_date == "неделя") {
			chart->Series->Clear();
			Series^ series1 = (gcnew Series());
			series1->Name = " ";
			series1->IsValueShownAsLabel = true;
			chart->Series->Add(series1);
			Series^ series2 = (gcnew Series());
			series2->Name = "  ";
			series2->IsValueShownAsLabel = true;
			chart->Series->Add(series2);
			Series^ series3 = (gcnew Series());
			series3->Name = "   ";
			series3->IsValueShownAsLabel = true;
			chart->Series->Add(series3);

			chart->Legends[0]->Title = "Номер затраты";
			chart->Titles[0]->Text = L"Затраты за неделю";

			String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database1.accdb;Persist Security Info=False;";
			OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

			dbConnection->Open();
			String^ query = "SELECT ID,Category, Summ FROM[Expenses] WHERE((DatePart(" + "'ww'" + ", [Dater]) = DatePart(" + "'ww'" + ", #" + date.Month
				+ "/" + date.Day + "/" + date.Year + "#) And Year([Dater])=Year(Date()))) ORDER BY Summ DESC";
			OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
			OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

			queryForSave = query;

			if (dbReader->HasRows == false) {
				MessageBox::Show("Ошибка данных", "Error");
				dbReader->Close();
				dbConnection->Close();
				return;
			}

			for (int ii = 0; ii < 3; ii++) {
				if (dbReader->Read()) {
					chart->Series[ii]->Points->Clear();
					String^ name = dbReader["ID"]->ToString();
					chart->Series[ii]->Name = name;
					chart->Series[ii]->Points->AddY(dbReader["Summ"]);
				}
			}

			dbReader->Close();
			dbConnection->Close();
		}
		break;
	default:
		break;
	}
	
}