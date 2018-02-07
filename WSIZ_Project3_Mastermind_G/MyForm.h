#pragma once
#pragma comment(lib, "winmm.lib")

#include <ctime>
#include <iostream>
#include "windows.h"
#include <string>
#include "frmAbout.h"
#include "frmInstrukcja.h"
#include <sstream>
#include <fstream>

using namespace std;

#define MAGIC_NUMBER 71830
#define W_KEY "NHGBE1QNERX2OEMRX3-4QYN5JFVM6PBCREAVHF"

namespace WSIZ_Project3_Mastermind_G {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			this->intSzukane = (gcnew array<Int16,1>(4));
			this->pbArrO = gcnew array<PictureBox^,2>(10,4) {
			{pbO11, pbO12, pbO13, pbO14},
			{pbO21, pbO22, pbO23, pbO24},
			{pbO31, pbO32, pbO33, pbO34},
			{pbO41, pbO42, pbO43, pbO44},
			{pbO51, pbO52, pbO53, pbO54},
			{pbO61, pbO62, pbO63, pbO64},
			{pbO71, pbO72, pbO73, pbO74},
			{pbO81, pbO82, pbO83, pbO84},
			{pbO91, pbO92, pbO93, pbO94},
			{pbOa1, pbOa2, pbOa3, pbOa4}};
			this->pbArrH = gcnew array<PictureBox^,2>(10,4) {
			{pbH11, pbH12, pbH13, pbH14},
			{pbH21, pbH22, pbH23, pbH24},
			{pbH31, pbH32, pbH33, pbH34},
			{pbH41, pbH42, pbH43, pbH44},
			{pbH51, pbH52, pbH53, pbH54},
			{pbH61, pbH62, pbH63, pbH64},
			{pbH71, pbH72, pbH73, pbH74},
			{pbH81, pbH82, pbH83, pbH84},
			{pbH91, pbH92, pbH93, pbH94},
			{pbHa1, pbHa2, pbHa3, pbHa4}};
			this->topScore = (gcnew array<time_t,1>(11));

		}

	protected:
		/// <summary>
		/// Wyczyść wszystkie używane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: array<Int16,1>^ intSzukane;
	private: array<PictureBox^,2>^ pbArrO;
	private: array<PictureBox^,2>^ pbArrH;
	private: array<time_t,1>^ topScore;
	private: UInt16 intProba;
	private: Boolean gameInProgress;
	private: time_t sTime, cTime;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  graToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  nowaGraToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  zakończProgramToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pomocToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  instrukcjaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  oProgramieToolStripMenuItem;
	private: System::Windows::Forms::Label^  lblTimer;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lblTop;
	private: System::Windows::Forms::PictureBox^  pbO11;
	private: System::Windows::Forms::PictureBox^  pbH11;
	private: System::Windows::Forms::PictureBox^  pbO12;
	private: System::Windows::Forms::PictureBox^  pbO13;
	private: System::Windows::Forms::PictureBox^  pbO14;
	private: System::Windows::Forms::PictureBox^  pbO24;
	private: System::Windows::Forms::PictureBox^  pbO23;
	private: System::Windows::Forms::PictureBox^  pbO22;
	private: System::Windows::Forms::PictureBox^  pbO21;
	private: System::Windows::Forms::PictureBox^  pbO34;
	private: System::Windows::Forms::PictureBox^  pbO33;
	private: System::Windows::Forms::PictureBox^  pbO32;
	private: System::Windows::Forms::PictureBox^  pbO31;
	private: System::Windows::Forms::PictureBox^  pbO44;
	private: System::Windows::Forms::PictureBox^  pbO43;
	private: System::Windows::Forms::PictureBox^  pbO42;
	private: System::Windows::Forms::PictureBox^  pbO41;
	private: System::Windows::Forms::PictureBox^  pbO54;
	private: System::Windows::Forms::PictureBox^  pbO53;
	private: System::Windows::Forms::PictureBox^  pbO52;
	private: System::Windows::Forms::PictureBox^  pbO51;
	private: System::Windows::Forms::PictureBox^  pbO64;
	private: System::Windows::Forms::PictureBox^  pbO63;
	private: System::Windows::Forms::PictureBox^  pbO62;
	private: System::Windows::Forms::PictureBox^  pbO61;
	private: System::Windows::Forms::PictureBox^  pbO74;
	private: System::Windows::Forms::PictureBox^  pbO73;
	private: System::Windows::Forms::PictureBox^  pbO72;
	private: System::Windows::Forms::PictureBox^  pbO71;
	private: System::Windows::Forms::PictureBox^  pbO84;
	private: System::Windows::Forms::PictureBox^  pbO83;
	private: System::Windows::Forms::PictureBox^  pbO82;
	private: System::Windows::Forms::PictureBox^  pbO81;
	private: System::Windows::Forms::PictureBox^  pbO94;
	private: System::Windows::Forms::PictureBox^  pbO93;
	private: System::Windows::Forms::PictureBox^  pbO92;
	private: System::Windows::Forms::PictureBox^  pbO91;
	private: System::Windows::Forms::PictureBox^  pbOa4;
	private: System::Windows::Forms::PictureBox^  pbOa3;
	private: System::Windows::Forms::PictureBox^  pbOa2;
	private: System::Windows::Forms::PictureBox^  pbOa1;
	private: System::Windows::Forms::PictureBox^  pbH12;
	private: System::Windows::Forms::PictureBox^  pbH13;
	private: System::Windows::Forms::PictureBox^  pbH14;
	private: System::Windows::Forms::PictureBox^  pbH24;
	private: System::Windows::Forms::PictureBox^  pbH23;
	private: System::Windows::Forms::PictureBox^  pbH22;
	private: System::Windows::Forms::PictureBox^  pbH21;
	private: System::Windows::Forms::PictureBox^  pbH34;
	private: System::Windows::Forms::PictureBox^  pbH33;
	private: System::Windows::Forms::PictureBox^  pbH32;
	private: System::Windows::Forms::PictureBox^  pbH31;
	private: System::Windows::Forms::PictureBox^  pbH44;
	private: System::Windows::Forms::PictureBox^  pbH43;
	private: System::Windows::Forms::PictureBox^  pbH42;
	private: System::Windows::Forms::PictureBox^  pbH41;
	private: System::Windows::Forms::PictureBox^  pbH54;
	private: System::Windows::Forms::PictureBox^  pbH53;
	private: System::Windows::Forms::PictureBox^  pbH52;
	private: System::Windows::Forms::PictureBox^  pbH51;
	private: System::Windows::Forms::PictureBox^  pbH64;
	private: System::Windows::Forms::PictureBox^  pbH63;
	private: System::Windows::Forms::PictureBox^  pbH62;
	private: System::Windows::Forms::PictureBox^  pbH61;
	private: System::Windows::Forms::PictureBox^  pbH74;
	private: System::Windows::Forms::PictureBox^  pbH73;
	private: System::Windows::Forms::PictureBox^  pbH72;
	private: System::Windows::Forms::PictureBox^  pbH71;
	private: System::Windows::Forms::PictureBox^  pbH84;
	private: System::Windows::Forms::PictureBox^  pbH83;
	private: System::Windows::Forms::PictureBox^  pbH82;
	private: System::Windows::Forms::PictureBox^  pbH81;
	private: System::Windows::Forms::PictureBox^  pbH94;
	private: System::Windows::Forms::PictureBox^  pbH93;
	private: System::Windows::Forms::PictureBox^  pbH92;
	private: System::Windows::Forms::PictureBox^  pbH91;
	private: System::Windows::Forms::PictureBox^  pbHa4;
	private: System::Windows::Forms::PictureBox^  pbHa3;
	private: System::Windows::Forms::PictureBox^  pbHa2;
	private: System::Windows::Forms::PictureBox^  pbHa1;
	private: System::Windows::Forms::PictureBox^  pbArrow;
	private: System::Windows::Forms::PictureBox^  pbZ1;
	private: System::Windows::Forms::PictureBox^  pbZ2;
	private: System::Windows::Forms::PictureBox^  pbZ3;
	private: System::Windows::Forms::PictureBox^  pbZ4;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Wymagana metoda wsparcia projektanta - nie należy modyfikować
		/// zawartość tej metody z edytorem kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->graToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nowaGraToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->zakończProgramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pomocToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->instrukcjaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->oProgramieToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblTimer = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblTop = (gcnew System::Windows::Forms::Label());
			this->pbO11 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH11 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO12 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO13 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO14 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO24 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO23 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO22 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO21 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO34 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO33 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO32 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO31 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO44 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO43 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO42 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO41 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO54 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO53 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO52 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO51 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO64 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO63 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO62 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO61 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO74 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO73 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO72 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO71 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO84 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO83 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO82 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO81 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO94 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO93 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO92 = (gcnew System::Windows::Forms::PictureBox());
			this->pbO91 = (gcnew System::Windows::Forms::PictureBox());
			this->pbOa4 = (gcnew System::Windows::Forms::PictureBox());
			this->pbOa3 = (gcnew System::Windows::Forms::PictureBox());
			this->pbOa2 = (gcnew System::Windows::Forms::PictureBox());
			this->pbOa1 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH12 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH13 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH14 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH24 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH23 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH22 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH21 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH34 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH33 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH32 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH31 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH44 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH43 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH42 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH41 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH54 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH53 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH52 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH51 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH64 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH63 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH62 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH61 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH74 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH73 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH72 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH71 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH84 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH83 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH82 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH81 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH94 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH93 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH92 = (gcnew System::Windows::Forms::PictureBox());
			this->pbH91 = (gcnew System::Windows::Forms::PictureBox());
			this->pbHa4 = (gcnew System::Windows::Forms::PictureBox());
			this->pbHa3 = (gcnew System::Windows::Forms::PictureBox());
			this->pbHa2 = (gcnew System::Windows::Forms::PictureBox());
			this->pbHa1 = (gcnew System::Windows::Forms::PictureBox());
			this->pbArrow = (gcnew System::Windows::Forms::PictureBox());
			this->pbZ1 = (gcnew System::Windows::Forms::PictureBox());
			this->pbZ2 = (gcnew System::Windows::Forms::PictureBox());
			this->pbZ3 = (gcnew System::Windows::Forms::PictureBox());
			this->pbZ4 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO23))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO34))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO33))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO32))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO31))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO44))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO43))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO42))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO41))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO54))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO53))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO52))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO51))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO64))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO63))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO62))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO61))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO74))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO73))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO72))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO71))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO84))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO83))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO82))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO81))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO94))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO93))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO92))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO91))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbOa4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbOa3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbOa2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbOa1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH23))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH34))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH33))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH32))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH31))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH44))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH43))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH42))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH41))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH54))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH53))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH52))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH51))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH64))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH63))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH62))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH61))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH74))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH73))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH72))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH71))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH84))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH83))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH82))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH81))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH94))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH93))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH92))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH91))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbHa4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbHa3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbHa2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbHa1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbArrow))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbZ1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbZ2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbZ3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbZ4))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Transparent;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->graToolStripMenuItem, 
				this->pomocToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(273, 24);
			this->menuStrip1->TabIndex = 95;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// graToolStripMenuItem
			// 
			this->graToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->nowaGraToolStripMenuItem, 
				this->toolStripMenuItem1, this->zakończProgramToolStripMenuItem});
			this->graToolStripMenuItem->Name = L"graToolStripMenuItem";
			this->graToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->graToolStripMenuItem->Text = L"&Gra";
			// 
			// nowaGraToolStripMenuItem
			// 
			this->nowaGraToolStripMenuItem->Name = L"nowaGraToolStripMenuItem";
			this->nowaGraToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->nowaGraToolStripMenuItem->Text = L"&Nowa gra";
			this->nowaGraToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::nowaGraToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(164, 6);
			// 
			// zakończProgramToolStripMenuItem
			// 
			this->zakończProgramToolStripMenuItem->Name = L"zakończProgramToolStripMenuItem";
			this->zakończProgramToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->zakończProgramToolStripMenuItem->Text = L"&Zakończ program";
			this->zakończProgramToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::zakończProgramToolStripMenuItem_Click);
			// 
			// pomocToolStripMenuItem
			// 
			this->pomocToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->instrukcjaToolStripMenuItem, 
				this->toolStripMenuItem2, this->oProgramieToolStripMenuItem});
			this->pomocToolStripMenuItem->Name = L"pomocToolStripMenuItem";
			this->pomocToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->pomocToolStripMenuItem->Text = L"&Pomoc";
			// 
			// instrukcjaToolStripMenuItem
			// 
			this->instrukcjaToolStripMenuItem->Name = L"instrukcjaToolStripMenuItem";
			this->instrukcjaToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->instrukcjaToolStripMenuItem->Text = L"&Instrukcja";
			this->instrukcjaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::instrukcjaToolStripMenuItem_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(138, 6);
			// 
			// oProgramieToolStripMenuItem
			// 
			this->oProgramieToolStripMenuItem->Name = L"oProgramieToolStripMenuItem";
			this->oProgramieToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->oProgramieToolStripMenuItem->Text = L"O progr&amie";
			this->oProgramieToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::oProgramieToolStripMenuItem_Click);
			// 
			// lblTimer
			// 
			this->lblTimer->AutoSize = true;
			this->lblTimer->BackColor = System::Drawing::Color::Transparent;
			this->lblTimer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblTimer->ForeColor = System::Drawing::Color::White;
			this->lblTimer->Location = System::Drawing::Point(195, 97);
			this->lblTimer->Name = L"lblTimer";
			this->lblTimer->Size = System::Drawing::Size(49, 18);
			this->lblTimer->TabIndex = 96;
			this->lblTimer->Text = L"00:00";
			this->lblTimer->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(193, 115);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 9);
			this->label2->TabIndex = 97;
			this->label2->Text = L"NAJLEPSZY:";
			this->label2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// lblTop
			// 
			this->lblTop->AutoSize = true;
			this->lblTop->BackColor = System::Drawing::Color::Transparent;
			this->lblTop->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->lblTop->ForeColor = System::Drawing::Color::White;
			this->lblTop->Location = System::Drawing::Point(201, 124);
			this->lblTop->Name = L"lblTop";
			this->lblTop->Size = System::Drawing::Size(34, 13);
			this->lblTop->TabIndex = 96;
			this->lblTop->Text = L"00:00";
			this->lblTop->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbO11
			// 
			this->pbO11->BackColor = System::Drawing::Color::Transparent;
			this->pbO11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO11->Location = System::Drawing::Point(37, 162);
			this->pbO11->Name = L"pbO11";
			this->pbO11->Size = System::Drawing::Size(23, 21);
			this->pbO11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO11->TabIndex = 98;
			this->pbO11->TabStop = false;
			this->pbO11->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbH11
			// 
			this->pbH11->BackColor = System::Drawing::Color::Transparent;
			this->pbH11->Location = System::Drawing::Point(189, 160);
			this->pbH11->Name = L"pbH11";
			this->pbH11->Size = System::Drawing::Size(15, 25);
			this->pbH11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH11->TabIndex = 99;
			this->pbH11->TabStop = false;
			this->pbH11->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbO12
			// 
			this->pbO12->BackColor = System::Drawing::Color::Transparent;
			this->pbO12->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO12->Location = System::Drawing::Point(66, 162);
			this->pbO12->Name = L"pbO12";
			this->pbO12->Size = System::Drawing::Size(23, 21);
			this->pbO12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO12->TabIndex = 100;
			this->pbO12->TabStop = false;
			this->pbO12->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO13
			// 
			this->pbO13->BackColor = System::Drawing::Color::Transparent;
			this->pbO13->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO13->Location = System::Drawing::Point(95, 162);
			this->pbO13->Name = L"pbO13";
			this->pbO13->Size = System::Drawing::Size(23, 21);
			this->pbO13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO13->TabIndex = 101;
			this->pbO13->TabStop = false;
			this->pbO13->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO14
			// 
			this->pbO14->BackColor = System::Drawing::Color::Transparent;
			this->pbO14->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO14->Location = System::Drawing::Point(124, 162);
			this->pbO14->Name = L"pbO14";
			this->pbO14->Size = System::Drawing::Size(23, 21);
			this->pbO14->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO14->TabIndex = 102;
			this->pbO14->TabStop = false;
			this->pbO14->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO24
			// 
			this->pbO24->BackColor = System::Drawing::Color::Transparent;
			this->pbO24->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO24->Location = System::Drawing::Point(124, 187);
			this->pbO24->Name = L"pbO24";
			this->pbO24->Size = System::Drawing::Size(23, 21);
			this->pbO24->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO24->TabIndex = 106;
			this->pbO24->TabStop = false;
			this->pbO24->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO23
			// 
			this->pbO23->BackColor = System::Drawing::Color::Transparent;
			this->pbO23->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO23->Location = System::Drawing::Point(95, 187);
			this->pbO23->Name = L"pbO23";
			this->pbO23->Size = System::Drawing::Size(23, 21);
			this->pbO23->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO23->TabIndex = 105;
			this->pbO23->TabStop = false;
			this->pbO23->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO22
			// 
			this->pbO22->BackColor = System::Drawing::Color::Transparent;
			this->pbO22->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO22->Location = System::Drawing::Point(66, 187);
			this->pbO22->Name = L"pbO22";
			this->pbO22->Size = System::Drawing::Size(23, 21);
			this->pbO22->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO22->TabIndex = 104;
			this->pbO22->TabStop = false;
			this->pbO22->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO21
			// 
			this->pbO21->BackColor = System::Drawing::Color::Transparent;
			this->pbO21->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO21->Location = System::Drawing::Point(37, 187);
			this->pbO21->Name = L"pbO21";
			this->pbO21->Size = System::Drawing::Size(23, 21);
			this->pbO21->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO21->TabIndex = 103;
			this->pbO21->TabStop = false;
			this->pbO21->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO34
			// 
			this->pbO34->BackColor = System::Drawing::Color::Transparent;
			this->pbO34->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO34->Location = System::Drawing::Point(124, 212);
			this->pbO34->Name = L"pbO34";
			this->pbO34->Size = System::Drawing::Size(23, 21);
			this->pbO34->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO34->TabIndex = 110;
			this->pbO34->TabStop = false;
			this->pbO34->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO33
			// 
			this->pbO33->BackColor = System::Drawing::Color::Transparent;
			this->pbO33->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO33->Location = System::Drawing::Point(95, 212);
			this->pbO33->Name = L"pbO33";
			this->pbO33->Size = System::Drawing::Size(23, 21);
			this->pbO33->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO33->TabIndex = 109;
			this->pbO33->TabStop = false;
			this->pbO33->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO32
			// 
			this->pbO32->BackColor = System::Drawing::Color::Transparent;
			this->pbO32->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO32->Location = System::Drawing::Point(66, 212);
			this->pbO32->Name = L"pbO32";
			this->pbO32->Size = System::Drawing::Size(23, 21);
			this->pbO32->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO32->TabIndex = 108;
			this->pbO32->TabStop = false;
			this->pbO32->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO31
			// 
			this->pbO31->BackColor = System::Drawing::Color::Transparent;
			this->pbO31->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO31->Location = System::Drawing::Point(37, 212);
			this->pbO31->Name = L"pbO31";
			this->pbO31->Size = System::Drawing::Size(23, 21);
			this->pbO31->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO31->TabIndex = 107;
			this->pbO31->TabStop = false;
			this->pbO31->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO44
			// 
			this->pbO44->BackColor = System::Drawing::Color::Transparent;
			this->pbO44->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO44->Location = System::Drawing::Point(124, 237);
			this->pbO44->Name = L"pbO44";
			this->pbO44->Size = System::Drawing::Size(23, 21);
			this->pbO44->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO44->TabIndex = 114;
			this->pbO44->TabStop = false;
			this->pbO44->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO43
			// 
			this->pbO43->BackColor = System::Drawing::Color::Transparent;
			this->pbO43->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO43->Location = System::Drawing::Point(95, 237);
			this->pbO43->Name = L"pbO43";
			this->pbO43->Size = System::Drawing::Size(23, 21);
			this->pbO43->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO43->TabIndex = 113;
			this->pbO43->TabStop = false;
			this->pbO43->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO42
			// 
			this->pbO42->BackColor = System::Drawing::Color::Transparent;
			this->pbO42->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO42->Location = System::Drawing::Point(66, 237);
			this->pbO42->Name = L"pbO42";
			this->pbO42->Size = System::Drawing::Size(23, 21);
			this->pbO42->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO42->TabIndex = 112;
			this->pbO42->TabStop = false;
			this->pbO42->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO41
			// 
			this->pbO41->BackColor = System::Drawing::Color::Transparent;
			this->pbO41->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO41->Location = System::Drawing::Point(37, 237);
			this->pbO41->Name = L"pbO41";
			this->pbO41->Size = System::Drawing::Size(23, 21);
			this->pbO41->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO41->TabIndex = 111;
			this->pbO41->TabStop = false;
			this->pbO41->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO54
			// 
			this->pbO54->BackColor = System::Drawing::Color::Transparent;
			this->pbO54->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO54->Location = System::Drawing::Point(124, 262);
			this->pbO54->Name = L"pbO54";
			this->pbO54->Size = System::Drawing::Size(23, 21);
			this->pbO54->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO54->TabIndex = 118;
			this->pbO54->TabStop = false;
			this->pbO54->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO53
			// 
			this->pbO53->BackColor = System::Drawing::Color::Transparent;
			this->pbO53->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO53->Location = System::Drawing::Point(95, 262);
			this->pbO53->Name = L"pbO53";
			this->pbO53->Size = System::Drawing::Size(23, 21);
			this->pbO53->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO53->TabIndex = 117;
			this->pbO53->TabStop = false;
			this->pbO53->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO52
			// 
			this->pbO52->BackColor = System::Drawing::Color::Transparent;
			this->pbO52->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO52->Location = System::Drawing::Point(66, 262);
			this->pbO52->Name = L"pbO52";
			this->pbO52->Size = System::Drawing::Size(23, 21);
			this->pbO52->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO52->TabIndex = 116;
			this->pbO52->TabStop = false;
			this->pbO52->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO51
			// 
			this->pbO51->BackColor = System::Drawing::Color::Transparent;
			this->pbO51->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO51->Location = System::Drawing::Point(37, 262);
			this->pbO51->Name = L"pbO51";
			this->pbO51->Size = System::Drawing::Size(23, 21);
			this->pbO51->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO51->TabIndex = 115;
			this->pbO51->TabStop = false;
			this->pbO51->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO64
			// 
			this->pbO64->BackColor = System::Drawing::Color::Transparent;
			this->pbO64->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO64->Location = System::Drawing::Point(124, 287);
			this->pbO64->Name = L"pbO64";
			this->pbO64->Size = System::Drawing::Size(23, 21);
			this->pbO64->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO64->TabIndex = 122;
			this->pbO64->TabStop = false;
			this->pbO64->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO63
			// 
			this->pbO63->BackColor = System::Drawing::Color::Transparent;
			this->pbO63->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO63->Location = System::Drawing::Point(95, 287);
			this->pbO63->Name = L"pbO63";
			this->pbO63->Size = System::Drawing::Size(23, 21);
			this->pbO63->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO63->TabIndex = 121;
			this->pbO63->TabStop = false;
			this->pbO63->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO62
			// 
			this->pbO62->BackColor = System::Drawing::Color::Transparent;
			this->pbO62->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO62->Location = System::Drawing::Point(66, 287);
			this->pbO62->Name = L"pbO62";
			this->pbO62->Size = System::Drawing::Size(23, 21);
			this->pbO62->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO62->TabIndex = 120;
			this->pbO62->TabStop = false;
			this->pbO62->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO61
			// 
			this->pbO61->BackColor = System::Drawing::Color::Transparent;
			this->pbO61->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO61->Location = System::Drawing::Point(37, 287);
			this->pbO61->Name = L"pbO61";
			this->pbO61->Size = System::Drawing::Size(23, 21);
			this->pbO61->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO61->TabIndex = 119;
			this->pbO61->TabStop = false;
			this->pbO61->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO74
			// 
			this->pbO74->BackColor = System::Drawing::Color::Transparent;
			this->pbO74->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO74->Location = System::Drawing::Point(124, 312);
			this->pbO74->Name = L"pbO74";
			this->pbO74->Size = System::Drawing::Size(23, 21);
			this->pbO74->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO74->TabIndex = 126;
			this->pbO74->TabStop = false;
			this->pbO74->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO73
			// 
			this->pbO73->BackColor = System::Drawing::Color::Transparent;
			this->pbO73->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO73->Location = System::Drawing::Point(95, 312);
			this->pbO73->Name = L"pbO73";
			this->pbO73->Size = System::Drawing::Size(23, 21);
			this->pbO73->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO73->TabIndex = 125;
			this->pbO73->TabStop = false;
			this->pbO73->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO72
			// 
			this->pbO72->BackColor = System::Drawing::Color::Transparent;
			this->pbO72->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO72->Location = System::Drawing::Point(66, 312);
			this->pbO72->Name = L"pbO72";
			this->pbO72->Size = System::Drawing::Size(23, 21);
			this->pbO72->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO72->TabIndex = 124;
			this->pbO72->TabStop = false;
			this->pbO72->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO71
			// 
			this->pbO71->BackColor = System::Drawing::Color::Transparent;
			this->pbO71->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO71->Location = System::Drawing::Point(37, 312);
			this->pbO71->Name = L"pbO71";
			this->pbO71->Size = System::Drawing::Size(23, 21);
			this->pbO71->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO71->TabIndex = 123;
			this->pbO71->TabStop = false;
			this->pbO71->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO84
			// 
			this->pbO84->BackColor = System::Drawing::Color::Transparent;
			this->pbO84->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO84->Location = System::Drawing::Point(124, 337);
			this->pbO84->Name = L"pbO84";
			this->pbO84->Size = System::Drawing::Size(23, 21);
			this->pbO84->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO84->TabIndex = 130;
			this->pbO84->TabStop = false;
			this->pbO84->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO83
			// 
			this->pbO83->BackColor = System::Drawing::Color::Transparent;
			this->pbO83->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO83->Location = System::Drawing::Point(95, 337);
			this->pbO83->Name = L"pbO83";
			this->pbO83->Size = System::Drawing::Size(23, 21);
			this->pbO83->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO83->TabIndex = 129;
			this->pbO83->TabStop = false;
			this->pbO83->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO82
			// 
			this->pbO82->BackColor = System::Drawing::Color::Transparent;
			this->pbO82->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO82->Location = System::Drawing::Point(66, 337);
			this->pbO82->Name = L"pbO82";
			this->pbO82->Size = System::Drawing::Size(23, 21);
			this->pbO82->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO82->TabIndex = 128;
			this->pbO82->TabStop = false;
			this->pbO82->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO81
			// 
			this->pbO81->BackColor = System::Drawing::Color::Transparent;
			this->pbO81->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO81->Location = System::Drawing::Point(37, 337);
			this->pbO81->Name = L"pbO81";
			this->pbO81->Size = System::Drawing::Size(23, 21);
			this->pbO81->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO81->TabIndex = 127;
			this->pbO81->TabStop = false;
			this->pbO81->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO94
			// 
			this->pbO94->BackColor = System::Drawing::Color::Transparent;
			this->pbO94->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO94->Location = System::Drawing::Point(124, 362);
			this->pbO94->Name = L"pbO94";
			this->pbO94->Size = System::Drawing::Size(23, 21);
			this->pbO94->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO94->TabIndex = 134;
			this->pbO94->TabStop = false;
			this->pbO94->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO93
			// 
			this->pbO93->BackColor = System::Drawing::Color::Transparent;
			this->pbO93->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO93->Location = System::Drawing::Point(95, 362);
			this->pbO93->Name = L"pbO93";
			this->pbO93->Size = System::Drawing::Size(23, 21);
			this->pbO93->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO93->TabIndex = 133;
			this->pbO93->TabStop = false;
			this->pbO93->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO92
			// 
			this->pbO92->BackColor = System::Drawing::Color::Transparent;
			this->pbO92->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO92->Location = System::Drawing::Point(66, 362);
			this->pbO92->Name = L"pbO92";
			this->pbO92->Size = System::Drawing::Size(23, 21);
			this->pbO92->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO92->TabIndex = 132;
			this->pbO92->TabStop = false;
			this->pbO92->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbO91
			// 
			this->pbO91->BackColor = System::Drawing::Color::Transparent;
			this->pbO91->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbO91->Location = System::Drawing::Point(37, 362);
			this->pbO91->Name = L"pbO91";
			this->pbO91->Size = System::Drawing::Size(23, 21);
			this->pbO91->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbO91->TabIndex = 131;
			this->pbO91->TabStop = false;
			this->pbO91->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbOa4
			// 
			this->pbOa4->BackColor = System::Drawing::Color::Transparent;
			this->pbOa4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbOa4->Location = System::Drawing::Point(124, 387);
			this->pbOa4->Name = L"pbOa4";
			this->pbOa4->Size = System::Drawing::Size(23, 21);
			this->pbOa4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbOa4->TabIndex = 138;
			this->pbOa4->TabStop = false;
			this->pbOa4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbOa3
			// 
			this->pbOa3->BackColor = System::Drawing::Color::Transparent;
			this->pbOa3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbOa3->Location = System::Drawing::Point(95, 387);
			this->pbOa3->Name = L"pbOa3";
			this->pbOa3->Size = System::Drawing::Size(23, 21);
			this->pbOa3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbOa3->TabIndex = 137;
			this->pbOa3->TabStop = false;
			this->pbOa3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbOa2
			// 
			this->pbOa2->BackColor = System::Drawing::Color::Transparent;
			this->pbOa2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbOa2->Location = System::Drawing::Point(66, 387);
			this->pbOa2->Name = L"pbOa2";
			this->pbOa2->Size = System::Drawing::Size(23, 21);
			this->pbOa2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbOa2->TabIndex = 136;
			this->pbOa2->TabStop = false;
			this->pbOa2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbOa1
			// 
			this->pbOa1->BackColor = System::Drawing::Color::Transparent;
			this->pbOa1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbOa1->Location = System::Drawing::Point(37, 387);
			this->pbOa1->Name = L"pbOa1";
			this->pbOa1->Size = System::Drawing::Size(23, 21);
			this->pbOa1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbOa1->TabIndex = 135;
			this->pbOa1->TabStop = false;
			this->pbOa1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox_MouseDown);
			// 
			// pbH12
			// 
			this->pbH12->BackColor = System::Drawing::Color::Transparent;
			this->pbH12->Location = System::Drawing::Point(204, 160);
			this->pbH12->Name = L"pbH12";
			this->pbH12->Size = System::Drawing::Size(15, 25);
			this->pbH12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH12->TabIndex = 139;
			this->pbH12->TabStop = false;
			this->pbH12->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH13
			// 
			this->pbH13->BackColor = System::Drawing::Color::Transparent;
			this->pbH13->Location = System::Drawing::Point(219, 160);
			this->pbH13->Name = L"pbH13";
			this->pbH13->Size = System::Drawing::Size(15, 25);
			this->pbH13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH13->TabIndex = 140;
			this->pbH13->TabStop = false;
			this->pbH13->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH14
			// 
			this->pbH14->BackColor = System::Drawing::Color::Transparent;
			this->pbH14->Location = System::Drawing::Point(234, 160);
			this->pbH14->Name = L"pbH14";
			this->pbH14->Size = System::Drawing::Size(15, 25);
			this->pbH14->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH14->TabIndex = 141;
			this->pbH14->TabStop = false;
			this->pbH14->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH24
			// 
			this->pbH24->BackColor = System::Drawing::Color::Transparent;
			this->pbH24->Location = System::Drawing::Point(234, 185);
			this->pbH24->Name = L"pbH24";
			this->pbH24->Size = System::Drawing::Size(15, 25);
			this->pbH24->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH24->TabIndex = 145;
			this->pbH24->TabStop = false;
			this->pbH24->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH23
			// 
			this->pbH23->BackColor = System::Drawing::Color::Transparent;
			this->pbH23->Location = System::Drawing::Point(219, 185);
			this->pbH23->Name = L"pbH23";
			this->pbH23->Size = System::Drawing::Size(15, 25);
			this->pbH23->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH23->TabIndex = 144;
			this->pbH23->TabStop = false;
			this->pbH23->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH22
			// 
			this->pbH22->BackColor = System::Drawing::Color::Transparent;
			this->pbH22->Location = System::Drawing::Point(204, 185);
			this->pbH22->Name = L"pbH22";
			this->pbH22->Size = System::Drawing::Size(15, 25);
			this->pbH22->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH22->TabIndex = 143;
			this->pbH22->TabStop = false;
			this->pbH22->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH21
			// 
			this->pbH21->BackColor = System::Drawing::Color::Transparent;
			this->pbH21->Location = System::Drawing::Point(189, 185);
			this->pbH21->Name = L"pbH21";
			this->pbH21->Size = System::Drawing::Size(15, 25);
			this->pbH21->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH21->TabIndex = 142;
			this->pbH21->TabStop = false;
			this->pbH21->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH34
			// 
			this->pbH34->BackColor = System::Drawing::Color::Transparent;
			this->pbH34->Location = System::Drawing::Point(234, 210);
			this->pbH34->Name = L"pbH34";
			this->pbH34->Size = System::Drawing::Size(15, 25);
			this->pbH34->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH34->TabIndex = 149;
			this->pbH34->TabStop = false;
			this->pbH34->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH33
			// 
			this->pbH33->BackColor = System::Drawing::Color::Transparent;
			this->pbH33->Location = System::Drawing::Point(219, 210);
			this->pbH33->Name = L"pbH33";
			this->pbH33->Size = System::Drawing::Size(15, 25);
			this->pbH33->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH33->TabIndex = 148;
			this->pbH33->TabStop = false;
			this->pbH33->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH32
			// 
			this->pbH32->BackColor = System::Drawing::Color::Transparent;
			this->pbH32->Location = System::Drawing::Point(204, 210);
			this->pbH32->Name = L"pbH32";
			this->pbH32->Size = System::Drawing::Size(15, 25);
			this->pbH32->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH32->TabIndex = 147;
			this->pbH32->TabStop = false;
			this->pbH32->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH31
			// 
			this->pbH31->BackColor = System::Drawing::Color::Transparent;
			this->pbH31->Location = System::Drawing::Point(189, 210);
			this->pbH31->Name = L"pbH31";
			this->pbH31->Size = System::Drawing::Size(15, 25);
			this->pbH31->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH31->TabIndex = 146;
			this->pbH31->TabStop = false;
			this->pbH31->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH44
			// 
			this->pbH44->BackColor = System::Drawing::Color::Transparent;
			this->pbH44->Location = System::Drawing::Point(234, 235);
			this->pbH44->Name = L"pbH44";
			this->pbH44->Size = System::Drawing::Size(15, 25);
			this->pbH44->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH44->TabIndex = 153;
			this->pbH44->TabStop = false;
			this->pbH44->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH43
			// 
			this->pbH43->BackColor = System::Drawing::Color::Transparent;
			this->pbH43->Location = System::Drawing::Point(219, 235);
			this->pbH43->Name = L"pbH43";
			this->pbH43->Size = System::Drawing::Size(15, 25);
			this->pbH43->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH43->TabIndex = 152;
			this->pbH43->TabStop = false;
			this->pbH43->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH42
			// 
			this->pbH42->BackColor = System::Drawing::Color::Transparent;
			this->pbH42->Location = System::Drawing::Point(204, 235);
			this->pbH42->Name = L"pbH42";
			this->pbH42->Size = System::Drawing::Size(15, 25);
			this->pbH42->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH42->TabIndex = 151;
			this->pbH42->TabStop = false;
			this->pbH42->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH41
			// 
			this->pbH41->BackColor = System::Drawing::Color::Transparent;
			this->pbH41->Location = System::Drawing::Point(189, 235);
			this->pbH41->Name = L"pbH41";
			this->pbH41->Size = System::Drawing::Size(15, 25);
			this->pbH41->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH41->TabIndex = 150;
			this->pbH41->TabStop = false;
			this->pbH41->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH54
			// 
			this->pbH54->BackColor = System::Drawing::Color::Transparent;
			this->pbH54->Location = System::Drawing::Point(234, 260);
			this->pbH54->Name = L"pbH54";
			this->pbH54->Size = System::Drawing::Size(15, 25);
			this->pbH54->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH54->TabIndex = 157;
			this->pbH54->TabStop = false;
			this->pbH54->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH53
			// 
			this->pbH53->BackColor = System::Drawing::Color::Transparent;
			this->pbH53->Location = System::Drawing::Point(219, 260);
			this->pbH53->Name = L"pbH53";
			this->pbH53->Size = System::Drawing::Size(15, 25);
			this->pbH53->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH53->TabIndex = 156;
			this->pbH53->TabStop = false;
			this->pbH53->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH52
			// 
			this->pbH52->BackColor = System::Drawing::Color::Transparent;
			this->pbH52->Location = System::Drawing::Point(204, 260);
			this->pbH52->Name = L"pbH52";
			this->pbH52->Size = System::Drawing::Size(15, 25);
			this->pbH52->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH52->TabIndex = 155;
			this->pbH52->TabStop = false;
			this->pbH52->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH51
			// 
			this->pbH51->BackColor = System::Drawing::Color::Transparent;
			this->pbH51->Location = System::Drawing::Point(189, 260);
			this->pbH51->Name = L"pbH51";
			this->pbH51->Size = System::Drawing::Size(15, 25);
			this->pbH51->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH51->TabIndex = 154;
			this->pbH51->TabStop = false;
			this->pbH51->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH64
			// 
			this->pbH64->BackColor = System::Drawing::Color::Transparent;
			this->pbH64->Location = System::Drawing::Point(234, 285);
			this->pbH64->Name = L"pbH64";
			this->pbH64->Size = System::Drawing::Size(15, 25);
			this->pbH64->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH64->TabIndex = 161;
			this->pbH64->TabStop = false;
			this->pbH64->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH63
			// 
			this->pbH63->BackColor = System::Drawing::Color::Transparent;
			this->pbH63->Location = System::Drawing::Point(219, 285);
			this->pbH63->Name = L"pbH63";
			this->pbH63->Size = System::Drawing::Size(15, 25);
			this->pbH63->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH63->TabIndex = 160;
			this->pbH63->TabStop = false;
			this->pbH63->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH62
			// 
			this->pbH62->BackColor = System::Drawing::Color::Transparent;
			this->pbH62->Location = System::Drawing::Point(204, 285);
			this->pbH62->Name = L"pbH62";
			this->pbH62->Size = System::Drawing::Size(15, 25);
			this->pbH62->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH62->TabIndex = 159;
			this->pbH62->TabStop = false;
			this->pbH62->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH61
			// 
			this->pbH61->BackColor = System::Drawing::Color::Transparent;
			this->pbH61->Location = System::Drawing::Point(189, 285);
			this->pbH61->Name = L"pbH61";
			this->pbH61->Size = System::Drawing::Size(15, 25);
			this->pbH61->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH61->TabIndex = 158;
			this->pbH61->TabStop = false;
			this->pbH61->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH74
			// 
			this->pbH74->BackColor = System::Drawing::Color::Transparent;
			this->pbH74->Location = System::Drawing::Point(234, 310);
			this->pbH74->Name = L"pbH74";
			this->pbH74->Size = System::Drawing::Size(15, 25);
			this->pbH74->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH74->TabIndex = 165;
			this->pbH74->TabStop = false;
			this->pbH74->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH73
			// 
			this->pbH73->BackColor = System::Drawing::Color::Transparent;
			this->pbH73->Location = System::Drawing::Point(219, 310);
			this->pbH73->Name = L"pbH73";
			this->pbH73->Size = System::Drawing::Size(15, 25);
			this->pbH73->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH73->TabIndex = 164;
			this->pbH73->TabStop = false;
			this->pbH73->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH72
			// 
			this->pbH72->BackColor = System::Drawing::Color::Transparent;
			this->pbH72->Location = System::Drawing::Point(204, 310);
			this->pbH72->Name = L"pbH72";
			this->pbH72->Size = System::Drawing::Size(15, 25);
			this->pbH72->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH72->TabIndex = 163;
			this->pbH72->TabStop = false;
			this->pbH72->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH71
			// 
			this->pbH71->BackColor = System::Drawing::Color::Transparent;
			this->pbH71->Location = System::Drawing::Point(189, 310);
			this->pbH71->Name = L"pbH71";
			this->pbH71->Size = System::Drawing::Size(15, 25);
			this->pbH71->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH71->TabIndex = 162;
			this->pbH71->TabStop = false;
			this->pbH71->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH84
			// 
			this->pbH84->BackColor = System::Drawing::Color::Transparent;
			this->pbH84->Location = System::Drawing::Point(234, 335);
			this->pbH84->Name = L"pbH84";
			this->pbH84->Size = System::Drawing::Size(15, 25);
			this->pbH84->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH84->TabIndex = 169;
			this->pbH84->TabStop = false;
			this->pbH84->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH83
			// 
			this->pbH83->BackColor = System::Drawing::Color::Transparent;
			this->pbH83->Location = System::Drawing::Point(219, 335);
			this->pbH83->Name = L"pbH83";
			this->pbH83->Size = System::Drawing::Size(15, 25);
			this->pbH83->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH83->TabIndex = 168;
			this->pbH83->TabStop = false;
			this->pbH83->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH82
			// 
			this->pbH82->BackColor = System::Drawing::Color::Transparent;
			this->pbH82->Location = System::Drawing::Point(204, 335);
			this->pbH82->Name = L"pbH82";
			this->pbH82->Size = System::Drawing::Size(15, 25);
			this->pbH82->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH82->TabIndex = 167;
			this->pbH82->TabStop = false;
			this->pbH82->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH81
			// 
			this->pbH81->BackColor = System::Drawing::Color::Transparent;
			this->pbH81->Location = System::Drawing::Point(189, 335);
			this->pbH81->Name = L"pbH81";
			this->pbH81->Size = System::Drawing::Size(15, 25);
			this->pbH81->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH81->TabIndex = 166;
			this->pbH81->TabStop = false;
			this->pbH81->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH94
			// 
			this->pbH94->BackColor = System::Drawing::Color::Transparent;
			this->pbH94->Location = System::Drawing::Point(234, 360);
			this->pbH94->Name = L"pbH94";
			this->pbH94->Size = System::Drawing::Size(15, 25);
			this->pbH94->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH94->TabIndex = 173;
			this->pbH94->TabStop = false;
			this->pbH94->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH93
			// 
			this->pbH93->BackColor = System::Drawing::Color::Transparent;
			this->pbH93->Location = System::Drawing::Point(219, 360);
			this->pbH93->Name = L"pbH93";
			this->pbH93->Size = System::Drawing::Size(15, 25);
			this->pbH93->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH93->TabIndex = 172;
			this->pbH93->TabStop = false;
			this->pbH93->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH92
			// 
			this->pbH92->BackColor = System::Drawing::Color::Transparent;
			this->pbH92->Location = System::Drawing::Point(204, 360);
			this->pbH92->Name = L"pbH92";
			this->pbH92->Size = System::Drawing::Size(15, 25);
			this->pbH92->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH92->TabIndex = 171;
			this->pbH92->TabStop = false;
			this->pbH92->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbH91
			// 
			this->pbH91->BackColor = System::Drawing::Color::Transparent;
			this->pbH91->Location = System::Drawing::Point(189, 360);
			this->pbH91->Name = L"pbH91";
			this->pbH91->Size = System::Drawing::Size(15, 25);
			this->pbH91->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbH91->TabIndex = 170;
			this->pbH91->TabStop = false;
			this->pbH91->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbHa4
			// 
			this->pbHa4->BackColor = System::Drawing::Color::Transparent;
			this->pbHa4->Location = System::Drawing::Point(234, 384);
			this->pbHa4->Name = L"pbHa4";
			this->pbHa4->Size = System::Drawing::Size(15, 25);
			this->pbHa4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbHa4->TabIndex = 177;
			this->pbHa4->TabStop = false;
			this->pbHa4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbHa3
			// 
			this->pbHa3->BackColor = System::Drawing::Color::Transparent;
			this->pbHa3->Location = System::Drawing::Point(219, 384);
			this->pbHa3->Name = L"pbHa3";
			this->pbHa3->Size = System::Drawing::Size(15, 25);
			this->pbHa3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbHa3->TabIndex = 176;
			this->pbHa3->TabStop = false;
			this->pbHa3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbHa2
			// 
			this->pbHa2->BackColor = System::Drawing::Color::Transparent;
			this->pbHa2->Location = System::Drawing::Point(204, 384);
			this->pbHa2->Name = L"pbHa2";
			this->pbHa2->Size = System::Drawing::Size(15, 25);
			this->pbHa2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbHa2->TabIndex = 175;
			this->pbHa2->TabStop = false;
			this->pbHa2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbHa1
			// 
			this->pbHa1->BackColor = System::Drawing::Color::Transparent;
			this->pbHa1->Location = System::Drawing::Point(189, 384);
			this->pbHa1->Name = L"pbHa1";
			this->pbHa1->Size = System::Drawing::Size(15, 25);
			this->pbHa1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbHa1->TabIndex = 174;
			this->pbHa1->TabStop = false;
			this->pbHa1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbArrow
			// 
			this->pbArrow->BackColor = System::Drawing::Color::Transparent;
			this->pbArrow->Location = System::Drawing::Point(15, 162);
			this->pbArrow->Name = L"pbArrow";
			this->pbArrow->Size = System::Drawing::Size(23, 21);
			this->pbArrow->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbArrow->TabIndex = 178;
			this->pbArrow->TabStop = false;
			this->pbArrow->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			// 
			// pbZ1
			// 
			this->pbZ1->BackColor = System::Drawing::Color::Transparent;
			this->pbZ1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbZ1->Location = System::Drawing::Point(37, 107);
			this->pbZ1->Name = L"pbZ1";
			this->pbZ1->Size = System::Drawing::Size(23, 21);
			this->pbZ1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbZ1->TabIndex = 179;
			this->pbZ1->TabStop = false;
			// 
			// pbZ2
			// 
			this->pbZ2->BackColor = System::Drawing::Color::Transparent;
			this->pbZ2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbZ2->Location = System::Drawing::Point(66, 107);
			this->pbZ2->Name = L"pbZ2";
			this->pbZ2->Size = System::Drawing::Size(23, 21);
			this->pbZ2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbZ2->TabIndex = 180;
			this->pbZ2->TabStop = false;
			// 
			// pbZ3
			// 
			this->pbZ3->BackColor = System::Drawing::Color::Transparent;
			this->pbZ3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbZ3->Location = System::Drawing::Point(95, 107);
			this->pbZ3->Name = L"pbZ3";
			this->pbZ3->Size = System::Drawing::Size(23, 21);
			this->pbZ3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbZ3->TabIndex = 181;
			this->pbZ3->TabStop = false;
			// 
			// pbZ4
			// 
			this->pbZ4->BackColor = System::Drawing::Color::Transparent;
			this->pbZ4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pbZ4->Location = System::Drawing::Point(124, 107);
			this->pbZ4->Name = L"pbZ4";
			this->pbZ4->Size = System::Drawing::Size(23, 21);
			this->pbZ4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbZ4->TabIndex = 182;
			this->pbZ4->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(273, 432);
			this->Controls->Add(this->pbArrow);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblTop);
			this->Controls->Add(this->lblTimer);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pbO11);
			this->Controls->Add(this->pbO12);
			this->Controls->Add(this->pbO13);
			this->Controls->Add(this->pbO14);
			this->Controls->Add(this->pbO21);
			this->Controls->Add(this->pbO22);
			this->Controls->Add(this->pbO24);
			this->Controls->Add(this->pbO23);
			this->Controls->Add(this->pbO34);
			this->Controls->Add(this->pbO33);
			this->Controls->Add(this->pbO32);
			this->Controls->Add(this->pbO31);
			this->Controls->Add(this->pbO54);
			this->Controls->Add(this->pbO53);
			this->Controls->Add(this->pbO52);
			this->Controls->Add(this->pbO51);
			this->Controls->Add(this->pbO44);
			this->Controls->Add(this->pbO43);
			this->Controls->Add(this->pbO42);
			this->Controls->Add(this->pbO41);
			this->Controls->Add(this->pbO74);
			this->Controls->Add(this->pbO73);
			this->Controls->Add(this->pbO72);
			this->Controls->Add(this->pbO71);
			this->Controls->Add(this->pbO64);
			this->Controls->Add(this->pbO63);
			this->Controls->Add(this->pbO62);
			this->Controls->Add(this->pbO61);
			this->Controls->Add(this->pbOa4);
			this->Controls->Add(this->pbOa3);
			this->Controls->Add(this->pbOa2);
			this->Controls->Add(this->pbOa1);
			this->Controls->Add(this->pbO94);
			this->Controls->Add(this->pbO93);
			this->Controls->Add(this->pbO92);
			this->Controls->Add(this->pbO91);
			this->Controls->Add(this->pbO84);
			this->Controls->Add(this->pbO83);
			this->Controls->Add(this->pbO82);
			this->Controls->Add(this->pbO81);
			this->Controls->Add(this->pbHa4);
			this->Controls->Add(this->pbHa3);
			this->Controls->Add(this->pbHa2);
			this->Controls->Add(this->pbHa1);
			this->Controls->Add(this->pbH94);
			this->Controls->Add(this->pbH93);
			this->Controls->Add(this->pbH92);
			this->Controls->Add(this->pbH91);
			this->Controls->Add(this->pbH84);
			this->Controls->Add(this->pbH83);
			this->Controls->Add(this->pbH82);
			this->Controls->Add(this->pbH81);
			this->Controls->Add(this->pbH74);
			this->Controls->Add(this->pbH73);
			this->Controls->Add(this->pbH72);
			this->Controls->Add(this->pbH71);
			this->Controls->Add(this->pbH64);
			this->Controls->Add(this->pbH63);
			this->Controls->Add(this->pbH62);
			this->Controls->Add(this->pbH61);
			this->Controls->Add(this->pbH54);
			this->Controls->Add(this->pbH53);
			this->Controls->Add(this->pbH52);
			this->Controls->Add(this->pbH51);
			this->Controls->Add(this->pbH44);
			this->Controls->Add(this->pbH43);
			this->Controls->Add(this->pbH42);
			this->Controls->Add(this->pbH41);
			this->Controls->Add(this->pbH34);
			this->Controls->Add(this->pbH33);
			this->Controls->Add(this->pbH32);
			this->Controls->Add(this->pbH31);
			this->Controls->Add(this->pbH24);
			this->Controls->Add(this->pbH23);
			this->Controls->Add(this->pbH22);
			this->Controls->Add(this->pbH21);
			this->Controls->Add(this->pbH14);
			this->Controls->Add(this->pbH13);
			this->Controls->Add(this->pbH12);
			this->Controls->Add(this->pbH11);
			this->Controls->Add(this->pbZ4);
			this->Controls->Add(this->pbZ3);
			this->Controls->Add(this->pbZ2);
			this->Controls->Add(this->pbZ1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"WSIZ Mastermind";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_Closing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Prog_MouseDown2);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO23))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO34))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO33))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO32))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO31))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO44))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO43))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO42))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO41))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO54))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO53))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO52))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO51))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO64))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO63))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO62))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO61))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO74))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO73))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO72))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO71))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO84))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO83))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO82))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO81))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO94))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO93))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO92))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbO91))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbOa4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbOa3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbOa2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbOa1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH23))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH34))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH33))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH32))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH31))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH44))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH43))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH42))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH41))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH54))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH53))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH52))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH51))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH64))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH63))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH62))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH61))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH74))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH73))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH72))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH71))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH84))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH83))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH82))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH81))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH94))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH93))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH92))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbH91))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbHa4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbHa3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbHa2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbHa1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbArrow))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbZ1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbZ2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbZ3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbZ4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
