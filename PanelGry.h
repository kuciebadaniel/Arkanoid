#include "Kulka.h"
#include "Ramka.h"
#include "Pasek.h"
#include "Suwak.h"
#include "Blok.h"
#include <conio.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <string>
#pragma once

namespace Gra1 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for PanelGry
	/// </summary>
	public ref class PanelGry : public System::Windows::Forms::Form
	{
	private:
		const int _predkoscSuwaka = 20;
		String ^nazwaPliku = "rekord.txt";
		double losowanaLiczbaX, losowanaLiczbaY;
		// Klasyczne wskaüniki (*, &, new)
		Kulka *kulka;
		Ramka *ramka;
		// Wskaüniki inteligentne (^, %, gcnew)
		Pasek ^suwak = gcnew Suwak();
		array<Pasek^> ^tablicaBlokow = gcnew array <Blok^>(9);
		bool wygrana, zapisano = false;
		int rekord, rekordZPliku;
		


	private: System::Windows::Forms::PictureBox^  kulkaObrazek;
	private: System::Windows::Forms::Timer^  czasomierzKulki;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^  czasomierzSuwaka;
	private: System::Windows::Forms::PictureBox^  klocekObrazek1;
	private: System::Windows::Forms::PictureBox^  ramkaGora;
	private: System::Windows::Forms::PictureBox^  ramkaPrawo;
	private: System::Windows::Forms::PictureBox^  ramkaDol;
	private: System::Windows::Forms::PictureBox^  ramkaLewo;
	private: System::Windows::Forms::PictureBox^  klocekObrazek2;
	private: System::Windows::Forms::PictureBox^  klocekObrazek3;
	private: System::Windows::Forms::PictureBox^  klocekObrazek5;
	private: System::Windows::Forms::PictureBox^  klocekObrazek4;
	private: System::Windows::Forms::PictureBox^  klocekObrazek6;
	private: System::Windows::Forms::PictureBox^  klocekObrazek7;
	private: System::Windows::Forms::PictureBox^  klocekObrazek8;
	private: System::Windows::Forms::PictureBox^  klocekObrazek9;
	private: System::Windows::Forms::PictureBox^  pasekObrazek;
	private: System::Windows::Forms::Label^  przegralesNapis;
	private: System::Windows::Forms::Label^  wygranaNapis;
	private: System::Windows::Forms::Label^  labelRekord;
	private: System::Windows::Forms::Label^  labelRekordOpis;



		array<PictureBox^> ^tablicaBokowObrazkow = gcnew array<PictureBox^>(9);
		

	public:
		// g≥Ûwny konstruktor 
		PanelGry(void)
		{
			InitializeComponent();
			// Losowanie liczb
			srand(time(NULL));
			// Rozmiar pola do gry 
			ramka = new Ramka(30, 750, 30, 550);
			// Pozycja kulki, wczytywana z pozycji obrazka na ekranie
			kulka = new Kulka(kulkaObrazek->Location.X + 10, kulkaObrazek->Location.Y + 10);
			// 
			suwak = gcnew Suwak(pasekObrazek->Location.X + 50, pasekObrazek->Location.Y);
			
			tablicaBlokow[0] = gcnew Blok(klocekObrazek1->Location.X, klocekObrazek1->Location.Y);
			tablicaBlokow[1] = gcnew Blok(klocekObrazek2->Location.X, klocekObrazek2->Location.Y);
			tablicaBlokow[2] = gcnew Blok(klocekObrazek3->Location.X, klocekObrazek3->Location.Y);
			tablicaBlokow[3] = gcnew Blok(klocekObrazek4->Location.X, klocekObrazek4->Location.Y);
			tablicaBlokow[4] = gcnew Blok(klocekObrazek5->Location.X, klocekObrazek5->Location.Y);
			tablicaBlokow[5] = gcnew Blok(klocekObrazek6->Location.X, klocekObrazek6->Location.Y);
			tablicaBlokow[6] = gcnew Blok(klocekObrazek7->Location.X, klocekObrazek7->Location.Y);
			tablicaBlokow[7] = gcnew Blok(klocekObrazek8->Location.X, klocekObrazek8->Location.Y);
			tablicaBlokow[8] = gcnew Blok(klocekObrazek9->Location.X, klocekObrazek9->Location.Y);
			
			tablicaBokowObrazkow[0] = klocekObrazek1;
			tablicaBokowObrazkow[1] = klocekObrazek2;
			tablicaBokowObrazkow[2] = klocekObrazek3;
			tablicaBokowObrazkow[3] = klocekObrazek4;
			tablicaBokowObrazkow[4] = klocekObrazek5;
			tablicaBokowObrazkow[5] = klocekObrazek6;
			tablicaBokowObrazkow[6] = klocekObrazek7;
			tablicaBokowObrazkow[7] = klocekObrazek8;
			tablicaBokowObrazkow[8] = klocekObrazek9;

			wygrana = false;

			rekord = 0;
			rekordZPliku = Convert::ToInt32(PobierzRekord());

			labelRekord->Text = PobierzRekord();

			czasomierzKulki->Start();
			czasomierzSuwaka->Start();			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PanelGry()
		{
			if (components)
			{
				delete components, kulka, ramka, suwak;
				kulka = nullptr;
				ramka = nullptr;
				suwak = nullptr;
			}
		}
		// Kod generowany automatycznie:
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PanelGry::typeid));
			this->kulkaObrazek = (gcnew System::Windows::Forms::PictureBox());
			this->czasomierzKulki = (gcnew System::Windows::Forms::Timer(this->components));
			this->pasekObrazek = (gcnew System::Windows::Forms::PictureBox());
			this->czasomierzSuwaka = (gcnew System::Windows::Forms::Timer(this->components));
			this->klocekObrazek1 = (gcnew System::Windows::Forms::PictureBox());
			this->ramkaGora = (gcnew System::Windows::Forms::PictureBox());
			this->ramkaPrawo = (gcnew System::Windows::Forms::PictureBox());
			this->ramkaDol = (gcnew System::Windows::Forms::PictureBox());
			this->ramkaLewo = (gcnew System::Windows::Forms::PictureBox());
			this->klocekObrazek2 = (gcnew System::Windows::Forms::PictureBox());
			this->klocekObrazek3 = (gcnew System::Windows::Forms::PictureBox());
			this->klocekObrazek5 = (gcnew System::Windows::Forms::PictureBox());
			this->klocekObrazek4 = (gcnew System::Windows::Forms::PictureBox());
			this->klocekObrazek6 = (gcnew System::Windows::Forms::PictureBox());
			this->klocekObrazek7 = (gcnew System::Windows::Forms::PictureBox());
			this->klocekObrazek8 = (gcnew System::Windows::Forms::PictureBox());
			this->klocekObrazek9 = (gcnew System::Windows::Forms::PictureBox());
			this->przegralesNapis = (gcnew System::Windows::Forms::Label());
			this->wygranaNapis = (gcnew System::Windows::Forms::Label());
			this->labelRekord = (gcnew System::Windows::Forms::Label());
			this->labelRekordOpis = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kulkaObrazek))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pasekObrazek))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ramkaGora))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ramkaPrawo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ramkaDol))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ramkaLewo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek9))->BeginInit();
			this->SuspendLayout();
			// 
			// kulkaObrazek
			// 
			this->kulkaObrazek->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"kulkaObrazek.Image")));
			this->kulkaObrazek->Location = System::Drawing::Point(323, 414);
			this->kulkaObrazek->Name = L"kulkaObrazek";
			this->kulkaObrazek->Size = System::Drawing::Size(20, 20);
			this->kulkaObrazek->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->kulkaObrazek->TabIndex = 1;
			this->kulkaObrazek->TabStop = false;
			// 
			// czasomierzKulki
			// 
			this->czasomierzKulki->Interval = 1;
			this->czasomierzKulki->Tick += gcnew System::EventHandler(this, &PanelGry::czasomierzKulki_Tick);
			// 
			// pasekObrazek
			// 
			this->pasekObrazek->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pasekObrazek.Image")));
			this->pasekObrazek->Location = System::Drawing::Point(356, 480);
			this->pasekObrazek->Name = L"pasekObrazek";
			this->pasekObrazek->Size = System::Drawing::Size(100, 20);
			this->pasekObrazek->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pasekObrazek->TabIndex = 2;
			this->pasekObrazek->TabStop = false;
			// 
			// czasomierzSuwaka
			// 
			this->czasomierzSuwaka->Interval = 50;
			// 
			// klocekObrazek1
			// 
			this->klocekObrazek1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"klocekObrazek1.Image")));
			this->klocekObrazek1->Location = System::Drawing::Point(76, 82);
			this->klocekObrazek1->Name = L"klocekObrazek1";
			this->klocekObrazek1->Size = System::Drawing::Size(70, 30);
			this->klocekObrazek1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->klocekObrazek1->TabIndex = 3;
			this->klocekObrazek1->TabStop = false;
			// 
			// ramkaGora
			// 
			this->ramkaGora->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ramkaGora.Image")));
			this->ramkaGora->Location = System::Drawing::Point(-107, -14);
			this->ramkaGora->Name = L"ramkaGora";
			this->ramkaGora->Size = System::Drawing::Size(985, 50);
			this->ramkaGora->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->ramkaGora->TabIndex = 4;
			this->ramkaGora->TabStop = false;
			// 
			// ramkaPrawo
			// 
			this->ramkaPrawo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ramkaPrawo.Image")));
			this->ramkaPrawo->Location = System::Drawing::Point(770, 28);
			this->ramkaPrawo->Name = L"ramkaPrawo";
			this->ramkaPrawo->Size = System::Drawing::Size(100, 572);
			this->ramkaPrawo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->ramkaPrawo->TabIndex = 5;
			this->ramkaPrawo->TabStop = false;
			// 
			// ramkaDol
			// 
			this->ramkaDol->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ramkaDol.Image")));
			this->ramkaDol->Location = System::Drawing::Point(-13, 564);
			this->ramkaDol->Name = L"ramkaDol";
			this->ramkaDol->Size = System::Drawing::Size(909, 50);
			this->ramkaDol->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->ramkaDol->TabIndex = 6;
			this->ramkaDol->TabStop = false;
			// 
			// ramkaLewo
			// 
			this->ramkaLewo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ramkaLewo.Image")));
			this->ramkaLewo->Location = System::Drawing::Point(-125, 12);
			this->ramkaLewo->Name = L"ramkaLewo";
			this->ramkaLewo->Size = System::Drawing::Size(156, 588);
			this->ramkaLewo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->ramkaLewo->TabIndex = 7;
			this->ramkaLewo->TabStop = false;
			// 
			// klocekObrazek2
			// 
			this->klocekObrazek2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"klocekObrazek2.Image")));
			this->klocekObrazek2->Location = System::Drawing::Point(222, 82);
			this->klocekObrazek2->Name = L"klocekObrazek2";
			this->klocekObrazek2->Size = System::Drawing::Size(70, 30);
			this->klocekObrazek2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->klocekObrazek2->TabIndex = 8;
			this->klocekObrazek2->TabStop = false;
			// 
			// klocekObrazek3
			// 
			this->klocekObrazek3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"klocekObrazek3.Image")));
			this->klocekObrazek3->Location = System::Drawing::Point(368, 82);
			this->klocekObrazek3->Name = L"klocekObrazek3";
			this->klocekObrazek3->Size = System::Drawing::Size(70, 30);
			this->klocekObrazek3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->klocekObrazek3->TabIndex = 9;
			this->klocekObrazek3->TabStop = false;
			// 
			// klocekObrazek5
			// 
			this->klocekObrazek5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"klocekObrazek5.Image")));
			this->klocekObrazek5->Location = System::Drawing::Point(660, 82);
			this->klocekObrazek5->Name = L"klocekObrazek5";
			this->klocekObrazek5->Size = System::Drawing::Size(70, 30);
			this->klocekObrazek5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->klocekObrazek5->TabIndex = 10;
			this->klocekObrazek5->TabStop = false;
			// 
			// klocekObrazek4
			// 
			this->klocekObrazek4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"klocekObrazek4.Image")));
			this->klocekObrazek4->Location = System::Drawing::Point(514, 82);
			this->klocekObrazek4->Name = L"klocekObrazek4";
			this->klocekObrazek4->Size = System::Drawing::Size(70, 30);
			this->klocekObrazek4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->klocekObrazek4->TabIndex = 11;
			this->klocekObrazek4->TabStop = false;
			// 
			// klocekObrazek6
			// 
			this->klocekObrazek6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"klocekObrazek6.Image")));
			this->klocekObrazek6->Location = System::Drawing::Point(149, 151);
			this->klocekObrazek6->Name = L"klocekObrazek6";
			this->klocekObrazek6->Size = System::Drawing::Size(70, 30);
			this->klocekObrazek6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->klocekObrazek6->TabIndex = 12;
			this->klocekObrazek6->TabStop = false;
			// 
			// klocekObrazek7
			// 
			this->klocekObrazek7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"klocekObrazek7.Image")));
			this->klocekObrazek7->Location = System::Drawing::Point(295, 151);
			this->klocekObrazek7->Name = L"klocekObrazek7";
			this->klocekObrazek7->Size = System::Drawing::Size(70, 30);
			this->klocekObrazek7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->klocekObrazek7->TabIndex = 13;
			this->klocekObrazek7->TabStop = false;
			// 
			// klocekObrazek8
			// 
			this->klocekObrazek8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"klocekObrazek8.Image")));
			this->klocekObrazek8->Location = System::Drawing::Point(441, 151);
			this->klocekObrazek8->Name = L"klocekObrazek8";
			this->klocekObrazek8->Size = System::Drawing::Size(70, 30);
			this->klocekObrazek8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->klocekObrazek8->TabIndex = 14;
			this->klocekObrazek8->TabStop = false;
			// 
			// klocekObrazek9
			// 
			this->klocekObrazek9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"klocekObrazek9.Image")));
			this->klocekObrazek9->Location = System::Drawing::Point(587, 151);
			this->klocekObrazek9->Name = L"klocekObrazek9";
			this->klocekObrazek9->Size = System::Drawing::Size(70, 30);
			this->klocekObrazek9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->klocekObrazek9->TabIndex = 15;
			this->klocekObrazek9->TabStop = false;
			// 
			// przegralesNapis
			// 
			this->przegralesNapis->AutoSize = true;
			this->przegralesNapis->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->przegralesNapis->ForeColor = System::Drawing::Color::Red;
			this->przegralesNapis->Location = System::Drawing::Point(306, 258);
			this->przegralesNapis->Name = L"przegralesNapis";
			this->przegralesNapis->Size = System::Drawing::Size(189, 39);
			this->przegralesNapis->TabIndex = 16;
			this->przegralesNapis->Text = L"Przegra≥eú!";
			this->przegralesNapis->Visible = false;
			// 
			// wygranaNapis
			// 
			this->wygranaNapis->AutoSize = true;
			this->wygranaNapis->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->wygranaNapis->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->wygranaNapis->Location = System::Drawing::Point(316, 297);
			this->wygranaNapis->Name = L"wygranaNapis";
			this->wygranaNapis->Size = System::Drawing::Size(168, 39);
			this->wygranaNapis->TabIndex = 17;
			this->wygranaNapis->Text = L"Wygra≥eú!";
			this->wygranaNapis->Visible = false;
			// 
			// labelRekord
			// 
			this->labelRekord->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelRekord->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelRekord->Location = System::Drawing::Point(133, 9);
			this->labelRekord->Name = L"labelRekord";
			this->labelRekord->Size = System::Drawing::Size(61, 23);
			this->labelRekord->TabIndex = 18;
			this->labelRekord->Text = L"0";
			// 
			// labelRekordOpis
			// 
			this->labelRekordOpis->AutoSize = true;
			this->labelRekordOpis->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelRekordOpis->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelRekordOpis->Location = System::Drawing::Point(12, 9);
			this->labelRekordOpis->Name = L"labelRekordOpis";
			this->labelRekordOpis->Size = System::Drawing::Size(115, 24);
			this->labelRekordOpis->TabIndex = 19;
			this->labelRekordOpis->Text = L"TwÛj rekord:";
			// 
			// PanelGry
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(797, 594);
			this->Controls->Add(this->labelRekordOpis);
			this->Controls->Add(this->labelRekord);
			this->Controls->Add(this->wygranaNapis);
			this->Controls->Add(this->przegralesNapis);
			this->Controls->Add(this->klocekObrazek9);
			this->Controls->Add(this->klocekObrazek8);
			this->Controls->Add(this->klocekObrazek7);
			this->Controls->Add(this->klocekObrazek6);
			this->Controls->Add(this->klocekObrazek4);
			this->Controls->Add(this->klocekObrazek5);
			this->Controls->Add(this->klocekObrazek3);
			this->Controls->Add(this->klocekObrazek2);
			this->Controls->Add(this->ramkaGora);
			this->Controls->Add(this->ramkaDol);
			this->Controls->Add(this->ramkaLewo);
			this->Controls->Add(this->ramkaPrawo);
			this->Controls->Add(this->klocekObrazek1);
			this->Controls->Add(this->pasekObrazek);
			this->Controls->Add(this->kulkaObrazek);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(813, 633);
			this->MinimumSize = System::Drawing::Size(813, 633);
			this->Name = L"PanelGry";
			this->Text = L"PanelGry";
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &PanelGry::PanelGry_KeyPress);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kulkaObrazek))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pasekObrazek))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ramkaGora))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ramkaPrawo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ramkaDol))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ramkaLewo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klocekObrazek9))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	private: 	
		// Czasomierz 
		System::Void czasomierzKulki_Tick(System::Object^  sender, System::EventArgs^  e) 
		{
			//Losowanie dwÛch liczb z zakresu (2.0 - 4.0)
			losowanaLiczbaX = (((rand() % 21) + 20) / 10);
			losowanaLiczbaY = (((rand() % 21) + 20) / 10);
			//int xKulkiLokalne = kulka->PobierzX(), yKulkiLokalne = kulka->PobierzY();
			
			// Sekcja bloczkÛw:
			for (int i = 0; i < 9; i++)
			{
				if (tablicaBokowObrazkow[i]->Visible == false)
					continue;

				// Odbicie z lewej strony bloczka
				if (tablicaBlokow[i]->CzyOdbiloSie(kulka->PobierzX() + 10, kulka->PobierzY()))
				{
					kulka->UstawWspolczynnikX((-1)*losowanaLiczbaX);
					tablicaBokowObrazkow[i]->Visible = false;
				}

				//Odbicie od gÛry bloczka
				if (tablicaBlokow[i]->CzyOdbiloSie(kulka->PobierzX(), kulka->PobierzY() + 10))
				{
					kulka->UstawWspolczynnikY((-1)*losowanaLiczbaY);
					tablicaBokowObrazkow[i]->Visible = false;
				}

				// Odbicie z prawej strony bloczka
				if (tablicaBlokow[i]->CzyOdbiloSie(kulka->PobierzX() - 10, kulka->PobierzY()))
				{
					kulka->UstawWspolczynnikX(losowanaLiczbaX);
					tablicaBokowObrazkow[i]->Visible = false;
				}

				// Odbicie z do≥u bloczka
				if (tablicaBlokow[i]->CzyOdbiloSie(kulka->PobierzX() - 10, kulka->PobierzY()))
				{
					kulka->UstawWspolczynnikY((-1)*losowanaLiczbaY);
					tablicaBokowObrazkow[i]->Visible = false;
				}
			}

			// Sekcja ramki:

			// Sekcja  X
			if (ramka->CzyWyszloWLewo(kulka->PobierzX()))
			{
				kulka->UstawWspolczynnikX(losowanaLiczbaX);
			}
			if (ramka->CzyWyszloWPrawo(kulka->PobierzX()))
			{
				kulka->UstawWspolczynnikX((-1)*losowanaLiczbaX);
			}
			double x = kulka->PobierzX();
			x = x + kulka->PobierzWspolczynnikX();
			kulka->UstawX(x);

			// Sekcja  Y
			if (ramka->CzyWyszloWGore(kulka->PobierzY()))
			{
				kulka->UstawWspolczynnikY(losowanaLiczbaY);
			}
			if (ramka->CzyWyszloWDol(kulka->PobierzY()) || suwak->CzyOdbiloSie(kulka->PobierzX(), kulka->PobierzY() + 10))
			{
				kulka->UstawWspolczynnikY((-1)*losowanaLiczbaY);
			}
			double y = kulka->PobierzY();
			y = y + kulka->PobierzWspolczynnikY();
			kulka->UstawY(y);

			// Jeúli kulka wyleci pod planszÍ to przegrana
			if (kulka->PobierzY() > 490 && wygrana == false)
			{
				kulkaObrazek->Visible = false;
				kulka->UstawWspolczynnikX(0);
				kulka->UstawWspolczynnikY(0);
				przegralesNapis->Visible = true;
				czasomierzKulki->Stop();
			}

			// Sprawdzenie, czy wszystkie bloczki zosta≥y rozwalone
			for (int i = 0; i < 9; i++)
			{
				if (tablicaBokowObrazkow[i]->Visible == true)
					break;
				else if (i == 8 && tablicaBokowObrazkow[i]->Visible == false)
				{
					wygrana = true;
					wygranaNapis->Visible = true;
					// Jeúli rekord jest mniejszy od rekordu z pliku, zapisz
					if (rekord < rekordZPliku && zapisano == false)
					{
						ZapiszRekor();
					}
				}				
			}

			// PresuniÍcie kulki
			kulkaObrazek->Location = System::Drawing::Point(kulka->Ruch());
			// Rysowanie kulki
			System::Drawing::Point(kulkaObrazek);
			// Aktualizacja etykiety z rekordem
			labelRekord->Text = Convert::ToString(++rekord);
		}
	private: 
		// Sterowanie lewo <-> prawo
		System::Void PanelGry_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
		{
			if (e->KeyChar == 'g' || e->KeyChar == 'G')
			{
				// Gdy przycisk wyjdzie poz planszÍ w lewo
				if (ramka->CzyWyszloWLewo(pasekObrazek->Location.X ))
					return;
				pasekObrazek->Location = System::Drawing::Point((int)round(suwak->PobierzX() - 50 - _predkoscSuwaka), (int)round(suwak->PobierzY()));
				suwak->UstawX(suwak->PobierzX() - _predkoscSuwaka);
			}
			if (e->KeyChar == 'h' || e->KeyChar == 'H')
			{
				// Gdy przycisk wyjdzie poz planszÍ w lewo
				if (ramka->CzyWyszloWPrawo(pasekObrazek->Location.X  + 80))
					return;
				pasekObrazek->Location = System::Drawing::Point((int)round(suwak->PobierzX() - 50 + _predkoscSuwaka), (int)round(suwak->PobierzY()));
				suwak->UstawX(suwak->PobierzX() + _predkoscSuwaka);
			}
		}

		/* =================================================
			Obs≥uga rekordu: try...catch oraz obs≥uga plikÛw
			=================================================
		*/
		// Pobranie rekordu z pliku.

		System::String ^PobierzRekord()
		{
			StreamWriter ^streamWriter;// = gcnew StreamWriter(nazwa);
			StreamReader ^streamReader;// = gcnew StreamReader(nazwa);
			String ^rekordTymcz;
			try
			{
				// Gdy plik istnieje
				if (System::IO::File::Exists(nazwaPliku))
				{
					streamReader = gcnew StreamReader(nazwaPliku);
					rekordTymcz = streamReader->ReadLine();
					streamReader->Close();
					return rekordTymcz;
				}
				// UtwÛrz plik
				else
				{
					streamWriter = gcnew StreamWriter(nazwaPliku);
					streamWriter->WriteLine("10000");
					streamWriter->Close();
					return "10000";
				}
			}
			catch (Exception^)
			{
				MessageBox::Show("B≥πd przy pobieraniu z pliku!");
			}	
			return "10000";
		}

		// Zpaisanie rekordu.
		void ZapiszRekor()
		{
			int rekordTymcz = rekord;
			zapisano = true;
			MessageBox::Show("Gratualcje pobi≥eú nowy rekord:\n" + Convert::ToString(rekordTymcz));
			StreamWriter ^streamWriter = gcnew StreamWriter(nazwaPliku);
			try
			{
				streamWriter->WriteLine(Convert::ToString(rekordTymcz));
			}
			catch (Exception ^)
			{
				MessageBox::Show("B≥πd przy zapisie do pliku!");
			}
			finally
			{
				streamWriter->Close();
			}
		}

	};
}
