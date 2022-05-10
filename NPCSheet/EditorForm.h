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

	// Hand-written members of this form get lost in the sea of designer generated code!
	// Look for my comments to find them.

	/// <summary>
	/// Summary for EditorForm
	/// </summary>
	public ref class EditorForm : public System::Windows::Forms::Form
	{

	private: bool efUnsaved; // Bool for unsaved work.
	private: System::Windows::Forms::Button^ efRandomStatsButton;
	private: System::Windows::Forms::ComboBox^ efRaceComboBox;

	private: System::Windows::Forms::NumericUpDown^ efStat6NumUpDown;
	private: System::Windows::Forms::NumericUpDown^ efStat5NumUpDown;
	private: System::Windows::Forms::NumericUpDown^ efStat4NumUpDown;
	private: System::Windows::Forms::NumericUpDown^ efStat3NumUpDown;
	private: System::Windows::Forms::NumericUpDown^ efStat2NumUpDown;
	private: System::Windows::Forms::NumericUpDown^ efStat1NumUpDown;
	private: System::Windows::Forms::TableLayoutPanel^ efOtherStatsTableLayout;

	private: System::Windows::Forms::NumericUpDown^ efHPNumUpDown;

	private: System::Windows::Forms::Label^ efHitPointLabel;
	private: System::Windows::Forms::Label^ efStaminaLabel;
	private: System::Windows::Forms::NumericUpDown^ efSPNumUpDown;

	private: System::Windows::Forms::CheckBox^ efStaminaCheckBox;
	private: System::Windows::Forms::Label^ efEnableStaminaLabel;
	private: System::Windows::Forms::Label^ efInitLabel;
	private: System::Windows::Forms::NumericUpDown^ efInitNumUpDown;
	private: System::Windows::Forms::Label^ efDefensesLabel;
	private: System::Windows::Forms::TableLayoutPanel^ efDefensesTableLayout;
	private: System::Windows::Forms::Label^ efDividerLabel;
	private: System::Windows::Forms::CheckBox^ efDef3UseCheckBox;

	private: System::Windows::Forms::CheckBox^ efDef2UseCheckBox;

	private: System::Windows::Forms::Label^ efDef3UseLabel;
	private: System::Windows::Forms::Label^ efDef2UseLabel;
	private: System::Windows::Forms::Label^ efDividerLabel2;
	private: System::Windows::Forms::Label^ efSkillsLabel;
	private: System::Windows::Forms::Label^ efSavesLabel;
	private: System::Windows::Forms::TextBox^ efDef3TextBox;
	private: System::Windows::Forms::TextBox^ efDef2TextBox;
	private: System::Windows::Forms::TextBox^ efDef1TextBox;
	private: System::Windows::Forms::NumericUpDown^ efDef2NumUpDown;
	private: System::Windows::Forms::NumericUpDown^ efDef1NumUpDown;
	private: System::Windows::Forms::NumericUpDown^ efDef3NumUpDown;
	private: System::Windows::Forms::TableLayoutPanel^ efSavesSkillsTableLayout;

	private: System::Windows::Forms::NumericUpDown^ efSkillsNumUpDown;
	private: System::Windows::Forms::NumericUpDown^ efSavesNumUpDown;
	private: System::Windows::Forms::TextBox^ efSavesTextBox;
	private: System::Windows::Forms::ListBox^ efSavesListBox;
	private: System::Windows::Forms::ListBox^ efSkillsListBox;
	private: System::Windows::Forms::TextBox^ efSkillsTextBox;
	private: System::Windows::Forms::Button^ efSkillsDeleteButton;
	private: System::Windows::Forms::Button^ efSavesDeleteButton;
	private: System::Windows::Forms::Button^ efSkillsAddButton;
	private: System::Windows::Forms::Button^ efSavesAddButton;
	private: System::Windows::Forms::TableLayoutPanel^ efSpellsTableLayout;
	private: System::Windows::Forms::Label^ efSpellsLabel;


	private: System::Windows::Forms::ListBox^ efSpellsListBox;
	private: System::Windows::Forms::TextBox^ efSpellsTextBox;

	private: System::Windows::Forms::Button^ efSpellsAddButton;
	private: System::Windows::Forms::Button^ efSpellsRemoveButton;
	private: System::Windows::Forms::NumericUpDown^ efSpellsNumUpDown;
	private: System::Windows::Forms::Label^ efActionsLabel;
	private: System::Windows::Forms::TextBox^ efActionDescTextBox;
	private: System::Windows::Forms::Button^ efViewButton;
	private: System::Windows::Forms::Button^ efActionDeleteButton;

	private: System::Windows::Forms::Button^ efActionAddButton;

	private: System::Windows::Forms::TextBox^ efActionNameTextBox;
	private: System::Windows::Forms::ListBox^ efActionListBox;
	private: System::Windows::Forms::Label^ efHorizLineLabel3;

	private: System::Windows::Forms::Label^ efVertLineLabel;
	private: System::Windows::Forms::Label^ efWeaponsLabel;
	private: System::Windows::Forms::ListBox^ efWeaponsListBox;

	private: System::Windows::Forms::Button^ efDeleteWeapButton;
	private: System::Windows::Forms::Label^ efDividerLabel5;




	private: System::Windows::Forms::Button^ efWeaponCreatorButton;
	private: System::Windows::Forms::Label^ efTraitsLabel;
	private: System::Windows::Forms::TextBox^ efTraitNameTextBox;



	private: System::Windows::Forms::TextBox^ efTraitDescTextBox;

	private: System::Windows::Forms::Button^ efItemAddButton;
	private: System::Windows::Forms::Button^ efItemDeleteButton;





	private: System::Windows::Forms::Label^ efItemsLabel;
	private: System::Windows::Forms::TextBox^ efItemTextBox;
	private: System::Windows::Forms::ListBox^ efItemsListBox;





	private: System::Windows::Forms::Button^ efAddTraitButton;

	private: System::Windows::Forms::NumericUpDown^ efItemQtyNumUpDown;
	private: System::Windows::Forms::TableLayoutPanel^ efTraitsTableLayout;
	
	private: System::Windows::Forms::ListBox^ efTraitsListBox;
	private: System::Windows::Forms::Button^ efTraitViewButton;
	private: System::Windows::Forms::Button^ efTraitDeleteButton;
	private: System::Windows::Forms::Label^ efLineLabel4;
	private: System::Windows::Forms::Label^ efAppearanceLabel;
	private: System::Windows::Forms::TableLayoutPanel^ efTacticsTableLayout;
	
	
	
	private: System::Windows::Forms::Label^ efTacticsLabel;
	private: System::Windows::Forms::TextBox^ efTMorTextBox;
	
	
	private: System::Windows::Forms::TextBox^ efTComTextBox;
	
	private: System::Windows::Forms::Label^ efTMoraleLabel;
	
	private: System::Windows::Forms::Label^ efTSocialLabel;
	private: System::Windows::Forms::TextBox^ efTSocTextBox;
	
	
	private: System::Windows::Forms::Label^ efTCombatLabel;
	
	private: System::Windows::Forms::Label^ efGoalsMotivesLabel;
	private: System::Windows::Forms::Label^ efPersonalityLabel;
	private: System::Windows::Forms::TableLayoutPanel^ efIBFTableLayout;
	
	
	
	
	
	
	
	private: System::Windows::Forms::ListBox^ efFlawsListBox;
	
	private: System::Windows::Forms::ListBox^ efBondsListBox;
	
	private: System::Windows::Forms::Button^ efFDelButton;
	
	private: System::Windows::Forms::Button^ efFViewButton;
	
	private: System::Windows::Forms::Button^ efFAddButton;
	
	private: System::Windows::Forms::Button^ efBDelButton;
	
	
	private: System::Windows::Forms::Button^ efBViewButton;
	
	private: System::Windows::Forms::Button^ efBAddButton;
	
	private: System::Windows::Forms::Button^ efIDelButton;
	
	private: System::Windows::Forms::Button^ efIViewButton;
	
	private: System::Windows::Forms::TextBox^ efFlawsTextBox;
	
	private: System::Windows::Forms::TextBox^ efBondsTextBox;
	
	private: System::Windows::Forms::Label^ efIdealsLabel;
	private: System::Windows::Forms::Label^ efBondsLabel;
	private: System::Windows::Forms::Label^ efFlawsLabel;
	private: System::Windows::Forms::TextBox^ efIdealsTextBox;
	private: System::Windows::Forms::Button^ efIAddButton;
	private: System::Windows::Forms::ListBox^ efIdealsListBox;
	private: System::Windows::Forms::TableLayoutPanel^ efDescTableLayout;
	
	
	
	
	
	
	
	private: System::Windows::Forms::TextBox^ efGoalMotTextBox;
	
	private: System::Windows::Forms::TextBox^ efAppearTextBox;
	private: System::Windows::Forms::TextBox^ efPersoTextBox;
	private: System::Windows::Forms::Label^ efAddlStatsLabel;
	private: System::Windows::Forms::TextBox^ efAddlStatsTextBox;













	private: int wizardStep; // Stage tracker for wizard.
	private: NPC^ n; // Temporary NPC object that will be returned if all is good. 
	private: System::Windows::Forms::Label^ efVertLabel2;
	private: System::Windows::Forms::Label^ label1;

	private: array<bool>^ stepSeen;
	private: array<String^>^ tradAtts;
	public: NPC^ retNPC(); // Function that returns the NPC being edited. This will only be called when DialogueResult is OK.
	private: System::Windows::Forms::TableLayoutPanel^ efCoreInfoTableLayout;

	private: System::Windows::Forms::TextBox^ efAlignmentTextBox;
	private: System::Windows::Forms::Label^ efAlignmentLabel;
	private: System::Windows::Forms::TextBox^ efRaceTextBox;

	private: System::Windows::Forms::TextBox^ efNameTextBox;
	private: System::Windows::Forms::Label^ efNameLabel;
	private: System::Windows::Forms::TabPage^ efTabPage3;
	private: System::Windows::Forms::TabPage^ efTabPage4;
	private: System::Windows::Forms::TabPage^ efTabPage5;
	private: System::Windows::Forms::TextBox^ efLanguagesTextBox;

	private: System::Windows::Forms::Label^ efTypeLabel;
	private: System::Windows::Forms::TextBox^ efTypeTextBox;
	private: System::Windows::Forms::TextBox^ efTagTextBox;
	private: System::Windows::Forms::Label^ efLanguagesLabel;
	private: System::Windows::Forms::TextBox^ efSensesTextBox;
	private: System::Windows::Forms::Label^ efSensesLabel;
	private: System::Windows::Forms::CheckBox^ efStatsCheckBox;
	private: System::Windows::Forms::Label^ efUseTraditionalLabel;


	private: System::Windows::Forms::Label^ efStatsLabel;
	private: System::Windows::Forms::TableLayoutPanel^ efStatsTableLayout;

	private: System::Windows::Forms::Label^ efStat6ModLabel;

	private: System::Windows::Forms::Label^ efStat5ModLabel;

	private: System::Windows::Forms::Label^ efStat4ModLabel;

	private: System::Windows::Forms::Label^ efStat3ModLabel;

	private: System::Windows::Forms::Label^ efStat2ModLabel;

	private: System::Windows::Forms::Label^ efStat1ModLabel;




	private: System::Windows::Forms::TextBox^ efStat6TextBox;
	private: System::Windows::Forms::TextBox^ efStat5TextBox;
	private: System::Windows::Forms::TextBox^ efStat4TextBox;
	private: System::Windows::Forms::TextBox^ efStat3TextBox;
	private: System::Windows::Forms::TextBox^ efStat2TextBox;
	private: System::Windows::Forms::TextBox^ efStat1TextBox;




	public:
		// Default constructor uses a wizard to create a new form.
		EditorForm(bool w) {
			InitializeComponent();
			n = gcnew NPC();
			tradAtts = gcnew array<String^>{
				"Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma"};
			stepSeen = gcnew array<bool>(11);
			for each (bool b in stepSeen) { b = false; }
			efUnsaved = false;
			//efSaveButton->Enabled = false;
			efNextButton->Visible = true;
			efStatsCheckBox->Checked = true;
			efRaceComboBox->SelectedIndex = 0;
			efStaminaCheckBox->Checked = false;
			efDef1TextBox->Text = "AC";
			efDef1NumUpDown->Value = 10;
			efDef2UseCheckBox->Checked = false;
			efDef3UseCheckBox->Checked = false;

			array<NumericUpDown^>^ statNumUpDown = gcnew array<NumericUpDown^>{
				efStat1NumUpDown, efStat2NumUpDown, efStat3NumUpDown, efStat4NumUpDown, efStat5NumUpDown, efStat6NumUpDown
			};
			for (int i = 0; i <= 5; ++i) { statNumUpDown[i]->Value = 10; }
			// w value indicates whether the wizard is enabled or not.
			if (w) { wizardStep = 0; }
			else { 
				wizardStep = -1;
				efNextButton->Visible = false;
			}
		}

		// Constructor for editing an existing NPC.
		EditorForm(NPC^ npc) {
			InitializeComponent();
			n = npc; // Copy npc passed by reference so edits can be cancelled if necessary. 
			efDef2UseCheckBox->Checked = false;
			efDef3UseCheckBox->Checked = false;
			LoadMyNPC();
			efUnsaved = false;
			efSaveButton->Enabled = true;
			efNextButton->Visible = false;
			efRandomStatsButton->Visible = false;
			wizardStep = -1;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditorForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^ efSaveButton;
	private: System::Windows::Forms::Button^ efCancelButton;
	private: System::Windows::Forms::TabControl^ efTabControl;
	private: System::Windows::Forms::TabPage^ efTabPage1;
	private: System::Windows::Forms::TabPage^ efTabPage2;
	private: System::Windows::Forms::Button^ efNextButton;




	protected:

	protected:

	protected:




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->efNextButton = (gcnew System::Windows::Forms::Button());
			this->efTabControl = (gcnew System::Windows::Forms::TabControl());
			this->efTabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->efCoreInfoTableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->efAlignmentTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efAlignmentLabel = (gcnew System::Windows::Forms::Label());
			this->efRaceTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efNameLabel = (gcnew System::Windows::Forms::Label());
			this->efTypeLabel = (gcnew System::Windows::Forms::Label());
			this->efTypeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efTagTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efLanguagesLabel = (gcnew System::Windows::Forms::Label());
			this->efLanguagesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efSensesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efSensesLabel = (gcnew System::Windows::Forms::Label());
			this->efRaceComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->efAddlStatsLabel = (gcnew System::Windows::Forms::Label());
			this->efAddlStatsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efTabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->efSkillsDeleteButton = (gcnew System::Windows::Forms::Button());
			this->efSavesDeleteButton = (gcnew System::Windows::Forms::Button());
			this->efSkillsAddButton = (gcnew System::Windows::Forms::Button());
			this->efSavesAddButton = (gcnew System::Windows::Forms::Button());
			this->efDef3UseCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->efDef2UseCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->efDef3UseLabel = (gcnew System::Windows::Forms::Label());
			this->efDef2UseLabel = (gcnew System::Windows::Forms::Label());
			this->efDividerLabel2 = (gcnew System::Windows::Forms::Label());
			this->efSkillsLabel = (gcnew System::Windows::Forms::Label());
			this->efSavesLabel = (gcnew System::Windows::Forms::Label());
			this->efDividerLabel = (gcnew System::Windows::Forms::Label());
			this->efDefensesLabel = (gcnew System::Windows::Forms::Label());
			this->efDefensesTableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->efDef3TextBox = (gcnew System::Windows::Forms::TextBox());
			this->efDef2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->efDef1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->efDef2NumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->efDef1NumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->efDef3NumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->efRandomStatsButton = (gcnew System::Windows::Forms::Button());
			this->efStatsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->efUseTraditionalLabel = (gcnew System::Windows::Forms::Label());
			this->efStatsLabel = (gcnew System::Windows::Forms::Label());
			this->efStatsTableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->efStat6NumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->efStat6ModLabel = (gcnew System::Windows::Forms::Label());
			this->efStat3NumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->efStat2NumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->efStat5NumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->efStat1NumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->efStat5ModLabel = (gcnew System::Windows::Forms::Label());
			this->efStat3ModLabel = (gcnew System::Windows::Forms::Label());
			this->efStat2ModLabel = (gcnew System::Windows::Forms::Label());
			this->efStat4NumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->efStat1ModLabel = (gcnew System::Windows::Forms::Label());
			this->efStat3TextBox = (gcnew System::Windows::Forms::TextBox());
			this->efStat6TextBox = (gcnew System::Windows::Forms::TextBox());
			this->efStat2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->efStat4ModLabel = (gcnew System::Windows::Forms::Label());
			this->efStat1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->efStat4TextBox = (gcnew System::Windows::Forms::TextBox());
			this->efStat5TextBox = (gcnew System::Windows::Forms::TextBox());
			this->efOtherStatsTableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->efHitPointLabel = (gcnew System::Windows::Forms::Label());
			this->efStaminaLabel = (gcnew System::Windows::Forms::Label());
			this->efStaminaCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->efEnableStaminaLabel = (gcnew System::Windows::Forms::Label());
			this->efHPNumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->efSPNumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->efInitLabel = (gcnew System::Windows::Forms::Label());
			this->efInitNumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->efSavesSkillsTableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->efSkillsNumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->efSavesNumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->efSavesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efSavesListBox = (gcnew System::Windows::Forms::ListBox());
			this->efSkillsListBox = (gcnew System::Windows::Forms::ListBox());
			this->efSkillsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efTabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->efWeaponCreatorButton = (gcnew System::Windows::Forms::Button());
			this->efDeleteWeapButton = (gcnew System::Windows::Forms::Button());
			this->efDividerLabel5 = (gcnew System::Windows::Forms::Label());
			this->efWeaponsListBox = (gcnew System::Windows::Forms::ListBox());
			this->efVertLineLabel = (gcnew System::Windows::Forms::Label());
			this->efWeaponsLabel = (gcnew System::Windows::Forms::Label());
			this->efHorizLineLabel3 = (gcnew System::Windows::Forms::Label());
			this->efViewButton = (gcnew System::Windows::Forms::Button());
			this->efActionDeleteButton = (gcnew System::Windows::Forms::Button());
			this->efActionAddButton = (gcnew System::Windows::Forms::Button());
			this->efActionNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efActionListBox = (gcnew System::Windows::Forms::ListBox());
			this->efActionsLabel = (gcnew System::Windows::Forms::Label());
			this->efActionDescTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efSpellsTableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->efSpellsListBox = (gcnew System::Windows::Forms::ListBox());
			this->efSpellsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efSpellsLabel = (gcnew System::Windows::Forms::Label());
			this->efSpellsAddButton = (gcnew System::Windows::Forms::Button());
			this->efSpellsRemoveButton = (gcnew System::Windows::Forms::Button());
			this->efSpellsNumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->efTabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->efLineLabel4 = (gcnew System::Windows::Forms::Label());
			this->efTraitsTableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->efTraitViewButton = (gcnew System::Windows::Forms::Button());
			this->efTraitDeleteButton = (gcnew System::Windows::Forms::Button());
			this->efTraitNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efTraitsLabel = (gcnew System::Windows::Forms::Label());
			this->efAddTraitButton = (gcnew System::Windows::Forms::Button());
			this->efTraitDescTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efTraitsListBox = (gcnew System::Windows::Forms::ListBox());
			this->efItemQtyNumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->efItemAddButton = (gcnew System::Windows::Forms::Button());
			this->efItemDeleteButton = (gcnew System::Windows::Forms::Button());
			this->efItemsLabel = (gcnew System::Windows::Forms::Label());
			this->efItemTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efItemsListBox = (gcnew System::Windows::Forms::ListBox());
			this->efTabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->efVertLabel2 = (gcnew System::Windows::Forms::Label());
			this->efDescTableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->efGoalMotTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efGoalsMotivesLabel = (gcnew System::Windows::Forms::Label());
			this->efPersonalityLabel = (gcnew System::Windows::Forms::Label());
			this->efAppearTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efPersoTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efAppearanceLabel = (gcnew System::Windows::Forms::Label());
			this->efIBFTableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->efFlawsListBox = (gcnew System::Windows::Forms::ListBox());
			this->efBondsListBox = (gcnew System::Windows::Forms::ListBox());
			this->efFDelButton = (gcnew System::Windows::Forms::Button());
			this->efFViewButton = (gcnew System::Windows::Forms::Button());
			this->efFAddButton = (gcnew System::Windows::Forms::Button());
			this->efBDelButton = (gcnew System::Windows::Forms::Button());
			this->efBViewButton = (gcnew System::Windows::Forms::Button());
			this->efBAddButton = (gcnew System::Windows::Forms::Button());
			this->efIDelButton = (gcnew System::Windows::Forms::Button());
			this->efIViewButton = (gcnew System::Windows::Forms::Button());
			this->efFlawsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efBondsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efIdealsLabel = (gcnew System::Windows::Forms::Label());
			this->efBondsLabel = (gcnew System::Windows::Forms::Label());
			this->efIdealsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efIAddButton = (gcnew System::Windows::Forms::Button());
			this->efIdealsListBox = (gcnew System::Windows::Forms::ListBox());
			this->efFlawsLabel = (gcnew System::Windows::Forms::Label());
			this->efTacticsTableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->efTacticsLabel = (gcnew System::Windows::Forms::Label());
			this->efTMorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efTMoraleLabel = (gcnew System::Windows::Forms::Label());
			this->efTSocialLabel = (gcnew System::Windows::Forms::Label());
			this->efTSocTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efTCombatLabel = (gcnew System::Windows::Forms::Label());
			this->efTComTextBox = (gcnew System::Windows::Forms::TextBox());
			this->efSaveButton = (gcnew System::Windows::Forms::Button());
			this->efCancelButton = (gcnew System::Windows::Forms::Button());
			this->efTabControl->SuspendLayout();
			this->efTabPage1->SuspendLayout();
			this->efCoreInfoTableLayout->SuspendLayout();
			this->efTabPage2->SuspendLayout();
			this->efDefensesTableLayout->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efDef2NumUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efDef1NumUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efDef3NumUpDown))->BeginInit();
			this->efStatsTableLayout->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efStat6NumUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efStat3NumUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efStat2NumUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efStat5NumUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efStat1NumUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efStat4NumUpDown))->BeginInit();
			this->efOtherStatsTableLayout->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efHPNumUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efSPNumUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efInitNumUpDown))->BeginInit();
			this->efSavesSkillsTableLayout->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efSkillsNumUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efSavesNumUpDown))->BeginInit();
			this->efTabPage3->SuspendLayout();
			this->efSpellsTableLayout->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efSpellsNumUpDown))->BeginInit();
			this->efTabPage4->SuspendLayout();
			this->efTraitsTableLayout->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efItemQtyNumUpDown))->BeginInit();
			this->efTabPage5->SuspendLayout();
			this->efDescTableLayout->SuspendLayout();
			this->efIBFTableLayout->SuspendLayout();
			this->efTacticsTableLayout->SuspendLayout();
			this->SuspendLayout();
			// 
			// efNextButton
			// 
			this->efNextButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efNextButton->Location = System::Drawing::Point(248, 587);
			this->efNextButton->Name = L"efNextButton";
			this->efNextButton->Size = System::Drawing::Size(116, 37);
			this->efNextButton->TabIndex = 2;
			this->efNextButton->Text = L"Next";
			this->efNextButton->UseVisualStyleBackColor = true;
			this->efNextButton->Click += gcnew System::EventHandler(this, &EditorForm::efNextButton_Click);
			// 
			// efTabControl
			// 
			this->efTabControl->Controls->Add(this->efTabPage1);
			this->efTabControl->Controls->Add(this->efTabPage2);
			this->efTabControl->Controls->Add(this->efTabPage3);
			this->efTabControl->Controls->Add(this->efTabPage4);
			this->efTabControl->Controls->Add(this->efTabPage5);
			this->efTabControl->Location = System::Drawing::Point(0, 9);
			this->efTabControl->Margin = System::Windows::Forms::Padding(0, 0, 0, 3);
			this->efTabControl->Name = L"efTabControl";
			this->efTabControl->SelectedIndex = 0;
			this->efTabControl->Size = System::Drawing::Size(491, 572);
			this->efTabControl->TabIndex = 5;
			this->efTabControl->Selecting += gcnew System::Windows::Forms::TabControlCancelEventHandler(this, &EditorForm::efTabControl_Selecting);
			// 
			// efTabPage1
			// 
			this->efTabPage1->Controls->Add(this->efCoreInfoTableLayout);
			this->efTabPage1->Location = System::Drawing::Point(4, 22);
			this->efTabPage1->Name = L"efTabPage1";
			this->efTabPage1->Padding = System::Windows::Forms::Padding(3);
			this->efTabPage1->Size = System::Drawing::Size(483, 546);
			this->efTabPage1->TabIndex = 0;
			this->efTabPage1->Text = L"Core Info";
			this->efTabPage1->UseVisualStyleBackColor = true;
			// 
			// efCoreInfoTableLayout
			// 
			this->efCoreInfoTableLayout->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->efCoreInfoTableLayout->ColumnCount = 3;
			this->efCoreInfoTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				120)));
			this->efCoreInfoTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				174)));
			this->efCoreInfoTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				178)));
			this->efCoreInfoTableLayout->Controls->Add(this->efAlignmentTextBox, 1, 2);
			this->efCoreInfoTableLayout->Controls->Add(this->efAlignmentLabel, 0, 2);
			this->efCoreInfoTableLayout->Controls->Add(this->efRaceTextBox, 1, 1);
			this->efCoreInfoTableLayout->Controls->Add(this->efNameTextBox, 1, 0);
			this->efCoreInfoTableLayout->Controls->Add(this->efNameLabel, 0, 0);
			this->efCoreInfoTableLayout->Controls->Add(this->efTypeLabel, 0, 3);
			this->efCoreInfoTableLayout->Controls->Add(this->efTypeTextBox, 1, 3);
			this->efCoreInfoTableLayout->Controls->Add(this->efTagTextBox, 2, 3);
			this->efCoreInfoTableLayout->Controls->Add(this->efLanguagesLabel, 0, 5);
			this->efCoreInfoTableLayout->Controls->Add(this->efLanguagesTextBox, 1, 4);
			this->efCoreInfoTableLayout->Controls->Add(this->efSensesTextBox, 1, 7);
			this->efCoreInfoTableLayout->Controls->Add(this->efSensesLabel, 0, 8);
			this->efCoreInfoTableLayout->Controls->Add(this->efRaceComboBox, 0, 1);
			this->efCoreInfoTableLayout->Controls->Add(this->efAddlStatsLabel, 0, 11);
			this->efCoreInfoTableLayout->Controls->Add(this->efAddlStatsTextBox, 1, 10);
			this->efCoreInfoTableLayout->Location = System::Drawing::Point(6, 6);
			this->efCoreInfoTableLayout->Name = L"efCoreInfoTableLayout";
			this->efCoreInfoTableLayout->RowCount = 14;
			this->efCoreInfoTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				36)));
			this->efCoreInfoTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				36)));
			this->efCoreInfoTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				36)));
			this->efCoreInfoTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				36)));
			this->efCoreInfoTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				36)));
			this->efCoreInfoTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				36)));
			this->efCoreInfoTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				36)));
			this->efCoreInfoTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				36)));
			this->efCoreInfoTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				36)));
			this->efCoreInfoTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				36)));
			this->efCoreInfoTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				36)));
			this->efCoreInfoTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				36)));
			this->efCoreInfoTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				36)));
			this->efCoreInfoTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				36)));
			this->efCoreInfoTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->efCoreInfoTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->efCoreInfoTableLayout->Size = System::Drawing::Size(472, 534);
			this->efCoreInfoTableLayout->TabIndex = 2;
			// 
			// efAlignmentTextBox
			// 
			this->efCoreInfoTableLayout->SetColumnSpan(this->efAlignmentTextBox, 2);
			this->efAlignmentTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->efAlignmentTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efAlignmentTextBox->Location = System::Drawing::Point(123, 75);
			this->efAlignmentTextBox->Name = L"efAlignmentTextBox";
			this->efAlignmentTextBox->Size = System::Drawing::Size(346, 31);
			this->efAlignmentTextBox->TabIndex = 4;
			// 
			// efAlignmentLabel
			// 
			this->efAlignmentLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->efAlignmentLabel->AutoSize = true;
			this->efAlignmentLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efAlignmentLabel->Location = System::Drawing::Point(3, 75);
			this->efAlignmentLabel->Name = L"efAlignmentLabel";
			this->efAlignmentLabel->Size = System::Drawing::Size(109, 30);
			this->efAlignmentLabel->TabIndex = 5;
			this->efAlignmentLabel->Text = L"Alignment";
			// 
			// efRaceTextBox
			// 
			this->efCoreInfoTableLayout->SetColumnSpan(this->efRaceTextBox, 2);
			this->efRaceTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->efRaceTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efRaceTextBox->Location = System::Drawing::Point(123, 39);
			this->efRaceTextBox->Name = L"efRaceTextBox";
			this->efRaceTextBox->Size = System::Drawing::Size(346, 31);
			this->efRaceTextBox->TabIndex = 3;
			this->efRaceTextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efNameTextBox
			// 
			this->efNameTextBox->BackColor = System::Drawing::SystemColors::Window;
			this->efCoreInfoTableLayout->SetColumnSpan(this->efNameTextBox, 2);
			this->efNameTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->efNameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efNameTextBox->Location = System::Drawing::Point(123, 3);
			this->efNameTextBox->Name = L"efNameTextBox";
			this->efNameTextBox->Size = System::Drawing::Size(346, 31);
			this->efNameTextBox->TabIndex = 1;
			this->efNameTextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efNameLabel
			// 
			this->efNameLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->efNameLabel->AutoSize = true;
			this->efNameLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efNameLabel->Location = System::Drawing::Point(3, 3);
			this->efNameLabel->Name = L"efNameLabel";
			this->efNameLabel->Size = System::Drawing::Size(69, 30);
			this->efNameLabel->TabIndex = 1;
			this->efNameLabel->Text = L"Name";
			// 
			// efTypeLabel
			// 
			this->efTypeLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->efTypeLabel->AutoSize = true;
			this->efTypeLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efTypeLabel->Location = System::Drawing::Point(3, 111);
			this->efTypeLabel->Name = L"efTypeLabel";
			this->efTypeLabel->Size = System::Drawing::Size(56, 30);
			this->efTypeLabel->TabIndex = 7;
			this->efTypeLabel->Text = L"Type";
			// 
			// efTypeTextBox
			// 
			this->efTypeTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->efTypeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efTypeTextBox->Location = System::Drawing::Point(123, 111);
			this->efTypeTextBox->Name = L"efTypeTextBox";
			this->efTypeTextBox->Size = System::Drawing::Size(168, 31);
			this->efTypeTextBox->TabIndex = 5;
			this->efTypeTextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efTagTextBox
			// 
			this->efTagTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->efTagTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efTagTextBox->Location = System::Drawing::Point(297, 111);
			this->efTagTextBox->Name = L"efTagTextBox";
			this->efTagTextBox->Size = System::Drawing::Size(172, 31);
			this->efTagTextBox->TabIndex = 6;
			// 
			// efLanguagesLabel
			// 
			this->efLanguagesLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->efLanguagesLabel->AutoSize = true;
			this->efLanguagesLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efLanguagesLabel->Location = System::Drawing::Point(3, 183);
			this->efLanguagesLabel->Name = L"efLanguagesLabel";
			this->efLanguagesLabel->Size = System::Drawing::Size(113, 30);
			this->efLanguagesLabel->TabIndex = 10;
			this->efLanguagesLabel->Text = L"Languages";
			// 
			// efLanguagesTextBox
			// 
			this->efCoreInfoTableLayout->SetColumnSpan(this->efLanguagesTextBox, 2);
			this->efLanguagesTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->efLanguagesTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efLanguagesTextBox->Location = System::Drawing::Point(123, 147);
			this->efLanguagesTextBox->Multiline = true;
			this->efLanguagesTextBox->Name = L"efLanguagesTextBox";
			this->efCoreInfoTableLayout->SetRowSpan(this->efLanguagesTextBox, 3);
			this->efLanguagesTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->efLanguagesTextBox->Size = System::Drawing::Size(346, 102);
			this->efLanguagesTextBox->TabIndex = 7;
			this->efLanguagesTextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efSensesTextBox
			// 
			this->efCoreInfoTableLayout->SetColumnSpan(this->efSensesTextBox, 2);
			this->efSensesTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efSensesTextBox->Location = System::Drawing::Point(123, 255);
			this->efSensesTextBox->Multiline = true;
			this->efSensesTextBox->Name = L"efSensesTextBox";
			this->efCoreInfoTableLayout->SetRowSpan(this->efSensesTextBox, 3);
			this->efSensesTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->efSensesTextBox->Size = System::Drawing::Size(346, 102);
			this->efSensesTextBox->TabIndex = 8;
			this->efSensesTextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efSensesLabel
			// 
			this->efSensesLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->efSensesLabel->AutoSize = true;
			this->efSensesLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efSensesLabel->Location = System::Drawing::Point(3, 291);
			this->efSensesLabel->Name = L"efSensesLabel";
			this->efSensesLabel->Size = System::Drawing::Size(76, 30);
			this->efSensesLabel->TabIndex = 13;
			this->efSensesLabel->Text = L"Senses";
			// 
			// efRaceComboBox
			// 
			this->efRaceComboBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->efRaceComboBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efRaceComboBox->FormattingEnabled = true;
			this->efRaceComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Race", L"Ancestry" });
			this->efRaceComboBox->Location = System::Drawing::Point(3, 39);
			this->efRaceComboBox->Name = L"efRaceComboBox";
			this->efRaceComboBox->Size = System::Drawing::Size(114, 33);
			this->efRaceComboBox->TabIndex = 2;
			this->efRaceComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EditorForm::efRaceComboBox_SelectedIndexChanged);
			// 
			// efAddlStatsLabel
			// 
			this->efAddlStatsLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->efAddlStatsLabel->AutoSize = true;
			this->efAddlStatsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efAddlStatsLabel->Location = System::Drawing::Point(3, 399);
			this->efAddlStatsLabel->Name = L"efAddlStatsLabel";
			this->efAddlStatsLabel->Size = System::Drawing::Size(93, 30);
			this->efAddlStatsLabel->TabIndex = 15;
			this->efAddlStatsLabel->Text = L"Statistics";
			// 
			// efAddlStatsTextBox
			// 
			this->efCoreInfoTableLayout->SetColumnSpan(this->efAddlStatsTextBox, 2);
			this->efAddlStatsTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efAddlStatsTextBox->Location = System::Drawing::Point(123, 363);
			this->efAddlStatsTextBox->Multiline = true;
			this->efAddlStatsTextBox->Name = L"efAddlStatsTextBox";
			this->efCoreInfoTableLayout->SetRowSpan(this->efAddlStatsTextBox, 3);
			this->efAddlStatsTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->efAddlStatsTextBox->Size = System::Drawing::Size(346, 102);
			this->efAddlStatsTextBox->TabIndex = 9;
			// 
			// efTabPage2
			// 
			this->efTabPage2->Controls->Add(this->efSkillsDeleteButton);
			this->efTabPage2->Controls->Add(this->efSavesDeleteButton);
			this->efTabPage2->Controls->Add(this->efSkillsAddButton);
			this->efTabPage2->Controls->Add(this->efSavesAddButton);
			this->efTabPage2->Controls->Add(this->efDef3UseCheckBox);
			this->efTabPage2->Controls->Add(this->efDef2UseCheckBox);
			this->efTabPage2->Controls->Add(this->efDef3UseLabel);
			this->efTabPage2->Controls->Add(this->efDef2UseLabel);
			this->efTabPage2->Controls->Add(this->efDividerLabel2);
			this->efTabPage2->Controls->Add(this->efSkillsLabel);
			this->efTabPage2->Controls->Add(this->efSavesLabel);
			this->efTabPage2->Controls->Add(this->efDividerLabel);
			this->efTabPage2->Controls->Add(this->efDefensesLabel);
			this->efTabPage2->Controls->Add(this->efDefensesTableLayout);
			this->efTabPage2->Controls->Add(this->efRandomStatsButton);
			this->efTabPage2->Controls->Add(this->efStatsCheckBox);
			this->efTabPage2->Controls->Add(this->efUseTraditionalLabel);
			this->efTabPage2->Controls->Add(this->efStatsLabel);
			this->efTabPage2->Controls->Add(this->efStatsTableLayout);
			this->efTabPage2->Controls->Add(this->efOtherStatsTableLayout);
			this->efTabPage2->Controls->Add(this->efSavesSkillsTableLayout);
			this->efTabPage2->Location = System::Drawing::Point(4, 22);
			this->efTabPage2->Name = L"efTabPage2";
			this->efTabPage2->Padding = System::Windows::Forms::Padding(3);
			this->efTabPage2->Size = System::Drawing::Size(483, 546);
			this->efTabPage2->TabIndex = 1;
			this->efTabPage2->Text = L"Stats";
			this->efTabPage2->UseVisualStyleBackColor = true;
			// 
			// efSkillsDeleteButton
			// 
			this->efSkillsDeleteButton->Location = System::Drawing::Point(406, 332);
			this->efSkillsDeleteButton->Name = L"efSkillsDeleteButton";
			this->efSkillsDeleteButton->Size = System::Drawing::Size(63, 23);
			this->efSkillsDeleteButton->TabIndex = 34;
			this->efSkillsDeleteButton->Text = L"Delete";
			this->efSkillsDeleteButton->UseVisualStyleBackColor = true;
			this->efSkillsDeleteButton->Click += gcnew System::EventHandler(this, &EditorForm::efSkillsDeleteButton_Click);
			// 
			// efSavesDeleteButton
			// 
			this->efSavesDeleteButton->Location = System::Drawing::Point(171, 332);
			this->efSavesDeleteButton->Name = L"efSavesDeleteButton";
			this->efSavesDeleteButton->Size = System::Drawing::Size(63, 23);
			this->efSavesDeleteButton->TabIndex = 29;
			this->efSavesDeleteButton->Text = L"Delete";
			this->efSavesDeleteButton->UseVisualStyleBackColor = true;
			this->efSavesDeleteButton->Click += gcnew System::EventHandler(this, &EditorForm::efSavesDeleteButton_Click);
			// 
			// efSkillsAddButton
			// 
			this->efSkillsAddButton->Location = System::Drawing::Point(337, 332);
			this->efSkillsAddButton->Name = L"efSkillsAddButton";
			this->efSkillsAddButton->Size = System::Drawing::Size(63, 23);
			this->efSkillsAddButton->TabIndex = 33;
			this->efSkillsAddButton->Text = L"Add";
			this->efSkillsAddButton->UseVisualStyleBackColor = true;
			this->efSkillsAddButton->Click += gcnew System::EventHandler(this, &EditorForm::efSkillsAddButton_Click);
			// 
			// efSavesAddButton
			// 
			this->efSavesAddButton->Location = System::Drawing::Point(102, 332);
			this->efSavesAddButton->Name = L"efSavesAddButton";
			this->efSavesAddButton->Size = System::Drawing::Size(63, 23);
			this->efSavesAddButton->TabIndex = 28;
			this->efSavesAddButton->Text = L"Add";
			this->efSavesAddButton->UseVisualStyleBackColor = true;
			this->efSavesAddButton->Click += gcnew System::EventHandler(this, &EditorForm::efSavesAddButton_Click);
			// 
			// efDef3UseCheckBox
			// 
			this->efDef3UseCheckBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efDef3UseCheckBox->AutoSize = true;
			this->efDef3UseCheckBox->Checked = true;
			this->efDef3UseCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->efDef3UseCheckBox->Location = System::Drawing::Point(441, 221);
			this->efDef3UseCheckBox->Margin = System::Windows::Forms::Padding(0, 3, 3, 0);
			this->efDef3UseCheckBox->Name = L"efDef3UseCheckBox";
			this->efDef3UseCheckBox->Size = System::Drawing::Size(15, 14);
			this->efDef3UseCheckBox->TabIndex = 23;
			this->efDef3UseCheckBox->UseVisualStyleBackColor = true;
			this->efDef3UseCheckBox->CheckedChanged += gcnew System::EventHandler(this, &EditorForm::DefCheck_CheckChanged);
			// 
			// efDef2UseCheckBox
			// 
			this->efDef2UseCheckBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efDef2UseCheckBox->AutoSize = true;
			this->efDef2UseCheckBox->Checked = true;
			this->efDef2UseCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->efDef2UseCheckBox->Location = System::Drawing::Point(369, 221);
			this->efDef2UseCheckBox->Margin = System::Windows::Forms::Padding(0, 3, 3, 0);
			this->efDef2UseCheckBox->Name = L"efDef2UseCheckBox";
			this->efDef2UseCheckBox->Size = System::Drawing::Size(15, 14);
			this->efDef2UseCheckBox->TabIndex = 20;
			this->efDef2UseCheckBox->UseVisualStyleBackColor = true;
			this->efDef2UseCheckBox->CheckedChanged += gcnew System::EventHandler(this, &EditorForm::DefCheck_CheckChanged);
			// 
			// efDef3UseLabel
			// 
			this->efDef3UseLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efDef3UseLabel->AutoSize = true;
			this->efDef3UseLabel->Location = System::Drawing::Point(403, 221);
			this->efDef3UseLabel->Name = L"efDef3UseLabel";
			this->efDef3UseLabel->Padding = System::Windows::Forms::Padding(3, 0, 0, 2);
			this->efDef3UseLabel->Size = System::Drawing::Size(35, 15);
			this->efDef3UseLabel->TabIndex = 3;
			this->efDef3UseLabel->Text = L"Use\?";
			// 
			// efDef2UseLabel
			// 
			this->efDef2UseLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efDef2UseLabel->AutoSize = true;
			this->efDef2UseLabel->Location = System::Drawing::Point(331, 221);
			this->efDef2UseLabel->Name = L"efDef2UseLabel";
			this->efDef2UseLabel->Padding = System::Windows::Forms::Padding(3, 0, 0, 2);
			this->efDef2UseLabel->Size = System::Drawing::Size(35, 15);
			this->efDef2UseLabel->TabIndex = 2;
			this->efDef2UseLabel->Text = L"Use\?";
			// 
			// efDividerLabel2
			// 
			this->efDividerLabel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->efDividerLabel2->Location = System::Drawing::Point(1, 326);
			this->efDividerLabel2->Name = L"efDividerLabel2";
			this->efDividerLabel2->Size = System::Drawing::Size(480, 2);
			this->efDividerLabel2->TabIndex = 25;
			// 
			// efSkillsLabel
			// 
			this->efSkillsLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->efSkillsLabel->AutoSize = true;
			this->efSkillsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efSkillsLabel->Location = System::Drawing::Point(244, 328);
			this->efSkillsLabel->Name = L"efSkillsLabel";
			this->efSkillsLabel->Size = System::Drawing::Size(58, 30);
			this->efSkillsLabel->TabIndex = 24;
			this->efSkillsLabel->Text = L"Skills";
			// 
			// efSavesLabel
			// 
			this->efSavesLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->efSavesLabel->AutoSize = true;
			this->efSavesLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efSavesLabel->Location = System::Drawing::Point(6, 328);
			this->efSavesLabel->Name = L"efSavesLabel";
			this->efSavesLabel->Size = System::Drawing::Size(65, 30);
			this->efSavesLabel->TabIndex = 23;
			this->efSavesLabel->Text = L"Saves";
			// 
			// efDividerLabel
			// 
			this->efDividerLabel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->efDividerLabel->Location = System::Drawing::Point(1, 176);
			this->efDividerLabel->Name = L"efDividerLabel";
			this->efDividerLabel->Size = System::Drawing::Size(480, 2);
			this->efDividerLabel->TabIndex = 19;
			// 
			// efDefensesLabel
			// 
			this->efDefensesLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->efDefensesLabel->AutoSize = true;
			this->efDefensesLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efDefensesLabel->Location = System::Drawing::Point(310, 182);
			this->efDefensesLabel->Name = L"efDefensesLabel";
			this->efDefensesLabel->Size = System::Drawing::Size(98, 30);
			this->efDefensesLabel->TabIndex = 18;
			this->efDefensesLabel->Text = L"Defenses";
			// 
			// efDefensesTableLayout
			// 
			this->efDefensesTableLayout->ColumnCount = 3;
			this->efDefensesTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->efDefensesTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->efDefensesTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->efDefensesTableLayout->Controls->Add(this->efDef3TextBox, 2, 0);
			this->efDefensesTableLayout->Controls->Add(this->efDef2TextBox, 1, 0);
			this->efDefensesTableLayout->Controls->Add(this->efDef1TextBox, 0, 0);
			this->efDefensesTableLayout->Controls->Add(this->efDef2NumUpDown, 1, 1);
			this->efDefensesTableLayout->Controls->Add(this->efDef1NumUpDown, 0, 1);
			this->efDefensesTableLayout->Controls->Add(this->efDef3NumUpDown, 2, 1);
			this->efDefensesTableLayout->Location = System::Drawing::Point(246, 236);
			this->efDefensesTableLayout->Name = L"efDefensesTableLayout";
			this->efDefensesTableLayout->RowCount = 2;
			this->efDefensesTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->efDefensesTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->efDefensesTableLayout->Size = System::Drawing::Size(228, 87);
			this->efDefensesTableLayout->TabIndex = 17;
			// 
			// efDef3TextBox
			// 
			this->efDef3TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efDef3TextBox->Location = System::Drawing::Point(155, 3);
			this->efDef3TextBox->Name = L"efDef3TextBox";
			this->efDef3TextBox->Size = System::Drawing::Size(69, 29);
			this->efDef3TextBox->TabIndex = 24;
			this->efDef3TextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efDef2TextBox
			// 
			this->efDef2TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efDef2TextBox->Location = System::Drawing::Point(79, 3);
			this->efDef2TextBox->Name = L"efDef2TextBox";
			this->efDef2TextBox->Size = System::Drawing::Size(69, 29);
			this->efDef2TextBox->TabIndex = 21;
			this->efDef2TextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efDef1TextBox
			// 
			this->efDef1TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efDef1TextBox->Location = System::Drawing::Point(3, 3);
			this->efDef1TextBox->MaximumSize = System::Drawing::Size(69, 29);
			this->efDef1TextBox->MinimumSize = System::Drawing::Size(69, 29);
			this->efDef1TextBox->Name = L"efDef1TextBox";
			this->efDef1TextBox->Size = System::Drawing::Size(69, 31);
			this->efDef1TextBox->TabIndex = 18;
			this->efDef1TextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efDef2NumUpDown
			// 
			this->efDef2NumUpDown->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->efDef2NumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efDef2NumUpDown->Location = System::Drawing::Point(79, 55);
			this->efDef2NumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->efDef2NumUpDown->Name = L"efDef2NumUpDown";
			this->efDef2NumUpDown->Size = System::Drawing::Size(69, 29);
			this->efDef2NumUpDown->TabIndex = 22;
			// 
			// efDef1NumUpDown
			// 
			this->efDef1NumUpDown->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->efDef1NumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efDef1NumUpDown->Location = System::Drawing::Point(3, 55);
			this->efDef1NumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->efDef1NumUpDown->Name = L"efDef1NumUpDown";
			this->efDef1NumUpDown->Size = System::Drawing::Size(69, 29);
			this->efDef1NumUpDown->TabIndex = 19;
			// 
			// efDef3NumUpDown
			// 
			this->efDef3NumUpDown->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->efDef3NumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efDef3NumUpDown->Location = System::Drawing::Point(155, 55);
			this->efDef3NumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->efDef3NumUpDown->Name = L"efDef3NumUpDown";
			this->efDef3NumUpDown->Size = System::Drawing::Size(70, 29);
			this->efDef3NumUpDown->TabIndex = 25;
			// 
			// efRandomStatsButton
			// 
			this->efRandomStatsButton->Location = System::Drawing::Point(165, 6);
			this->efRandomStatsButton->Name = L"efRandomStatsButton";
			this->efRandomStatsButton->Size = System::Drawing::Size(152, 23);
			this->efRandomStatsButton->TabIndex = 0;
			this->efRandomStatsButton->Text = L"Roll Random\?";
			this->efRandomStatsButton->UseVisualStyleBackColor = true;
			this->efRandomStatsButton->Click += gcnew System::EventHandler(this, &EditorForm::efRandomStatsButton_Click);
			// 
			// efStatsCheckBox
			// 
			this->efStatsCheckBox->AutoSize = true;
			this->efStatsCheckBox->Location = System::Drawing::Point(456, 13);
			this->efStatsCheckBox->Margin = System::Windows::Forms::Padding(2, 7, 3, 3);
			this->efStatsCheckBox->Name = L"efStatsCheckBox";
			this->efStatsCheckBox->Size = System::Drawing::Size(15, 14);
			this->efStatsCheckBox->TabIndex = 1;
			this->efStatsCheckBox->UseVisualStyleBackColor = true;
			this->efStatsCheckBox->CheckedChanged += gcnew System::EventHandler(this, &EditorForm::efStatsCheckBox_CheckedChanged);
			// 
			// efUseTraditionalLabel
			// 
			this->efUseTraditionalLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->efUseTraditionalLabel->AutoSize = true;
			this->efUseTraditionalLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efUseTraditionalLabel->Location = System::Drawing::Point(334, 9);
			this->efUseTraditionalLabel->Name = L"efUseTraditionalLabel";
			this->efUseTraditionalLabel->Size = System::Drawing::Size(120, 21);
			this->efUseTraditionalLabel->TabIndex = 1;
			this->efUseTraditionalLabel->Text = L"Use Traditional\?";
			// 
			// efStatsLabel
			// 
			this->efStatsLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->efStatsLabel->AutoSize = true;
			this->efStatsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efStatsLabel->Location = System::Drawing::Point(6, 3);
			this->efStatsLabel->Name = L"efStatsLabel";
			this->efStatsLabel->Size = System::Drawing::Size(137, 30);
			this->efStatsLabel->TabIndex = 3;
			this->efStatsLabel->Text = L"Ability Scores";
			// 
			// efStatsTableLayout
			// 
			this->efStatsTableLayout->AutoSize = true;
			this->efStatsTableLayout->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->efStatsTableLayout->ColumnCount = 6;
			this->efStatsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				78)));
			this->efStatsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				78)));
			this->efStatsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				78)));
			this->efStatsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				78)));
			this->efStatsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				78)));
			this->efStatsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				78)));
			this->efStatsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->efStatsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->efStatsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->efStatsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->efStatsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->efStatsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->efStatsTableLayout->Controls->Add(this->efStat6NumUpDown, 4, 3);
			this->efStatsTableLayout->Controls->Add(this->efStat6ModLabel, 5, 3);
			this->efStatsTableLayout->Controls->Add(this->efStat3NumUpDown, 4, 1);
			this->efStatsTableLayout->Controls->Add(this->efStat2NumUpDown, 2, 1);
			this->efStatsTableLayout->Controls->Add(this->efStat5NumUpDown, 2, 3);
			this->efStatsTableLayout->Controls->Add(this->efStat1NumUpDown, 0, 1);
			this->efStatsTableLayout->Controls->Add(this->efStat5ModLabel, 3, 3);
			this->efStatsTableLayout->Controls->Add(this->efStat3ModLabel, 5, 1);
			this->efStatsTableLayout->Controls->Add(this->efStat2ModLabel, 3, 1);
			this->efStatsTableLayout->Controls->Add(this->efStat4NumUpDown, 0, 3);
			this->efStatsTableLayout->Controls->Add(this->efStat1ModLabel, 1, 1);
			this->efStatsTableLayout->Controls->Add(this->efStat3TextBox, 4, 0);
			this->efStatsTableLayout->Controls->Add(this->efStat6TextBox, 4, 2);
			this->efStatsTableLayout->Controls->Add(this->efStat2TextBox, 2, 0);
			this->efStatsTableLayout->Controls->Add(this->efStat4ModLabel, 1, 3);
			this->efStatsTableLayout->Controls->Add(this->efStat1TextBox, 0, 0);
			this->efStatsTableLayout->Controls->Add(this->efStat4TextBox, 0, 2);
			this->efStatsTableLayout->Controls->Add(this->efStat5TextBox, 2, 2);
			this->efStatsTableLayout->Location = System::Drawing::Point(6, 33);
			this->efStatsTableLayout->Name = L"efStatsTableLayout";
			this->efStatsTableLayout->RowCount = 4;
			this->efStatsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				35)));
			this->efStatsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				35)));
			this->efStatsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				35)));
			this->efStatsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				35)));
			this->efStatsTableLayout->Size = System::Drawing::Size(468, 140);
			this->efStatsTableLayout->TabIndex = 2;
			// 
			// efStat6NumUpDown
			// 
			this->efStat6NumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efStat6NumUpDown->Location = System::Drawing::Point(315, 108);
			this->efStat6NumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->efStat6NumUpDown->Name = L"efStat6NumUpDown";
			this->efStat6NumUpDown->Size = System::Drawing::Size(72, 29);
			this->efStat6NumUpDown->TabIndex = 13;
			this->efStat6NumUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->efStat6NumUpDown->ValueChanged += gcnew System::EventHandler(this, &EditorForm::StatVals_TextChanged);
			// 
			// efStat6ModLabel
			// 
			this->efStat6ModLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->efStat6ModLabel->AutoSize = true;
			this->efStat6ModLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efStat6ModLabel->Location = System::Drawing::Point(410, 105);
			this->efStat6ModLabel->Name = L"efStat6ModLabel";
			this->efStat6ModLabel->Size = System::Drawing::Size(38, 35);
			this->efStat6ModLabel->TabIndex = 14;
			this->efStat6ModLabel->Text = L"+0";
			this->efStat6ModLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// efStat3NumUpDown
			// 
			this->efStat3NumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efStat3NumUpDown->Location = System::Drawing::Point(315, 38);
			this->efStat3NumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->efStat3NumUpDown->Name = L"efStat3NumUpDown";
			this->efStat3NumUpDown->Size = System::Drawing::Size(72, 29);
			this->efStat3NumUpDown->TabIndex = 7;
			this->efStat3NumUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->efStat3NumUpDown->ValueChanged += gcnew System::EventHandler(this, &EditorForm::StatVals_TextChanged);
			// 
			// efStat2NumUpDown
			// 
			this->efStat2NumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efStat2NumUpDown->Location = System::Drawing::Point(159, 38);
			this->efStat2NumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->efStat2NumUpDown->Name = L"efStat2NumUpDown";
			this->efStat2NumUpDown->Size = System::Drawing::Size(72, 29);
			this->efStat2NumUpDown->TabIndex = 5;
			this->efStat2NumUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->efStat2NumUpDown->ValueChanged += gcnew System::EventHandler(this, &EditorForm::StatVals_TextChanged);
			// 
			// efStat5NumUpDown
			// 
			this->efStat5NumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efStat5NumUpDown->Location = System::Drawing::Point(159, 108);
			this->efStat5NumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->efStat5NumUpDown->Name = L"efStat5NumUpDown";
			this->efStat5NumUpDown->Size = System::Drawing::Size(72, 29);
			this->efStat5NumUpDown->TabIndex = 11;
			this->efStat5NumUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->efStat5NumUpDown->ValueChanged += gcnew System::EventHandler(this, &EditorForm::StatVals_TextChanged);
			// 
			// efStat1NumUpDown
			// 
			this->efStat1NumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efStat1NumUpDown->Location = System::Drawing::Point(3, 38);
			this->efStat1NumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->efStat1NumUpDown->Name = L"efStat1NumUpDown";
			this->efStat1NumUpDown->Size = System::Drawing::Size(72, 29);
			this->efStat1NumUpDown->TabIndex = 3;
			this->efStat1NumUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->efStat1NumUpDown->ValueChanged += gcnew System::EventHandler(this, &EditorForm::StatVals_TextChanged);
			// 
			// efStat5ModLabel
			// 
			this->efStat5ModLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->efStat5ModLabel->AutoSize = true;
			this->efStat5ModLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efStat5ModLabel->Location = System::Drawing::Point(254, 105);
			this->efStat5ModLabel->Name = L"efStat5ModLabel";
			this->efStat5ModLabel->Size = System::Drawing::Size(38, 35);
			this->efStat5ModLabel->TabIndex = 13;
			this->efStat5ModLabel->Text = L"+0";
			this->efStat5ModLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// efStat3ModLabel
			// 
			this->efStat3ModLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->efStat3ModLabel->AutoSize = true;
			this->efStat3ModLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efStat3ModLabel->Location = System::Drawing::Point(410, 35);
			this->efStat3ModLabel->Name = L"efStat3ModLabel";
			this->efStat3ModLabel->Size = System::Drawing::Size(38, 35);
			this->efStat3ModLabel->TabIndex = 7;
			this->efStat3ModLabel->Text = L"+0";
			this->efStat3ModLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// efStat2ModLabel
			// 
			this->efStat2ModLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->efStat2ModLabel->AutoSize = true;
			this->efStat2ModLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efStat2ModLabel->Location = System::Drawing::Point(254, 35);
			this->efStat2ModLabel->Name = L"efStat2ModLabel";
			this->efStat2ModLabel->Size = System::Drawing::Size(38, 35);
			this->efStat2ModLabel->TabIndex = 8;
			this->efStat2ModLabel->Text = L"+0";
			this->efStat2ModLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// efStat4NumUpDown
			// 
			this->efStat4NumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efStat4NumUpDown->Location = System::Drawing::Point(3, 108);
			this->efStat4NumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->efStat4NumUpDown->Name = L"efStat4NumUpDown";
			this->efStat4NumUpDown->Size = System::Drawing::Size(72, 29);
			this->efStat4NumUpDown->TabIndex = 9;
			this->efStat4NumUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->efStat4NumUpDown->ValueChanged += gcnew System::EventHandler(this, &EditorForm::StatVals_TextChanged);
			// 
			// efStat1ModLabel
			// 
			this->efStat1ModLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->efStat1ModLabel->AutoSize = true;
			this->efStat1ModLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efStat1ModLabel->Location = System::Drawing::Point(98, 35);
			this->efStat1ModLabel->Name = L"efStat1ModLabel";
			this->efStat1ModLabel->Size = System::Drawing::Size(38, 35);
			this->efStat1ModLabel->TabIndex = 6;
			this->efStat1ModLabel->Text = L"+0";
			this->efStat1ModLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// efStat3TextBox
			// 
			this->efStatsTableLayout->SetColumnSpan(this->efStat3TextBox, 2);
			this->efStat3TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efStat3TextBox->Location = System::Drawing::Point(315, 3);
			this->efStat3TextBox->Name = L"efStat3TextBox";
			this->efStat3TextBox->Size = System::Drawing::Size(150, 29);
			this->efStat3TextBox->TabIndex = 6;
			this->efStat3TextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efStat6TextBox
			// 
			this->efStatsTableLayout->SetColumnSpan(this->efStat6TextBox, 2);
			this->efStat6TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efStat6TextBox->Location = System::Drawing::Point(315, 73);
			this->efStat6TextBox->Name = L"efStat6TextBox";
			this->efStat6TextBox->Size = System::Drawing::Size(150, 29);
			this->efStat6TextBox->TabIndex = 12;
			this->efStat6TextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efStat2TextBox
			// 
			this->efStatsTableLayout->SetColumnSpan(this->efStat2TextBox, 2);
			this->efStat2TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efStat2TextBox->Location = System::Drawing::Point(159, 3);
			this->efStat2TextBox->Name = L"efStat2TextBox";
			this->efStat2TextBox->Size = System::Drawing::Size(150, 29);
			this->efStat2TextBox->TabIndex = 4;
			this->efStat2TextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efStat4ModLabel
			// 
			this->efStat4ModLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->efStat4ModLabel->AutoSize = true;
			this->efStat4ModLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efStat4ModLabel->Location = System::Drawing::Point(98, 105);
			this->efStat4ModLabel->Name = L"efStat4ModLabel";
			this->efStat4ModLabel->Size = System::Drawing::Size(38, 35);
			this->efStat4ModLabel->TabIndex = 12;
			this->efStat4ModLabel->Text = L"+0";
			this->efStat4ModLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// efStat1TextBox
			// 
			this->efStat1TextBox->BackColor = System::Drawing::SystemColors::Window;
			this->efStatsTableLayout->SetColumnSpan(this->efStat1TextBox, 2);
			this->efStat1TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efStat1TextBox->ForeColor = System::Drawing::SystemColors::WindowText;
			this->efStat1TextBox->Location = System::Drawing::Point(3, 3);
			this->efStat1TextBox->Name = L"efStat1TextBox";
			this->efStat1TextBox->Size = System::Drawing::Size(150, 29);
			this->efStat1TextBox->TabIndex = 2;
			this->efStat1TextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efStat4TextBox
			// 
			this->efStatsTableLayout->SetColumnSpan(this->efStat4TextBox, 2);
			this->efStat4TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efStat4TextBox->Location = System::Drawing::Point(3, 73);
			this->efStat4TextBox->Name = L"efStat4TextBox";
			this->efStat4TextBox->Size = System::Drawing::Size(150, 29);
			this->efStat4TextBox->TabIndex = 8;
			this->efStat4TextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efStat5TextBox
			// 
			this->efStatsTableLayout->SetColumnSpan(this->efStat5TextBox, 2);
			this->efStat5TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efStat5TextBox->Location = System::Drawing::Point(159, 73);
			this->efStat5TextBox->Name = L"efStat5TextBox";
			this->efStat5TextBox->Size = System::Drawing::Size(150, 29);
			this->efStat5TextBox->TabIndex = 10;
			this->efStat5TextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efOtherStatsTableLayout
			// 
			this->efOtherStatsTableLayout->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->efOtherStatsTableLayout->ColumnCount = 3;
			this->efOtherStatsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				98)));
			this->efOtherStatsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				59)));
			this->efOtherStatsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				77)));
			this->efOtherStatsTableLayout->Controls->Add(this->efHitPointLabel, 0, 0);
			this->efOtherStatsTableLayout->Controls->Add(this->efStaminaLabel, 0, 2);
			this->efOtherStatsTableLayout->Controls->Add(this->efStaminaCheckBox, 1, 1);
			this->efOtherStatsTableLayout->Controls->Add(this->efEnableStaminaLabel, 0, 1);
			this->efOtherStatsTableLayout->Controls->Add(this->efHPNumUpDown, 2, 0);
			this->efOtherStatsTableLayout->Controls->Add(this->efSPNumUpDown, 2, 2);
			this->efOtherStatsTableLayout->Controls->Add(this->efInitLabel, 0, 4);
			this->efOtherStatsTableLayout->Controls->Add(this->efInitNumUpDown, 2, 4);
			this->efOtherStatsTableLayout->Location = System::Drawing::Point(3, 179);
			this->efOtherStatsTableLayout->Name = L"efOtherStatsTableLayout";
			this->efOtherStatsTableLayout->RowCount = 5;
			this->efOtherStatsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				35)));
			this->efOtherStatsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				19)));
			this->efOtherStatsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				35)));
			this->efOtherStatsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				19)));
			this->efOtherStatsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				35)));
			this->efOtherStatsTableLayout->Size = System::Drawing::Size(234, 143);
			this->efOtherStatsTableLayout->TabIndex = 16;
			// 
			// efHitPointLabel
			// 
			this->efHitPointLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->efHitPointLabel->AutoSize = true;
			this->efOtherStatsTableLayout->SetColumnSpan(this->efHitPointLabel, 2);
			this->efHitPointLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efHitPointLabel->Location = System::Drawing::Point(3, 2);
			this->efHitPointLabel->Name = L"efHitPointLabel";
			this->efHitPointLabel->Size = System::Drawing::Size(102, 30);
			this->efHitPointLabel->TabIndex = 14;
			this->efHitPointLabel->Text = L"Hit Points";
			// 
			// efStaminaLabel
			// 
			this->efStaminaLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->efStaminaLabel->AutoSize = true;
			this->efOtherStatsTableLayout->SetColumnSpan(this->efStaminaLabel, 2);
			this->efStaminaLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efStaminaLabel->ForeColor = System::Drawing::SystemColors::ControlText;
			this->efStaminaLabel->Location = System::Drawing::Point(3, 56);
			this->efStaminaLabel->Name = L"efStaminaLabel";
			this->efStaminaLabel->Size = System::Drawing::Size(149, 30);
			this->efStaminaLabel->TabIndex = 15;
			this->efStaminaLabel->Text = L"Stamina Points";
			// 
			// efStaminaCheckBox
			// 
			this->efStaminaCheckBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efStaminaCheckBox->AutoSize = true;
			this->efStaminaCheckBox->Checked = true;
			this->efStaminaCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->efStaminaCheckBox->Location = System::Drawing::Point(98, 40);
			this->efStaminaCheckBox->Margin = System::Windows::Forms::Padding(0, 3, 3, 0);
			this->efStaminaCheckBox->Name = L"efStaminaCheckBox";
			this->efStaminaCheckBox->Size = System::Drawing::Size(15, 14);
			this->efStaminaCheckBox->TabIndex = 15;
			this->efStaminaCheckBox->UseVisualStyleBackColor = true;
			this->efStaminaCheckBox->CheckedChanged += gcnew System::EventHandler(this, &EditorForm::efStaminaCheckBox_CheckedChanged);
			// 
			// efEnableStaminaLabel
			// 
			this->efEnableStaminaLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efEnableStaminaLabel->AutoSize = true;
			this->efEnableStaminaLabel->Location = System::Drawing::Point(3, 39);
			this->efEnableStaminaLabel->Name = L"efEnableStaminaLabel";
			this->efEnableStaminaLabel->Padding = System::Windows::Forms::Padding(3, 0, 0, 2);
			this->efEnableStaminaLabel->Size = System::Drawing::Size(90, 15);
			this->efEnableStaminaLabel->TabIndex = 1;
			this->efEnableStaminaLabel->Text = L"Enable Stamina\?";
			// 
			// efHPNumUpDown
			// 
			this->efHPNumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efHPNumUpDown->Location = System::Drawing::Point(160, 3);
			this->efHPNumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->efHPNumUpDown->Name = L"efHPNumUpDown";
			this->efHPNumUpDown->Size = System::Drawing::Size(71, 29);
			this->efHPNumUpDown->TabIndex = 14;
			this->efHPNumUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// efSPNumUpDown
			// 
			this->efSPNumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efSPNumUpDown->Location = System::Drawing::Point(160, 57);
			this->efSPNumUpDown->Name = L"efSPNumUpDown";
			this->efSPNumUpDown->Size = System::Drawing::Size(71, 29);
			this->efSPNumUpDown->TabIndex = 16;
			this->efSPNumUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// efInitLabel
			// 
			this->efInitLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->efInitLabel->AutoSize = true;
			this->efOtherStatsTableLayout->SetColumnSpan(this->efInitLabel, 2);
			this->efInitLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efInitLabel->ForeColor = System::Drawing::SystemColors::ControlText;
			this->efInitLabel->Location = System::Drawing::Point(3, 110);
			this->efInitLabel->Name = L"efInitLabel";
			this->efInitLabel->Size = System::Drawing::Size(92, 30);
			this->efInitLabel->TabIndex = 20;
			this->efInitLabel->Text = L"Initiative";
			// 
			// efInitNumUpDown
			// 
			this->efInitNumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efInitNumUpDown->Location = System::Drawing::Point(160, 111);
			this->efInitNumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->efInitNumUpDown->Name = L"efInitNumUpDown";
			this->efInitNumUpDown->Size = System::Drawing::Size(71, 29);
			this->efInitNumUpDown->TabIndex = 17;
			// 
			// efSavesSkillsTableLayout
			// 
			this->efSavesSkillsTableLayout->ColumnCount = 4;
			this->efSavesSkillsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				35)));
			this->efSavesSkillsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->efSavesSkillsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				35)));
			this->efSavesSkillsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->efSavesSkillsTableLayout->Controls->Add(this->efSkillsNumUpDown, 3, 0);
			this->efSavesSkillsTableLayout->Controls->Add(this->efSavesNumUpDown, 1, 0);
			this->efSavesSkillsTableLayout->Controls->Add(this->efSavesTextBox, 0, 0);
			this->efSavesSkillsTableLayout->Controls->Add(this->efSavesListBox, 0, 1);
			this->efSavesSkillsTableLayout->Controls->Add(this->efSkillsListBox, 2, 1);
			this->efSavesSkillsTableLayout->Controls->Add(this->efSkillsTextBox, 2, 0);
			this->efSavesSkillsTableLayout->Location = System::Drawing::Point(3, 361);
			this->efSavesSkillsTableLayout->Name = L"efSavesSkillsTableLayout";
			this->efSavesSkillsTableLayout->RowCount = 2;
			this->efSavesSkillsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				35)));
			this->efSavesSkillsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->efSavesSkillsTableLayout->Size = System::Drawing::Size(473, 180);
			this->efSavesSkillsTableLayout->TabIndex = 22;
			// 
			// efSkillsNumUpDown
			// 
			this->efSkillsNumUpDown->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->efSkillsNumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efSkillsNumUpDown->Location = System::Drawing::Point(403, 3);
			this->efSkillsNumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->efSkillsNumUpDown->Name = L"efSkillsNumUpDown";
			this->efSkillsNumUpDown->Size = System::Drawing::Size(67, 29);
			this->efSkillsNumUpDown->TabIndex = 32;
			// 
			// efSavesNumUpDown
			// 
			this->efSavesNumUpDown->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->efSavesNumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efSavesNumUpDown->Location = System::Drawing::Point(168, 3);
			this->efSavesNumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->efSavesNumUpDown->Name = L"efSavesNumUpDown";
			this->efSavesNumUpDown->Size = System::Drawing::Size(64, 29);
			this->efSavesNumUpDown->TabIndex = 27;
			// 
			// efSavesTextBox
			// 
			this->efSavesTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->efSavesTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efSavesTextBox->Location = System::Drawing::Point(3, 3);
			this->efSavesTextBox->Name = L"efSavesTextBox";
			this->efSavesTextBox->Size = System::Drawing::Size(159, 29);
			this->efSavesTextBox->TabIndex = 26;
			// 
			// efSavesListBox
			// 
			this->efSavesSkillsTableLayout->SetColumnSpan(this->efSavesListBox, 2);
			this->efSavesListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->efSavesListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efSavesListBox->FormattingEnabled = true;
			this->efSavesListBox->HorizontalExtent = 30;
			this->efSavesListBox->ItemHeight = 16;
			this->efSavesListBox->Location = System::Drawing::Point(3, 38);
			this->efSavesListBox->Name = L"efSavesListBox";
			this->efSavesListBox->Size = System::Drawing::Size(229, 139);
			this->efSavesListBox->TabIndex = 2;
			// 
			// efSkillsListBox
			// 
			this->efSavesSkillsTableLayout->SetColumnSpan(this->efSkillsListBox, 2);
			this->efSkillsListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->efSkillsListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efSkillsListBox->FormattingEnabled = true;
			this->efSkillsListBox->ItemHeight = 16;
			this->efSkillsListBox->Location = System::Drawing::Point(238, 38);
			this->efSkillsListBox->Name = L"efSkillsListBox";
			this->efSkillsListBox->Size = System::Drawing::Size(232, 139);
			this->efSkillsListBox->TabIndex = 35;
			// 
			// efSkillsTextBox
			// 
			this->efSkillsTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->efSkillsTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efSkillsTextBox->Location = System::Drawing::Point(238, 3);
			this->efSkillsTextBox->Name = L"efSkillsTextBox";
			this->efSkillsTextBox->Size = System::Drawing::Size(159, 29);
			this->efSkillsTextBox->TabIndex = 31;
			// 
			// efTabPage3
			// 
			this->efTabPage3->Controls->Add(this->efWeaponCreatorButton);
			this->efTabPage3->Controls->Add(this->efDeleteWeapButton);
			this->efTabPage3->Controls->Add(this->efDividerLabel5);
			this->efTabPage3->Controls->Add(this->efWeaponsListBox);
			this->efTabPage3->Controls->Add(this->efVertLineLabel);
			this->efTabPage3->Controls->Add(this->efWeaponsLabel);
			this->efTabPage3->Controls->Add(this->efHorizLineLabel3);
			this->efTabPage3->Controls->Add(this->efViewButton);
			this->efTabPage3->Controls->Add(this->efActionDeleteButton);
			this->efTabPage3->Controls->Add(this->efActionAddButton);
			this->efTabPage3->Controls->Add(this->efActionNameTextBox);
			this->efTabPage3->Controls->Add(this->efActionListBox);
			this->efTabPage3->Controls->Add(this->efActionsLabel);
			this->efTabPage3->Controls->Add(this->efActionDescTextBox);
			this->efTabPage3->Controls->Add(this->efSpellsTableLayout);
			this->efTabPage3->Location = System::Drawing::Point(4, 22);
			this->efTabPage3->Name = L"efTabPage3";
			this->efTabPage3->Padding = System::Windows::Forms::Padding(3);
			this->efTabPage3->Size = System::Drawing::Size(483, 546);
			this->efTabPage3->TabIndex = 2;
			this->efTabPage3->Text = L"Actions";
			this->efTabPage3->UseVisualStyleBackColor = true;
			// 
			// efWeaponCreatorButton
			// 
			this->efWeaponCreatorButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efWeaponCreatorButton->Location = System::Drawing::Point(231, 228);
			this->efWeaponCreatorButton->Name = L"efWeaponCreatorButton";
			this->efWeaponCreatorButton->Size = System::Drawing::Size(119, 29);
			this->efWeaponCreatorButton->TabIndex = 7;
			this->efWeaponCreatorButton->Text = L"Create Weapon";
			this->efWeaponCreatorButton->UseVisualStyleBackColor = true;
			this->efWeaponCreatorButton->Click += gcnew System::EventHandler(this, &EditorForm::efWeaponCreatorButton_Click);
			// 
			// efDeleteWeapButton
			// 
			this->efDeleteWeapButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efDeleteWeapButton->Location = System::Drawing::Point(356, 228);
			this->efDeleteWeapButton->Name = L"efDeleteWeapButton";
			this->efDeleteWeapButton->Size = System::Drawing::Size(122, 29);
			this->efDeleteWeapButton->TabIndex = 8;
			this->efDeleteWeapButton->Text = L"Delete Weapon";
			this->efDeleteWeapButton->UseVisualStyleBackColor = true;
			this->efDeleteWeapButton->Click += gcnew System::EventHandler(this, &EditorForm::efDeleteWeapButton_Click);
			// 
			// efDividerLabel5
			// 
			this->efDividerLabel5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->efDividerLabel5->Location = System::Drawing::Point(224, 273);
			this->efDividerLabel5->Name = L"efDividerLabel5";
			this->efDividerLabel5->Size = System::Drawing::Size(257, 2);
			this->efDividerLabel5->TabIndex = 33;
			// 
			// efWeaponsListBox
			// 
			this->efWeaponsListBox->FormattingEnabled = true;
			this->efWeaponsListBox->Location = System::Drawing::Point(231, 75);
			this->efWeaponsListBox->Name = L"efWeaponsListBox";
			this->efWeaponsListBox->Size = System::Drawing::Size(247, 147);
			this->efWeaponsListBox->TabIndex = 6;
			// 
			// efVertLineLabel
			// 
			this->efVertLineLabel->BackColor = System::Drawing::Color::Silver;
			this->efVertLineLabel->Location = System::Drawing::Point(224, 3);
			this->efVertLineLabel->Name = L"efVertLineLabel";
			this->efVertLineLabel->Size = System::Drawing::Size(1, 272);
			this->efVertLineLabel->TabIndex = 31;
			// 
			// efWeaponsLabel
			// 
			this->efWeaponsLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efWeaponsLabel->AutoSize = true;
			this->efWeaponsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efWeaponsLabel->Location = System::Drawing::Point(231, 35);
			this->efWeaponsLabel->Name = L"efWeaponsLabel";
			this->efWeaponsLabel->Padding = System::Windows::Forms::Padding(0, 0, 0, 3);
			this->efWeaponsLabel->Size = System::Drawing::Size(99, 33);
			this->efWeaponsLabel->TabIndex = 30;
			this->efWeaponsLabel->Text = L"Weapons";
			// 
			// efHorizLineLabel3
			// 
			this->efHorizLineLabel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->efHorizLineLabel3->Location = System::Drawing::Point(-1, 345);
			this->efHorizLineLabel3->Name = L"efHorizLineLabel3";
			this->efHorizLineLabel3->Size = System::Drawing::Size(480, 2);
			this->efHorizLineLabel3->TabIndex = 29;
			// 
			// efViewButton
			// 
			this->efViewButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efViewButton->Location = System::Drawing::Point(231, 278);
			this->efViewButton->Name = L"efViewButton";
			this->efViewButton->Size = System::Drawing::Size(103, 29);
			this->efViewButton->TabIndex = 4;
			this->efViewButton->Text = L"View Action";
			this->efViewButton->UseVisualStyleBackColor = true;
			this->efViewButton->Click += gcnew System::EventHandler(this, &EditorForm::efViewButton_Click);
			// 
			// efActionDeleteButton
			// 
			this->efActionDeleteButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efActionDeleteButton->Location = System::Drawing::Point(231, 313);
			this->efActionDeleteButton->Name = L"efActionDeleteButton";
			this->efActionDeleteButton->Size = System::Drawing::Size(103, 29);
			this->efActionDeleteButton->TabIndex = 5;
			this->efActionDeleteButton->Text = L"Delete Action";
			this->efActionDeleteButton->UseVisualStyleBackColor = true;
			this->efActionDeleteButton->Click += gcnew System::EventHandler(this, &EditorForm::efActionDeleteButton_Click);
			// 
			// efActionAddButton
			// 
			this->efActionAddButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efActionAddButton->Location = System::Drawing::Point(146, 40);
			this->efActionAddButton->Name = L"efActionAddButton";
			this->efActionAddButton->Size = System::Drawing::Size(75, 29);
			this->efActionAddButton->TabIndex = 2;
			this->efActionAddButton->Text = L"Add";
			this->efActionAddButton->UseVisualStyleBackColor = true;
			this->efActionAddButton->Click += gcnew System::EventHandler(this, &EditorForm::efActionAddButton_Click);
			// 
			// efActionNameTextBox
			// 
			this->efActionNameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efActionNameTextBox->Location = System::Drawing::Point(7, 40);
			this->efActionNameTextBox->Name = L"efActionNameTextBox";
			this->efActionNameTextBox->Size = System::Drawing::Size(133, 29);
			this->efActionNameTextBox->TabIndex = 0;
			// 
			// efActionListBox
			// 
			this->efActionListBox->FormattingEnabled = true;
			this->efActionListBox->Location = System::Drawing::Point(7, 221);
			this->efActionListBox->Name = L"efActionListBox";
			this->efActionListBox->Size = System::Drawing::Size(214, 121);
			this->efActionListBox->TabIndex = 3;
			// 
			// efActionsLabel
			// 
			this->efActionsLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efActionsLabel->AutoSize = true;
			this->efActionsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efActionsLabel->Location = System::Drawing::Point(6, 6);
			this->efActionsLabel->Name = L"efActionsLabel";
			this->efActionsLabel->Padding = System::Windows::Forms::Padding(0, 0, 0, 3);
			this->efActionsLabel->Size = System::Drawing::Size(82, 33);
			this->efActionsLabel->TabIndex = 18;
			this->efActionsLabel->Text = L"Actions";
			// 
			// efActionDescTextBox
			// 
			this->efActionDescTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efActionDescTextBox->Location = System::Drawing::Point(7, 75);
			this->efActionDescTextBox->Multiline = true;
			this->efActionDescTextBox->Name = L"efActionDescTextBox";
			this->efActionDescTextBox->Size = System::Drawing::Size(214, 140);
			this->efActionDescTextBox->TabIndex = 1;
			// 
			// efSpellsTableLayout
			// 
			this->efSpellsTableLayout->ColumnCount = 5;
			this->efSpellsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				73)));
			this->efSpellsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				152)));
			this->efSpellsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				58)));
			this->efSpellsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				100)));
			this->efSpellsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				102)));
			this->efSpellsTableLayout->Controls->Add(this->efSpellsListBox, 0, 1);
			this->efSpellsTableLayout->Controls->Add(this->efSpellsTextBox, 1, 0);
			this->efSpellsTableLayout->Controls->Add(this->efSpellsLabel, 0, 0);
			this->efSpellsTableLayout->Controls->Add(this->efSpellsAddButton, 3, 0);
			this->efSpellsTableLayout->Controls->Add(this->efSpellsRemoveButton, 4, 0);
			this->efSpellsTableLayout->Controls->Add(this->efSpellsNumUpDown, 2, 0);
			this->efSpellsTableLayout->Location = System::Drawing::Point(-1, 348);
			this->efSpellsTableLayout->Name = L"efSpellsTableLayout";
			this->efSpellsTableLayout->RowCount = 2;
			this->efSpellsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				35)));
			this->efSpellsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				178)));
			this->efSpellsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->efSpellsTableLayout->Size = System::Drawing::Size(485, 198);
			this->efSpellsTableLayout->TabIndex = 16;
			// 
			// efSpellsListBox
			// 
			this->efSpellsTableLayout->SetColumnSpan(this->efSpellsListBox, 5);
			this->efSpellsListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->efSpellsListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efSpellsListBox->FormattingEnabled = true;
			this->efSpellsListBox->ItemHeight = 20;
			this->efSpellsListBox->Location = System::Drawing::Point(3, 38);
			this->efSpellsListBox->Name = L"efSpellsListBox";
			this->efSpellsListBox->Size = System::Drawing::Size(479, 172);
			this->efSpellsListBox->TabIndex = 4;
			// 
			// efSpellsTextBox
			// 
			this->efSpellsTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efSpellsTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efSpellsTextBox->Location = System::Drawing::Point(76, 3);
			this->efSpellsTextBox->Name = L"efSpellsTextBox";
			this->efSpellsTextBox->Size = System::Drawing::Size(146, 29);
			this->efSpellsTextBox->TabIndex = 0;
			// 
			// efSpellsLabel
			// 
			this->efSpellsLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efSpellsLabel->AutoSize = true;
			this->efSpellsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efSpellsLabel->Location = System::Drawing::Point(3, 2);
			this->efSpellsLabel->Name = L"efSpellsLabel";
			this->efSpellsLabel->Padding = System::Windows::Forms::Padding(0, 0, 0, 3);
			this->efSpellsLabel->Size = System::Drawing::Size(66, 33);
			this->efSpellsLabel->TabIndex = 15;
			this->efSpellsLabel->Text = L"Spells";
			// 
			// efSpellsAddButton
			// 
			this->efSpellsAddButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efSpellsAddButton->Location = System::Drawing::Point(286, 3);
			this->efSpellsAddButton->Name = L"efSpellsAddButton";
			this->efSpellsAddButton->Size = System::Drawing::Size(94, 29);
			this->efSpellsAddButton->TabIndex = 2;
			this->efSpellsAddButton->Text = L"Add Spell";
			this->efSpellsAddButton->UseVisualStyleBackColor = true;
			this->efSpellsAddButton->Click += gcnew System::EventHandler(this, &EditorForm::efSpellsAddButton_Click);
			// 
			// efSpellsRemoveButton
			// 
			this->efSpellsRemoveButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efSpellsRemoveButton->Location = System::Drawing::Point(386, 3);
			this->efSpellsRemoveButton->Name = L"efSpellsRemoveButton";
			this->efSpellsRemoveButton->Size = System::Drawing::Size(94, 29);
			this->efSpellsRemoveButton->TabIndex = 3;
			this->efSpellsRemoveButton->Text = L"Remove Last";
			this->efSpellsRemoveButton->UseVisualStyleBackColor = true;
			this->efSpellsRemoveButton->Click += gcnew System::EventHandler(this, &EditorForm::efSpellsRemoveButton_Click);
			// 
			// efSpellsNumUpDown
			// 
			this->efSpellsNumUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->efSpellsNumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efSpellsNumUpDown->Location = System::Drawing::Point(228, 3);
			this->efSpellsNumUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9, 0, 0, 0 });
			this->efSpellsNumUpDown->Name = L"efSpellsNumUpDown";
			this->efSpellsNumUpDown->Size = System::Drawing::Size(52, 29);
			this->efSpellsNumUpDown->TabIndex = 1;
			// 
			// efTabPage4
			// 
			this->efTabPage4->Controls->Add(this->efLineLabel4);
			this->efTabPage4->Controls->Add(this->efTraitsTableLayout);
			this->efTabPage4->Controls->Add(this->efItemQtyNumUpDown);
			this->efTabPage4->Controls->Add(this->efItemAddButton);
			this->efTabPage4->Controls->Add(this->efItemDeleteButton);
			this->efTabPage4->Controls->Add(this->efItemsLabel);
			this->efTabPage4->Controls->Add(this->efItemTextBox);
			this->efTabPage4->Controls->Add(this->efItemsListBox);
			this->efTabPage4->Location = System::Drawing::Point(4, 22);
			this->efTabPage4->Name = L"efTabPage4";
			this->efTabPage4->Padding = System::Windows::Forms::Padding(3);
			this->efTabPage4->Size = System::Drawing::Size(483, 546);
			this->efTabPage4->TabIndex = 3;
			this->efTabPage4->Text = L"Traits";
			this->efTabPage4->UseVisualStyleBackColor = true;
			// 
			// efLineLabel4
			// 
			this->efLineLabel4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->efLineLabel4->Location = System::Drawing::Point(3, 310);
			this->efLineLabel4->Name = L"efLineLabel4";
			this->efLineLabel4->Size = System::Drawing::Size(477, 2);
			this->efLineLabel4->TabIndex = 34;
			// 
			// efTraitsTableLayout
			// 
			this->efTraitsTableLayout->ColumnCount = 5;
			this->efTraitsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25.005F)));
			this->efTraitsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25.005F)));
			this->efTraitsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66333F)));
			this->efTraitsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66333F)));
			this->efTraitsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66333F)));
			this->efTraitsTableLayout->Controls->Add(this->efTraitViewButton, 3, 1);
			this->efTraitsTableLayout->Controls->Add(this->efTraitDeleteButton, 4, 1);
			this->efTraitsTableLayout->Controls->Add(this->efTraitNameTextBox, 0, 1);
			this->efTraitsTableLayout->Controls->Add(this->efTraitsLabel, 0, 0);
			this->efTraitsTableLayout->Controls->Add(this->efAddTraitButton, 2, 1);
			this->efTraitsTableLayout->Controls->Add(this->efTraitDescTextBox, 0, 2);
			this->efTraitsTableLayout->Controls->Add(this->efTraitsListBox, 3, 2);
			this->efTraitsTableLayout->Location = System::Drawing::Point(3, 6);
			this->efTraitsTableLayout->Name = L"efTraitsTableLayout";
			this->efTraitsTableLayout->RowCount = 3;
			this->efTraitsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				45)));
			this->efTraitsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				35)));
			this->efTraitsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->efTraitsTableLayout->Size = System::Drawing::Size(475, 310);
			this->efTraitsTableLayout->TabIndex = 33;
			// 
			// efTraitViewButton
			// 
			this->efTraitViewButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efTraitViewButton->Location = System::Drawing::Point(318, 48);
			this->efTraitViewButton->Name = L"efTraitViewButton";
			this->efTraitViewButton->Size = System::Drawing::Size(73, 29);
			this->efTraitViewButton->TabIndex = 3;
			this->efTraitViewButton->Text = L"View";
			this->efTraitViewButton->UseVisualStyleBackColor = true;
			this->efTraitViewButton->Click += gcnew System::EventHandler(this, &EditorForm::efViewTraitButton_Click);
			// 
			// efTraitDeleteButton
			// 
			this->efTraitDeleteButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efTraitDeleteButton->Location = System::Drawing::Point(397, 48);
			this->efTraitDeleteButton->Name = L"efTraitDeleteButton";
			this->efTraitDeleteButton->Size = System::Drawing::Size(75, 29);
			this->efTraitDeleteButton->TabIndex = 4;
			this->efTraitDeleteButton->Text = L"Delete";
			this->efTraitDeleteButton->UseVisualStyleBackColor = true;
			this->efTraitDeleteButton->Click += gcnew System::EventHandler(this, &EditorForm::efDeleteTraitButton_Click);
			// 
			// efTraitNameTextBox
			// 
			this->efTraitsTableLayout->SetColumnSpan(this->efTraitNameTextBox, 2);
			this->efTraitNameTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->efTraitNameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efTraitNameTextBox->Location = System::Drawing::Point(3, 48);
			this->efTraitNameTextBox->Name = L"efTraitNameTextBox";
			this->efTraitNameTextBox->Size = System::Drawing::Size(230, 29);
			this->efTraitNameTextBox->TabIndex = 0;
			// 
			// efTraitsLabel
			// 
			this->efTraitsLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efTraitsLabel->AutoSize = true;
			this->efTraitsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efTraitsLabel->Location = System::Drawing::Point(3, 12);
			this->efTraitsLabel->Name = L"efTraitsLabel";
			this->efTraitsLabel->Padding = System::Windows::Forms::Padding(0, 0, 0, 3);
			this->efTraitsLabel->Size = System::Drawing::Size(61, 33);
			this->efTraitsLabel->TabIndex = 19;
			this->efTraitsLabel->Text = L"Traits";
			// 
			// efAddTraitButton
			// 
			this->efAddTraitButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->efAddTraitButton->Location = System::Drawing::Point(239, 48);
			this->efAddTraitButton->Name = L"efAddTraitButton";
			this->efAddTraitButton->Size = System::Drawing::Size(73, 29);
			this->efAddTraitButton->TabIndex = 2;
			this->efAddTraitButton->Text = L"Add";
			this->efAddTraitButton->UseVisualStyleBackColor = true;
			this->efAddTraitButton->Click += gcnew System::EventHandler(this, &EditorForm::efAddTraitButton_Click);
			// 
			// efTraitDescTextBox
			// 
			this->efTraitsTableLayout->SetColumnSpan(this->efTraitDescTextBox, 3);
			this->efTraitDescTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efTraitDescTextBox->Location = System::Drawing::Point(3, 83);
			this->efTraitDescTextBox->Multiline = true;
			this->efTraitDescTextBox->Name = L"efTraitDescTextBox";
			this->efTraitDescTextBox->Size = System::Drawing::Size(309, 212);
			this->efTraitDescTextBox->TabIndex = 1;
			// 
			// efTraitsListBox
			// 
			this->efTraitsTableLayout->SetColumnSpan(this->efTraitsListBox, 2);
			this->efTraitsListBox->FormattingEnabled = true;
			this->efTraitsListBox->Location = System::Drawing::Point(318, 83);
			this->efTraitsListBox->Name = L"efTraitsListBox";
			this->efTraitsListBox->Size = System::Drawing::Size(152, 212);
			this->efTraitsListBox->TabIndex = 5;
			// 
			// efItemQtyNumUpDown
			// 
			this->efItemQtyNumUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->efItemQtyNumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efItemQtyNumUpDown->Location = System::Drawing::Point(362, 358);
			this->efItemQtyNumUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->efItemQtyNumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->efItemQtyNumUpDown->Name = L"efItemQtyNumUpDown";
			this->efItemQtyNumUpDown->Size = System::Drawing::Size(88, 29);
			this->efItemQtyNumUpDown->TabIndex = 1;
			this->efItemQtyNumUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// efItemAddButton
			// 
			this->efItemAddButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efItemAddButton->Location = System::Drawing::Point(245, 322);
			this->efItemAddButton->Name = L"efItemAddButton";
			this->efItemAddButton->Size = System::Drawing::Size(111, 29);
			this->efItemAddButton->TabIndex = 2;
			this->efItemAddButton->Text = L"Add";
			this->efItemAddButton->UseVisualStyleBackColor = true;
			this->efItemAddButton->Click += gcnew System::EventHandler(this, &EditorForm::efItemAddButton_Click);
			// 
			// efItemDeleteButton
			// 
			this->efItemDeleteButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efItemDeleteButton->Location = System::Drawing::Point(362, 322);
			this->efItemDeleteButton->Name = L"efItemDeleteButton";
			this->efItemDeleteButton->Size = System::Drawing::Size(111, 29);
			this->efItemDeleteButton->TabIndex = 3;
			this->efItemDeleteButton->Text = L"Delete";
			this->efItemDeleteButton->UseVisualStyleBackColor = true;
			this->efItemDeleteButton->Click += gcnew System::EventHandler(this, &EditorForm::efItemDeleteButton_Click);
			// 
			// efItemsLabel
			// 
			this->efItemsLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efItemsLabel->AutoSize = true;
			this->efItemsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efItemsLabel->Location = System::Drawing::Point(6, 322);
			this->efItemsLabel->Name = L"efItemsLabel";
			this->efItemsLabel->Padding = System::Windows::Forms::Padding(0, 0, 0, 3);
			this->efItemsLabel->Size = System::Drawing::Size(64, 33);
			this->efItemsLabel->TabIndex = 27;
			this->efItemsLabel->Text = L"Items";
			// 
			// efItemTextBox
			// 
			this->efItemTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efItemTextBox->Location = System::Drawing::Point(6, 358);
			this->efItemTextBox->Name = L"efItemTextBox";
			this->efItemTextBox->Size = System::Drawing::Size(350, 29);
			this->efItemTextBox->TabIndex = 0;
			// 
			// efItemsListBox
			// 
			this->efItemsListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efItemsListBox->FormattingEnabled = true;
			this->efItemsListBox->ItemHeight = 16;
			this->efItemsListBox->Location = System::Drawing::Point(6, 393);
			this->efItemsListBox->Name = L"efItemsListBox";
			this->efItemsListBox->Size = System::Drawing::Size(467, 132);
			this->efItemsListBox->TabIndex = 4;
			// 
			// efTabPage5
			// 
			this->efTabPage5->AutoScroll = true;
			this->efTabPage5->Controls->Add(this->label1);
			this->efTabPage5->Controls->Add(this->efVertLabel2);
			this->efTabPage5->Controls->Add(this->efDescTableLayout);
			this->efTabPage5->Controls->Add(this->efIBFTableLayout);
			this->efTabPage5->Controls->Add(this->efTacticsTableLayout);
			this->efTabPage5->Location = System::Drawing::Point(4, 22);
			this->efTabPage5->Name = L"efTabPage5";
			this->efTabPage5->Padding = System::Windows::Forms::Padding(3);
			this->efTabPage5->Size = System::Drawing::Size(483, 546);
			this->efTabPage5->TabIndex = 4;
			this->efTabPage5->Text = L"Personality";
			this->efTabPage5->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Location = System::Drawing::Point(2, 554);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(465, 2);
			this->label1->TabIndex = 41;
			// 
			// efVertLabel2
			// 
			this->efVertLabel2->BackColor = System::Drawing::Color::Silver;
			this->efVertLabel2->Location = System::Drawing::Point(221, 3);
			this->efVertLabel2->Name = L"efVertLabel2";
			this->efVertLabel2->Size = System::Drawing::Size(1, 551);
			this->efVertLabel2->TabIndex = 40;
			// 
			// efDescTableLayout
			// 
			this->efDescTableLayout->ColumnCount = 1;
			this->efDescTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->efDescTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->efDescTableLayout->Controls->Add(this->efGoalMotTextBox, 0, 5);
			this->efDescTableLayout->Controls->Add(this->efGoalsMotivesLabel, 0, 4);
			this->efDescTableLayout->Controls->Add(this->efPersonalityLabel, 0, 2);
			this->efDescTableLayout->Controls->Add(this->efAppearTextBox, 0, 1);
			this->efDescTableLayout->Controls->Add(this->efPersoTextBox, 0, 3);
			this->efDescTableLayout->Controls->Add(this->efAppearanceLabel, 0, 0);
			this->efDescTableLayout->Location = System::Drawing::Point(4, 6);
			this->efDescTableLayout->Name = L"efDescTableLayout";
			this->efDescTableLayout->RowCount = 6;
			this->efDescTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
			this->efDescTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 146)));
			this->efDescTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
			this->efDescTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 146)));
			this->efDescTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
			this->efDescTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 146)));
			this->efDescTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->efDescTableLayout->Size = System::Drawing::Size(214, 544);
			this->efDescTableLayout->TabIndex = 39;
			// 
			// efGoalMotTextBox
			// 
			this->efGoalMotTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efGoalMotTextBox->Location = System::Drawing::Point(3, 400);
			this->efGoalMotTextBox->Multiline = true;
			this->efGoalMotTextBox->Name = L"efGoalMotTextBox";
			this->efGoalMotTextBox->Size = System::Drawing::Size(208, 141);
			this->efGoalMotTextBox->TabIndex = 2;
			this->efGoalMotTextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efGoalsMotivesLabel
			// 
			this->efGoalsMotivesLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efGoalsMotivesLabel->AutoSize = true;
			this->efGoalsMotivesLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efGoalsMotivesLabel->Location = System::Drawing::Point(3, 364);
			this->efGoalsMotivesLabel->Name = L"efGoalsMotivesLabel";
			this->efGoalsMotivesLabel->Padding = System::Windows::Forms::Padding(0, 0, 0, 3);
			this->efGoalsMotivesLabel->Size = System::Drawing::Size(166, 33);
			this->efGoalsMotivesLabel->TabIndex = 35;
			this->efGoalsMotivesLabel->Text = L"Goals && Motives";
			// 
			// efPersonalityLabel
			// 
			this->efPersonalityLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efPersonalityLabel->AutoSize = true;
			this->efPersonalityLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efPersonalityLabel->Location = System::Drawing::Point(3, 183);
			this->efPersonalityLabel->Name = L"efPersonalityLabel";
			this->efPersonalityLabel->Padding = System::Windows::Forms::Padding(0, 0, 0, 3);
			this->efPersonalityLabel->Size = System::Drawing::Size(113, 33);
			this->efPersonalityLabel->TabIndex = 33;
			this->efPersonalityLabel->Text = L"Personality";
			// 
			// efAppearTextBox
			// 
			this->efAppearTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efAppearTextBox->Location = System::Drawing::Point(3, 38);
			this->efAppearTextBox->Multiline = true;
			this->efAppearTextBox->Name = L"efAppearTextBox";
			this->efAppearTextBox->Size = System::Drawing::Size(208, 140);
			this->efAppearTextBox->TabIndex = 0;
			this->efAppearTextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efPersoTextBox
			// 
			this->efPersoTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efPersoTextBox->Location = System::Drawing::Point(3, 219);
			this->efPersoTextBox->Multiline = true;
			this->efPersoTextBox->Name = L"efPersoTextBox";
			this->efPersoTextBox->Size = System::Drawing::Size(208, 140);
			this->efPersoTextBox->TabIndex = 1;
			this->efPersoTextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efAppearanceLabel
			// 
			this->efAppearanceLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->efAppearanceLabel->AutoSize = true;
			this->efAppearanceLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efAppearanceLabel->Location = System::Drawing::Point(3, 2);
			this->efAppearanceLabel->Name = L"efAppearanceLabel";
			this->efAppearanceLabel->Padding = System::Windows::Forms::Padding(0, 0, 0, 3);
			this->efAppearanceLabel->Size = System::Drawing::Size(124, 33);
			this->efAppearanceLabel->TabIndex = 20;
			this->efAppearanceLabel->Text = L"Appearance";
			// 
			// efIBFTableLayout
			// 
			this->efIBFTableLayout->ColumnCount = 9;
			this->efIBFTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				11.11111F)));
			this->efIBFTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				11.11111F)));
			this->efIBFTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				11.11111F)));
			this->efIBFTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				11.11111F)));
			this->efIBFTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				11.11111F)));
			this->efIBFTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				11.11111F)));
			this->efIBFTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				11.11111F)));
			this->efIBFTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				11.11111F)));
			this->efIBFTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				11.11111F)));
			this->efIBFTableLayout->Controls->Add(this->efFlawsListBox, 6, 3);
			this->efIBFTableLayout->Controls->Add(this->efBondsListBox, 3, 3);
			this->efIBFTableLayout->Controls->Add(this->efFDelButton, 8, 2);
			this->efIBFTableLayout->Controls->Add(this->efFViewButton, 7, 2);
			this->efIBFTableLayout->Controls->Add(this->efFAddButton, 6, 2);
			this->efIBFTableLayout->Controls->Add(this->efBDelButton, 5, 2);
			this->efIBFTableLayout->Controls->Add(this->efBViewButton, 4, 2);
			this->efIBFTableLayout->Controls->Add(this->efBAddButton, 3, 2);
			this->efIBFTableLayout->Controls->Add(this->efIDelButton, 2, 2);
			this->efIBFTableLayout->Controls->Add(this->efIViewButton, 1, 2);
			this->efIBFTableLayout->Controls->Add(this->efFlawsTextBox, 6, 1);
			this->efIBFTableLayout->Controls->Add(this->efBondsTextBox, 3, 1);
			this->efIBFTableLayout->Controls->Add(this->efIdealsLabel, 0, 0);
			this->efIBFTableLayout->Controls->Add(this->efBondsLabel, 3, 0);
			this->efIBFTableLayout->Controls->Add(this->efIdealsTextBox, 0, 1);
			this->efIBFTableLayout->Controls->Add(this->efIAddButton, 0, 2);
			this->efIBFTableLayout->Controls->Add(this->efIdealsListBox, 0, 3);
			this->efIBFTableLayout->Controls->Add(this->efFlawsLabel, 6, 0);
			this->efIBFTableLayout->Location = System::Drawing::Point(3, 551);
			this->efIBFTableLayout->Name = L"efIBFTableLayout";
			this->efIBFTableLayout->RowCount = 4;
			this->efIBFTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
			this->efIBFTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
			this->efIBFTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
			this->efIBFTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->efIBFTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->efIBFTableLayout->Size = System::Drawing::Size(460, 314);
			this->efIBFTableLayout->TabIndex = 38;
			// 
			// efFlawsListBox
			// 
			this->efIBFTableLayout->SetColumnSpan(this->efFlawsListBox, 3);
			this->efFlawsListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->efFlawsListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efFlawsListBox->FormattingEnabled = true;
			this->efFlawsListBox->HorizontalScrollbar = true;
			this->efFlawsListBox->ItemHeight = 16;
			this->efFlawsListBox->Location = System::Drawing::Point(309, 108);
			this->efFlawsListBox->Name = L"efFlawsListBox";
			this->efFlawsListBox->Size = System::Drawing::Size(148, 203);
			this->efFlawsListBox->TabIndex = 14;
			// 
			// efBondsListBox
			// 
			this->efIBFTableLayout->SetColumnSpan(this->efBondsListBox, 3);
			this->efBondsListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->efBondsListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efBondsListBox->FormattingEnabled = true;
			this->efBondsListBox->HorizontalScrollbar = true;
			this->efBondsListBox->ItemHeight = 16;
			this->efBondsListBox->Location = System::Drawing::Point(156, 108);
			this->efBondsListBox->Name = L"efBondsListBox";
			this->efBondsListBox->Size = System::Drawing::Size(147, 203);
			this->efBondsListBox->TabIndex = 9;
			// 
			// efFDelButton
			// 
			this->efFDelButton->Location = System::Drawing::Point(411, 73);
			this->efFDelButton->Name = L"efFDelButton";
			this->efFDelButton->Size = System::Drawing::Size(46, 29);
			this->efFDelButton->TabIndex = 13;
			this->efFDelButton->Text = L"Del";
			this->efFDelButton->UseVisualStyleBackColor = true;
			this->efFDelButton->Click += gcnew System::EventHandler(this, &EditorForm::efFDelButton_Click);
			// 
			// efFViewButton
			// 
			this->efFViewButton->Location = System::Drawing::Point(360, 73);
			this->efFViewButton->Name = L"efFViewButton";
			this->efFViewButton->Size = System::Drawing::Size(45, 29);
			this->efFViewButton->TabIndex = 12;
			this->efFViewButton->Text = L"View";
			this->efFViewButton->UseVisualStyleBackColor = true;
			this->efFViewButton->Click += gcnew System::EventHandler(this, &EditorForm::efFViewButton_Click);
			// 
			// efFAddButton
			// 
			this->efFAddButton->Location = System::Drawing::Point(309, 73);
			this->efFAddButton->Name = L"efFAddButton";
			this->efFAddButton->Size = System::Drawing::Size(45, 29);
			this->efFAddButton->TabIndex = 11;
			this->efFAddButton->Text = L"Add";
			this->efFAddButton->UseVisualStyleBackColor = true;
			this->efFAddButton->Click += gcnew System::EventHandler(this, &EditorForm::efFAddButton_Click);
			// 
			// efBDelButton
			// 
			this->efBDelButton->Location = System::Drawing::Point(258, 73);
			this->efBDelButton->Name = L"efBDelButton";
			this->efBDelButton->Size = System::Drawing::Size(45, 29);
			this->efBDelButton->TabIndex = 8;
			this->efBDelButton->Text = L"Del";
			this->efBDelButton->UseVisualStyleBackColor = true;
			this->efBDelButton->Click += gcnew System::EventHandler(this, &EditorForm::efBDelButton_Click);
			// 
			// efBViewButton
			// 
			this->efBViewButton->Location = System::Drawing::Point(207, 73);
			this->efBViewButton->Name = L"efBViewButton";
			this->efBViewButton->Size = System::Drawing::Size(45, 29);
			this->efBViewButton->TabIndex = 7;
			this->efBViewButton->Text = L"View";
			this->efBViewButton->UseVisualStyleBackColor = true;
			this->efBViewButton->Click += gcnew System::EventHandler(this, &EditorForm::efBViewButton_Click);
			// 
			// efBAddButton
			// 
			this->efBAddButton->Location = System::Drawing::Point(156, 73);
			this->efBAddButton->Name = L"efBAddButton";
			this->efBAddButton->Size = System::Drawing::Size(45, 29);
			this->efBAddButton->TabIndex = 6;
			this->efBAddButton->Text = L"Add";
			this->efBAddButton->UseVisualStyleBackColor = true;
			this->efBAddButton->Click += gcnew System::EventHandler(this, &EditorForm::efBAddButton_Click);
			// 
			// efIDelButton
			// 
			this->efIDelButton->Location = System::Drawing::Point(105, 73);
			this->efIDelButton->Name = L"efIDelButton";
			this->efIDelButton->Size = System::Drawing::Size(45, 29);
			this->efIDelButton->TabIndex = 3;
			this->efIDelButton->Text = L"Del";
			this->efIDelButton->UseVisualStyleBackColor = true;
			this->efIDelButton->Click += gcnew System::EventHandler(this, &EditorForm::efIDelButton_Click);
			// 
			// efIViewButton
			// 
			this->efIViewButton->Location = System::Drawing::Point(54, 73);
			this->efIViewButton->Name = L"efIViewButton";
			this->efIViewButton->Size = System::Drawing::Size(45, 29);
			this->efIViewButton->TabIndex = 2;
			this->efIViewButton->Text = L"View";
			this->efIViewButton->UseVisualStyleBackColor = true;
			this->efIViewButton->Click += gcnew System::EventHandler(this, &EditorForm::efIViewButton_Click);
			// 
			// efFlawsTextBox
			// 
			this->efIBFTableLayout->SetColumnSpan(this->efFlawsTextBox, 3);
			this->efFlawsTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efFlawsTextBox->Location = System::Drawing::Point(309, 38);
			this->efFlawsTextBox->Name = L"efFlawsTextBox";
			this->efFlawsTextBox->Size = System::Drawing::Size(148, 29);
			this->efFlawsTextBox->TabIndex = 10;
			this->efFlawsTextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efBondsTextBox
			// 
			this->efIBFTableLayout->SetColumnSpan(this->efBondsTextBox, 3);
			this->efBondsTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efBondsTextBox->Location = System::Drawing::Point(156, 38);
			this->efBondsTextBox->Name = L"efBondsTextBox";
			this->efBondsTextBox->Size = System::Drawing::Size(147, 29);
			this->efBondsTextBox->TabIndex = 5;
			this->efBondsTextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efIdealsLabel
			// 
			this->efIdealsLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->efIdealsLabel->AutoSize = true;
			this->efIBFTableLayout->SetColumnSpan(this->efIdealsLabel, 3);
			this->efIdealsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efIdealsLabel->Location = System::Drawing::Point(43, 2);
			this->efIdealsLabel->Name = L"efIdealsLabel";
			this->efIdealsLabel->Padding = System::Windows::Forms::Padding(0, 0, 0, 3);
			this->efIdealsLabel->Size = System::Drawing::Size(67, 33);
			this->efIdealsLabel->TabIndex = 36;
			this->efIdealsLabel->Text = L"Ideals";
			// 
			// efBondsLabel
			// 
			this->efBondsLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->efBondsLabel->AutoSize = true;
			this->efIBFTableLayout->SetColumnSpan(this->efBondsLabel, 3);
			this->efBondsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efBondsLabel->Location = System::Drawing::Point(194, 2);
			this->efBondsLabel->Name = L"efBondsLabel";
			this->efBondsLabel->Padding = System::Windows::Forms::Padding(0, 0, 0, 3);
			this->efBondsLabel->Size = System::Drawing::Size(70, 33);
			this->efBondsLabel->TabIndex = 37;
			this->efBondsLabel->Text = L"Bonds";
			// 
			// efIdealsTextBox
			// 
			this->efIBFTableLayout->SetColumnSpan(this->efIdealsTextBox, 3);
			this->efIdealsTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->efIdealsTextBox->Location = System::Drawing::Point(3, 38);
			this->efIdealsTextBox->Name = L"efIdealsTextBox";
			this->efIdealsTextBox->Size = System::Drawing::Size(147, 29);
			this->efIdealsTextBox->TabIndex = 0;
			this->efIdealsTextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efIAddButton
			// 
			this->efIAddButton->Location = System::Drawing::Point(3, 73);
			this->efIAddButton->Name = L"efIAddButton";
			this->efIAddButton->Size = System::Drawing::Size(45, 29);
			this->efIAddButton->TabIndex = 1;
			this->efIAddButton->Text = L"Add";
			this->efIAddButton->UseVisualStyleBackColor = true;
			this->efIAddButton->Click += gcnew System::EventHandler(this, &EditorForm::efIAddButton_Click);
			// 
			// efIdealsListBox
			// 
			this->efIBFTableLayout->SetColumnSpan(this->efIdealsListBox, 3);
			this->efIdealsListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->efIdealsListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efIdealsListBox->FormattingEnabled = true;
			this->efIdealsListBox->HorizontalScrollbar = true;
			this->efIdealsListBox->ItemHeight = 16;
			this->efIdealsListBox->Location = System::Drawing::Point(3, 108);
			this->efIdealsListBox->Name = L"efIdealsListBox";
			this->efIdealsListBox->Size = System::Drawing::Size(147, 203);
			this->efIdealsListBox->TabIndex = 4;
			// 
			// efFlawsLabel
			// 
			this->efFlawsLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->efFlawsLabel->AutoSize = true;
			this->efIBFTableLayout->SetColumnSpan(this->efFlawsLabel, 3);
			this->efFlawsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efFlawsLabel->Location = System::Drawing::Point(351, 2);
			this->efFlawsLabel->Name = L"efFlawsLabel";
			this->efFlawsLabel->Padding = System::Windows::Forms::Padding(0, 0, 0, 3);
			this->efFlawsLabel->Size = System::Drawing::Size(63, 33);
			this->efFlawsLabel->TabIndex = 38;
			this->efFlawsLabel->Text = L"Flaws";
			// 
			// efTacticsTableLayout
			// 
			this->efTacticsTableLayout->ColumnCount = 1;
			this->efTacticsTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				242)));
			this->efTacticsTableLayout->Controls->Add(this->efTacticsLabel, 0, 0);
			this->efTacticsTableLayout->Controls->Add(this->efTMorTextBox, 0, 6);
			this->efTacticsTableLayout->Controls->Add(this->efTMoraleLabel, 0, 5);
			this->efTacticsTableLayout->Controls->Add(this->efTSocialLabel, 0, 1);
			this->efTacticsTableLayout->Controls->Add(this->efTSocTextBox, 0, 2);
			this->efTacticsTableLayout->Controls->Add(this->efTCombatLabel, 0, 3);
			this->efTacticsTableLayout->Controls->Add(this->efTComTextBox, 0, 4);
			this->efTacticsTableLayout->Location = System::Drawing::Point(224, 6);
			this->efTacticsTableLayout->Name = L"efTacticsTableLayout";
			this->efTacticsTableLayout->RowCount = 7;
			this->efTacticsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				35)));
			this->efTacticsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->efTacticsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				150)));
			this->efTacticsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->efTacticsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				150)));
			this->efTacticsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->efTacticsTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				150)));
			this->efTacticsTableLayout->Size = System::Drawing::Size(242, 545);
			this->efTacticsTableLayout->TabIndex = 31;
			// 
			// efTacticsLabel
			// 
			this->efTacticsLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->efTacticsLabel->AutoSize = true;
			this->efTacticsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efTacticsLabel->Location = System::Drawing::Point(165, 2);
			this->efTacticsLabel->Name = L"efTacticsLabel";
			this->efTacticsLabel->Padding = System::Windows::Forms::Padding(0, 0, 0, 3);
			this->efTacticsLabel->Size = System::Drawing::Size(74, 33);
			this->efTacticsLabel->TabIndex = 32;
			this->efTacticsLabel->Text = L"Tactics";
			// 
			// efTMorTextBox
			// 
			this->efTMorTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efTMorTextBox->Location = System::Drawing::Point(3, 398);
			this->efTMorTextBox->Multiline = true;
			this->efTMorTextBox->Name = L"efTMorTextBox";
			this->efTMorTextBox->Size = System::Drawing::Size(236, 144);
			this->efTMorTextBox->TabIndex = 2;
			this->efTMorTextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efTMoraleLabel
			// 
			this->efTMoraleLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->efTMoraleLabel->AutoSize = true;
			this->efTMoraleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efTMoraleLabel->Location = System::Drawing::Point(190, 379);
			this->efTMoraleLabel->Name = L"efTMoraleLabel";
			this->efTMoraleLabel->Size = System::Drawing::Size(49, 16);
			this->efTMoraleLabel->TabIndex = 28;
			this->efTMoraleLabel->Text = L"Morale";
			// 
			// efTSocialLabel
			// 
			this->efTSocialLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->efTSocialLabel->AutoSize = true;
			this->efTSocialLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efTSocialLabel->Location = System::Drawing::Point(194, 39);
			this->efTSocialLabel->Name = L"efTSocialLabel";
			this->efTSocialLabel->Size = System::Drawing::Size(45, 16);
			this->efTSocialLabel->TabIndex = 26;
			this->efTSocialLabel->Text = L"Social";
			// 
			// efTSocTextBox
			// 
			this->efTSocTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efTSocTextBox->Location = System::Drawing::Point(3, 58);
			this->efTSocTextBox->Multiline = true;
			this->efTSocTextBox->Name = L"efTSocTextBox";
			this->efTSocTextBox->Size = System::Drawing::Size(236, 144);
			this->efTSocTextBox->TabIndex = 0;
			this->efTSocTextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efTCombatLabel
			// 
			this->efTCombatLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->efTCombatLabel->AutoSize = true;
			this->efTCombatLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efTCombatLabel->Location = System::Drawing::Point(185, 209);
			this->efTCombatLabel->Name = L"efTCombatLabel";
			this->efTCombatLabel->Size = System::Drawing::Size(54, 16);
			this->efTCombatLabel->TabIndex = 27;
			this->efTCombatLabel->Text = L"Combat";
			// 
			// efTComTextBox
			// 
			this->efTComTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->efTComTextBox->Location = System::Drawing::Point(3, 228);
			this->efTComTextBox->Multiline = true;
			this->efTComTextBox->Name = L"efTComTextBox";
			this->efTComTextBox->Size = System::Drawing::Size(236, 144);
			this->efTComTextBox->TabIndex = 1;
			this->efTComTextBox->TextChanged += gcnew System::EventHandler(this, &EditorForm::ValidateUndoRed);
			// 
			// efSaveButton
			// 
			this->efSaveButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->efSaveButton->Location = System::Drawing::Point(4, 586);
			this->efSaveButton->Name = L"efSaveButton";
			this->efSaveButton->Size = System::Drawing::Size(116, 37);
			this->efSaveButton->TabIndex = 0;
			this->efSaveButton->Text = L"Save";
			this->efSaveButton->UseVisualStyleBackColor = true;
			this->efSaveButton->Click += gcnew System::EventHandler(this, &EditorForm::efSaveButton_Click);
			// 
			// efCancelButton
			// 
			this->efCancelButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->efCancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->efCancelButton->Location = System::Drawing::Point(126, 587);
			this->efCancelButton->Name = L"efCancelButton";
			this->efCancelButton->Size = System::Drawing::Size(116, 37);
			this->efCancelButton->TabIndex = 1;
			this->efCancelButton->Text = L"Cancel";
			this->efCancelButton->UseVisualStyleBackColor = true;
			this->efCancelButton->Click += gcnew System::EventHandler(this, &EditorForm::efCancelButton_Click);
			// 
			// EditorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(492, 634);
			this->Controls->Add(this->efNextButton);
			this->Controls->Add(this->efSaveButton);
			this->Controls->Add(this->efCancelButton);
			this->Controls->Add(this->efTabControl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"EditorForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Editor";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &EditorForm::EditorForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &EditorForm::EditorForm_Load);
			this->efTabControl->ResumeLayout(false);
			this->efTabPage1->ResumeLayout(false);
			this->efCoreInfoTableLayout->ResumeLayout(false);
			this->efCoreInfoTableLayout->PerformLayout();
			this->efTabPage2->ResumeLayout(false);
			this->efTabPage2->PerformLayout();
			this->efDefensesTableLayout->ResumeLayout(false);
			this->efDefensesTableLayout->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efDef2NumUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efDef1NumUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efDef3NumUpDown))->EndInit();
			this->efStatsTableLayout->ResumeLayout(false);
			this->efStatsTableLayout->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efStat6NumUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efStat3NumUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efStat2NumUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efStat5NumUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efStat1NumUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efStat4NumUpDown))->EndInit();
			this->efOtherStatsTableLayout->ResumeLayout(false);
			this->efOtherStatsTableLayout->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efHPNumUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efSPNumUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efInitNumUpDown))->EndInit();
			this->efSavesSkillsTableLayout->ResumeLayout(false);
			this->efSavesSkillsTableLayout->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efSkillsNumUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efSavesNumUpDown))->EndInit();
			this->efTabPage3->ResumeLayout(false);
			this->efTabPage3->PerformLayout();
			this->efSpellsTableLayout->ResumeLayout(false);
			this->efSpellsTableLayout->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efSpellsNumUpDown))->EndInit();
			this->efTabPage4->ResumeLayout(false);
			this->efTabPage4->PerformLayout();
			this->efTraitsTableLayout->ResumeLayout(false);
			this->efTraitsTableLayout->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->efItemQtyNumUpDown))->EndInit();
			this->efTabPage5->ResumeLayout(false);
			this->efDescTableLayout->ResumeLayout(false);
			this->efDescTableLayout->PerformLayout();
			this->efIBFTableLayout->ResumeLayout(false);
			this->efIBFTableLayout->PerformLayout();
			this->efTacticsTableLayout->ResumeLayout(false);
			this->efTacticsTableLayout->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void efCancelButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EditorForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void EditorForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efStatsCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efRandomStatsButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void StatVals_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efStaminaCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DefCheck_CheckChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efSavesAddButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efSavesDeleteButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efSkillsAddButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efSkillsDeleteButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efActionAddButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efWeaponCreatorButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efDeleteWeapButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efViewButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efActionDeleteButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efSpellsAddButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efSpellsRemoveButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void UpdateWeaponsListBox(int idx);
	private: System::Void DisplaySpellsInListBox();
	private: System::Void efAddTraitButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efViewTraitButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efDeleteTraitButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efItemAddButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efItemDeleteButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efIAddButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efIViewButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efIDelButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efBAddButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efBViewButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efBDelButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efFAddButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efFViewButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efFDelButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efSaveButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efNextButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: bool ValidateEditorFormSave();
	private: System::Void ValidateUndoRed(System::Object^ sender, System::EventArgs^ e);
	private: System::Void efRaceComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void LoadMyNPC();
	private: System::Void efTabControl_Selecting(System::Object^ sender, System::Windows::Forms::TabControlCancelEventArgs^ e);
};
}