private: System::Drawing::Color getColor(int colId) 
		{
			switch (colId)
			{
				default: return Color::Black;
				case 0: return Color::Blue;
				case 1: return Color::Green;
				case 2: return Color::Red;
				case 3: return Color::Yellow;
				case 4: return Color::Purple;
				case 5: return Color::Orange;
				case 6: return Color::LightGray;
				case 8: return Color::Black;
				case 9: return Color::White;
			}
		}
private: System::Int16 getColorId(Color colId) 
		{
			if (colId == Color::Blue) return 0;
			else if (colId == Color::Green) return 1;
			else if (colId == Color::Red) return 2;
			else if (colId == Color::Yellow) return 3;
			else if (colId == Color::Purple) return 4;
			else if (colId == Color::Orange) return 5;
			else if (colId == Color::LightGray) return 6;
			else if (colId == Color::Black) return 8;
			else if (colId == Color::White) return 9;
			else return 0;
		}
private: System::String^ getColorId(PictureBox^ pb) 
		{
			if ((Color)pb->Tag == Color::Blue) return L"PNG_BLUE";
			else if ((Color)pb->Tag == Color::Green) return L"PNG_GREEN";
			else if ((Color)pb->Tag == Color::Red) return L"PNG_RED";
			else if ((Color)pb->Tag == Color::Yellow) return L"PNG_YELLOW";
			else if ((Color)pb->Tag == Color::Purple) return L"PNG_PURPLE";
			else if ((Color)pb->Tag == Color::Orange) return L"PNG_ORANGE";
			else if ((Color)pb->Tag == Color::LightGray) return L"PNG_HOLE_L";
			else if ((Color)pb->Tag == Color::Black) return L"PNG_BLACK";
			else if ((Color)pb->Tag == Color::White) return L"PNG_WHITE";
			else return L"PNG_HOLE_L";
		}
