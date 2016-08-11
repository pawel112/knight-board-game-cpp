#pragma once

#include "stdafx.h"
#include "rules.h"
#include "author.h"
#include <cstdlib>

namespace knight {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for chessboard
	/// </summary>

	public ref class chessboard : public System::Windows::Forms::Form
	{
	public:
		chessboard(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			game_started = false;
			initial_field_movement = 0;
			moving_back_from_the_field = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~chessboard()
		{
			if (components)
			{
				delete components;
			}
		}
	public: static int									 initial_field_movement;
	public: static int									 moving_back_from_the_field;
	public: static bool									 game_started;
	private: System::Windows::Forms::MenuStrip^			 menu;
	private: System::Windows::Forms::ToolStripMenuItem^  gameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newGameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  koniecGryToolStripMenuItem;
	private: System::Windows::Forms::TableLayoutPanel^   tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^   tableLayoutPanel2;
	public: static System::Windows::Forms::Label^		 message_box;
	public: static System::Windows::Forms::PictureBox^   pictureBox64;
	public: static System::Windows::Forms::PictureBox^   pictureBox63;
	public: static System::Windows::Forms::PictureBox^   pictureBox62;
	public: static System::Windows::Forms::PictureBox^   pictureBox61;
	public: static System::Windows::Forms::PictureBox^   pictureBox60;
	public: static System::Windows::Forms::PictureBox^   pictureBox59;
	public: static System::Windows::Forms::PictureBox^   pictureBox58;
	public: static System::Windows::Forms::PictureBox^   pictureBox57;
	public: static System::Windows::Forms::PictureBox^   pictureBox56;
	public: static System::Windows::Forms::PictureBox^   pictureBox55;
	public: static System::Windows::Forms::PictureBox^   pictureBox54;
	public: static System::Windows::Forms::PictureBox^   pictureBox53;
	public: static System::Windows::Forms::PictureBox^   pictureBox52;
	public: static System::Windows::Forms::PictureBox^   pictureBox51;
	public: static System::Windows::Forms::PictureBox^   pictureBox50;
	public: static System::Windows::Forms::PictureBox^   pictureBox49;
	public: static System::Windows::Forms::PictureBox^   pictureBox48;
	public: static System::Windows::Forms::PictureBox^   pictureBox47;
	public: static System::Windows::Forms::PictureBox^   pictureBox46;
	public: static System::Windows::Forms::PictureBox^   pictureBox45;
	public: static System::Windows::Forms::PictureBox^   pictureBox44;
	public: static System::Windows::Forms::PictureBox^   pictureBox43;
	public: static System::Windows::Forms::PictureBox^   pictureBox42;
	public: static System::Windows::Forms::PictureBox^   pictureBox41;
	public: static System::Windows::Forms::PictureBox^   pictureBox40;
	public: static System::Windows::Forms::PictureBox^   pictureBox39;
	public: static System::Windows::Forms::PictureBox^   pictureBox38;
	public: static System::Windows::Forms::PictureBox^   pictureBox37;
	public: static System::Windows::Forms::PictureBox^   pictureBox36;
	public: static System::Windows::Forms::PictureBox^   pictureBox35;
	public: static System::Windows::Forms::PictureBox^   pictureBox34;
	public: static System::Windows::Forms::PictureBox^   pictureBox33;
	public: static System::Windows::Forms::PictureBox^   pictureBox32;
	public: static System::Windows::Forms::PictureBox^   pictureBox31;
	public: static System::Windows::Forms::PictureBox^   pictureBox30;
	public: static System::Windows::Forms::PictureBox^   pictureBox29;
	public: static System::Windows::Forms::PictureBox^   pictureBox28;
	public: static System::Windows::Forms::PictureBox^   pictureBox27;
	public: static System::Windows::Forms::PictureBox^   pictureBox26;
	public: static System::Windows::Forms::PictureBox^   pictureBox25;
	public: static System::Windows::Forms::PictureBox^   pictureBox24;
	public: static System::Windows::Forms::PictureBox^   pictureBox23;
	public: static System::Windows::Forms::PictureBox^   pictureBox22;
	public: static System::Windows::Forms::PictureBox^   pictureBox21;
	public: static System::Windows::Forms::PictureBox^   pictureBox20;
	public: static System::Windows::Forms::PictureBox^   pictureBox19;
	public: static System::Windows::Forms::PictureBox^   pictureBox18;
	public: static System::Windows::Forms::PictureBox^   pictureBox17;
	public: static System::Windows::Forms::PictureBox^   pictureBox16;
	public: static System::Windows::Forms::PictureBox^   pictureBox15;
	public: static System::Windows::Forms::PictureBox^   pictureBox14;
	public: static System::Windows::Forms::PictureBox^   pictureBox13;
	public: static System::Windows::Forms::PictureBox^   pictureBox12;
	public: static System::Windows::Forms::PictureBox^   pictureBox11;
	public: static System::Windows::Forms::PictureBox^   pictureBox10;
	public: static System::Windows::Forms::PictureBox^   pictureBox9;
	public: static System::Windows::Forms::PictureBox^   pictureBox8;
	public: static System::Windows::Forms::PictureBox^   pictureBox7;
	public: static System::Windows::Forms::PictureBox^   pictureBox6;
	public: static System::Windows::Forms::PictureBox^   pictureBox5;
	public: static System::Windows::Forms::PictureBox^   pictureBox4;
	public: static System::Windows::Forms::PictureBox^   pictureBox3;
	public: static System::Windows::Forms::PictureBox^   pictureBox2;
	public: static System::Windows::Forms::PictureBox^   pictureBox1;
	public: static System::Windows::Forms::Label^		 player_1_score;
	public: static System::Windows::Forms::Label^		 player_2_score;
	public: static System::Windows::Forms::Button^		 end_of_movement;
	public: static System::Windows::Forms::Label^		 which_player_field;
	public: static System::Windows::Forms::Label^		 field_with_the_computer_movement;
	public: static System::Windows::Forms::Label^		 label2;
	public: static System::Windows::Forms::Label^		 label1;
	private: System::Windows::Forms::ToolStripMenuItem^  gameWithHumanToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gameWithComputerToolStripMenuItem;
	private: System::Windows::Forms::Label^				 label3;
	private: System::Windows::Forms::Label^				 label4;
	private: System::Windows::Forms::Label^ 			 label5;
	private: System::Windows::Forms::Label^ 			 label6;
	private: System::Windows::Forms::Label^ 			 label7;
	private: System::Windows::Forms::Label^ 			 label8;
	private: System::Windows::Forms::Label^ 			 label9;
	private: System::Windows::Forms::Label^ 			 label10;
	private: System::Windows::Forms::Label^ 			 label11;
	private: System::Windows::Forms::Label^ 			 label12;
	private: System::Windows::Forms::Label^ 			 label13;
	private: System::Windows::Forms::Label^ 			 label14;
	private: System::Windows::Forms::Label^ 			 label15;
	private: System::Windows::Forms::Label^ 			 label16;
	private: System::Windows::Forms::Label^ 			 label17;
	private: System::Windows::Forms::Label^ 			 label18;
	private: System::Windows::Forms::ToolStripMenuItem^  gameRulesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  authorToolStripMenuItem;
	private: System::ComponentModel::IContainer^		 components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(chessboard::typeid));
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->gameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gameWithHumanToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gameWithComputerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->koniecGryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gameRulesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->authorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->pictureBox64 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox63 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox62 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox61 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox60 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox59 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox58 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox57 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox56 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox55 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox54 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox53 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox52 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox51 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox50 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox49 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox48 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox47 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox46 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox45 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox44 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox43 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox42 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox41 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox40 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox39 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox38 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox37 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox36 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox35 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox34 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox33 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox32 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox31 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox30 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox29 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox28 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox27 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox26 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox25 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox24 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox23 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox22 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox21 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox20 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox19 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox18 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox17 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->player_2_score = (gcnew System::Windows::Forms::Label());
			this->player_1_score = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->message_box = (gcnew System::Windows::Forms::Label());
			this->end_of_movement = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->which_player_field = (gcnew System::Windows::Forms::Label());
			this->field_with_the_computer_movement = (gcnew System::Windows::Forms::Label());
			this->menu->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox64))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox63))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox62))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox61))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox60))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox59))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox58))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox57))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox56))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox55))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox54))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox53))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox52))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox51))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox50))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox49))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox48))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox47))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox46))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox45))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox44))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox43))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox42))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox41))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox40))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox39))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox38))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox37))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox36))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox35))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox34))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox33))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox32))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox31))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox30))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox29))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox28))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox27))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox26))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox25))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox23))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menu
			// 
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->gameToolStripMenuItem,
					this->gameRulesToolStripMenuItem, this->authorToolStripMenuItem
			});
			this->menu->Location = System::Drawing::Point(0, 0);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(642, 24);
			this->menu->TabIndex = 0;
			this->menu->Text = L"menuStrip1";
			// 
			// gameToolStripMenuItem
			// 
			this->gameToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->newGameToolStripMenuItem,
					this->koniecGryToolStripMenuItem
			});
			this->gameToolStripMenuItem->Name = L"gameToolStripMenuItem";
			this->gameToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->gameToolStripMenuItem->Text = L"Game";
			// 
			// newGameToolStripMenuItem
			// 
			this->newGameToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->gameWithHumanToolStripMenuItem,
					this->gameWithComputerToolStripMenuItem
			});
			this->newGameToolStripMenuItem->Name = L"newGameToolStripMenuItem";
			this->newGameToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->newGameToolStripMenuItem->Text = L"New game";
			this->newGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &chessboard::newGameToolStripMenuItem_Click);
			// 
			// gameWithHumanToolStripMenuItem
			// 
			this->gameWithHumanToolStripMenuItem->Name = L"gameWithHumanToolStripMenuItem";
			this->gameWithHumanToolStripMenuItem->Size = System::Drawing::Size(194, 22);
			this->gameWithHumanToolStripMenuItem->Text = L"Playing with human";
			this->gameWithHumanToolStripMenuItem->Click += gcnew System::EventHandler(this, &chessboard::gameWithHumanToolStripMenuItem_Click);
			// 
			// gameWithComputerToolStripMenuItem
			// 
			this->gameWithComputerToolStripMenuItem->Name = L"gameWithComputerToolStripMenuItem";
			this->gameWithComputerToolStripMenuItem->Size = System::Drawing::Size(194, 22);
			this->gameWithComputerToolStripMenuItem->Text = L"Playing with computer";
			this->gameWithComputerToolStripMenuItem->Click += gcnew System::EventHandler(this, &chessboard::gameWithComputerToolStripMenuItem_Click);
			// 
			// koniecGryToolStripMenuItem
			// 
			this->koniecGryToolStripMenuItem->Name = L"koniecGryToolStripMenuItem";
			this->koniecGryToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->koniecGryToolStripMenuItem->Text = L"End of the game";
			this->koniecGryToolStripMenuItem->Click += gcnew System::EventHandler(this, &chessboard::koniecGryToolStripMenuItem_Click);
			// 
			// gameRulesToolStripMenuItem
			// 
			this->gameRulesToolStripMenuItem->Name = L"gameRulesToolStripMenuItem";
			this->gameRulesToolStripMenuItem->Size = System::Drawing::Size(78, 20);
			this->gameRulesToolStripMenuItem->Text = L"Game rules";
			this->gameRulesToolStripMenuItem->Click += gcnew System::EventHandler(this, &chessboard::gameRulesToolStripMenuItem_Click);
			// 
			// authorToolStripMenuItem
			// 
			this->authorToolStripMenuItem->Name = L"authorToolStripMenuItem";
			this->authorToolStripMenuItem->Size = System::Drawing::Size(101, 20);
			this->authorToolStripMenuItem->Text = L"About program";
			this->authorToolStripMenuItem->Click += gcnew System::EventHandler(this, &chessboard::authorToolStripMenuItem_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 8;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->Controls->Add(this->pictureBox64, 7, 7);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox63, 6, 7);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox62, 5, 7);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox61, 4, 7);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox60, 3, 7);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox59, 2, 7);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox58, 1, 7);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox57, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox56, 7, 6);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox55, 6, 6);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox54, 5, 6);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox53, 4, 6);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox52, 3, 6);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox51, 2, 6);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox50, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox49, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox48, 7, 5);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox47, 6, 5);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox46, 5, 5);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox45, 4, 5);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox44, 3, 5);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox43, 2, 5);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox42, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox41, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox40, 7, 4);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox39, 6, 4);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox38, 5, 4);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox37, 4, 4);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox36, 3, 4);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox35, 2, 4);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox34, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox33, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox32, 7, 3);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox31, 6, 3);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox30, 5, 3);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox29, 4, 3);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox28, 3, 3);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox27, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox26, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox25, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox24, 7, 2);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox23, 6, 2);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox22, 5, 2);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox21, 4, 2);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox20, 3, 2);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox19, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox18, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox17, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox16, 7, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox15, 6, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox14, 5, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox13, 4, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox12, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox11, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox10, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox9, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox8, 7, 0);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox7, 6, 0);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox6, 5, 0);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox5, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox4, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox3, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox1, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(20, 54);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 8;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(280, 280);
			this->tableLayoutPanel1->TabIndex = 1;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &chessboard::tableLayoutPanel1_Paint);
			// 
			// pictureBox64
			// 
			this->pictureBox64->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox64.Image")));
			this->pictureBox64->Location = System::Drawing::Point(248, 248);
			this->pictureBox64->Name = L"pictureBox64";
			this->pictureBox64->Size = System::Drawing::Size(29, 29);
			this->pictureBox64->TabIndex = 63;
			this->pictureBox64->TabStop = false;
			this->pictureBox64->Click += gcnew System::EventHandler(this, &chessboard::pictureBox64_Click);
			// 
			// pictureBox63
			// 
			this->pictureBox63->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox63.Image")));
			this->pictureBox63->Location = System::Drawing::Point(213, 248);
			this->pictureBox63->Name = L"pictureBox63";
			this->pictureBox63->Size = System::Drawing::Size(29, 29);
			this->pictureBox63->TabIndex = 62;
			this->pictureBox63->TabStop = false;
			this->pictureBox63->Click += gcnew System::EventHandler(this, &chessboard::pictureBox63_Click);
			// 
			// pictureBox62
			// 
			this->pictureBox62->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox62.Image")));
			this->pictureBox62->Location = System::Drawing::Point(178, 248);
			this->pictureBox62->Name = L"pictureBox62";
			this->pictureBox62->Size = System::Drawing::Size(29, 29);
			this->pictureBox62->TabIndex = 61;
			this->pictureBox62->TabStop = false;
			this->pictureBox62->Click += gcnew System::EventHandler(this, &chessboard::pictureBox62_Click);
			// 
			// pictureBox61
			// 
			this->pictureBox61->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox61.Image")));
			this->pictureBox61->Location = System::Drawing::Point(143, 248);
			this->pictureBox61->Name = L"pictureBox61";
			this->pictureBox61->Size = System::Drawing::Size(29, 29);
			this->pictureBox61->TabIndex = 60;
			this->pictureBox61->TabStop = false;
			this->pictureBox61->Click += gcnew System::EventHandler(this, &chessboard::pictureBox61_Click);
			// 
			// pictureBox60
			// 
			this->pictureBox60->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox60.Image")));
			this->pictureBox60->Location = System::Drawing::Point(108, 248);
			this->pictureBox60->Name = L"pictureBox60";
			this->pictureBox60->Size = System::Drawing::Size(29, 29);
			this->pictureBox60->TabIndex = 59;
			this->pictureBox60->TabStop = false;
			this->pictureBox60->Click += gcnew System::EventHandler(this, &chessboard::pictureBox60_Click);
			// 
			// pictureBox59
			// 
			this->pictureBox59->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox59.Image")));
			this->pictureBox59->Location = System::Drawing::Point(73, 248);
			this->pictureBox59->Name = L"pictureBox59";
			this->pictureBox59->Size = System::Drawing::Size(29, 29);
			this->pictureBox59->TabIndex = 58;
			this->pictureBox59->TabStop = false;
			this->pictureBox59->Click += gcnew System::EventHandler(this, &chessboard::pictureBox59_Click);
			// 
			// pictureBox58
			// 
			this->pictureBox58->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox58.Image")));
			this->pictureBox58->Location = System::Drawing::Point(38, 248);
			this->pictureBox58->Name = L"pictureBox58";
			this->pictureBox58->Size = System::Drawing::Size(29, 29);
			this->pictureBox58->TabIndex = 57;
			this->pictureBox58->TabStop = false;
			this->pictureBox58->Click += gcnew System::EventHandler(this, &chessboard::pictureBox58_Click);
			// 
			// pictureBox57
			// 
			this->pictureBox57->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox57.Image")));
			this->pictureBox57->Location = System::Drawing::Point(3, 248);
			this->pictureBox57->Name = L"pictureBox57";
			this->pictureBox57->Size = System::Drawing::Size(29, 29);
			this->pictureBox57->TabIndex = 56;
			this->pictureBox57->TabStop = false;
			this->pictureBox57->Click += gcnew System::EventHandler(this, &chessboard::pictureBox57_Click);
			// 
			// pictureBox56
			// 
			this->pictureBox56->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox56.Image")));
			this->pictureBox56->Location = System::Drawing::Point(248, 213);
			this->pictureBox56->Name = L"pictureBox56";
			this->pictureBox56->Size = System::Drawing::Size(29, 29);
			this->pictureBox56->TabIndex = 55;
			this->pictureBox56->TabStop = false;
			this->pictureBox56->Click += gcnew System::EventHandler(this, &chessboard::pictureBox56_Click);
			// 
			// pictureBox55
			// 
			this->pictureBox55->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox55.Image")));
			this->pictureBox55->Location = System::Drawing::Point(213, 213);
			this->pictureBox55->Name = L"pictureBox55";
			this->pictureBox55->Size = System::Drawing::Size(29, 29);
			this->pictureBox55->TabIndex = 54;
			this->pictureBox55->TabStop = false;
			this->pictureBox55->Click += gcnew System::EventHandler(this, &chessboard::pictureBox55_Click);
			// 
			// pictureBox54
			// 
			this->pictureBox54->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox54.Image")));
			this->pictureBox54->Location = System::Drawing::Point(178, 213);
			this->pictureBox54->Name = L"pictureBox54";
			this->pictureBox54->Size = System::Drawing::Size(29, 29);
			this->pictureBox54->TabIndex = 53;
			this->pictureBox54->TabStop = false;
			this->pictureBox54->Click += gcnew System::EventHandler(this, &chessboard::pictureBox54_Click);
			// 
			// pictureBox53
			// 
			this->pictureBox53->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox53.Image")));
			this->pictureBox53->Location = System::Drawing::Point(143, 213);
			this->pictureBox53->Name = L"pictureBox53";
			this->pictureBox53->Size = System::Drawing::Size(29, 29);
			this->pictureBox53->TabIndex = 52;
			this->pictureBox53->TabStop = false;
			this->pictureBox53->Click += gcnew System::EventHandler(this, &chessboard::pictureBox53_Click);
			// 
			// pictureBox52
			// 
			this->pictureBox52->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox52.Image")));
			this->pictureBox52->Location = System::Drawing::Point(108, 213);
			this->pictureBox52->Name = L"pictureBox52";
			this->pictureBox52->Size = System::Drawing::Size(29, 29);
			this->pictureBox52->TabIndex = 51;
			this->pictureBox52->TabStop = false;
			this->pictureBox52->Click += gcnew System::EventHandler(this, &chessboard::pictureBox52_Click);
			// 
			// pictureBox51
			// 
			this->pictureBox51->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox51.Image")));
			this->pictureBox51->Location = System::Drawing::Point(73, 213);
			this->pictureBox51->Name = L"pictureBox51";
			this->pictureBox51->Size = System::Drawing::Size(29, 29);
			this->pictureBox51->TabIndex = 50;
			this->pictureBox51->TabStop = false;
			this->pictureBox51->Click += gcnew System::EventHandler(this, &chessboard::pictureBox51_Click);
			// 
			// pictureBox50
			// 
			this->pictureBox50->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox50.Image")));
			this->pictureBox50->Location = System::Drawing::Point(38, 213);
			this->pictureBox50->Name = L"pictureBox50";
			this->pictureBox50->Size = System::Drawing::Size(29, 29);
			this->pictureBox50->TabIndex = 49;
			this->pictureBox50->TabStop = false;
			this->pictureBox50->Click += gcnew System::EventHandler(this, &chessboard::pictureBox50_Click);
			// 
			// pictureBox49
			// 
			this->pictureBox49->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox49.Image")));
			this->pictureBox49->Location = System::Drawing::Point(3, 213);
			this->pictureBox49->Name = L"pictureBox49";
			this->pictureBox49->Size = System::Drawing::Size(29, 29);
			this->pictureBox49->TabIndex = 48;
			this->pictureBox49->TabStop = false;
			this->pictureBox49->Click += gcnew System::EventHandler(this, &chessboard::pictureBox49_Click);
			// 
			// pictureBox48
			// 
			this->pictureBox48->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox48.Image")));
			this->pictureBox48->Location = System::Drawing::Point(248, 178);
			this->pictureBox48->Name = L"pictureBox48";
			this->pictureBox48->Size = System::Drawing::Size(29, 29);
			this->pictureBox48->TabIndex = 47;
			this->pictureBox48->TabStop = false;
			this->pictureBox48->Click += gcnew System::EventHandler(this, &chessboard::pictureBox48_Click);
			// 
			// pictureBox47
			// 
			this->pictureBox47->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox47.Image")));
			this->pictureBox47->Location = System::Drawing::Point(213, 178);
			this->pictureBox47->Name = L"pictureBox47";
			this->pictureBox47->Size = System::Drawing::Size(29, 29);
			this->pictureBox47->TabIndex = 46;
			this->pictureBox47->TabStop = false;
			this->pictureBox47->Click += gcnew System::EventHandler(this, &chessboard::pictureBox47_Click);
			// 
			// pictureBox46
			// 
			this->pictureBox46->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox46.Image")));
			this->pictureBox46->Location = System::Drawing::Point(178, 178);
			this->pictureBox46->Name = L"pictureBox46";
			this->pictureBox46->Size = System::Drawing::Size(29, 29);
			this->pictureBox46->TabIndex = 45;
			this->pictureBox46->TabStop = false;
			this->pictureBox46->Click += gcnew System::EventHandler(this, &chessboard::pictureBox46_Click);
			// 
			// pictureBox45
			// 
			this->pictureBox45->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox45.Image")));
			this->pictureBox45->Location = System::Drawing::Point(143, 178);
			this->pictureBox45->Name = L"pictureBox45";
			this->pictureBox45->Size = System::Drawing::Size(29, 29);
			this->pictureBox45->TabIndex = 44;
			this->pictureBox45->TabStop = false;
			this->pictureBox45->Click += gcnew System::EventHandler(this, &chessboard::pictureBox45_Click);
			// 
			// pictureBox44
			// 
			this->pictureBox44->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox44.Image")));
			this->pictureBox44->Location = System::Drawing::Point(108, 178);
			this->pictureBox44->Name = L"pictureBox44";
			this->pictureBox44->Size = System::Drawing::Size(29, 29);
			this->pictureBox44->TabIndex = 43;
			this->pictureBox44->TabStop = false;
			this->pictureBox44->Click += gcnew System::EventHandler(this, &chessboard::pictureBox44_Click);
			// 
			// pictureBox43
			// 
			this->pictureBox43->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox43.Image")));
			this->pictureBox43->Location = System::Drawing::Point(73, 178);
			this->pictureBox43->Name = L"pictureBox43";
			this->pictureBox43->Size = System::Drawing::Size(29, 29);
			this->pictureBox43->TabIndex = 42;
			this->pictureBox43->TabStop = false;
			this->pictureBox43->Click += gcnew System::EventHandler(this, &chessboard::pictureBox43_Click);
			// 
			// pictureBox42
			// 
			this->pictureBox42->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox42.Image")));
			this->pictureBox42->Location = System::Drawing::Point(38, 178);
			this->pictureBox42->Name = L"pictureBox42";
			this->pictureBox42->Size = System::Drawing::Size(29, 29);
			this->pictureBox42->TabIndex = 41;
			this->pictureBox42->TabStop = false;
			this->pictureBox42->Click += gcnew System::EventHandler(this, &chessboard::pictureBox42_Click);
			// 
			// pictureBox41
			// 
			this->pictureBox41->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox41.Image")));
			this->pictureBox41->Location = System::Drawing::Point(3, 178);
			this->pictureBox41->Name = L"pictureBox41";
			this->pictureBox41->Size = System::Drawing::Size(29, 29);
			this->pictureBox41->TabIndex = 40;
			this->pictureBox41->TabStop = false;
			this->pictureBox41->Click += gcnew System::EventHandler(this, &chessboard::pictureBox41_Click_1);
			// 
			// pictureBox40
			// 
			this->pictureBox40->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox40.Image")));
			this->pictureBox40->Location = System::Drawing::Point(248, 143);
			this->pictureBox40->Name = L"pictureBox40";
			this->pictureBox40->Size = System::Drawing::Size(29, 29);
			this->pictureBox40->TabIndex = 39;
			this->pictureBox40->TabStop = false;
			this->pictureBox40->Click += gcnew System::EventHandler(this, &chessboard::pictureBox40_Click);
			// 
			// pictureBox39
			// 
			this->pictureBox39->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox39.Image")));
			this->pictureBox39->Location = System::Drawing::Point(213, 143);
			this->pictureBox39->Name = L"pictureBox39";
			this->pictureBox39->Size = System::Drawing::Size(29, 29);
			this->pictureBox39->TabIndex = 38;
			this->pictureBox39->TabStop = false;
			this->pictureBox39->Click += gcnew System::EventHandler(this, &chessboard::pictureBox39_Click);
			// 
			// pictureBox38
			// 
			this->pictureBox38->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox38.Image")));
			this->pictureBox38->Location = System::Drawing::Point(178, 143);
			this->pictureBox38->Name = L"pictureBox38";
			this->pictureBox38->Size = System::Drawing::Size(29, 29);
			this->pictureBox38->TabIndex = 37;
			this->pictureBox38->TabStop = false;
			this->pictureBox38->Click += gcnew System::EventHandler(this, &chessboard::pictureBox38_Click);
			// 
			// pictureBox37
			// 
			this->pictureBox37->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox37.Image")));
			this->pictureBox37->Location = System::Drawing::Point(143, 143);
			this->pictureBox37->Name = L"pictureBox37";
			this->pictureBox37->Size = System::Drawing::Size(29, 29);
			this->pictureBox37->TabIndex = 36;
			this->pictureBox37->TabStop = false;
			this->pictureBox37->Click += gcnew System::EventHandler(this, &chessboard::pictureBox37_Click);
			// 
			// pictureBox36
			// 
			this->pictureBox36->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox36.Image")));
			this->pictureBox36->Location = System::Drawing::Point(108, 143);
			this->pictureBox36->Name = L"pictureBox36";
			this->pictureBox36->Size = System::Drawing::Size(29, 29);
			this->pictureBox36->TabIndex = 35;
			this->pictureBox36->TabStop = false;
			this->pictureBox36->Click += gcnew System::EventHandler(this, &chessboard::pictureBox36_Click);
			// 
			// pictureBox35
			// 
			this->pictureBox35->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox35.Image")));
			this->pictureBox35->Location = System::Drawing::Point(73, 143);
			this->pictureBox35->Name = L"pictureBox35";
			this->pictureBox35->Size = System::Drawing::Size(29, 29);
			this->pictureBox35->TabIndex = 34;
			this->pictureBox35->TabStop = false;
			this->pictureBox35->Click += gcnew System::EventHandler(this, &chessboard::pictureBox35_Click);
			// 
			// pictureBox34
			// 
			this->pictureBox34->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox34.Image")));
			this->pictureBox34->Location = System::Drawing::Point(38, 143);
			this->pictureBox34->Name = L"pictureBox34";
			this->pictureBox34->Size = System::Drawing::Size(29, 29);
			this->pictureBox34->TabIndex = 33;
			this->pictureBox34->TabStop = false;
			this->pictureBox34->Click += gcnew System::EventHandler(this, &chessboard::pictureBox34_Click);
			// 
			// pictureBox33
			// 
			this->pictureBox33->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox33.Image")));
			this->pictureBox33->Location = System::Drawing::Point(3, 143);
			this->pictureBox33->Name = L"pictureBox33";
			this->pictureBox33->Size = System::Drawing::Size(29, 29);
			this->pictureBox33->TabIndex = 32;
			this->pictureBox33->TabStop = false;
			this->pictureBox33->Click += gcnew System::EventHandler(this, &chessboard::pictureBox33_Click);
			// 
			// pictureBox32
			// 
			this->pictureBox32->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox32.Image")));
			this->pictureBox32->Location = System::Drawing::Point(248, 108);
			this->pictureBox32->Name = L"pictureBox32";
			this->pictureBox32->Size = System::Drawing::Size(29, 29);
			this->pictureBox32->TabIndex = 31;
			this->pictureBox32->TabStop = false;
			this->pictureBox32->Click += gcnew System::EventHandler(this, &chessboard::pictureBox32_Click);
			// 
			// pictureBox31
			// 
			this->pictureBox31->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox31.Image")));
			this->pictureBox31->Location = System::Drawing::Point(213, 108);
			this->pictureBox31->Name = L"pictureBox31";
			this->pictureBox31->Size = System::Drawing::Size(29, 29);
			this->pictureBox31->TabIndex = 30;
			this->pictureBox31->TabStop = false;
			this->pictureBox31->Click += gcnew System::EventHandler(this, &chessboard::pictureBox31_Click);
			// 
			// pictureBox30
			// 
			this->pictureBox30->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox30.Image")));
			this->pictureBox30->Location = System::Drawing::Point(178, 108);
			this->pictureBox30->Name = L"pictureBox30";
			this->pictureBox30->Size = System::Drawing::Size(29, 29);
			this->pictureBox30->TabIndex = 29;
			this->pictureBox30->TabStop = false;
			this->pictureBox30->Click += gcnew System::EventHandler(this, &chessboard::pictureBox30_Click);
			// 
			// pictureBox29
			// 
			this->pictureBox29->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox29.Image")));
			this->pictureBox29->Location = System::Drawing::Point(143, 108);
			this->pictureBox29->Name = L"pictureBox29";
			this->pictureBox29->Size = System::Drawing::Size(29, 29);
			this->pictureBox29->TabIndex = 28;
			this->pictureBox29->TabStop = false;
			this->pictureBox29->Click += gcnew System::EventHandler(this, &chessboard::pictureBox29_Click);
			// 
			// pictureBox28
			// 
			this->pictureBox28->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox28.Image")));
			this->pictureBox28->Location = System::Drawing::Point(108, 108);
			this->pictureBox28->Name = L"pictureBox28";
			this->pictureBox28->Size = System::Drawing::Size(29, 29);
			this->pictureBox28->TabIndex = 27;
			this->pictureBox28->TabStop = false;
			this->pictureBox28->Click += gcnew System::EventHandler(this, &chessboard::pictureBox28_Click);
			// 
			// pictureBox27
			// 
			this->pictureBox27->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox27.Image")));
			this->pictureBox27->Location = System::Drawing::Point(73, 108);
			this->pictureBox27->Name = L"pictureBox27";
			this->pictureBox27->Size = System::Drawing::Size(29, 29);
			this->pictureBox27->TabIndex = 26;
			this->pictureBox27->TabStop = false;
			this->pictureBox27->Click += gcnew System::EventHandler(this, &chessboard::pictureBox27_Click);
			// 
			// pictureBox26
			// 
			this->pictureBox26->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox26.Image")));
			this->pictureBox26->Location = System::Drawing::Point(38, 108);
			this->pictureBox26->Name = L"pictureBox26";
			this->pictureBox26->Size = System::Drawing::Size(29, 29);
			this->pictureBox26->TabIndex = 25;
			this->pictureBox26->TabStop = false;
			this->pictureBox26->Click += gcnew System::EventHandler(this, &chessboard::pictureBox26_Click);
			// 
			// pictureBox25
			// 
			this->pictureBox25->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox25.Image")));
			this->pictureBox25->Location = System::Drawing::Point(3, 108);
			this->pictureBox25->Name = L"pictureBox25";
			this->pictureBox25->Size = System::Drawing::Size(29, 29);
			this->pictureBox25->TabIndex = 24;
			this->pictureBox25->TabStop = false;
			this->pictureBox25->Click += gcnew System::EventHandler(this, &chessboard::pictureBox25_Click);
			// 
			// pictureBox24
			// 
			this->pictureBox24->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox24.Image")));
			this->pictureBox24->Location = System::Drawing::Point(248, 73);
			this->pictureBox24->Name = L"pictureBox24";
			this->pictureBox24->Size = System::Drawing::Size(29, 29);
			this->pictureBox24->TabIndex = 23;
			this->pictureBox24->TabStop = false;
			this->pictureBox24->Click += gcnew System::EventHandler(this, &chessboard::pictureBox24_Click);
			// 
			// pictureBox23
			// 
			this->pictureBox23->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox23.Image")));
			this->pictureBox23->Location = System::Drawing::Point(213, 73);
			this->pictureBox23->Name = L"pictureBox23";
			this->pictureBox23->Size = System::Drawing::Size(29, 29);
			this->pictureBox23->TabIndex = 22;
			this->pictureBox23->TabStop = false;
			this->pictureBox23->Click += gcnew System::EventHandler(this, &chessboard::pictureBox23_Click);
			// 
			// pictureBox22
			// 
			this->pictureBox22->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox22.Image")));
			this->pictureBox22->Location = System::Drawing::Point(178, 73);
			this->pictureBox22->Name = L"pictureBox22";
			this->pictureBox22->Size = System::Drawing::Size(29, 29);
			this->pictureBox22->TabIndex = 21;
			this->pictureBox22->TabStop = false;
			this->pictureBox22->Click += gcnew System::EventHandler(this, &chessboard::pictureBox22_Click);
			// 
			// pictureBox21
			// 
			this->pictureBox21->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox21.Image")));
			this->pictureBox21->Location = System::Drawing::Point(143, 73);
			this->pictureBox21->Name = L"pictureBox21";
			this->pictureBox21->Size = System::Drawing::Size(29, 29);
			this->pictureBox21->TabIndex = 20;
			this->pictureBox21->TabStop = false;
			this->pictureBox21->Click += gcnew System::EventHandler(this, &chessboard::pictureBox21_Click);
			// 
			// pictureBox20
			// 
			this->pictureBox20->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox20.Image")));
			this->pictureBox20->Location = System::Drawing::Point(108, 73);
			this->pictureBox20->Name = L"pictureBox20";
			this->pictureBox20->Size = System::Drawing::Size(29, 29);
			this->pictureBox20->TabIndex = 19;
			this->pictureBox20->TabStop = false;
			this->pictureBox20->Click += gcnew System::EventHandler(this, &chessboard::pictureBox20_Click);
			// 
			// pictureBox19
			// 
			this->pictureBox19->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox19.Image")));
			this->pictureBox19->Location = System::Drawing::Point(73, 73);
			this->pictureBox19->Name = L"pictureBox19";
			this->pictureBox19->Size = System::Drawing::Size(29, 29);
			this->pictureBox19->TabIndex = 18;
			this->pictureBox19->TabStop = false;
			this->pictureBox19->Click += gcnew System::EventHandler(this, &chessboard::pictureBox19_Click);
			// 
			// pictureBox18
			// 
			this->pictureBox18->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox18.Image")));
			this->pictureBox18->Location = System::Drawing::Point(38, 73);
			this->pictureBox18->Name = L"pictureBox18";
			this->pictureBox18->Size = System::Drawing::Size(29, 29);
			this->pictureBox18->TabIndex = 17;
			this->pictureBox18->TabStop = false;
			this->pictureBox18->Click += gcnew System::EventHandler(this, &chessboard::pictureBox18_Click);
			// 
			// pictureBox17
			// 
			this->pictureBox17->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox17.Image")));
			this->pictureBox17->Location = System::Drawing::Point(3, 73);
			this->pictureBox17->Name = L"pictureBox17";
			this->pictureBox17->Size = System::Drawing::Size(29, 29);
			this->pictureBox17->TabIndex = 16;
			this->pictureBox17->TabStop = false;
			this->pictureBox17->Click += gcnew System::EventHandler(this, &chessboard::pictureBox17_Click);
			// 
			// pictureBox16
			// 
			this->pictureBox16->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox16.Image")));
			this->pictureBox16->Location = System::Drawing::Point(248, 38);
			this->pictureBox16->Name = L"pictureBox16";
			this->pictureBox16->Size = System::Drawing::Size(29, 29);
			this->pictureBox16->TabIndex = 15;
			this->pictureBox16->TabStop = false;
			this->pictureBox16->Click += gcnew System::EventHandler(this, &chessboard::pictureBox16_Click);
			// 
			// pictureBox15
			// 
			this->pictureBox15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox15.Image")));
			this->pictureBox15->Location = System::Drawing::Point(213, 38);
			this->pictureBox15->Name = L"pictureBox15";
			this->pictureBox15->Size = System::Drawing::Size(29, 29);
			this->pictureBox15->TabIndex = 14;
			this->pictureBox15->TabStop = false;
			this->pictureBox15->Click += gcnew System::EventHandler(this, &chessboard::pictureBox15_Click);
			// 
			// pictureBox14
			// 
			this->pictureBox14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox14.Image")));
			this->pictureBox14->Location = System::Drawing::Point(178, 38);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(29, 29);
			this->pictureBox14->TabIndex = 13;
			this->pictureBox14->TabStop = false;
			this->pictureBox14->Click += gcnew System::EventHandler(this, &chessboard::pictureBox14_Click);
			// 
			// pictureBox13
			// 
			this->pictureBox13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox13.Image")));
			this->pictureBox13->Location = System::Drawing::Point(143, 38);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(29, 29);
			this->pictureBox13->TabIndex = 12;
			this->pictureBox13->TabStop = false;
			this->pictureBox13->Click += gcnew System::EventHandler(this, &chessboard::pictureBox13_Click);
			// 
			// pictureBox12
			// 
			this->pictureBox12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.Image")));
			this->pictureBox12->Location = System::Drawing::Point(108, 38);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(29, 29);
			this->pictureBox12->TabIndex = 11;
			this->pictureBox12->TabStop = false;
			this->pictureBox12->Click += gcnew System::EventHandler(this, &chessboard::pictureBox12_Click);
			// 
			// pictureBox11
			// 
			this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.Image")));
			this->pictureBox11->Location = System::Drawing::Point(73, 38);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(29, 29);
			this->pictureBox11->TabIndex = 10;
			this->pictureBox11->TabStop = false;
			this->pictureBox11->Click += gcnew System::EventHandler(this, &chessboard::pictureBox11_Click);
			// 
			// pictureBox10
			// 
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(38, 38);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(29, 29);
			this->pictureBox10->TabIndex = 9;
			this->pictureBox10->TabStop = false;
			this->pictureBox10->Click += gcnew System::EventHandler(this, &chessboard::pictureBox10_Click);
			// 
			// pictureBox9
			// 
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(3, 38);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(29, 29);
			this->pictureBox9->TabIndex = 8;
			this->pictureBox9->TabStop = false;
			this->pictureBox9->Click += gcnew System::EventHandler(this, &chessboard::pictureBox9_Click);
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(248, 3);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(29, 29);
			this->pictureBox8->TabIndex = 7;
			this->pictureBox8->TabStop = false;
			this->pictureBox8->Click += gcnew System::EventHandler(this, &chessboard::pictureBox8_Click);
			// 
			// pictureBox7
			// 
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(213, 3);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(29, 29);
			this->pictureBox7->TabIndex = 6;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->Click += gcnew System::EventHandler(this, &chessboard::pictureBox7_Click);
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(178, 3);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(29, 29);
			this->pictureBox6->TabIndex = 5;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->Click += gcnew System::EventHandler(this, &chessboard::pictureBox6_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(143, 3);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(29, 29);
			this->pictureBox5->TabIndex = 4;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &chessboard::pictureBox5_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(108, 3);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(29, 29);
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &chessboard::pictureBox4_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(73, 3);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(29, 29);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &chessboard::pictureBox3_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(38, 3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(29, 29);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &chessboard::pictureBox2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(29, 29);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &chessboard::pictureBox1_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->player_2_score, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->player_1_score, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->label1, 1, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(388, 258);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(200, 68);
			this->tableLayoutPanel2->TabIndex = 2;
			this->tableLayoutPanel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &chessboard::tableLayoutPanel2_Paint);
			// 
			// player_2_score
			// 
			this->player_2_score->AutoSize = true;
			this->player_2_score->Dock = System::Windows::Forms::DockStyle::Fill;
			this->player_2_score->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->player_2_score->Location = System::Drawing::Point(3, 34);
			this->player_2_score->Name = L"player_2_score";
			this->player_2_score->Size = System::Drawing::Size(94, 34);
			this->player_2_score->TabIndex = 3;
			this->player_2_score->Text = L"0";
			this->player_2_score->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// player_1_score
			// 
			this->player_1_score->AutoSize = true;
			this->player_1_score->Dock = System::Windows::Forms::DockStyle::Fill;
			this->player_1_score->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->player_1_score->Location = System::Drawing::Point(103, 34);
			this->player_1_score->Name = L"player_1_score";
			this->player_1_score->Size = System::Drawing::Size(94, 34);
			this->player_1_score->TabIndex = 2;
			this->player_1_score->Text = L"0";
			this->player_1_score->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->player_1_score->Click += gcnew System::EventHandler(this, &chessboard::label3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(3, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 25);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Player 1";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->Click += gcnew System::EventHandler(this, &chessboard::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(103, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Player 2";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &chessboard::label1_Click_1);
			// 
			// message_box
			// 
			this->message_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->message_box->Location = System::Drawing::Point(359, 54);
			this->message_box->Name = L"message_box";
			this->message_box->Size = System::Drawing::Size(257, 30);
			this->message_box->TabIndex = 3;
			this->message_box->Text = L"Game isn\'t started";
			this->message_box->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->message_box->Click += gcnew System::EventHandler(this, &chessboard::label1_Click);
			// 
			// end_of_movement
			// 
			this->end_of_movement->Enabled = false;
			this->end_of_movement->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->end_of_movement->Location = System::Drawing::Point(377, 208);
			this->end_of_movement->Name = L"end_of_movement";
			this->end_of_movement->Size = System::Drawing::Size(223, 44);
			this->end_of_movement->TabIndex = 4;
			this->end_of_movement->Text = L"End of movement";
			this->end_of_movement->UseVisualStyleBackColor = true;
			this->end_of_movement->Visible = false;
			this->end_of_movement->Click += gcnew System::EventHandler(this, &chessboard::end_of_movement_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(1, 57);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(20, 24);
			this->label3->TabIndex = 6;
			this->label3->Text = L"1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(1, 92);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(20, 24);
			this->label4->TabIndex = 7;
			this->label4->Text = L"2";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(1, 127);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(20, 24);
			this->label5->TabIndex = 8;
			this->label5->Text = L"3";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(1, 162);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(20, 24);
			this->label6->TabIndex = 9;
			this->label6->Text = L"4";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(1, 197);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(20, 24);
			this->label7->TabIndex = 10;
			this->label7->Text = L"5";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(1, 232);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(20, 24);
			this->label8->TabIndex = 11;
			this->label8->Text = L"6";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(1, 267);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(20, 24);
			this->label9->TabIndex = 12;
			this->label9->Text = L"7";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(1, 302);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(20, 24);
			this->label10->TabIndex = 13;
			this->label10->Text = L"8";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label11->Location = System::Drawing::Point(25, 24);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(23, 24);
			this->label11->TabIndex = 14;
			this->label11->Text = L"A";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label12->Location = System::Drawing::Point(61, 24);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(22, 24);
			this->label12->TabIndex = 15;
			this->label12->Text = L"B";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label13->Location = System::Drawing::Point(95, 24);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(23, 24);
			this->label13->TabIndex = 16;
			this->label13->Text = L"C";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label14->Location = System::Drawing::Point(130, 24);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(23, 24);
			this->label14->TabIndex = 17;
			this->label14->Text = L"D";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label15->Location = System::Drawing::Point(165, 24);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(23, 24);
			this->label15->TabIndex = 18;
			this->label15->Text = L"E";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label16->Location = System::Drawing::Point(201, 24);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(22, 24);
			this->label16->TabIndex = 19;
			this->label16->Text = L"F";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label17->Location = System::Drawing::Point(238, 24);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(24, 24);
			this->label17->TabIndex = 20;
			this->label17->Text = L"G";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label18->Location = System::Drawing::Point(268, 24);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(24, 24);
			this->label18->TabIndex = 21;
			this->label18->Text = L"H";
			// 
			// which_player_field
			// 
			this->which_player_field->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->which_player_field->Location = System::Drawing::Point(359, 24);
			this->which_player_field->Name = L"which_player_field";
			this->which_player_field->Size = System::Drawing::Size(257, 30);
			this->which_player_field->TabIndex = 22;
			this->which_player_field->Text = L"Player 1. movement";
			this->which_player_field->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->which_player_field->Visible = false;
			// 
			// field_with_the_computer_movement
			// 
			this->field_with_the_computer_movement->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->field_with_the_computer_movement->Location = System::Drawing::Point(303, 99);
			this->field_with_the_computer_movement->Name = L"field_with_the_computer_movement";
			this->field_with_the_computer_movement->Size = System::Drawing::Size(339, 106);
			this->field_with_the_computer_movement->TabIndex = 23;
			this->field_with_the_computer_movement->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// chessboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(642, 346);
			this->Controls->Add(this->field_with_the_computer_movement);
			this->Controls->Add(this->which_player_field);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->end_of_movement);
			this->Controls->Add(this->message_box);
			this->Controls->Add(this->menu);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menu;
			this->Name = L"chessboard";
			this->Text = L"Game Knight";
			this->menu->ResumeLayout(false);
			this->menu->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox64))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox63))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox62))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox61))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox60))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox59))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox58))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox57))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox56))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox55))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox54))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox53))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox52))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox51))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox50))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox49))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox48))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox47))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox46))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox45))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox44))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox43))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox42))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox41))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox40))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox39))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox38))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox37))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox36))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox35))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox34))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox33))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox32))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox31))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox30))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox29))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox28))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox27))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox26))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox25))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox23))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void koniecGryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
			 exit(0);
		 }
