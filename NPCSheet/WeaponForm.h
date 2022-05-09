#pragma once

namespace NPCSheet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for WeaponForm
	/// </summary>
	public ref class WeaponForm : public System::Windows::Forms::Form
	{
	public:
		WeaponForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WeaponForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ wfNameLabel;
	private: System::Windows::Forms::TextBox^ wfNameTextBox;
	protected:

	private: System::Windows::Forms::Label^ wtfAttackLabel;
	private: System::Windows::Forms::ComboBox^ wfAttackComboBox;
	private: System::Windows::Forms::Label^ wfPlusLabel1;



	private: System::Windows::Forms::NumericUpDown^ wfAttackNumUpDown;

	private: System::Windows::Forms::Label^ wfRangeLabel;
	private: System::Windows::Forms::TextBox^ wfRangeTextBox;


	private: System::Windows::Forms::Label^ wfDamage1Label;

	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::ComboBox^ wfDmgDice1ComboBox;
	private: System::Windows::Forms::Label^ wfPlusLabel2;


	private: System::Windows::Forms::ComboBox^ wfDamage1ComboBox;
	private: System::Windows::Forms::Label^ wfPlusLabel3;


	private: System::Windows::Forms::NumericUpDown^ wfDmg1NumUpDown;

	private: System::Windows::Forms::Label^ wfType1Label;
	private: System::Windows::Forms::TextBox^ wfType1TextBox;


	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ wfType2TextBox;

	private: System::Windows::Forms::Label^ wfType2Label;
	private: System::Windows::Forms::NumericUpDown^ wfDmg2NumUpDown;
	private: System::Windows::Forms::Label^ wfPlusLabel5;



	private: System::Windows::Forms::ComboBox^ wfDamage2ComboBox;
	private: System::Windows::Forms::Label^ wfPlusLabel4;


	private: System::Windows::Forms::ComboBox^ wfDmgDice2ComboBox;

	private: System::Windows::Forms::NumericUpDown^ numericUpDown5;
	private: System::Windows::Forms::Label^ wfDamage2Label;
	private: System::Windows::Forms::Label^ wfUseLabel;
	private: System::Windows::Forms::CheckBox^ wfUseCheckBox;



	private: System::Windows::Forms::Button^ wfSaveButton;
	private: System::Windows::Forms::Button^ wfCancelButton;


	private: System::Windows::Forms::Label^ label15;

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
			this->wfNameLabel = (gcnew System::Windows::Forms::Label());
			this->wfNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->wtfAttackLabel = (gcnew System::Windows::Forms::Label());
			this->wfAttackComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->wfPlusLabel1 = (gcnew System::Windows::Forms::Label());
			this->wfAttackNumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->wfRangeLabel = (gcnew System::Windows::Forms::Label());
			this->wfRangeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->wfDamage1Label = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->wfDmgDice1ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->wfPlusLabel2 = (gcnew System::Windows::Forms::Label());
			this->wfDamage1ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->wfPlusLabel3 = (gcnew System::Windows::Forms::Label());
			this->wfDmg1NumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->wfType1Label = (gcnew System::Windows::Forms::Label());
			this->wfType1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->wfType2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->wfType2Label = (gcnew System::Windows::Forms::Label());
			this->wfDmg2NumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->wfPlusLabel5 = (gcnew System::Windows::Forms::Label());
			this->wfDamage2ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->wfPlusLabel4 = (gcnew System::Windows::Forms::Label());
			this->wfDmgDice2ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->wfDamage2Label = (gcnew System::Windows::Forms::Label());
			this->wfUseLabel = (gcnew System::Windows::Forms::Label());
			this->wfUseCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->wfSaveButton = (gcnew System::Windows::Forms::Button());
			this->wfCancelButton = (gcnew System::Windows::Forms::Button());
			this->label15 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wfAttackNumUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wfDmg1NumUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wfDmg2NumUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->BeginInit();
			this->SuspendLayout();
			// 
			// wfNameLabel
			// 
			this->wfNameLabel->AutoSize = true;
			this->wfNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfNameLabel->Location = System::Drawing::Point(12, 9);
			this->wfNameLabel->Name = L"wfNameLabel";
			this->wfNameLabel->Size = System::Drawing::Size(55, 20);
			this->wfNameLabel->TabIndex = 0;
			this->wfNameLabel->Text = L"Name:";
			// 
			// wfNameTextBox
			// 
			this->wfNameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfNameTextBox->Location = System::Drawing::Point(73, 6);
			this->wfNameTextBox->Name = L"wfNameTextBox";
			this->wfNameTextBox->Size = System::Drawing::Size(277, 26);
			this->wfNameTextBox->TabIndex = 1;
			// 
			// wtfAttackLabel
			// 
			this->wtfAttackLabel->AutoSize = true;
			this->wtfAttackLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wtfAttackLabel->Location = System::Drawing::Point(12, 47);
			this->wtfAttackLabel->Name = L"wtfAttackLabel";
			this->wtfAttackLabel->Size = System::Drawing::Size(109, 20);
			this->wtfAttackLabel->TabIndex = 2;
			this->wtfAttackLabel->Text = L"Attack Bonus:";
			// 
			// wfAttackComboBox
			// 
			this->wfAttackComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->wfAttackComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfAttackComboBox->FormattingEnabled = true;
			this->wfAttackComboBox->Location = System::Drawing::Point(127, 44);
			this->wfAttackComboBox->Name = L"wfAttackComboBox";
			this->wfAttackComboBox->Size = System::Drawing::Size(120, 28);
			this->wfAttackComboBox->TabIndex = 3;
			// 
			// wfPlusLabel1
			// 
			this->wfPlusLabel1->AutoSize = true;
			this->wfPlusLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfPlusLabel1->Location = System::Drawing::Point(253, 47);
			this->wfPlusLabel1->Name = L"wfPlusLabel1";
			this->wfPlusLabel1->Size = System::Drawing::Size(18, 20);
			this->wfPlusLabel1->TabIndex = 4;
			this->wfPlusLabel1->Text = L"+";
			// 
			// wfAttackNumUpDown
			// 
			this->wfAttackNumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfAttackNumUpDown->Location = System::Drawing::Point(277, 45);
			this->wfAttackNumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->wfAttackNumUpDown->Name = L"wfAttackNumUpDown";
			this->wfAttackNumUpDown->Size = System::Drawing::Size(73, 26);
			this->wfAttackNumUpDown->TabIndex = 5;
			// 
			// wfRangeLabel
			// 
			this->wfRangeLabel->AutoSize = true;
			this->wfRangeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfRangeLabel->Location = System::Drawing::Point(12, 89);
			this->wfRangeLabel->Name = L"wfRangeLabel";
			this->wfRangeLabel->Size = System::Drawing::Size(61, 20);
			this->wfRangeLabel->TabIndex = 6;
			this->wfRangeLabel->Text = L"Range:";
			// 
			// wfRangeTextBox
			// 
			this->wfRangeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfRangeTextBox->Location = System::Drawing::Point(73, 86);
			this->wfRangeTextBox->Name = L"wfRangeTextBox";
			this->wfRangeTextBox->Size = System::Drawing::Size(277, 26);
			this->wfRangeTextBox->TabIndex = 7;
			// 
			// wfDamage1Label
			// 
			this->wfDamage1Label->AutoSize = true;
			this->wfDamage1Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfDamage1Label->Location = System::Drawing::Point(12, 135);
			this->wfDamage1Label->Name = L"wfDamage1Label";
			this->wfDamage1Label->Size = System::Drawing::Size(74, 20);
			this->wfDamage1Label->TabIndex = 8;
			this->wfDamage1Label->Text = L"Damage:";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDown2->Location = System::Drawing::Point(94, 133);
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(61, 26);
			this->numericUpDown2->TabIndex = 9;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// wfDmgDice1ComboBox
			// 
			this->wfDmgDice1ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->wfDmgDice1ComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfDmgDice1ComboBox->FormattingEnabled = true;
			this->wfDmgDice1ComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"d3", L"d4", L"d6", L"d8", L"d10", L"d12",
					L"d20", L"d50", L"d100"
			});
			this->wfDmgDice1ComboBox->Location = System::Drawing::Point(161, 132);
			this->wfDmgDice1ComboBox->Name = L"wfDmgDice1ComboBox";
			this->wfDmgDice1ComboBox->Size = System::Drawing::Size(53, 28);
			this->wfDmgDice1ComboBox->TabIndex = 10;
			// 
			// wfPlusLabel2
			// 
			this->wfPlusLabel2->AutoSize = true;
			this->wfPlusLabel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfPlusLabel2->Location = System::Drawing::Point(69, 178);
			this->wfPlusLabel2->Name = L"wfPlusLabel2";
			this->wfPlusLabel2->Size = System::Drawing::Size(18, 20);
			this->wfPlusLabel2->TabIndex = 11;
			this->wfPlusLabel2->Text = L"+";
			// 
			// wfDamage1ComboBox
			// 
			this->wfDamage1ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->wfDamage1ComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfDamage1ComboBox->FormattingEnabled = true;
			this->wfDamage1ComboBox->Location = System::Drawing::Point(94, 175);
			this->wfDamage1ComboBox->Name = L"wfDamage1ComboBox";
			this->wfDamage1ComboBox->Size = System::Drawing::Size(120, 28);
			this->wfDamage1ComboBox->TabIndex = 12;
			// 
			// wfPlusLabel3
			// 
			this->wfPlusLabel3->AutoSize = true;
			this->wfPlusLabel3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfPlusLabel3->Location = System::Drawing::Point(220, 181);
			this->wfPlusLabel3->Name = L"wfPlusLabel3";
			this->wfPlusLabel3->Size = System::Drawing::Size(18, 20);
			this->wfPlusLabel3->TabIndex = 13;
			this->wfPlusLabel3->Text = L"+";
			// 
			// wfDmg1NumUpDown
			// 
			this->wfDmg1NumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfDmg1NumUpDown->Location = System::Drawing::Point(244, 177);
			this->wfDmg1NumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->wfDmg1NumUpDown->Name = L"wfDmg1NumUpDown";
			this->wfDmg1NumUpDown->Size = System::Drawing::Size(61, 26);
			this->wfDmg1NumUpDown->TabIndex = 14;
			// 
			// wfType1Label
			// 
			this->wfType1Label->AutoSize = true;
			this->wfType1Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfType1Label->Location = System::Drawing::Point(12, 225);
			this->wfType1Label->Name = L"wfType1Label";
			this->wfType1Label->Size = System::Drawing::Size(47, 20);
			this->wfType1Label->TabIndex = 15;
			this->wfType1Label->Text = L"Type:";
			// 
			// wfType1TextBox
			// 
			this->wfType1TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfType1TextBox->Location = System::Drawing::Point(73, 222);
			this->wfType1TextBox->Name = L"wfType1TextBox";
			this->wfType1TextBox->Size = System::Drawing::Size(277, 26);
			this->wfType1TextBox->TabIndex = 16;
			// 
			// label8
			// 
			this->label8->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label8->Location = System::Drawing::Point(16, 123);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(338, 2);
			this->label8->TabIndex = 34;
			// 
			// label9
			// 
			this->label9->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label9->Location = System::Drawing::Point(16, 262);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(338, 2);
			this->label9->TabIndex = 35;
			// 
			// wfType2TextBox
			// 
			this->wfType2TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfType2TextBox->Location = System::Drawing::Point(73, 362);
			this->wfType2TextBox->Name = L"wfType2TextBox";
			this->wfType2TextBox->Size = System::Drawing::Size(277, 26);
			this->wfType2TextBox->TabIndex = 44;
			// 
			// wfType2Label
			// 
			this->wfType2Label->AutoSize = true;
			this->wfType2Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfType2Label->Location = System::Drawing::Point(12, 365);
			this->wfType2Label->Name = L"wfType2Label";
			this->wfType2Label->Size = System::Drawing::Size(47, 20);
			this->wfType2Label->TabIndex = 43;
			this->wfType2Label->Text = L"Type:";
			// 
			// wfDmg2NumUpDown
			// 
			this->wfDmg2NumUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfDmg2NumUpDown->Location = System::Drawing::Point(244, 317);
			this->wfDmg2NumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->wfDmg2NumUpDown->Name = L"wfDmg2NumUpDown";
			this->wfDmg2NumUpDown->Size = System::Drawing::Size(61, 26);
			this->wfDmg2NumUpDown->TabIndex = 42;
			// 
			// wfPlusLabel5
			// 
			this->wfPlusLabel5->AutoSize = true;
			this->wfPlusLabel5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfPlusLabel5->Location = System::Drawing::Point(220, 321);
			this->wfPlusLabel5->Name = L"wfPlusLabel5";
			this->wfPlusLabel5->Size = System::Drawing::Size(18, 20);
			this->wfPlusLabel5->TabIndex = 41;
			this->wfPlusLabel5->Text = L"+";
			// 
			// wfDamage2ComboBox
			// 
			this->wfDamage2ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->wfDamage2ComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfDamage2ComboBox->FormattingEnabled = true;
			this->wfDamage2ComboBox->Location = System::Drawing::Point(94, 315);
			this->wfDamage2ComboBox->Name = L"wfDamage2ComboBox";
			this->wfDamage2ComboBox->Size = System::Drawing::Size(120, 28);
			this->wfDamage2ComboBox->TabIndex = 40;
			// 
			// wfPlusLabel4
			// 
			this->wfPlusLabel4->AutoSize = true;
			this->wfPlusLabel4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfPlusLabel4->Location = System::Drawing::Point(69, 318);
			this->wfPlusLabel4->Name = L"wfPlusLabel4";
			this->wfPlusLabel4->Size = System::Drawing::Size(18, 20);
			this->wfPlusLabel4->TabIndex = 39;
			this->wfPlusLabel4->Text = L"+";
			// 
			// wfDmgDice2ComboBox
			// 
			this->wfDmgDice2ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->wfDmgDice2ComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfDmgDice2ComboBox->FormattingEnabled = true;
			this->wfDmgDice2ComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"d3", L"d4", L"d6", L"d8", L"d10", L"d12",
					L"d20", L"d50", L"d100"
			});
			this->wfDmgDice2ComboBox->Location = System::Drawing::Point(161, 272);
			this->wfDmgDice2ComboBox->Name = L"wfDmgDice2ComboBox";
			this->wfDmgDice2ComboBox->Size = System::Drawing::Size(53, 28);
			this->wfDmgDice2ComboBox->TabIndex = 38;
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDown5->Location = System::Drawing::Point(94, 273);
			this->numericUpDown5->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(61, 26);
			this->numericUpDown5->TabIndex = 37;
			this->numericUpDown5->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// wfDamage2Label
			// 
			this->wfDamage2Label->AutoSize = true;
			this->wfDamage2Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wfDamage2Label->Location = System::Drawing::Point(12, 275);
			this->wfDamage2Label->Name = L"wfDamage2Label";
			this->wfDamage2Label->Size = System::Drawing::Size(74, 20);
			this->wfDamage2Label->TabIndex = 36;
			this->wfDamage2Label->Text = L"Damage:";
			// 
			// wfUseLabel
			// 
			this->wfUseLabel->AutoSize = true;
			this->wfUseLabel->Location = System::Drawing::Point(273, 280);
			this->wfUseLabel->Name = L"wfUseLabel";
			this->wfUseLabel->Size = System::Drawing::Size(32, 13);
			this->wfUseLabel->TabIndex = 45;
			this->wfUseLabel->Text = L"Use\?";
			// 
			// wfUseCheckBox
			// 
			this->wfUseCheckBox->AutoSize = true;
			this->wfUseCheckBox->Checked = true;
			this->wfUseCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->wfUseCheckBox->Location = System::Drawing::Point(308, 280);
			this->wfUseCheckBox->Margin = System::Windows::Forms::Padding(0, 3, 3, 3);
			this->wfUseCheckBox->Name = L"wfUseCheckBox";
			this->wfUseCheckBox->Size = System::Drawing::Size(15, 14);
			this->wfUseCheckBox->TabIndex = 46;
			this->wfUseCheckBox->UseVisualStyleBackColor = true;
			// 
			// wfSaveButton
			// 
			this->wfSaveButton->Location = System::Drawing::Point(16, 414);
			this->wfSaveButton->Name = L"wfSaveButton";
			this->wfSaveButton->Size = System::Drawing::Size(75, 23);
			this->wfSaveButton->TabIndex = 47;
			this->wfSaveButton->Text = L"Save";
			this->wfSaveButton->UseVisualStyleBackColor = true;
			// 
			// wfCancelButton
			// 
			this->wfCancelButton->Location = System::Drawing::Point(97, 414);
			this->wfCancelButton->Name = L"wfCancelButton";
			this->wfCancelButton->Size = System::Drawing::Size(75, 23);
			this->wfCancelButton->TabIndex = 48;
			this->wfCancelButton->Text = L"Cancel";
			this->wfCancelButton->UseVisualStyleBackColor = true;
			// 
			// label15
			// 
			this->label15->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label15->Location = System::Drawing::Point(16, 400);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(338, 2);
			this->label15->TabIndex = 49;
			// 
			// WeaponForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(366, 448);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->wfCancelButton);
			this->Controls->Add(this->wfSaveButton);
			this->Controls->Add(this->wfUseCheckBox);
			this->Controls->Add(this->wfUseLabel);
			this->Controls->Add(this->wfType2TextBox);
			this->Controls->Add(this->wfType2Label);
			this->Controls->Add(this->wfDmg2NumUpDown);
			this->Controls->Add(this->wfPlusLabel5);
			this->Controls->Add(this->wfDamage2ComboBox);
			this->Controls->Add(this->wfPlusLabel4);
			this->Controls->Add(this->wfDmgDice2ComboBox);
			this->Controls->Add(this->numericUpDown5);
			this->Controls->Add(this->wfDamage2Label);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->wfType1TextBox);
			this->Controls->Add(this->wfType1Label);
			this->Controls->Add(this->wfDmg1NumUpDown);
			this->Controls->Add(this->wfPlusLabel3);
			this->Controls->Add(this->wfDamage1ComboBox);
			this->Controls->Add(this->wfPlusLabel2);
			this->Controls->Add(this->wfDmgDice1ComboBox);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->wfDamage1Label);
			this->Controls->Add(this->wfRangeTextBox);
			this->Controls->Add(this->wfRangeLabel);
			this->Controls->Add(this->wfAttackNumUpDown);
			this->Controls->Add(this->wfPlusLabel1);
			this->Controls->Add(this->wfAttackComboBox);
			this->Controls->Add(this->wtfAttackLabel);
			this->Controls->Add(this->wfNameTextBox);
			this->Controls->Add(this->wfNameLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"WeaponForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Weapon Creator";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wfAttackNumUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wfDmg1NumUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wfDmg2NumUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