private: System::Void pokazZadanie() {
			 pbZ1->Tag = getColor(intSzukane[0]);
			 pbZ2->Tag = getColor(intSzukane[1]);
			 pbZ3->Tag = getColor(intSzukane[2]);
			 pbZ4->Tag = getColor(intSzukane[3]);
			 System::Resources::ResourceManager^ rm = gcnew System::Resources::ResourceManager("WSIZ_Project3_Mastermind_G.WSIZ_Project3_Mastermind_G", GetType()->Assembly);
			 pbZ1->Image = safe_cast<Image^>(rm->GetObject(getColorId(pbZ1)));
			 pbZ2->Image = safe_cast<Image^>(rm->GetObject(getColorId(pbZ2)));
			 pbZ3->Image = safe_cast<Image^>(rm->GetObject(getColorId(pbZ3)));
			 pbZ4->Image = safe_cast<Image^>(rm->GetObject(getColorId(pbZ4)));
			 delete rm;
			 pbArrow->Visible = false;
		 }
private: System::String^ formatTime(time_t cT) {
			std::ostringstream strs;
			UInt32 mins, secs, msecs;
			mins = floor(cT/60);
			secs = cT-(mins*60);
			strs << (mins<=9 ? "0" : "") << mins << ":" << (secs<=9 ? "0" : "") << secs;
			std::string str = strs.str();
			return gcnew String(str.c_str());
		 }