private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
private: System::Void tableLayoutPanel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label1_Click_1(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void newGameToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
		 }
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (1);
		 }
private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (2);
		 }
private: System::Void pictureBox3_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (3);
		 }
private: System::Void pictureBox4_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (4);
		 }
private: System::Void pictureBox5_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (5);
		 }
private: System::Void pictureBox6_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (6);
		 }
private: System::Void pictureBox7_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (7);
		 }
private: System::Void pictureBox8_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (8);
		 }
private: System::Void pictureBox9_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (9);
		 }
private: System::Void pictureBox10_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (10);
		 }
private: System::Void pictureBox11_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (11);
		 }
private: System::Void pictureBox12_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (12);
		 }
private: System::Void pictureBox13_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (13);
		 }
private: System::Void pictureBox14_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (14);
		 }
private: System::Void pictureBox15_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (15);
		 }
private: System::Void pictureBox16_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (16);
		 }
private: System::Void pictureBox17_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (17);
		 }
private: System::Void pictureBox18_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (18);
		 }
private: System::Void pictureBox19_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (19);
		 }
private: System::Void pictureBox20_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (20);
		 }
private: System::Void pictureBox21_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (21);
		 }
private: System::Void pictureBox22_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (22);
		 }
private: System::Void pictureBox23_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (23);
		 }
