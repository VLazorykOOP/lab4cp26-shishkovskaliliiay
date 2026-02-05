#pragma once

namespace project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			// Встановлюємо фокус на поле логіна при відкритті
			this->ActiveControl = txtUser;
		}

	protected:
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::TextBox^ txtUser;
	private: System::Windows::Forms::Label^ lblUser;
	private: System::Windows::Forms::TextBox^ txtPass;
	private: System::Windows::Forms::Label^ lblPass;
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->lblTitle = (gcnew System::Windows::Forms::Label());
			   this->txtUser = (gcnew System::Windows::Forms::TextBox());
			   this->lblUser = (gcnew System::Windows::Forms::Label());
			   this->txtPass = (gcnew System::Windows::Forms::TextBox());
			   this->lblPass = (gcnew System::Windows::Forms::Label());
			   this->btnLogin = (gcnew System::Windows::Forms::Button());
			   this->btnCancel = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // lblTitle
			   // 
			   this->lblTitle->AutoSize = true;
			   this->lblTitle->Font = (gcnew System::Drawing::Font(L"Cambria", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			   this->lblTitle->Location = System::Drawing::Point(12, 9);
			   this->lblTitle->Name = L"lblTitle";
			   this->lblTitle->Size = System::Drawing::Size(174, 27);
			   this->lblTitle->TabIndex = 6;
			   this->lblTitle->Text = L"Вхід у систему";
			   // 
			   // txtUser
			   // 
			   this->txtUser->Location = System::Drawing::Point(12, 70);
			   this->txtUser->Name = L"txtUser";
			   this->txtUser->Size = System::Drawing::Size(300, 22);
			   this->txtUser->TabIndex = 5;
			   // 
			   // lblUser
			   // 
			   this->lblUser->AutoSize = true;
			   this->lblUser->Location = System::Drawing::Point(12, 50);
			   this->lblUser->Name = L"lblUser";
			   this->lblUser->Size = System::Drawing::Size(44, 16);
			   this->lblUser->TabIndex = 4;
			   this->lblUser->Text = L"Логін:";
			   // 
			   // txtPass
			   // 
			   this->txtPass->Location = System::Drawing::Point(12, 125);
			   this->txtPass->Name = L"txtPass";
			   this->txtPass->PasswordChar = '*';
			   this->txtPass->Size = System::Drawing::Size(300, 22);
			   this->txtPass->TabIndex = 3;
			   // 
			   // lblPass
			   // 
			   this->lblPass->AutoSize = true;
			   this->lblPass->Location = System::Drawing::Point(12, 105);
			   this->lblPass->Name = L"lblPass";
			   this->lblPass->Size = System::Drawing::Size(59, 16);
			   this->lblPass->TabIndex = 2;
			   this->lblPass->Text = L"Пароль:";
			   // 
			   // btnLogin
			   // 
			   this->btnLogin->Location = System::Drawing::Point(12, 170);
			   this->btnLogin->Name = L"btnLogin";
			   this->btnLogin->Size = System::Drawing::Size(100, 40);
			   this->btnLogin->TabIndex = 1;
			   this->btnLogin->Text = L"Увійти";
			   this->btnLogin->Click += gcnew System::EventHandler(this, &LoginForm::btnLogin_Click);
			   // 
			   // btnCancel
			   // 
			   this->btnCancel->Location = System::Drawing::Point(212, 170);
			   this->btnCancel->Name = L"btnCancel";
			   this->btnCancel->Size = System::Drawing::Size(100, 40);
			   this->btnCancel->TabIndex = 0;
			   this->btnCancel->Text = L"Скасувати";
			   this->btnCancel->Click += gcnew System::EventHandler(this, &LoginForm::btnCancel_Click);
			   // 
			   // LoginForm
			   // 
			   this->AcceptButton = this->btnLogin;
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::PapayaWhip;
			   this->ClientSize = System::Drawing::Size(336, 277);
			   this->Controls->Add(this->btnCancel);
			   this->Controls->Add(this->btnLogin);
			   this->Controls->Add(this->lblPass);
			   this->Controls->Add(this->txtPass);
			   this->Controls->Add(this->lblUser);
			   this->Controls->Add(this->txtUser);
			   this->Controls->Add(this->lblTitle);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			   this->Name = L"LoginForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Авторизація";
			   this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

		   // Логіка кнопки "Увійти"
	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ user = txtUser->Text;
		String^ pass = txtPass->Text;

		if (String::IsNullOrWhiteSpace(user) || String::IsNullOrWhiteSpace(pass)) {
			MessageBox::Show("Будь ласка, заповніть усі поля!", "Попередження", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			String^ connStr = "Server=(localdb)\\MSSQLLocalDB;Database=LibraryDB;Integrated Security=True;TrustServerCertificate=True;";
			SqlConnection^ conn = gcnew SqlConnection(connStr);

			String^ query = "SELECT COUNT(*) FROM Users WHERE username=@user AND password_hash=@pass AND is_active=1";
			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			cmd->Parameters->AddWithValue("@user", user);
			cmd->Parameters->AddWithValue("@pass", pass);

			conn->Open();
			int count = (int)cmd->ExecuteScalar();
			conn->Close();

			if (count > 0) {
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
			}
			else {
				MessageBox::Show("Невірний логін або пароль!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Помилка підключення: " + ex->Message, "Помилка БД", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

		   // Логіка кнопки "Скасувати"
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit(); // Закриває всю програму
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