private: System::Void Prog_MouseDown2(System::Object^  sender, System::Windows::Forms::MouseEventArgs^ e) {
			 System::Resources::ResourceManager^ rm = gcnew System::Resources::ResourceManager("WSIZ_Project3_Mastermind_G.WSIZ_Project3_Mastermind_G", GetType()->Assembly);
			 if(e->Button == System::Windows::Forms::MouseButtons::Right) {
				 // pobieramy dane
				 Int16 intTmp[4] = { getColorId((Color)pbArrO[intProba-1,0]->Tag),getColorId((Color)pbArrO[intProba-1,1]->Tag),getColorId((Color)pbArrO[intProba-1,2]->Tag),getColorId((Color)pbArrO[intProba-1,3]->Tag)};
				 // sprawdzamy, czy mamy trafione na pozycji
				 int np = 0;
				 for (int i=0; i < 4; i++)
					 if (intTmp[i] == intSzukane[i]) {
						 np++;
						 intTmp[i]=-1;
					 }
				 Boolean odgadnieto = (np == 4);
				 // sprawdzamy, czy mamy trafione w złym miejscu
				 int nz = 0;
				 for (int i=0; i < 4; i++)
					 for (int j=0; j<4; j++)
						 if (intTmp[j] == intSzukane[i] && intTmp[i] != -1) {
							 nz++;
							 intTmp[j]=-2;
							 break;
						 }
				 // ustawiamy podpowiedź
				 for (int i=0; i < 4; i++)
					 if (np>0) {
						 np--;
						 pbArrH[intProba-1,i]->Tag = getColor(8);
						 pbArrH[intProba-1,i]->Image = safe_cast<Image^>(rm->GetObject(getColorId(pbArrH[intProba-1,i])));
					 } else if (nz>0) {
						 nz--;
						 pbArrH[intProba-1,i]->Tag = getColor(9);
						 pbArrH[intProba-1,i]->Image = safe_cast<Image^>(rm->GetObject(getColorId(pbArrH[intProba-1,i])));
					 } 
				if (!odgadnieto)
				{
					if (intProba == 10) 
					{
						// nie udalo sie
						int tmp = rand()%2+1;
						std::string start = "Sounds\\gameover", result, end = ".wav";
						char numstr[1];
						result = start + itoa(tmp, numstr, 10) + ".wav";
						PlaySoundA((LPCSTR)result.c_str(), NULL, SND_FILENAME | SND_ASYNC);
						gameInProgress = false;
						pokazZadanie();
						delete rm;
						return;
					} else {
						int tmp = rand()%9+1;
						std::string start = "Sounds\\work", result, end = ".wav";
						char numstr[1];
						result = start + itoa(tmp, numstr, 10) + ".wav";
						PlaySoundA((LPCSTR)result.c_str(), NULL, SND_FILENAME | SND_ASYNC);
						pbArrow->Top += 25;
					}
					intProba++;
					lblTop->Text = formatTime(topScore[intProba]);
					delete rm;
					return;
				} 
				// odgadnieto :)
				if (cTime < topScore[intProba] || topScore[intProba] == 0)  topScore[intProba] = cTime; // top w próbie
				if (cTime < topScore[0] || topScore[0] == 0)  topScore[0] = cTime; // top of the top :)
				
				int tmp = rand()%7+1;
				std::string start = "Sounds\\ok", result, end = ".wav";
				char numstr[1];
				result = start + itoa(tmp, numstr, 10) + ".wav";
				PlaySoundA((LPCSTR)result.c_str(), NULL, SND_FILENAME | SND_ASYNC);
				pokazZadanie();
				gameInProgress = false;
				timer1->Enabled = false;
			 }
			 delete rm;

		 }