private: System::Void pictureBox24_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (24);
		 }
private: System::Void pictureBox25_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (25);
		 }
private: System::Void pictureBox26_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (26);
		 }
private: System::Void pictureBox27_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (27);
		 }
private: System::Void pictureBox28_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (28);
		 }
private: System::Void pictureBox29_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (29);
		 }
private: System::Void pictureBox30_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (30);
		 }
private: System::Void pictureBox31_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (31);
		 }
private: System::Void pictureBox32_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (32);
		 }
private: System::Void pictureBox33_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (33);
		 }
private: System::Void pictureBox34_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (34);
		 }
private: System::Void pictureBox35_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (35);
		 }
private: System::Void pictureBox36_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (36);
		 }
private: System::Void pictureBox37_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (37);
		 }
private: System::Void pictureBox38_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (38);
		 }
private: System::Void pictureBox39_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (39);
		 }
private: System::Void pictureBox40_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (40);
		 }
private: System::Void pictureBox41_Click_1(System::Object^  sender, System::EventArgs^  e)
 		 {
			clicked_field (41);
		 }
private: System::Void pictureBox42_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (42);
		 }
private: System::Void pictureBox43_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (43);
		 }
private: System::Void pictureBox44_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (44);
		 }
private: System::Void pictureBox45_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (45);
		 }
