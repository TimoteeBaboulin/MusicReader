#include "Player.h"
#define	WATER_STREAM_0		"C:/Users/Etudiant1/Documents/LocalRepository/MusicReader/WinformCplusplus/BadApple.ogg"
#define	WATER_STREAM_1		"Ruisseau_Escattes_02.wav"
#pragma once

namespace WinformCplusplus {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			init();
		}


	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	protected:

	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::Button^ playButton;
	private: System::Windows::Forms::Button^ pauseButton;
	private: System::Windows::Forms::Button^ resumeButton;
	private: System::Windows::Forms::Button^ stopButton;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::Button^ addButton;
	private: System::Windows::Forms::Button^ removeButton;
	private: System::Windows::Forms::MenuStrip^ menuStrip;


	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::TrackBar^ volumeTrackBar;
	private: System::Windows::Forms::TextBox^ volumeTextBox;







	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->playButton = (gcnew System::Windows::Forms::Button());
			this->pauseButton = (gcnew System::Windows::Forms::Button());
			this->resumeButton = (gcnew System::Windows::Forms::Button());
			this->stopButton = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->removeButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->volumeTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->volumeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->volumeTrackBar))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// playButton
			// 
			this->playButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->playButton->Location = System::Drawing::Point(579, 26);
			this->playButton->Name = L"playButton";
			this->playButton->Size = System::Drawing::Size(48, 48);
			this->playButton->TabIndex = 0;
			this->playButton->Text = L"▶";
			this->playButton->UseVisualStyleBackColor = true;
			this->playButton->Click += gcnew System::EventHandler(this, &MyForm::playButton_Click);
			// 
			// pauseButton
			// 
			this->pauseButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pauseButton->Location = System::Drawing::Point(579, 80);
			this->pauseButton->Name = L"pauseButton";
			this->pauseButton->Size = System::Drawing::Size(48, 48);
			this->pauseButton->TabIndex = 1;
			this->pauseButton->Text = L"⏸";
			this->pauseButton->UseVisualStyleBackColor = true;
			this->pauseButton->Click += gcnew System::EventHandler(this, &MyForm::pauseButton_Click);
			// 
			// resumeButton
			// 
			this->resumeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resumeButton->Location = System::Drawing::Point(579, 134);
			this->resumeButton->Name = L"resumeButton";
			this->resumeButton->Size = System::Drawing::Size(48, 48);
			this->resumeButton->TabIndex = 2;
			this->resumeButton->Text = L"⏯";
			this->resumeButton->UseVisualStyleBackColor = true;
			this->resumeButton->Click += gcnew System::EventHandler(this, &MyForm::resumeButton_Click);
			// 
			// stopButton
			// 
			this->stopButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stopButton->Location = System::Drawing::Point(579, 188);
			this->stopButton->Name = L"stopButton";
			this->stopButton->Size = System::Drawing::Size(48, 48);
			this->stopButton->TabIndex = 3;
			this->stopButton->Text = L"⏹";
			this->stopButton->UseVisualStyleBackColor = true;
			this->stopButton->Click += gcnew System::EventHandler(this, &MyForm::stopButton_Click);
			// 
			// listView1
			// 
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(12, 27);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(561, 209);
			this->listView1->TabIndex = 4;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// addButton
			// 
			this->addButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addButton->Location = System::Drawing::Point(12, 242);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(24, 24);
			this->addButton->TabIndex = 5;
			this->addButton->Text = L"+";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &MyForm::addButton_Click);
			// 
			// removeButton
			// 
			this->removeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->removeButton->Location = System::Drawing::Point(42, 242);
			this->removeButton->Name = L"removeButton";
			this->removeButton->Size = System::Drawing::Size(24, 24);
			this->removeButton->TabIndex = 6;
			this->removeButton->Text = L"-";
			this->removeButton->UseVisualStyleBackColor = true;
			this->removeButton->Click += gcnew System::EventHandler(this, &MyForm::removeButton_Click);
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(640, 24);
			this->menuStrip->TabIndex = 7;
			this->menuStrip->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->fileToolStripMenuItem->Text = L"Playlist";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// volumeTrackBar
			// 
			this->volumeTrackBar->Location = System::Drawing::Point(73, 243);
			this->volumeTrackBar->Maximum = 100;
			this->volumeTrackBar->Name = L"volumeTrackBar";
			this->volumeTrackBar->Size = System::Drawing::Size(500, 45);
			this->volumeTrackBar->TabIndex = 8;
			this->volumeTrackBar->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->volumeTrackBar->Value = 50;
			this->volumeTrackBar->ValueChanged += gcnew System::EventHandler(this, &MyForm::volumeTrackBar_ValueChanged);
			// 
			// volumeTextBox
			// 
			this->volumeTextBox->Location = System::Drawing::Point(579, 243);
			this->volumeTextBox->Name = L"volumeTextBox";
			this->volumeTextBox->ReadOnly = true;
			this->volumeTextBox->Size = System::Drawing::Size(48, 20);
			this->volumeTextBox->TabIndex = 9;
			this->volumeTextBox->Text = L"50";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(640, 360);
			this->Controls->Add(this->volumeTextBox);
			this->Controls->Add(this->volumeTrackBar);
			this->Controls->Add(this->removeButton);
			this->Controls->Add(this->addButton);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->stopButton);
			this->Controls->Add(this->resumeButton);
			this->Controls->Add(this->pauseButton);
			this->Controls->Add(this->playButton);
			this->Controls->Add(this->menuStrip);
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"MyForm";
			this->Text = L"OpenAL Music Player";
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->volumeTrackBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void playButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Play(WATER_STREAM_0);
	}
	private: System::Void volumeTrackBar_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		volumeTextBox->Text = volumeTrackBar->Value.ToString();
	}
	private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Open file dialog to select audio files (e.g., WAV files and OGG files)
		openFileDialog1->Multiselect = true;
		openFileDialog1->Filter = "Audio Files|*.wav;*.ogg|All Files|*.*";
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			// Add selected files to the list view
			// Format: Filename (Full Path, Hidden) - Name (name + extension) - Duration (mm:ss) - Size (KB) - Format (WAV/OGG)
			for each (System::String^ file in openFileDialog1->FileNames)
			{
				System::IO::FileInfo^ fileInfo = gcnew System::IO::FileInfo(file);
				System::String^ fileName = fileInfo->Name;
				System::String^ fileSize = (fileInfo->Length / 1024).ToString() + " KB";
				System::String^ fileFormat = fileInfo->Extension->ToUpper()->TrimStart('.');
				System::Windows::Forms::ListViewItem^ item = gcnew System::Windows::Forms::ListViewItem(file);
				item->SubItems->Add(fileName);
				item->SubItems->Add("00:00"); // Placeholder for duration
				item->SubItems->Add(fileSize);
				item->SubItems->Add(fileFormat);
				listView1->Items->Add(item);
			}
		}
	}
	private: System::Void removeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Remove selected items from the list view
		for each (System::Windows::Forms::ListViewItem^ item in listView1->SelectedItems)
		{
			listView1->Items->Remove(item);
		}
	}
	private: System::Void pauseButton_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void resumeButton_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void stopButton_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