private: System::Void game_Start() {
			 // losujemy kolory
			 // 0 - niebieski, 1 - zielony, 2 - czerowny, 3 - zółty, 4 - fioletowy, 5 - pomarańczowy
			 System::Resources::ResourceManager^ rm = gcnew System::Resources::ResourceManager("WSIZ_Project3_Mastermind_G.WSIZ_Project3_Mastermind_G", GetType()->Assembly);
			 for (int i= 0; i<10;i++)
			 {
				 for(int j=0; j<4; j++)
				 {
					 pbArrO[i,j]->Image = safe_cast<Image^>(rm->GetObject(L"PNG_HOLE_L"));
					 pbArrO[i,j]->Tag = Color::LightGray;
					 pbArrH[i,j]->Image = safe_cast<Image^>(rm->GetObject(L"PNG_HOLE_S"));
					 pbArrH[i,j]->Tag = Color::LightGray;
				 }
			 }
			 
			 intSzukane[0] = (rand()%6);
			 intSzukane[1] = (rand()%6);
			 intSzukane[2] = (rand()%6);
			 intSzukane[3] = (rand()%6);

			 intProba = 1;
			 pbArrow->Visible = true;
			 pbArrow->Top = 162;

			 pbZ1->Image = safe_cast<Image^>(rm->GetObject(L"PNG_UNKNOWN"));
			 pbZ2->Image = safe_cast<Image^>(rm->GetObject(L"PNG_UNKNOWN"));
			 pbZ3->Image = safe_cast<Image^>(rm->GetObject(L"PNG_UNKNOWN"));
			 pbZ4->Image = safe_cast<Image^>(rm->GetObject(L"PNG_UNKNOWN"));

			 gameInProgress = true;
			 sTime = time(NULL);
			 timer1->Enabled = true;
			 lblTop->Text = formatTime(topScore[intProba]);
			 delete rm;
		 }

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			// wczytaj najlepsze wyniki
			 System::Resources::ResourceManager^ rm = gcnew System::Resources::ResourceManager("WSIZ_Project3_Mastermind_G.WSIZ_Project3_Mastermind_G", GetType()->Assembly);
			 this->BackgroundImage = safe_cast<Image^>(rm->GetObject(L"PNG_BOARD"));
			 pbArrow->Image = safe_cast<Image^>(rm->GetObject(L"PNG_ARROW"));
			fstream myFile;
			myFile.open("HighScore.dat", fstream::in );
			string strT0,strT1;
			if(!myFile.fail())
			{
				getline(myFile,strT0);
				if (strT0 == "[High Score]") 
				{
					getline(myFile,strT0);
					getline(myFile,strT1);
					int a = atoi(strT0.c_str());
					int b = atoi(strT1.c_str()) ^ MAGIC_NUMBER;
					if (a == b)
						topScore[0] = atoi(strT0.c_str());
				}
				
				for (int i=1; i <= 10; i++)
				{
					std::ostringstream strs;
					strs << "[p" << i << "]";
					std::string str = strs.str();
					getline(myFile,strT0);
					if (strT0==str)
					{
						getline(myFile,strT0);
						getline(myFile,strT1);
						int a = atoi(strT0.c_str());
						int b = atoi(strT1.c_str()) ^ MAGIC_NUMBER;
						if (a == b)
							topScore[i] = atoi(strT0.c_str());
					}
				}
				myFile.close();
			}
			 
			 // start
			 srand(time(NULL));

			 game_Start();
			 delete rm;
			 

		 }