private: System::Void pictureBox46_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (46);
		 }
private: System::Void pictureBox47_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (47);
		 }
private: System::Void pictureBox48_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (48);
		 }
private: System::Void pictureBox49_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (49);
		 }
private: System::Void pictureBox50_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (50);
		 }
private: System::Void pictureBox51_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (51);
		 }
private: System::Void pictureBox52_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (52);
		 }
private: System::Void pictureBox53_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (53);
		 }
private: System::Void pictureBox54_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (54);
		 }
private: System::Void pictureBox55_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (55);
		 }
private: System::Void pictureBox56_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (56);
		 }
private: System::Void pictureBox57_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (57);
		 }
private: System::Void pictureBox58_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (58);
		 }
private: System::Void pictureBox59_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (59);
		 }
private: System::Void pictureBox60_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (60);
		 }
private: System::Void pictureBox61_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (61);
		 }
private: System::Void pictureBox62_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (62);
		 }
private: System::Void pictureBox63_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (63);
		 }
private: System::Void pictureBox64_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			clicked_field (64);
		 }
private: System::Void gameWithHumanToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 start_a_new_game (true);
		 }
private: System::Void gameWithComputerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 start_a_new_game (false);
		 }
private: System::Void end_of_movement_Click (System::Object^  sender, System::EventArgs^  e)
		 {
			button_end_of_movement_clicked ();
		 }
private: System::Void gameRulesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 rules^ h_Message  = gcnew rules;
			 h_Message->Show();
		 }
private: System::Void authorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 author^ h_Message  = gcnew author;
			 h_Message->Show();
		 }
};
}