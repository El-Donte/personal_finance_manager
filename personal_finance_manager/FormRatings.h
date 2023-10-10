#pragma once

namespace personalfinancemanager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;

	public ref class FormRatings : public System::Windows::Forms::Form
	{
	public:
		FormRatings(void)
		{
			InitializeComponent();
		}

	protected:
		~FormRatings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::Button^ button_OK;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
		System::Windows::Forms::GroupBox^ groupBox1;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::GroupBox^ groupBox2;
		System::Windows::Forms::RadioButton^ button_Category;
		System::Windows::Forms::RadioButton^ button_Expenses;
		System::Windows::Forms::RadioButton^ button_month;
		System::Windows::Forms::RadioButton^ button_week;
		System::Windows::Forms::DateTimePicker^ DatePickMonth;
		System::Windows::Forms::DateTimePicker^ DatePickWeek;
		System::ComponentModel::Container ^components; 
		System::Windows::Forms::MenuStrip^ menuStrip1;
		System::Windows::Forms::ToolStripMenuItem^ ActionToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ saveToFileToolStripMenuItem;
		System::Windows::Forms::SaveFileDialog^ saveToFile;

	private: 
		int type;
		String^ type_date;
		String^ queryForSave = nullptr;
		DateTime d;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormRatings::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->button_OK = (gcnew System::Windows::Forms::Button());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->DatePickWeek = (gcnew System::Windows::Forms::DateTimePicker());
			this->DatePickMonth = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button_Category = (gcnew System::Windows::Forms::RadioButton());
			this->button_Expenses = (gcnew System::Windows::Forms::RadioButton());
			this->button_month = (gcnew System::Windows::Forms::RadioButton());
			this->button_week = (gcnew System::Windows::Forms::RadioButton());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ActionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToFile = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_OK
			// 
			resources->ApplyResources(this->button_OK, L"button_OK");
			this->button_OK->Name = L"button_OK";
			this->button_OK->UseVisualStyleBackColor = true;
			this->button_OK->Click += gcnew System::EventHandler(this, &FormRatings::button_OK_Click);
			// 
			// chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			resources->ApplyResources(this->chart, L"chart");
			legend1->AutoFitMinFontSize = 12;
			legend1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			legend1->IsTextAutoFit = false;
			legend1->Name = L"Legend1";
			legend1->Title = L"Категории";
			legend1->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			legend1->TitleSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::ThickLine;
			this->chart->Legends->Add(legend1);
			this->chart->Name = L"chart";
			series1->ChartArea = L"ChartArea1";
			series1->EmptyPointStyle->IsVisibleInLegend = false;
			series1->IsValueShownAsLabel = true;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea1";
			series2->EmptyPointStyle->IsVisibleInLegend = false;
			series2->IsValueShownAsLabel = true;
			series2->Legend = L"Legend1";
			series2->Name = L"Series2";
			series3->ChartArea = L"ChartArea1";
			series3->EmptyPointStyle->IsVisibleInLegend = false;
			series3->IsValueShownAsLabel = true;
			series3->Legend = L"Legend1";
			series3->Name = L"Series3";
			this->chart->Series->Add(series1);
			this->chart->Series->Add(series2);
			this->chart->Series->Add(series3);
			title1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			title1->Name = L"Title1";
			this->chart->Titles->Add(title1);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->DatePickWeek);
			this->groupBox1->Controls->Add(this->DatePickMonth);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->button_month);
			this->groupBox1->Controls->Add(this->button_week);
			this->groupBox1->Controls->Add(this->button_OK);
			resources->ApplyResources(this->groupBox1, L"groupBox1");
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->TabStop = false;
			// 
			// DatePickWeek
			// 
			resources->ApplyResources(this->DatePickWeek, L"DatePickWeek");
			this->DatePickWeek->Name = L"DatePickWeek";
			this->DatePickWeek->ValueChanged += gcnew System::EventHandler(this, &FormRatings::DatePickWeek_ValueChanged);
			// 
			// DatePickMonth
			// 
			resources->ApplyResources(this->DatePickMonth, L"DatePickMonth");
			this->DatePickMonth->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->DatePickMonth->Name = L"DatePickMonth";
			this->DatePickMonth->ValueChanged += gcnew System::EventHandler(this, &FormRatings::DatePick_ValueChanged);
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button_Category);
			this->groupBox2->Controls->Add(this->button_Expenses);
			resources->ApplyResources(this->groupBox2, L"groupBox2");
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->TabStop = false;
			// 
			// button_Category
			// 
			resources->ApplyResources(this->button_Category, L"button_Category");
			this->button_Category->Name = L"button_Category";
			this->button_Category->TabStop = true;
			this->button_Category->UseVisualStyleBackColor = true;
			this->button_Category->CheckedChanged += gcnew System::EventHandler(this, &FormRatings::button_Category_CheckedChanged);
			// 
			// button_Expenses
			// 
			resources->ApplyResources(this->button_Expenses, L"button_Expenses");
			this->button_Expenses->Name = L"button_Expenses";
			this->button_Expenses->TabStop = true;
			this->button_Expenses->UseVisualStyleBackColor = true;
			this->button_Expenses->CheckedChanged += gcnew System::EventHandler(this, &FormRatings::button_Expenses_CheckedChanged);
			// 
			// button_month
			// 
			resources->ApplyResources(this->button_month, L"button_month");
			this->button_month->Name = L"button_month";
			this->button_month->TabStop = true;
			this->button_month->UseVisualStyleBackColor = true;
			this->button_month->CheckedChanged += gcnew System::EventHandler(this, &FormRatings::button_month_CheckedChanged);
			// 
			// button_week
			// 
			resources->ApplyResources(this->button_week, L"button_week");
			this->button_week->Name = L"button_week";
			this->button_week->TabStop = true;
			this->button_week->UseVisualStyleBackColor = true;
			this->button_week->CheckedChanged += gcnew System::EventHandler(this, &FormRatings::Button_week_CheckedChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ActionToolStripMenuItem });
			resources->ApplyResources(this->menuStrip1, L"menuStrip1");
			this->menuStrip1->Name = L"menuStrip1";
			// 
			// ActionToolStripMenuItem
			// 
			this->ActionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->saveToFileToolStripMenuItem });
			this->ActionToolStripMenuItem->Name = L"ActionToolStripMenuItem";
			resources->ApplyResources(this->ActionToolStripMenuItem, L"ActionToolStripMenuItem");
			// 
			// saveToFileToolStripMenuItem
			// 
			this->saveToFileToolStripMenuItem->Name = L"saveToFileToolStripMenuItem";
			resources->ApplyResources(this->saveToFileToolStripMenuItem, L"saveToFileToolStripMenuItem");
			this->saveToFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormRatings::saveToFileToolStripMenuItem_Click);
			// 
			// FormRatings
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->chart);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"FormRatings";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button_OK_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Category_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Expenses_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_week_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_month_CheckedChanged(System::Object^ sender, System::EventArgs^ e); 
	private: System::Void DatePick_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: void FillChart(int type, String^ type_date, DateTime date);
	private: System::Void DatePickWeek_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void saveToFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

};
}
