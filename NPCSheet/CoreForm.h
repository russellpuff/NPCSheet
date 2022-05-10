#pragma once
#include "NPC.h";

namespace NPCSheet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace NSNPC;

	/// <summary>
	/// Summary for CoreForm
	/// </summary>
	public ref class CoreForm : public System::Windows::Forms::Form
	{

	// Class members I created.
	private: bool cfUnsaved;
	private: String^ caption = "NPCSheet";
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cfDataGridNameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cfDataGridAlignColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cfDataGridRaceColumn;



	private: List<NPC^>^ NPCs;
	// End of homemade class members.

	public:
		CoreForm(void)
		{
			InitializeComponent();
			// Constructor code
			cfUnsaved = false; // On empty form, unsaved is false to allow exit without interruption if no other actions are taken
			NPCs = gcnew List<NPC^>();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CoreForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ cfTitleLabel;

	protected:

	private: System::Windows::Forms::Button^ cfHelpButton;
	private: System::Windows::Forms::TableLayoutPanel^ cfBottomTableLayout;
	private: System::Windows::Forms::Button^ cfEditButton;
	private: System::Windows::Forms::Button^ cfLoadButton;
	private: System::Windows::Forms::Button^ cfNewButton;
	private: System::Windows::Forms::Button^ cfSaveButton;
	private: System::Windows::Forms::DataGridView^ cfDataGrid;

	private: System::Windows::Forms::TableLayoutPanel^ cfTopTableLayout;


	private: System::ComponentModel::IContainer^ components;


	protected:

	protected:

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
			this->cfTitleLabel = (gcnew System::Windows::Forms::Label());
			this->cfHelpButton = (gcnew System::Windows::Forms::Button());
			this->cfBottomTableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->cfEditButton = (gcnew System::Windows::Forms::Button());
			this->cfLoadButton = (gcnew System::Windows::Forms::Button());
			this->cfDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->cfDataGridNameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cfDataGridAlignColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cfDataGridRaceColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cfNewButton = (gcnew System::Windows::Forms::Button());
			this->cfSaveButton = (gcnew System::Windows::Forms::Button());
			this->cfTopTableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->cfBottomTableLayout->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cfDataGrid))->BeginInit();
			this->cfTopTableLayout->SuspendLayout();
			this->SuspendLayout();
			// 
			// cfTitleLabel
			// 
			this->cfTitleLabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cfTitleLabel->AutoSize = true;
			this->cfTitleLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cfTitleLabel->Location = System::Drawing::Point(81, 0);
			this->cfTitleLabel->Name = L"cfTitleLabel";
			this->cfTitleLabel->Size = System::Drawing::Size(135, 37);
			this->cfTitleLabel->TabIndex = 0;
			this->cfTitleLabel->Text = L"NPCSheet";
			// 
			// cfHelpButton
			// 
			this->cfHelpButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cfHelpButton->Location = System::Drawing::Point(273, 8);
			this->cfHelpButton->Margin = System::Windows::Forms::Padding(3, 8, 3, 3);
			this->cfHelpButton->Name = L"cfHelpButton";
			this->cfHelpButton->Size = System::Drawing::Size(24, 24);
			this->cfHelpButton->TabIndex = 1;
			this->cfHelpButton->Text = L"\?";
			this->cfHelpButton->UseVisualStyleBackColor = true;
			this->cfHelpButton->Click += gcnew System::EventHandler(this, &CoreForm::cfHelpButton_Click);
			// 
			// cfBottomTableLayout
			// 
			this->cfBottomTableLayout->ColumnCount = 2;
			this->cfBottomTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->cfBottomTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->cfBottomTableLayout->Controls->Add(this->cfEditButton, 1, 1);
			this->cfBottomTableLayout->Controls->Add(this->cfLoadButton, 1, 2);
			this->cfBottomTableLayout->Controls->Add(this->cfDataGrid, 0, 0);
			this->cfBottomTableLayout->Controls->Add(this->cfNewButton, 0, 1);
			this->cfBottomTableLayout->Controls->Add(this->cfSaveButton, 0, 2);
			this->cfBottomTableLayout->Location = System::Drawing::Point(12, 57);
			this->cfBottomTableLayout->Name = L"cfBottomTableLayout";
			this->cfBottomTableLayout->RowCount = 3;
			this->cfBottomTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				387)));
			this->cfBottomTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				43)));
			this->cfBottomTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				43)));
			this->cfBottomTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->cfBottomTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->cfBottomTableLayout->Size = System::Drawing::Size(300, 473);
			this->cfBottomTableLayout->TabIndex = 3;
			// 
			// cfEditButton
			// 
			this->cfEditButton->Enabled = false;
			this->cfEditButton->Location = System::Drawing::Point(153, 390);
			this->cfEditButton->Name = L"cfEditButton";
			this->cfEditButton->Size = System::Drawing::Size(144, 37);
			this->cfEditButton->TabIndex = 3;
			this->cfEditButton->Text = L"Edit";
			this->cfEditButton->UseVisualStyleBackColor = true;
			this->cfEditButton->Click += gcnew System::EventHandler(this, &CoreForm::cfEditButton_Click);
			// 
			// cfLoadButton
			// 
			this->cfLoadButton->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->cfLoadButton->Location = System::Drawing::Point(153, 433);
			this->cfLoadButton->Name = L"cfLoadButton";
			this->cfLoadButton->Size = System::Drawing::Size(144, 37);
			this->cfLoadButton->TabIndex = 5;
			this->cfLoadButton->Text = L"Load";
			this->cfLoadButton->UseVisualStyleBackColor = true;
			this->cfLoadButton->Click += gcnew System::EventHandler(this, &CoreForm::cfLoadButton_Click);
			// 
			// cfDataGrid
			// 
			this->cfDataGrid->AllowUserToAddRows = false;
			this->cfDataGrid->AllowUserToDeleteRows = false;
			this->cfDataGrid->AllowUserToResizeColumns = false;
			this->cfDataGrid->AllowUserToResizeRows = false;
			this->cfDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->cfDataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->cfDataGridNameColumn,
					this->cfDataGridAlignColumn, this->cfDataGridRaceColumn
			});
			this->cfBottomTableLayout->SetColumnSpan(this->cfDataGrid, 2);
			this->cfDataGrid->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->cfDataGrid->EnableHeadersVisualStyles = false;
			this->cfDataGrid->Location = System::Drawing::Point(3, 3);
			this->cfDataGrid->MultiSelect = false;
			this->cfDataGrid->Name = L"cfDataGrid";
			this->cfDataGrid->ReadOnly = true;
			this->cfDataGrid->RowHeadersVisible = false;
			this->cfDataGrid->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->cfDataGrid->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->cfDataGrid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->cfDataGrid->ShowEditingIcon = false;
			this->cfDataGrid->Size = System::Drawing::Size(294, 381);
			this->cfDataGrid->TabIndex = 9;
			this->cfDataGrid->TabStop = false;
			this->cfDataGrid->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &CoreForm::cfDataGrid_RowsAdded);
			this->cfDataGrid->RowsRemoved += gcnew System::Windows::Forms::DataGridViewRowsRemovedEventHandler(this, &CoreForm::cfDataGrid_RowsRemoved);
			// 
			// cfDataGridNameColumn
			// 
			this->cfDataGridNameColumn->HeaderText = L"Name";
			this->cfDataGridNameColumn->Name = L"cfDataGridNameColumn";
			this->cfDataGridNameColumn->ReadOnly = true;
			this->cfDataGridNameColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// cfDataGridAlignColumn
			// 
			this->cfDataGridAlignColumn->HeaderText = L"Alignment";
			this->cfDataGridAlignColumn->Name = L"cfDataGridAlignColumn";
			this->cfDataGridAlignColumn->ReadOnly = true;
			this->cfDataGridAlignColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// cfDataGridRaceColumn
			// 
			this->cfDataGridRaceColumn->HeaderText = L"Race";
			this->cfDataGridRaceColumn->Name = L"cfDataGridRaceColumn";
			this->cfDataGridRaceColumn->ReadOnly = true;
			this->cfDataGridRaceColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// cfNewButton
			// 
			this->cfNewButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->cfNewButton->Location = System::Drawing::Point(3, 390);
			this->cfNewButton->Name = L"cfNewButton";
			this->cfNewButton->Size = System::Drawing::Size(144, 37);
			this->cfNewButton->TabIndex = 2;
			this->cfNewButton->Text = L"New";
			this->cfNewButton->UseVisualStyleBackColor = true;
			this->cfNewButton->Click += gcnew System::EventHandler(this, &CoreForm::cfNewButton_Click);
			// 
			// cfSaveButton
			// 
			this->cfSaveButton->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->cfSaveButton->Enabled = false;
			this->cfSaveButton->Location = System::Drawing::Point(3, 433);
			this->cfSaveButton->Name = L"cfSaveButton";
			this->cfSaveButton->Size = System::Drawing::Size(144, 37);
			this->cfSaveButton->TabIndex = 4;
			this->cfSaveButton->Text = L"Save";
			this->cfSaveButton->UseVisualStyleBackColor = true;
			this->cfSaveButton->Click += gcnew System::EventHandler(this, &CoreForm::cfSaveButton_Click);
			// 
			// cfTopTableLayout
			// 
			this->cfTopTableLayout->ColumnCount = 3;
			this->cfTopTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66458F)));
			this->cfTopTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				66.67083F)));
			this->cfTopTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66458F)));
			this->cfTopTableLayout->Controls->Add(this->cfTitleLabel, 1, 0);
			this->cfTopTableLayout->Controls->Add(this->cfHelpButton, 2, 0);
			this->cfTopTableLayout->Location = System::Drawing::Point(12, 12);
			this->cfTopTableLayout->Name = L"cfTopTableLayout";
			this->cfTopTableLayout->RowCount = 1;
			this->cfTopTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->cfTopTableLayout->Size = System::Drawing::Size(300, 39);
			this->cfTopTableLayout->TabIndex = 4;
			// 
			// CoreForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(324, 542);
			this->Controls->Add(this->cfTopTableLayout);
			this->Controls->Add(this->cfBottomTableLayout);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"CoreForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"NPCSheet";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &CoreForm::CoreForm_FormClosing);
			this->cfBottomTableLayout->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cfDataGrid))->EndInit();
			this->cfTopTableLayout->ResumeLayout(false);
			this->cfTopTableLayout->PerformLayout();
			this->ResumeLayout(false);

		}

	// Declarations for events. 
	private: System::Void cfHelpButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cfNewButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cfEditButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cfSaveButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cfLoadButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CoreForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void cfDataGrid_RowsRemoved(System::Object^ sender, System::Windows::Forms::DataGridViewRowsRemovedEventArgs^ e);
	private: System::Void cfDataGrid_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e);
	private: System::Void DataGridRowUpdate();
};
}
#pragma endregion
