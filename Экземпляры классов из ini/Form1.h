#pragma once
#include "Weapon.h"
#include <vector>
namespace CppCLR_WinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DomainUpDown^  domainUpDown1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->domainUpDown1 = (gcnew System::Windows::Forms::DomainUpDown());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// domainUpDown1
			// 
			this->domainUpDown1->BackColor = System::Drawing::Color::Black;
			this->domainUpDown1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->domainUpDown1->ForeColor = System::Drawing::Color::ForestGreen;
			this->domainUpDown1->Location = System::Drawing::Point(16, 16);
			this->domainUpDown1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->domainUpDown1->Name = L"domainUpDown1";
			this->domainUpDown1->Size = System::Drawing::Size(181, 41);
			this->domainUpDown1->TabIndex = 0;
			this->domainUpDown1->SelectedItemChanged += gcnew System::EventHandler(this, &Form1::domainUpDown1_SelectedItemChanged);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Black;
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Right;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->ForeColor = System::Drawing::Color::ForestGreen;
			this->textBox1->Location = System::Drawing::Point(205, 0);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(603, 570);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::ForestGreen;
			this->button1->Location = System::Drawing::Point(16, 65);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(181, 488);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Ïðî÷èòàòü àòðèáóòû îáúåêòîâ èç ôàéëà è ñîçäàòü îáúåêòû\r\n(âñ¸ â îäíîé êíîïêå, êëàñ"
				L"ñíî\?)";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"Ôàéë êîíôèãóðàöèè (*.ini)|*.ini";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(808, 570);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->domainUpDown1);
			this->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::Color::ForestGreen;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Form1";
			this->Text = L"Weapon";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		cli::array<Weapon^>^ ArrA;
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//std::vector<Weapon^> formArrAW;
		StreamReader ^ Myini;
		textBox1->Text = "";
		domainUpDown1->Items->Clear();
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if (this->openFileDialog1->OpenFile() != nullptr)
			{
				int sizeOfArrA = 0;
				Myini = gcnew StreamReader(openFileDialog1->FileName);
				String ^ dummy, ^ Sname, ^ Scalibre, ^ SclipCapasity, ^ Slicense, ^ SdateOfIssue;
				bool startCreate = 0;
				while ((dummy = Myini->ReadLine()) != nullptr)
				{
					if (dummy == "{")
						sizeOfArrA += 1;
				}
				ArrA = gcnew cli::array<Weapon^>(sizeOfArrA);
				sizeOfArrA = 0;
				Myini->BaseStream->Position = 0;
				while ((dummy = Myini->ReadLine()) != nullptr)
				{
					/*array<unsigned char>^ arr = System::Text::Encoding::GetEncoding(866)->GetBytes(dummy);
					pin_ptr<unsigned char> ptr = &arr[0];
					char* str = (char*)ptr;*/
					array<wchar_t> ^ separs = { ' ',':' };
					for (int i = 0;i < dummy->Length;i++)
						if (startCreate)
							switch (dummy[i])
							{
							case 'n':

								for (int n = 0; n < dummy->Split(separs)->Length;n++)
									if (dummy->Split(separs)[n] == "name")
									{
										for (int m = n; m < dummy->Split(separs)->Length;m++)
											if (dummy->Split(separs)[m] != "")
											{
												Sname = dummy->Split(separs)[m];
												i += 1 + dummy->Split(separs)[0]->Length + dummy->Split(separs)[m]->Length;
											}
									}

								break;
							case 'c':
								for (int n = 0; n < dummy->Split(separs)->Length;n++)
									if (dummy->Split(separs)[0] == "calibre")
									{
										for (int m = n; m < dummy->Split(separs)->Length;m++)
											if (dummy->Split(separs)[m] != "")
											{
												Scalibre = dummy->Split(separs)[m];
												i += 1 + dummy->Split(separs)[0]->Length + dummy->Split(separs)[m]->Length;
											}
									}
									else if (dummy->Split(separs)[0] == "clipCapasity")
									{
										for (int m = n; m < dummy->Split(separs)->Length;m++)
											if (dummy->Split(separs)[m] != "")
											{
												SclipCapasity = dummy->Split(separs)[m];
												i += 1 + dummy->Split(separs)[0]->Length + dummy->Split(separs)[m]->Length;
											}
									}
								break;
							case 'l':
								for (int n = 0; n < dummy->Split(separs)->Length;n++)
									if (dummy->Split(separs)[0] == "license")
									{
										for (int m = n; m < dummy->Split(separs)->Length;m++)
											if (dummy->Split(separs)[m] != "")
											{
												Slicense = dummy->Split(separs)[m];
												i += 1 + dummy->Split(separs)[0]->Length + dummy->Split(separs)[m]->Length;
											}
									}
								break;
							case 'd':
								for (int n = 0; n < dummy->Split(separs)->Length;n++)
									if (dummy->Split(separs)[0] == "dateOfIssue")
									{
										for (int m = n; m < dummy->Split(separs)->Length;m++)
											if (dummy->Split(separs)[m] != "")
											{
												SdateOfIssue = dummy->Split(separs)[m];
												i += 1 + dummy->Split(separs)[0]->Length + dummy->Split(separs)[m]->Length;
											}
									}
								break;
							case '}':
								if (Sname != nullptr && Scalibre != nullptr && SclipCapasity != nullptr && Slicense != nullptr && SdateOfIssue != nullptr)
								{
									Weapon ^ temp = gcnew Weapon(Sname, Scalibre, SclipCapasity, Slicense, SdateOfIssue);
									ArrA[sizeOfArrA] = temp;
									sizeOfArrA++;
									delete temp;
									domainUpDown1->Items->Add(Sname);
									startCreate = 0;
								}
								break;
							default:
								break;
							}
						else if (dummy[i] == '{')
							startCreate = 1;
				}
				Myini->Close();
			}
		}
		else
			textBox1->Text = "×òî-òî íå òàê (ôàéëà íåò)";
	}
	private: System::Void domainUpDown1_SelectedItemChanged(System::Object^  sender, System::EventArgs^  e) {
		int m;
		textBox1->Text = "";
		for (int i = 0;i < ArrA->Length;i++)
			if (domainUpDown1->SelectedItem->Equals(ArrA[i]->name))
				m = i;
		textBox1->AppendText("name: " + ArrA[m]->name + "\r\n" + "calibre: " + Convert::ToString(ArrA[m]->calibre) + "\r\n" + "clipCapasity: " + Convert::ToString(ArrA[m]->clipCapasity) + "\r\n" + "license: " + Convert::ToString(ArrA[m]->license) + "\r\n" + "dateOfIssue: " + Convert::ToString(ArrA[m]->dateOfIssue));
	}
	};
}