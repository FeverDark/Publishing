#pragma once

#include "CreationForm.h"
#include "EditForm.h"
#include "Leaks.h"
#include <msclr\marshal_cppstd.h>
#include <vector>
#include <string>

namespace Publishing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm()
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (!leakss) {
				close();
			}
			if (components)
			{
				delete components;
			}
		}
	private: bool leakss = false;
	private: String^ find = L"";
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox1;

	protected:
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGridView1->Location = System::Drawing::Point(181, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(1091, 437);
			this->dataGridView1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(13, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 58);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Добавить издание";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(13, 77);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(125, 58);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Изменить состояние";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(12, 269);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(125, 58);
			this->button3->TabIndex = 16;
			this->button3->Text = L"Обновить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(12, 423);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(163, 26);
			this->textBox1->TabIndex = 17;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 401);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 19);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Фильтр:";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(12, 141);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(125, 58);
			this->button4->TabIndex = 20;
			this->button4->Text = L"Удалить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(13, 333);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(125, 58);
			this->button6->TabIndex = 22;
			this->button6->Text = L"Утечки";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MainForm::button6_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 211);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(144, 21);
			this->label1->TabIndex = 23;
			this->label1->Text = L"Сортировать по:";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"ISBN", L"Названию", L"Автору", L"Рейтингу", L"Кол-во страниц",
					L"Тиражу"
			});
			this->comboBox1->Location = System::Drawing::Point(12, 236);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(125, 27);
			this->comboBox1->TabIndex = 24;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox1_SelectedIndexChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1284, 461);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"База Издательства";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		button3_Click(dataGridView1, gcnew EventArgs());
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		find = textBox1->Text;
		button3_Click(dataGridView1, gcnew EventArgs());
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();
		DataGridViewColumn^ c = gcnew DataGridViewColumn();
		DataGridViewCell^ td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"ISBN";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Название";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Автор(ы)";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Возрастной рейтинг";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Кол-во страниц";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Тип обложки";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Тираж";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Статус";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		std::vector<int> types;
		std::vector<int> ageRatings;
		std::vector<int> strNumbers;
		std::vector<int> circulations;
		std::vector<std::vector<std::wstring>> str;
		switch (comboBox1->SelectedIndex) {
		case 0:
			getAll(types, ageRatings, strNumbers, circulations, str, msclr::interop::marshal_as<std::wstring>(find->ToString()), 0);
			break;
		case 1:
			getAll(types, ageRatings, strNumbers, circulations, str, msclr::interop::marshal_as<std::wstring>(find->ToString()), 1);
			break;
		case 2:
			getAll(types, ageRatings, strNumbers, circulations, str, msclr::interop::marshal_as<std::wstring>(find->ToString()), 2);
			break;
		case 3:
			getAll(types, ageRatings, strNumbers, circulations, str, msclr::interop::marshal_as<std::wstring>(find->ToString()), 3);
			break;
		case 4:
			getAll(types, ageRatings, strNumbers, circulations, str, msclr::interop::marshal_as<std::wstring>(find->ToString()), 4);
			break;
		case 5:
			getAll(types, ageRatings, strNumbers, circulations, str, msclr::interop::marshal_as<std::wstring>(find->ToString()), 5);
			break;
		default:
			getAll(types, ageRatings, strNumbers, circulations, str, msclr::interop::marshal_as<std::wstring>(find->ToString()), -1);
		}
		
		for (int i = 0; i < str.size(); ++i) {
			DataGridViewRow^ r = gcnew DataGridViewRow();
			if (types[i] == 1) r->HeaderCell->Value = L"Книга";
			else if (types[i] == 2) r->HeaderCell->Value = L"Журнал";
			else r->HeaderCell->Value = L"Сборник";
			r->CreateCells(dataGridView1);
			cli::array<String^>^ Values = gcnew cli::array<String^>(dataGridView1->ColumnCount);
			Values[0] = msclr::interop::marshal_as<String^>(str[i][0]);
			Values[1] = msclr::interop::marshal_as<String^>(str[i][1]);
			Values[2] = msclr::interop::marshal_as<String^>(str[i][4]);
			Values[3] = ageRatings[i].ToString();
			Values[4] = strNumbers[i].ToString();
			Values[5] = msclr::interop::marshal_as<String^>(str[i][2]);
			Values[6] = circulations[i].ToString();
			Values[7] = msclr::interop::marshal_as<String^>(str[i][3]);
			r->SetValues(Values);
			dataGridView1->Rows->Add(r);
			dataGridView1->RowHeadersWidth = 150;
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Publishing::CreationForm creation;
		creation.ShowDialog();
		if (creation.number->Length != 0) {
			addEdition(msclr::interop::marshal_as<std::wstring>(creation.number->ToString()), msclr::interop::marshal_as<std::wstring>(creation.name->ToString()), msclr::interop::marshal_as<std::wstring>(creation.author->ToString()), msclr::interop::marshal_as<std::wstring>(creation.ageRating->ToString()), msclr::interop::marshal_as<std::wstring>(creation.strNumber->ToString()), msclr::interop::marshal_as<std::wstring>(creation.formatType->ToString()), msclr::interop::marshal_as<std::wstring>(creation.circulation->ToString()), msclr::interop::marshal_as<std::wstring>(creation.state->ToString()), static_cast<int>(creation.type));
			button3_Click(dataGridView1, gcnew EventArgs());
			MainForm::Update();
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int tempid = dataGridView1->CurrentCell->RowIndex;
		if (tempid >= 0 && tempid < dataGridView1->RowCount) {
			Publishing::EditForm editform(this->dataGridView1->Rows[tempid]->Cells[7]->Value->ToString());
			editform.ShowDialog();
			if (editform.state->Length != 0) {
				editState(msclr::interop::marshal_as<std::wstring>(this->dataGridView1->Rows[tempid]->Cells[0]->Value->ToString()), msclr::interop::marshal_as<std::wstring>(editform.state->ToString()));
				button3_Click(dataGridView1, gcnew EventArgs());
				MainForm::Update();
			}
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		int tempid = dataGridView1->CurrentCell->RowIndex;
		if (tempid >= 0 && tempid < dataGridView1->RowCount) {
			deleteEdition(msclr::interop::marshal_as<std::wstring>(this->dataGridView1->Rows[tempid]->Cells[0]->Value->ToString()));
			button3_Click(dataGridView1, gcnew EventArgs());
			MainForm::Update();
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	/*dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();
		DataGridViewColumn^ c = gcnew DataGridViewColumn();
		DataGridViewCell^ td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"ISBN";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Название";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Автор(ы)";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Возрастной рейтинг";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Кол-во страниц";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Тип обложки";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Тираж";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Статус";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		std::vector<int> types;
		std::vector<int> ageRatings;
		std::vector<int> strNumbers;
		std::vector<int> circulations;
		std::vector<std::vector<std::wstring>> str;
		getAll(types, ageRatings, strNumbers, circulations, str, msclr::interop::marshal_as<std::wstring>(find->ToString()), 2);
		for (int i = 0; i < str.size(); ++i) {
			DataGridViewRow^ r = gcnew DataGridViewRow();
			if (types[i] == 1) r->HeaderCell->Value = L"Книга";
			else if (types[i] == 2) r->HeaderCell->Value = L"Журнал";
			else r->HeaderCell->Value = L"Сборник";
			r->CreateCells(dataGridView1);
			cli::array<String^>^ Values = gcnew cli::array<String^>(dataGridView1->ColumnCount);
			Values[0] = msclr::interop::marshal_as<String^>(str[i][0]);
			Values[1] = msclr::interop::marshal_as<String^>(str[i][1]);
			Values[2] = msclr::interop::marshal_as<String^>(str[i][4]);
			Values[3] = ageRatings[i].ToString();
			Values[4] = strNumbers[i].ToString();
			Values[5] = msclr::interop::marshal_as<String^>(str[i][2]);
			Values[6] = circulations[i].ToString();
			Values[7] = msclr::interop::marshal_as<String^>(str[i][3]);
			r->SetValues(Values);
			dataGridView1->Rows->Add(r);
			dataGridView1->RowHeadersWidth = 150;
		}*/
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		leakss = true;
		Publishing::Leaks leaks;
		leaks.ShowDialog();
		this->Close();
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		button3_Click(dataGridView1, gcnew EventArgs());
		MainForm::Update();
	}
};
}