private: System::Void MyForm_Closing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			// zapisz najlepszy wynik
			ofstream myFile;
			myFile.open("Highscore.dat");

			if(!myFile.fail())
			{
				myFile << "[High Score]\n" << topScore[0] << "\n" << (topScore[0] ^ MAGIC_NUMBER) << "\n";
				for(int i=1; i<=10;i++)
					myFile << "[p" << i << "]\n" << topScore[i] << "\n" << (topScore[i] ^ MAGIC_NUMBER) << "\n";
				myFile.close();
			}
		 }
private: System::Void IndexOf(Array^ matrix, Object^ element, int% row, int% column)
	{
		row = column = -1;

		for (int i=matrix->GetLowerBound(0); i <= matrix->GetUpperBound(0); ++i)
			for (int j=matrix->GetLowerBound(1); j <= matrix->GetUpperBound(1); ++j)
				if (Object::ReferenceEquals(matrix->GetValue(i, j), element))
				{
					row = i;
					column = j;
					return;
				}
	}
private: System::Void PictureBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^ e) {
			if(e->Button == System::Windows::Forms::MouseButtons::Left && gameInProgress)
			{
				System::Resources::ResourceManager^ rm = gcnew System::Resources::ResourceManager("WSIZ_Project3_Mastermind_G.WSIZ_Project3_Mastermind_G", GetType()->Assembly);
				String^ buttonName = safe_cast<PictureBox^>(sender)->Name;
				int row = 0, column = 0;
				IndexOf(pbArrO, sender, row, column);
				Int16 col = getColorId((Color)pbArrO[row,column]->Tag);
				if (row+1 == intProba)
				{
					pbArrO[row,column]->Tag = getColor(col==6 ? 0 : col+1);
					pbArrO[row,column]->Image = safe_cast<Image^>(rm->GetObject(getColorId(pbArrO[row,column])));
				}
				delete rm;
			} else if(e->Button == System::Windows::Forms::MouseButtons::Right) Prog_MouseDown2 (sender, e);
		 }

private: System::Void zakończProgramToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
		 }
private: System::Void nowaGraToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 game_Start();
		 }
private: System::Void oProgramieToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			frmAbout^ frm = gcnew frmAbout(this);
			frm->Show();
			this->Enabled = false;
		 }
private: System::Void instrukcjaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			frmInstrukcja^ frm = gcnew frmInstrukcja(this);
			frm->Show();
			this->Enabled = false;
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if (!gameInProgress) return;
			cTime = time(NULL)-sTime;
			lblTimer->Text = formatTime(cTime);
		 }
};
}
