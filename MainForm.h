#include "LoginForm.h"
#include "AddBookForm.h"
#include "OrderForm.h"

#pragma once

namespace project1 {

    using namespace System;
    using namespace System::Data;
    using namespace System::Data::SqlClient;
    using namespace System::Windows::Forms;

    public ref class Form1 : public System::Windows::Forms::Form {
    public:
        Form1(void) {
            InitializeComponent();
        }

    protected:
        ~Form1() {
            if (components) delete components;
        }

    private:
        System::Windows::Forms::DataGridView^ dgvBooks;
        System::Windows::Forms::Button^ btnRefresh;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::MenuStrip^ menuStrip1;
        System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ авторизаціяToolStripMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ вихідToolStripMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ управлінняToolStripMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ додатиНовуКнигуToolStripMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ редагуватиОбрануToolStripMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ видалитиToolStripMenuItem;
    private: System::Windows::Forms::Button^ button1;
           System::ComponentModel::Container^ components;

        void InitializeComponent(void) {
            this->dgvBooks = (gcnew System::Windows::Forms::DataGridView());
            this->btnRefresh = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
            this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->авторизаціяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->вихідToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->управлінняToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->додатиНовуКнигуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->редагуватиОбрануToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->видалитиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->button1 = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBooks))->BeginInit();
            this->menuStrip1->SuspendLayout();
            this->SuspendLayout();
            // 
            // dgvBooks
            // 
            this->dgvBooks->AllowUserToAddRows = false;
            this->dgvBooks->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->dgvBooks->ColumnHeadersHeight = 29;
            this->dgvBooks->Location = System::Drawing::Point(12, 110);
            this->dgvBooks->MultiSelect = false;
            this->dgvBooks->Name = L"dgvBooks";
            this->dgvBooks->ReadOnly = true;
            this->dgvBooks->RowHeadersWidth = 51;
            this->dgvBooks->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dgvBooks->Size = System::Drawing::Size(676, 220);
            this->dgvBooks->TabIndex = 2;
            // 
            // btnRefresh
            // 
            this->btnRefresh->Location = System::Drawing::Point(12, 350);
            this->btnRefresh->Name = L"btnRefresh";
            this->btnRefresh->Size = System::Drawing::Size(100, 30);
            this->btnRefresh->TabIndex = 1;
            this->btnRefresh->Text = L"Оновити";
            this->btnRefresh->Click += gcnew System::EventHandler(this, &Form1::btnRefresh_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->label1->Location = System::Drawing::Point(220, 50);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(279, 28);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Облік бібліотечного фонду";
            // 
            // menuStrip1
            // 
            this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
            this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
                this->файлToolStripMenuItem,
                    this->управлінняToolStripMenuItem
            });
            this->menuStrip1->Location = System::Drawing::Point(0, 0);
            this->menuStrip1->Name = L"menuStrip1";
            this->menuStrip1->Size = System::Drawing::Size(700, 28);
            this->menuStrip1->TabIndex = 3;
            // 
            // файлToolStripMenuItem
            // 
            this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
                this->авторизаціяToolStripMenuItem,
                    this->вихідToolStripMenuItem
            });
            this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
            this->файлToolStripMenuItem->Size = System::Drawing::Size(59, 24);
            this->файлToolStripMenuItem->Text = L"Файл";
            // 
            // авторизаціяToolStripMenuItem
            // 
            this->авторизаціяToolStripMenuItem->Name = L"авторизаціяToolStripMenuItem";
            this->авторизаціяToolStripMenuItem->Size = System::Drawing::Size(179, 26);
            this->авторизаціяToolStripMenuItem->Text = L"Авторизація";
            this->авторизаціяToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::авторизаціяToolStripMenuItem_Click);
            // 
            // вихідToolStripMenuItem
            // 
            this->вихідToolStripMenuItem->Name = L"вихідToolStripMenuItem";
            this->вихідToolStripMenuItem->Size = System::Drawing::Size(179, 26);
            this->вихідToolStripMenuItem->Text = L"Вихід";
            this->вихідToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::вихідToolStripMenuItem_Click);
            // 
            // управлінняToolStripMenuItem
            // 
            this->управлінняToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
                this->додатиНовуКнигуToolStripMenuItem,
                    this->редагуватиОбрануToolStripMenuItem, this->видалитиToolStripMenuItem
            });
            this->управлінняToolStripMenuItem->Name = L"управлінняToolStripMenuItem";
            this->управлінняToolStripMenuItem->Size = System::Drawing::Size(104, 24);
            this->управлінняToolStripMenuItem->Text = L"Управління";
            // 
            // додатиНовуКнигуToolStripMenuItem
            // 
            this->додатиНовуКнигуToolStripMenuItem->Name = L"додатиНовуКнигуToolStripMenuItem";
            this->додатиНовуКнигуToolStripMenuItem->Size = System::Drawing::Size(223, 26);
            this->додатиНовуКнигуToolStripMenuItem->Text = L"Додати нову книгу";
            this->додатиНовуКнигуToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::додатиНовуКнигуToolStripMenuItem_Click);
            // 
            // редагуватиОбрануToolStripMenuItem
            // 
            this->редагуватиОбрануToolStripMenuItem->Name = L"редагуватиОбрануToolStripMenuItem";
            this->редагуватиОбрануToolStripMenuItem->Size = System::Drawing::Size(223, 26);
            this->редагуватиОбрануToolStripMenuItem->Text = L"Редагувати обрану";
            this->редагуватиОбрануToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::редагуватиОбрануToolStripMenuItem_Click);
            // 
            // видалитиToolStripMenuItem
            // 
            this->видалитиToolStripMenuItem->Name = L"видалитиToolStripMenuItem";
            this->видалитиToolStripMenuItem->Size = System::Drawing::Size(223, 26);
            this->видалитиToolStripMenuItem->Text = L"Видалити";
            this->видалитиToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::видалитиToolStripMenuItem_Click);
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(496, 356);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(132, 23);
            this->button1->TabIndex = 4;
            this->button1->Text = L"Видати книгу";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
            // 
            // Form1
            // 
            this->BackColor = System::Drawing::Color::PapayaWhip;
            this->ClientSize = System::Drawing::Size(700, 410);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->btnRefresh);
            this->Controls->Add(this->dgvBooks);
            this->Controls->Add(this->menuStrip1);
            this->MainMenuStrip = this->menuStrip1;
            this->Name = L"Form1";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Бібліотека v1.0";
            this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBooks))->EndInit();
            this->menuStrip1->ResumeLayout(false);
            this->menuStrip1->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        // --- ЛОГІКА ДОДАТКУ ---

    private: System::Void LoadData() {
        try {
            String^ connStr = "Server=(localdb)\\MSSQLLocalDB;Database=LibraryDB;Integrated Security=True;TrustServerCertificate=True;";
            SqlConnection^ conn = gcnew SqlConnection(connStr);

            // Вибираємо дані з гарними іменами колонок
            String^ query = "SELECT book_id as ID, inventory_number as [Інвентарний №], title as [Назва], authors as [Автор] FROM Books";

            SqlDataAdapter^ da = gcnew SqlDataAdapter(query, conn);
            DataTable^ dt = gcnew DataTable();
            da->Fill(dt);
            dgvBooks->DataSource = dt;
        }
        catch (Exception^ ex) { MessageBox::Show("Помилка завантаження: " + ex->Message); }
    }

    private: System::Void Form1_Load(Object^ s, EventArgs^ e) { LoadData(); }
    private: System::Void btnRefresh_Click(Object^ s, EventArgs^ e) { LoadData(); }

    private: System::Void авторизаціяToolStripMenuItem_Click(Object^ s, EventArgs^ e) {
        LoginForm^ login = gcnew LoginForm();
        login->ShowDialog();
    }

    private: System::Void вихідToolStripMenuItem_Click(Object^ s, EventArgs^ e) {
        if (MessageBox::Show("Закрити програму?", "Вихід", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
            Application::Exit();
        }
    }

    private: System::Void додатиНовуКнигуToolStripMenuItem_Click(Object^ s, EventArgs^ e) {
        AddBookForm^ addForm = gcnew AddBookForm();
        if (addForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            LoadData();
        }
    }

    private: System::Void редагуватиОбрануToolStripMenuItem_Click(Object^ s, EventArgs^ e) {
        if (dgvBooks->SelectedRows->Count > 0) {
            int id = Convert::ToInt32(dgvBooks->SelectedRows[0]->Cells["ID"]->Value);
            String^ inv = dgvBooks->SelectedRows[0]->Cells["Інвентарний №"]->Value->ToString();
            String^ title = dgvBooks->SelectedRows[0]->Cells["Назва"]->Value->ToString();
            String^ author = dgvBooks->SelectedRows[0]->Cells["Автор"]->Value->ToString();

            AddBookForm^ editForm = gcnew AddBookForm(id, inv, title, author);
            if (editForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                LoadData();
            }
        }
        else { MessageBox::Show("Виберіть книгу для редагування!"); }
    }

    private: System::Void видалитиToolStripMenuItem_Click(Object^ s, EventArgs^ e) {
        if (dgvBooks->SelectedRows->Count > 0) {
            if (MessageBox::Show("Видалити цю книгу?", "Увага", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes) {
                try {
                    int id = Convert::ToInt32(dgvBooks->SelectedRows[0]->Cells["ID"]->Value);
                    String^ connStr = "Server=(localdb)\\MSSQLLocalDB;Database=LibraryDB;Integrated Security=True;TrustServerCertificate=True;";
                    SqlConnection^ conn = gcnew SqlConnection(connStr);

                    SqlCommand^ cmd = gcnew SqlCommand("DELETE FROM Books WHERE book_id = @id", conn);
                    cmd->Parameters->AddWithValue("@id", id);

                    conn->Open();
                    cmd->ExecuteNonQuery();
                    conn->Close();

                    LoadData();
                    MessageBox::Show("Книгу видалено.");
                }
                catch (Exception^ ex) { MessageBox::Show("Помилка: " + ex->Message); }
            }
        }
        else { MessageBox::Show("Виберіть книгу!"); }
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dgvBooks->SelectedRows->Count > 0) {
            int id = Convert::ToInt32(dgvBooks->SelectedRows[0]->Cells["ID"]->Value);
            String^ title = dgvBooks->SelectedRows[0]->Cells["Назва"]->Value->ToString();

            OrderForm^ ordForm = gcnew OrderForm(id, title);
            ordForm->ShowDialog();
        }
        else {
            MessageBox::Show("Виберіть книгу для замовлення!");
        }
    }
};
}
