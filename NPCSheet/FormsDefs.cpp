#include "CoreForm.h"
#include "EditorForm.h"
#include "WeaponForm.h"
#include <time.h>
#include <random> 

namespace NPCSheet {

	typedef std::mt19937 MyRNG;
	uint32_t seed_val = time(NULL);
	MyRNG rng;
	
	int ModifierCalc(Decimal s) {
		s = Math::Floor(Decimal::Divide(Decimal::Subtract(s, 10), 2)); // Needlessly elaborate way of writing floor(s-10)/2. Thanks System class!
		return Decimal::ToInt32(s);
	}

	// Converts a Skill and its bonus to a special format for use in ListBox.
	String^ Listerizer(String^ s, Decimal d) {
		int i = Decimal::ToInt32(d);
		if (i > 0) { s += " +"; }
		else { s += " "; }
		s += i.ToString();
		return s;
	}

	// Clicking the ? button on the core form.
	System::Void CoreForm::cfHelpButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ message = caption + " by Benjamin Russell\n\nWant to read the documentation?";
		auto result = MessageBox::Show(message, caption, MessageBoxButtons::YesNo, MessageBoxIcon::Information);
		if (result == System::Windows::Forms::DialogResult::Yes) {
			System::Diagnostics::Process::Start("https://pastebin.com/ZVjUyUBb");
		}
	}

	// Clicking the New button on the core form.
	System::Void CoreForm::cfNewButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ message = "The wizard will guide you through creating the NPC character sheet step-by-step.\n";
		message += "Are you ready to begin?";
		auto result = MessageBox::Show(message, caption, MessageBoxButtons::YesNo, MessageBoxIcon::Information);
		if (result == System::Windows::Forms::DialogResult::Yes) {
			EditorForm e;
			this->Hide();
			e.ShowDialog();
			this->Show();
			if (e.DialogResult == System::Windows::Forms::DialogResult::OK) {
				NPCs.push_back(e.retNPC());
				// update datagridview
			}
		}
	}

	// Clicking the Edit buton on the core form.
	System::Void CoreForm::cfEditButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Editor
	}

	// Clicking the Save button on the core form.
	System::Void CoreForm::cfSaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// save to file
	}

	System::Void CoreForm::cfLoadButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Load from file
	}

	// Event that triggers when the core form attempts to close. 
	System::Void CoreForm::CoreForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (cfUnsaved) {
			String^ message = "You have unsaved changes in this file.\nDo you really want to exit?";
			auto result = MessageBox::Show(message, caption, MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::No) {
				e->Cancel = true;
			}
		}
	}

	// Event that triggers when the editor form loads.
	System::Void EditorForm::EditorForm_Load(System::Object^ sender, System::EventArgs^ e) {
		//efTabControl_SelectedIndexChanged(NULL, EventArgs::Empty);
		DisplaySpellsInListBox();
		rng.seed(seed_val); // initialize rng
	}

	// Event that triggers when the editor form attempts to close.
	System::Void EditorForm::EditorForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (efUnsaved) {
			String^ message = "You have unsaved changes to your NPC.\nDO you really want to exit?";
			auto result = MessageBox::Show(message, "Editor", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::No) {
				e->Cancel = true;
			}
			else { this->DialogResult = System::Windows::Forms::DialogResult::Cancel; }
		}
	}

	// Clicking the cancel button in the editor form.
	System::Void EditorForm::efCancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	} 

	/*
	// When something changes which tab the editor form is focused on.
	// This was supposed to dynamically change the size of the form to match each tab, but it's currently unused!
	System::Void EditorForm::efTabControl_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		switch (efTabControl->SelectedIndex) {
		case 0:
			//efTableLayout->Width = ;
			//this->Width = ;
			break;
		case 1:
			//efTableLayout->Width = ;
			//this->Width = ;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			String^ message = "Something wonky has occured with the tab control selected index.";
			MessageBox::Show(message, "Editor", MessageBoxButtons::OK, MessageBoxIcon::Information);
			break;
		}
	}*/

	// When the checkbox next to "Use Traditional?" is checked in the editor form.
	System::Void EditorForm::efStatsCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		array<TextBox^>^ statTextBoxes = gcnew array<TextBox^>{
			efStat1TextBox, efStat2TextBox, efStat3TextBox, efStat4TextBox, efStat5TextBox, efStat6TextBox
		};
		// Sets defaults to these six ability scores and locks editing. 
		array<String^>^ tradAtts = gcnew array<String^>{
			"Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma"
		};
		if (efStatsCheckBox->Checked == true) {
			for (int i = 0; i <= 5; ++i) {
				statTextBoxes[i]->Text = tradAtts[i];
				statTextBoxes[i]->Enabled = false;
			}
		}
		else {
			for (int i = 0; i <= 5; ++i) {
				statTextBoxes[i]->Clear();
				statTextBoxes[i]->Enabled = true;
			}
		}
	}

	// Clicking the roll random button in the editor form. 
	System::Void EditorForm::efRandomStatsButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Segment rolls 4d6, then drops the lowest. It does this once per ability score. 
		std::uniform_int_distribution<uint32_t> dist6(1, 6);
		int dice[4] = { 0,0,0,0 };
		int stats[6] = { 0,0,0,0,0,0 };
		int i, j, k ,l;
		for (i = 0; i <= 5; ++i) {
			for (j = 0; j <= 3; ++j) { dice[j] = dist6(rng); }
			int lowest = 0;
			for (k = 0; k <= 3; ++k) {
				if (dice[k] < dice[lowest]) { lowest = k; }
			}
			dice[lowest] = 0;
			stats[i] = dice[0] + dice[1] + dice[2] + dice[3];
		}
		array<NumericUpDown^>^ statNumUpDown = gcnew array<NumericUpDown^>{
			efStat1NumUpDown, efStat2NumUpDown, efStat3NumUpDown, efStat4NumUpDown, efStat5NumUpDown, efStat6NumUpDown
		};
		for (l = 0; l <= 5; ++l) { statNumUpDown[l]->Value = stats[l]; }
	}

	// Event when the stat value text boxes change text in editor form.
	System::Void EditorForm::StatVals_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		NumericUpDown^ b = safe_cast<NumericUpDown^>(sender);
		String^ s = b->Value.ToString();
		Char c = b->Name[6]; // Gets sender's number.
		int mod = ModifierCalc(b->Value);
		String^ txt = mod.ToString();
		if (mod > -1) { txt = "+" + txt; }
		array<Label^>^ modLabels = gcnew array<Label^>{ // Refs to the associated label.
			efStat1ModLabel, efStat2ModLabel, efStat3ModLabel, efStat4ModLabel, efStat5ModLabel, efStat6ModLabel
		};
		modLabels[c - '1']->Text = txt;
	}

	// Event that triggers when the check box next to "Enable Stamina?" label is checked on the editor form.
	System::Void EditorForm::efStaminaCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (efStaminaCheckBox->Checked == true) {
			efSPNumUpDown->Enabled = true;
			efSPNumUpDown->Value = 1;
			efStaminaLabel->ForeColor = SystemColors::ControlText;
		}
		else {
			efSPNumUpDown->Enabled = false;
			efSPNumUpDown->Value = 0;
			efStaminaLabel->ForeColor = SystemColors::ControlDark;
		}
	}

	// Event that triggers when one of the check boxes next to "Use?" labels is checked on the editor form.
	System::Void EditorForm::DefCheck_CheckChanged(System::Object^ sender, System::EventArgs^ e) {
		CheckBox^ b = safe_cast<CheckBox^>(sender);
		char c = b->Name[5];
		if (c == '2') {
			efDef2TextBox->Enabled = b->Checked;
			efDef2NumUpDown->Enabled = b->Checked;
		}
		else {
			efDef3TextBox->Enabled = b->Checked;
			efDef3NumUpDown->Enabled = b->Checked;
		}
	}

	// Clicking the Add button in the Saves section of the editor form.
	System::Void EditorForm::efSavesAddButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if ((efSavesTextBox->Text->Length != 0) && (efSavesNumUpDown->Value != 0)) {
			n->savesDesc->Add(efSavesTextBox->Text);
			n->savesVal->Add(Decimal::ToInt32(efSavesNumUpDown->Value));
			String^ s = Listerizer(efSavesTextBox->Text, efSavesNumUpDown->Value);
			efSavesListBox->Items->Add(s);
			efSavesTextBox->Clear();
			efSavesNumUpDown->Value = 0;
		}
		else { Media::SystemSounds::Exclamation->Play(); }
	}

	// Clicking the Delete button in the Saves section of the editor form.
	System::Void EditorForm::efSavesDeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = efSavesListBox->SelectedIndex;
		if (idx > -1) {
			n->savesDesc->RemoveAt(idx);
			n->savesVal->RemoveAt(idx);
			efSavesListBox->Items->Remove(efSavesListBox->SelectedItem);
			efSavesListBox->Refresh();
		}
		else { Media::SystemSounds::Exclamation->Play(); }
	}

	// Clicking the Add button in the Skills section of the editor form.
	System::Void EditorForm::efSkillsAddButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if ((efSkillsTextBox->Text->Length != 0) && (efSkillsNumUpDown->Value != 0)) {
			n->skillDesc->Add(efSkillsTextBox->Text);
			n->skillVal->Add(Decimal::ToInt32(efSkillsNumUpDown->Value));
			String^ s = Listerizer(efSkillsTextBox->Text, efSkillsNumUpDown->Value);
			efSkillsListBox->Items->Add(s);
			efSkillsTextBox->Clear();
			efSkillsNumUpDown->Value = 0;
		}
		else { Media::SystemSounds::Exclamation->Play(); }
	}

	// Clicking the Delete button in the Skills section of the editor form.
	System::Void EditorForm::efSkillsDeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (efSkillsListBox->SelectedIndex > -1) {
			n->skillDesc->RemoveAt(efSkillsListBox->SelectedIndex);
			n->skillVal->RemoveAt(efSkillsListBox->SelectedIndex);
			efSkillsListBox->Items->Remove(efSkillsListBox->SelectedItem);
			efSkillsListBox->Refresh();
		}
		else { Media::SystemSounds::Exclamation->Play(); }
	}

	// When the Weapon Creator button is clicked in the editor form.
	System::Void EditorForm::efWeaponCreatorButton_Click(System::Object^ sender, System::EventArgs^ e) {
		array<String^>^ scores = gcnew array<String^>{efStat1TextBox->Text, efStat2TextBox->Text, efStat3TextBox->Text,
			efStat4TextBox->Text, efStat5TextBox->Text, efStat6TextBox->Text, efStat1ModLabel->Text, efStat2ModLabel->Text,
			efStat3ModLabel->Text, efStat4ModLabel->Text, efStat5ModLabel->Text, efStat6ModLabel->Text };

		WeaponForm w(scores);
		w.ShowDialog();
		if (w.DialogResult == System::Windows::Forms::DialogResult::OK) {
			n->weapons->Add(w.retWeapon());
			int i = n->weapons->Count - 1;
			UpdateWeaponsListBox(i);
		}
	}

	// Similar function to Listerizer() but for Weapons.
	System::Void EditorForm::UpdateWeaponsListBox(int idx) {
		String^ litem = n->weapons[idx]->wpName;
		if (n->weapons[idx]->atkBonus > -1) { litem += " +"; }
		litem += Convert::ToString(n->weapons[idx]->atkBonus);
		litem += " [" + n->weapons[idx]->dmgA + " ";
		litem += n->weapons[idx]->typeA;
		if (!String::IsNullOrEmpty(n->weapons[idx]->dmgB)) {
			litem += " / " + n->weapons[idx]->dmgB + " ";
			litem += n->weapons[idx]->typeB;
		}
		litem += "]";
		efWeaponsListBox->Items->Add(litem);
		efWeaponsListBox->Refresh();
	}

	// When the Delete Weapon button is clicked in the editor form.
	System::Void EditorForm::efDeleteWeapButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = efWeaponsListBox->SelectedIndex;
		if (idx != -1) {
			efWeaponsListBox->Items->RemoveAt(idx);
			n->weapons->RemoveAt(idx);
			efWeaponsListBox->Refresh();
		}
		else { Media::SystemSounds::Exclamation->Play(); }
	}

	// When the Add Action button is clicked in the editor form.
	System::Void EditorForm::efActionAddButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ an = efActionNameTextBox->Text;
		String^ ad = efActionDescTextBox->Text;
		if (!String::IsNullOrEmpty(an) && !String::IsNullOrEmpty(ad)) {
			n->actionsName->Add(an);
			n->actionsDesc->Add(ad);
			efActionListBox->Items->Add(an);
			efActionListBox->Refresh();
			efActionNameTextBox->Clear();
			efActionDescTextBox->Clear();
		}
		else { Media::SystemSounds::Exclamation->Play(); }
	}

	// When the View Action button is clicked in the editor form.
	System::Void EditorForm::efViewButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = efActionListBox->SelectedIndex;
		efActionNameTextBox->Text = n->actionsName[idx];
		efActionDescTextBox->Text = n->actionsDesc[idx];
	}

	// When the Delete Action button is clicked in the editor form.
	System::Void EditorForm::efActionDeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = efActionListBox->SelectedIndex;
		if (idx != -1) {
			n->actionsName->RemoveAt(idx);
			n->actionsDesc->RemoveAt(idx);
			efActionListBox->Items->RemoveAt(idx);
			efActionListBox->Refresh();
		}
	}

	// When the Add Spell button is clicked in the editor form.
	System::Void EditorForm::efSpellsAddButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!String::IsNullOrEmpty(efSpellsTextBox->Text)) {
			int idx = Decimal::ToInt32(efSpellsNumUpDown->Value);
			n->spells[idx]->Add(efSpellsTextBox->Text);
			DisplaySpellsInListBox();
		}
		else { Media::SystemSounds::Exclamation->Play(); }
	}

	// When the Remove Last button is clicked in the editor form.
	System::Void EditorForm::efSpellsRemoveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = efSpellsListBox->SelectedIndex;
		if (idx != -1 && n->spells[idx]->Count > 0) {
			n->spells[idx]->RemoveAt((n->spells[idx]->Count) - 1);
			efSpellsListBox->SelectedIndex = -1;
			DisplaySpellsInListBox();
		}
	}

	// A special function to display all known spells in the ListBox using the typical format used in statblocks. 
	System::Void EditorForm::DisplaySpellsInListBox() {
		efSpellsListBox->Items->Clear();
		String^ litem;
		for (int i = 0; i <= 9; ++i) {
			litem = Convert::ToString(i) + ": ";
			for each (String^ s in n->spells[i]) {
				litem += s + ", ";
			}
			if (litem->Length > 3) { litem = litem->Substring(0, (litem->Length - 2)); } // If last item, delete the comma and space.
			efSpellsListBox->Items->Add(litem);
		}
		efSpellsListBox->Refresh();
	}

	// When the save button is clicked on the weapon form.
	System::Void WeaponForm::wfSaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (wfValidateSave()) {
			String^ wname = wfNameTextBox->Text;
			int amod1 = 0, amod2 = 0, amod3 = 0, cmod = 0; // amod = ability mod, cmod = combined mod
			if (wfAttackComboBox->SelectedIndex != 0) { amod1 = mods[(wfAttackComboBox->SelectedIndex)-1]; } // Add amod if applicable.
			int watk = Decimal::ToInt32(wfAttackNumUpDown->Value) + amod1; // atk bonus is the specified value plus the first amod
			
			// Weapon damage 1.
			if (wfDamage1ComboBox->SelectedIndex != 0) { amod2 = mods[(wfDamage1ComboBox->SelectedIndex) - 1]; }
			String^ wdmg1 = Convert::ToString(wfDice1NumUpDown->Value) + wfDmgDice1ComboBox->Text;
			cmod = amod2 + Decimal::ToInt32(wfDmg1NumUpDown->Value); // first cmod is the specified value plus the second amod
			if (cmod > -1) { wdmg1 += "+"; }
			wdmg1 += Convert::ToString(cmod);
			String^ wtype1 = wfType1TextBox->Text;
			
			// Weapon damage 2
			String^ wdmg2 = "";
			String^ wtype2 = "";
			// Basically same shit if the use CheckBox is checked. otherwise the associated variables are blank and will be ignored. 
			if (wfUseCheckBox->Checked) {
				if (wfDamage2ComboBox->SelectedIndex != 0) { amod3 = mods[(wfDamage2ComboBox->SelectedIndex) - 1]; }
				cmod = 0;
				wdmg2 = Convert::ToString(wfDmg2NumUpDown->Value) + wfDmgDice2ComboBox->Text;
				cmod = amod3 + Decimal::ToInt32(wfDmg2NumUpDown->Value);
				if (cmod > -1) { wdmg2 += "+"; }
				wdmg2 += Convert::ToString(cmod);
				wtype2 = wfType2TextBox->Text;
			}
			String^ wrng = wfRangeTextBox->Text;
			wp = gcnew Weapon(wname, watk, wdmg1, wtype1, wdmg2, wtype2, wrng);
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		} else { Media::SystemSounds::Exclamation->Play(); }
	}

	// When the cancel button is clicked on the weapon form.
	System::Void WeaponForm::wfCancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}

	// Event that triggers when the Use checkbox is checked in the weapon form.
	System::Void WeaponForm::wfUseCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (wfUseCheckBox->Checked == true) {
			wfDamage2Label->ForeColor = SystemColors::ControlText;
			wfType2Label->ForeColor = SystemColors::ControlText;
			wfPlusLabel4->ForeColor = SystemColors::ControlText;
			wfPlusLabel5->ForeColor = SystemColors::ControlText;
		}
		else {
			wfDamage2Label->ForeColor = SystemColors::ControlDark;
			wfType2Label->ForeColor = SystemColors::ControlDark;
			wfPlusLabel4->ForeColor = SystemColors::ControlDark;
			wfPlusLabel5->ForeColor = SystemColors::ControlDark;
		}
		wfDice2NumUpDown->Enabled = wfUseCheckBox->Checked;
		wfDmgDice2ComboBox->Enabled = wfUseCheckBox->Checked;
		wfDamage2ComboBox->Enabled = wfUseCheckBox->Checked;
		wfDmg2NumUpDown->Enabled = wfUseCheckBox->Checked;
		wfType2TextBox->Enabled = wfUseCheckBox->Checked;

	}

	// When the Add button in the Traits section is clikced on the editor form.
	System::Void EditorForm::efAddTraitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!String::IsNullOrEmpty(efTraitNameTextBox->Text) && !String::IsNullOrEmpty(efTraitDescTextBox->Text)) {
			n->traitsName->Add(efTraitNameTextBox->Text);
			n->traitsDesc->Add(efTraitDescTextBox->Text);
			efTraitsListBox->Items->Add(efTraitNameTextBox->Text);
			efTraitNameTextBox->Clear();
			efTraitDescTextBox->Clear();
			efTraitsListBox->Refresh();
		} else { Media::SystemSounds::Exclamation->Play(); }
	}
	// When the View button in the Traits section is clicked on the editor form.
	System::Void EditorForm::efViewTraitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = efTraitsListBox->SelectedIndex;
		if (idx != -1) {
			efTraitNameTextBox->Text = n->traitsName[idx];
			efTraitDescTextBox->Text = n->traitsDesc[idx];
		}
	}

	// When the Delete button in the Traits section is clicked on the editor form.
	System::Void EditorForm::efDeleteTraitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = efTraitsListBox->SelectedIndex;
		if (idx != -1) {
			n->traitsName->RemoveAt(idx);
			n->traitsDesc->RemoveAt(idx);
			efTraitsListBox->Items->RemoveAt(idx);
			efTraitsListBox->Refresh();
		}
	}

	// When the Add item in the Items section is clicked on the editor form.
	System::Void EditorForm::efItemAddButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!String::IsNullOrEmpty(efItemTextBox->Text)) {
			String^ litem = efItemTextBox->Text;
			litem += " (";
			litem += Convert::ToString(efItemQtyNumUpDown->Value);
			litem += ")";
			efItemsListBox->Items->Add(litem);
			efItemTextBox->Clear();
			efItemQtyNumUpDown->Value = 1;
			efItemsListBox->Refresh();
			n->items->Add(litem);
		}
		else { Media::SystemSounds::Exclamation->Play(); }
	}

	// When the Delete button in the Items section is clicked on the editor form.
	System::Void EditorForm::efItemDeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = efItemsListBox->SelectedIndex;
		if (idx != -1) {
			n->items->RemoveAt(idx);
			efItemsListBox->Items->RemoveAt(idx);
			efItemsListBox->Refresh();
		}
	}

	NPC^ EditorForm::retNPC() {
		return n;
	}

	Weapon^ WeaponForm::retWeapon() {
		return wp;
	}

	// You can't save if certain required fields are blank. This checks for them.
	bool WeaponForm::wfValidateSave() {
		bool validate1, validate2, validate3, validate4 = true, validate5 = true;
		validate1 = !String::IsNullOrEmpty(wfNameTextBox->Text);
		validate2 = (wfDmgDice1ComboBox->SelectedIndex != -1);
		validate3 = !String::IsNullOrEmpty(wfType1TextBox->Text);
		if (wfUseCheckBox->Checked) {
			validate4 = (wfDmgDice2ComboBox->SelectedIndex != -1);
			validate5 = !String::IsNullOrEmpty(wfType2TextBox->Text);
		}
		return (validate1 && validate2 && validate3 && validate4 && validate5);
	}
}