#pragma once

namespace project1 {
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Data::SqlClient;

	public ref class OrderForm : public System::Windows::Forms::Form
	{
	private:
		int bookId;
		String^ connString = "Server=(localdb)\\MSSQLLocalDB;Database=LibraryDB;Integrated Security=True;TrustServerCertificate=True;";

	public:
		OrderForm(int id, String^ bookTitle)
		{
			InitializeComponent();
			this->bookId = id;
			this->lblInfo->Text = "Видача книги: " + bookTitle;
			this->dtpReturn->Value = DateTime::Now.AddDays(14);
		}

	protected:
		~OrderForm() { if (components) delete components; }

	private:
		System::Windows::Forms::Label^ lblInfo;
		System::Windows::Forms::TextBox^ txtReader;
		System::Windows::Forms::DateTimePicker^ dtpReturn;
		System::Windows::Forms::Button^ btnOk;
		System::ComponentModel::Container^ components;

		void InitializeComponent(void)
		{
			this->lblInfo = (gcnew System::Windows::Forms::Label());
			this->txtReader = (gcnew System::Windows::Forms::TextBox());
			this->dtpReturn = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnOk = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblInfo
			// 
			this->lblInfo->Location = System::Drawing::Point(20, 20);
			this->lblInfo->Name = L"lblInfo";
			this->lblInfo->Size = System::Drawing::Size(250, 40);
			this->lblInfo->TabIndex = 3;
			// 
			// txtReader
			// 
			this->txtReader->Location = System::Drawing::Point(20, 70);
			this->txtReader->Name = L"txtReader";
			this->txtReader->Size = System::Drawing::Size(240, 22);
			this->txtReader->TabIndex = 2;
			// 
			// dtpReturn
			// 
			this->dtpReturn->Location = System::Drawing::Point(20, 110);
			this->dtpReturn->Name = L"dtpReturn";
			this->dtpReturn->Size = System::Drawing::Size(240, 22);
			this->dtpReturn->TabIndex = 1;
			// 
			// btnOk
			// 
			this->btnOk->Location = System::Drawing::Point(80, 160);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(75, 23);
			this->btnOk->TabIndex = 0;
			this->btnOk->Text = L"Видати книгу";
			this->btnOk->Click += gcnew System::EventHandler(this, &OrderForm::btnOk_Click);
			// 
			// OrderForm
			// 
			this->BackColor = System::Drawing::Color::PapayaWhip;
			this->ClientSize = System::Drawing::Size(292, 238);
			this->Controls->Add(this->btnOk);
			this->Controls->Add(this->dtpReturn);
			this->Controls->Add(this->txtReader);
			this->Controls->Add(this->lblInfo);
			this->Name = L"OrderForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Нове замовлення";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: System::Void btnOk_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(txtReader->Text)) {
			MessageBox::Show("Введіть ім'я читача!");
			return;
		}
		try {
			SqlConnection^ conn = gcnew SqlConnection(connString);
			SqlCommand^ cmd = gcnew SqlCommand(
				"INSERT INTO Orders (book_id, reader_name, order_date, return_date) VALUES (@bid, @name, GETDATE(), @rdate)", conn);
			cmd->Parameters->AddWithValue("@bid", bookId);
			cmd->Parameters->AddWithValue("@name", txtReader->Text);
			cmd->Parameters->AddWithValue("@rdate", dtpReturn->Value);

			conn->Open();
			cmd->ExecuteNonQuery();
			conn->Close();

			MessageBox::Show("Книгу успішно видано читачу!");
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		catch (Exception^ ex) { MessageBox::Show(ex->Message); }
	}
	};
}
