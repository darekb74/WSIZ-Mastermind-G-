#pragma once

namespace WSIZ_Project3_Mastermind_G {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o frmInstrukcja
	/// </summary>
	public ref class frmInstrukcja : public System::Windows::Forms::Form
	{
	public:
		frmInstrukcja(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

		frmInstrukcja(Form ^ o)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			parent = o;
		}
	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~frmInstrukcja()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 

	private: System::Windows::Forms::Label^  label3;



	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Form^  parent;
	private: System::Windows::Forms::PictureBox^  pbH;
	private: System::Windows::Forms::PictureBox^  pbM;

	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Wymagana metoda wsparcia projektanta - nie nale¿y modyfikowaæ
		/// zawartoœæ tej metody z edytorem kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmInstrukcja::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pbH = (gcnew System::Windows::Forms::PictureBox());
			this->pbM = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbM))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(129, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"WSIZ Mastermind";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 34);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Zasady gry:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(208, 271);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(31, 25);
			this->button1->TabIndex = 6;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmInstrukcja::button1_Click);
			// 
			// pbH
			// 
			this->pbH->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbH.Image")));
			this->pbH->Location = System::Drawing::Point(10, 53);
			this->pbH->Name = L"pbH";
			this->pbH->Size = System::Drawing::Size(420, 215);
			this->pbH->TabIndex = 7;
			this->pbH->TabStop = false;
			// 
			// pbM
			// 
			this->pbM->Location = System::Drawing::Point(10, 53);
			this->pbM->Name = L"pbM";
			this->pbM->Size = System::Drawing::Size(420, 215);
			this->pbM->TabIndex = 8;
			this->pbM->TabStop = false;
			// 
			// frmInstrukcja
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(442, 299);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pbH);
			this->Controls->Add(this->pbM);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"frmInstrukcja";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Instrukcja";
			this->Closed += gcnew System::EventHandler(this, &frmInstrukcja::frmInstrukcja_Close);
			this->Load += gcnew System::EventHandler(this, &frmInstrukcja::frmInstrukcja_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbM))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		parent->Enabled = true;
		parent->Focus();
		this->Close();
	}
private: System::Void frmInstrukcja_Close(System::Object^  sender, System::EventArgs^  e) {
		parent->Enabled = true;
		parent->Focus();
	}
private: System::Void frmInstrukcja_Load(System::Object^  sender, System::EventArgs^  e) {

		 }
};
}
