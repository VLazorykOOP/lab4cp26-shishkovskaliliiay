#pragma once

namespace project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	public ref class AddBookForm : public System::Windows::Forms::Form
	{
	private:
		String^ connString = "Server=(localdb)\\MSSQLLocalDB;Database=LibraryDB;Integrated Security=True;TrustServerCertificate=True;";
		int bookIdToEdit = -1;

	public:
		AddBookForm(void)
		{
			InitializeComponent();
			this->Text = L"Додати нову книгу";
			bookIdToEdit = -1;
		}

		AddBookForm(int id, String^ inv, String^ title, String^ author)
		{
			InitializeComponent();
			this->Text = L"Редагувати книгу";
			bookIdToEdit = id;
			txtInvNum->Text = inv;
			txtTitle->Text = title;
			txtAuthor->Text = author;
		}

	protected:
		~AddBookForm() { if (components) delete components; }

	private: System::Windows::Forms::Label^ lblInvNum;
	private: System::Windows::Forms::TextBox^ txtInvNum;
	private: System::Windows::Forms::TextBox^ txtTitle;
	private: System::Windows::Forms::TextBox^ txtAuthor;
	private: System::Windows::Forms::ComboBox^ cmbGenre;
	private: System::Windows::Forms::ComboBox^ cmbPub;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->lblInvNum = (gcnew System::Windows::Forms::Label());
			   this->txtInvNum = (gcnew System::Windows::Forms::TextBox());
			   this->txtTitle = (gcnew System::Windows::Forms::TextBox());
			   this->txtAuthor = (gcnew System::Windows::Forms::TextBox());
			   this->cmbGenre = (gcnew System::Windows::Forms::ComboBox());
			   this->cmbPub = (gcnew System::Windows::Forms::ComboBox());
			   this->btnSave = (gcnew System::Windows::Forms::Button());
			   this->btnCancel = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();

			   // lblInvNum
			   this->lblInvNum->Location = System::Drawing::Point(12, 12);
			   this->lblInvNum->Size = System::Drawing::Size(150, 20);
			   this->lblInvNum->Text = L"Інвентарний номер:";
			   // txtInvNum
			   this->txtInvNum->Location = System::Drawing::Point(12, 35);
			   this->txtInvNum->Size = System::Drawing::Size(360, 22);
			   // txtTitle
			   this->txtTitle->Location = System::Drawing::Point(12, 80);
			   this->txtTitle->Size = System::Drawing::Size(170, 22);
			   // txtAuthor
			   this->txtAuthor->Location = System::Drawing::Point(200, 80);
			   this->txtAuthor->Size = System::Drawing::Size(172, 22);

			   // ВИПРАВЛЕНО ДЛЯ ДИЗАЙНЕРА:
			   this->cmbGenre->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->cmbGenre->Location = System::Drawing::Point(12, 144);
			   this->cmbGenre->Size = System::Drawing::Size(170, 24);

			   this->cmbPub->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->cmbPub->Location = System::Drawing::Point(200, 144);
			   this->cmbPub->Size = System::Drawing::Size(172, 24);

			   // Кнопки
			   this->btnSave->Location = System::Drawing::Point(12, 230);
			   this->btnSave->Size = System::Drawing::Size(120, 40);
			   this->btnSave->Text = L"Зберегти";
			   this->btnSave->Click += gcnew System::EventHandler(this, &AddBookForm::btnSave_Click);
			   this->btnCancel->Location = System::Drawing::Point(252, 230);
			   this->btnCancel->Size = System::Drawing::Size(120, 40);
			   this->btnCancel->Text = L"Скасувати";
			   this->btnCancel->Click += gcnew System::EventHandler(this, &AddBookForm::btnCancel_Click);

			   // Мітки
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(15, 64);
			   this->label1->Text = L"Назва";
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(200, 64);
			   this->label2->Text = L"Автор";
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(15, 125);
			   this->label3->Text = L"Оберіть жанр";
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(200, 125);
			   this->label4->Text = L"Видавництво";

			   // AddBookForm
			   this->BackColor = System::Drawing::Color::PapayaWhip;
			   this->ClientSize = System::Drawing::Size(400, 300);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->btnCancel);
			   this->Controls->Add(this->btnSave);
			   this->Controls->Add(this->cmbPub);
			   this->Controls->Add(this->cmbGenre);
			   this->Controls->Add(this->txtAuthor);
			   this->Controls->Add(this->txtTitle);
			   this->Controls->Add(this->txtInvNum);
			   this->Controls->Add(this->lblInvNum);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->Load += gcnew System::EventHandler(this, &AddBookForm::AddBookForm_Load);
			   this->ResumeLayout(false);
			   this->PerformLayout();
		   }
#pragma endregion

	private: System::Void AddBookForm_Load(System::Object^ sender, System::EventArgs^ e) {
		try {
			SqlConnection^ conn = gcnew SqlConnection(connString);
			conn->Open();
			SqlDataAdapter^ daG = gcnew SqlDataAdapter("SELECT genre_id, genre_name FROM Genres", conn);
			DataTable^ dtG = gcnew DataTable();
			daG->Fill(dtG);
			cmbGenre->DataSource = dtG;
			cmbGenre->DisplayMember = "genre_name";
			cmbGenre->ValueMember = "genre_id";

			SqlDataAdapter^ daP = gcnew SqlDataAdapter("SELECT publisher_id, publisher_name FROM Publishers", conn);
			DataTable^ dtP = gcnew DataTable();
			daP->Fill(dtP);
			cmbPub->DataSource = dtP;
			cmbPub->DisplayMember = "publisher_name";
			cmbPub->ValueMember = "publisher_id";
			conn->Close();
		}
		catch (Exception^ ex) { MessageBox::Show(ex->Message); }
	}

	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(txtInvNum->Text) || String::IsNullOrWhiteSpace(txtTitle->Text)) {
			MessageBox::Show("Заповніть поля!"); return;
		}
		try {
			SqlConnection^ conn = gcnew SqlConnection(connString);
			String^ sql = (bookIdToEdit == -1) ?
				"INSERT INTO Books (inventory_number, title, authors, genre_id, publisher_id, price, available_quantity) VALUES (@inv, @t, @a, @g, @p, 0, 1)" :
				"UPDATE Books SET inventory_number=@inv, title=@t, authors=@a, genre_id=@g, publisher_id=@p WHERE book_id=@id";

			SqlCommand^ cmd = gcnew SqlCommand(sql, conn);
			cmd->Parameters->AddWithValue("@inv", txtInvNum->Text);
			cmd->Parameters->AddWithValue("@t", txtTitle->Text);
			cmd->Parameters->AddWithValue("@a", txtAuthor->Text);
			cmd->Parameters->AddWithValue("@g", cmbGenre->SelectedValue);
			cmd->Parameters->AddWithValue("@p", cmbPub->SelectedValue);
			if (bookIdToEdit != -1) cmd->Parameters->AddWithValue("@id", bookIdToEdit);

			conn->Open();
			cmd->ExecuteNonQuery();
			conn->Close();
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		catch (Exception^ ex) { MessageBox::Show(ex->Message); }
	}

	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}
	};
}
