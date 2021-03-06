#include "CoreForm.h"
#include "EditorForm.h"
#include "WeaponForm.h"
#include <time.h>
#include <random> 

namespace NPCSheet {
	// I'm acutely aware that BinarySerializer is obsolete. 
	// However, Soap doesn't support generic List<T> serialization, which this application relies heavily on.
	// JSON isn't natively supported in this version of C++/CLI and getting random unreliable external .dlls to work is agonizing.
	// XML serializer keeps throwing NullReferenceExceptions on GetType() when I try to tell the serializer what an NPC object is.
	// Therefore, Binary wins.
	using namespace System::Runtime::Serialization::Formatters::Binary;

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
		String^ message = "Would you like the wizard to guide you through creating the NPC character sheet step-by-step?\n";
		auto result = MessageBox::Show(message, caption, MessageBoxButtons::YesNoCancel, MessageBoxIcon::Information);
		bool w;
		if (result == System::Windows::Forms::DialogResult::Yes) { w = true; }
		else if (result == System::Windows::Forms::DialogResult::No) { w = false; }
		if (result != System::Windows::Forms::DialogResult::Cancel) {
			EditorForm e(w);
			this->Hide();
			e.ShowDialog();
			this->Show();
			if (e.DialogResult == System::Windows::Forms::DialogResult::OK) {
				cfUnsaved = true;
				NPCs->Add(e.retNPC());
				int idx = NPCs->Count - 1;
				this->cfDataGrid->Rows->Add(NPCs[idx]->name, NPCs[idx]->alignment, NPCs[idx]->race);
				cfDataGrid->ClearSelection();
			}
		}
	}

	// Clicking the Edit button on the core form.
	System::Void CoreForm::cfEditButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = cfDataGrid->CurrentCell->RowIndex;
		if (idx != -1) {
			EditorForm e(NPCs[idx]);
			this->Hide();
			e.ShowDialog();
			this->Show();
			if (e.DialogResult == System::Windows::Forms::DialogResult::OK) {
				cfUnsaved = true;
				NPCs[idx] = e.retNPC();
				int idx = NPCs->Count - 1;
				cfDataGrid->Rows[idx]->Cells["cfDataGridNameColumn"]->Value = NPCs[idx]->name;
				cfDataGrid->Rows[idx]->Cells["cfDataGridAlignColumn"]->Value = NPCs[idx]->alignment;
				cfDataGrid->Rows[idx]->Cells["cfDataGridRaceColumn"]->Value = NPCs[idx]->race;
				cfDataGrid->ClearSelection();
			}
		}
	}

	// Clicking the Save button on the core form.
	System::Void CoreForm::cfSaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			BinaryFormatter^ cereal = gcnew BinaryFormatter();
			SaveFileDialog^ sfd = gcnew SaveFileDialog();
			sfd->Filter = "NPC Pack File|*.npcs";
			sfd->Title = "Save NPC Pack file";
			if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				System::IO::FileStream^ file = System::IO::File::Create(sfd->FileName);
				cereal->Serialize(file, NPCs);
				file->Close();
				cfUnsaved = false;
			}
		}
		catch (...) {
			MessageBox::Show("Save file error.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

	System::Void CoreForm::cfLoadButton_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			BinaryFormatter^ cereal = gcnew BinaryFormatter();
			OpenFileDialog^ ofd = gcnew OpenFileDialog();
			ofd->Filter = "NPC Pack File|*.npcs";
			ofd->Title = "Open NPC Pack file";
			if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				System::IO::FileStream^ file = System::IO::File::Open(ofd->FileName, System::IO::FileMode::Open);
				NPCs = (List<NPC^>^) cereal->Deserialize(file);
				for each (NPC ^ npc in NPCs) { cfDataGrid->Rows->Add(npc->name, npc->alignment, npc->race); }
				cfDataGrid->Refresh();
			}
		}
		catch (...) {
			MessageBox::Show("Load file error.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
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
		DisplaySpellsInListBox();
		rng.seed(seed_val); // initialize rng
		if (wizardStep != -1) { efNextButton_Click(NULL, EventArgs::Empty); } // Triggers first step of the wizard. 
	}

	// Event that triggers when the editor form attempts to close.
	System::Void EditorForm::EditorForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (efUnsaved) {
			String^ message = "You have unsaved changes to your NPC.\nDo you really want to exit?";
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

	// When the checkbox next to "Use Traditional?" is checked in the editor form.
	System::Void EditorForm::efStatsCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		array<TextBox^>^ statTextBoxes = gcnew array<TextBox^>{
			efStat1TextBox, efStat2TextBox, efStat3TextBox, efStat4TextBox, efStat5TextBox, efStat6TextBox
		};
		// Sets defaults to tradAtts ability scores and locks editing. 
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
		if (efTabPage3->BackColor == System::Drawing::Color::LightCoral) { efTabPage3->BackColor = System::Drawing::Color::Transparent; } // Reset invalid.
		efUnsaved = true;
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
			if (efTabPage3->BackColor == System::Drawing::Color::LightCoral) { efTabPage3->BackColor = System::Drawing::Color::Transparent; } // Reset invalid.
			efUnsaved = true;
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
			if (efTabPage3->BackColor == System::Drawing::Color::LightCoral) { efTabPage3->BackColor = System::Drawing::Color::Transparent; } // Reset invalid.
			efUnsaved = true;
			int idx = Decimal::ToInt32(efSpellsNumUpDown->Value);
			n->spells[idx]->Add(efSpellsTextBox->Text);
			efSpellsTextBox->Clear();
			efSpellsNumUpDown->Value = 0;
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
				wdmg2 = Convert::ToString(wfDice2NumUpDown->Value) + wfDmgDice2ComboBox->Text;
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

	// When the Add button in the Ideals section is clicked on the editor form.
	System::Void EditorForm::efIAddButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ txt = efIdealsTextBox->Text;
		if (!String::IsNullOrEmpty(txt)) {
			n->ideals->Add(txt);
			efIdealsListBox->Items->Add(txt);
			efIdealsTextBox->Clear();
			efIdealsListBox->Refresh();
		} else { Media::SystemSounds::Exclamation->Play(); }
	}

	// When the View button in the Ideals section is clicked on the editor form.
	System::Void EditorForm::efIViewButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = efIdealsListBox->SelectedIndex;
		if (idx != -1) { efIdealsTextBox->Text = n->ideals[idx]; }
	}

	// When the Del button in the Ideals section is clicked on the editor form.
	System::Void EditorForm::efIDelButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = efIdealsListBox->SelectedIndex;
		if (idx != -1) {
			n->ideals->RemoveAt(idx);
			efIdealsListBox->Items->RemoveAt(idx);
			efIdealsListBox->Refresh();
		}
	}

	// When the Add button in the Bonds section is clicked on the editor form.
	System::Void EditorForm::efBAddButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ txt = efBondsTextBox->Text;
		if (!String::IsNullOrEmpty(txt)) {
			n->bonds->Add(txt);
			efBondsListBox->Items->Add(txt);
			efBondsTextBox->Clear();
			efBondsListBox->Refresh();
		}
		else { Media::SystemSounds::Exclamation->Play(); }
	}

	// When the View button in the Bonds section is clicked on the editor form.
	System::Void EditorForm::efBViewButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = efBondsListBox->SelectedIndex;
		if (idx != -1) { efBondsTextBox->Text = n->bonds[idx]; }
	}

	// When the Del button in the Bonds section is clicked on the editor form.
	System::Void EditorForm::efBDelButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = efBondsListBox->SelectedIndex;
		if (idx != -1) {
			n->bonds->RemoveAt(idx);
			efBondsListBox->Items->RemoveAt(idx);
			efBondsListBox->Refresh();
		}
	}

	// When the Add button in the Flaws section is clicked on the editor form.
	System::Void EditorForm::efFAddButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ txt = efFlawsTextBox->Text;
		if (!String::IsNullOrEmpty(txt)) {
			n->flaws->Add(txt);
			efFlawsListBox->Items->Add(txt);
			efFlawsTextBox->Clear();
			efFlawsListBox->Refresh();
		}
		else { Media::SystemSounds::Exclamation->Play(); }
	}

	// When the View button in the Flaws section is clicked on the editor form.
	System::Void EditorForm::efFViewButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = efFlawsListBox->SelectedIndex;
		if (idx != -1) { efFlawsTextBox->Text = n->flaws[idx]; }
	}

	// When the Del button in the Flaws section is clicked on the editor form.
	System::Void EditorForm::efFDelButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int idx = efFlawsListBox->SelectedIndex;
		if (idx != -1) {
			n->flaws->RemoveAt(idx);
			efFlawsListBox->Items->RemoveAt(idx);
			efFlawsListBox->Refresh();
		}
	}

	// When the save button is clicked on the editor form.
	System::Void EditorForm::efSaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (ValidateEditorFormSave()) {
			n->name = efNameTextBox->Text;
			n->race = efRaceTextBox->Text;
			n->raceName = efRaceComboBox->Text;
			n->alignment = efAlignmentTextBox->Text;
			n->creatureType = efTypeTextBox->Text;
			if (!String::IsNullOrEmpty(efTagTextBox->Text)) { n->ctTag = "(" + efTagTextBox->Text + ")"; }
			n->tacticsSocial = efTSocTextBox->Text;
			n->tacticsCombat = efTComTextBox->Text;
			n->tacticsMorale = efTMorTextBox->Text;
			n->personality = efPersoTextBox->Text;
			n->appearance = efAppearTextBox->Text;
			n->goalsMotives = efGoalMotTextBox->Text;
			n->initBonus = Decimal::ToInt32(efInitNumUpDown->Value);
			n->hp = Decimal::ToInt32(efHPNumUpDown->Value);
			n->sp = Decimal::ToInt32(efSPNumUpDown->Value);
			n->senses->Clear();
			array<String^>^ sen = efSensesTextBox->Text->Split('\n');
			for each (String ^ s in sen) { n->senses->Add(s); }
			n->languages->Clear();
			array<String^>^ lan = efLanguagesTextBox->Text->Split('\n');
			for each (String ^ l in lan) { n->languages->Add(l); }
			n->addnlStatistics->Clear();
			array<String^>^ add = efAddlStatsTextBox->Text->Split('\n');
			for each (String ^ a in add) { n->addnlStatistics->Add(a); }
			n->defenseDesc[0] = efDef1TextBox->Text;
			n->defenseDesc[1] = efDef2TextBox->Text;
			n->defenseDesc[2] = efDef3TextBox->Text;
			n->statDesc[0] = efStat1TextBox->Text;
			n->statDesc[1] = efStat2TextBox->Text;
			n->statDesc[2] = efStat3TextBox->Text;
			n->statDesc[3] = efStat4TextBox->Text;
			n->statDesc[4] = efStat5TextBox->Text;
			n->statDesc[5] = efStat6TextBox->Text;
			n->defenseVal[0] = Decimal::ToInt32(efDef1NumUpDown->Value);
			n->defenseVal[1] = Decimal::ToInt32(efDef2NumUpDown->Value);
			n->defenseVal[2] = Decimal::ToInt32(efDef3NumUpDown->Value);
			n->statVal[0] = Decimal::ToInt32(efStat1NumUpDown->Value);
			n->statVal[1] = Decimal::ToInt32(efStat2NumUpDown->Value);
			n->statVal[2] = Decimal::ToInt32(efStat3NumUpDown->Value);
			n->statVal[3] = Decimal::ToInt32(efStat4NumUpDown->Value);
			n->statVal[4] = Decimal::ToInt32(efStat5NumUpDown->Value);
			n->statVal[5] = Decimal::ToInt32(efStat6NumUpDown->Value);
			// Everything not listed here is automatically saved via the related ListBoxes.
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			efUnsaved = false;
			this->Close();
		}
		else {
			String^ message = "Missing required fields. Please doublecheck them.";
			String^ caption = "Editor";
			MessageBox::Show(message, caption, MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

	// When the next button is clicked on the editor form.
	System::Void EditorForm::efNextButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ cap = "Wizard", ^msg = "";
		String^ missing = "Mising required fields.\nThe required fields in this step are:";
		MessageBoxButtons bt = MessageBoxButtons::OK;
		switch (wizardStep) {
		case 0:
			if (!stepSeen[0]) {
				// Lock all controls so the user can't mess with anything until the wizard allows.
				for each (TabPage ^ tab in efTabControl->TabPages) { tab->Enabled = false; }
				efTabControl->TabPages[0]->Enabled = true;
				efSaveButton->Enabled = false;

				efLanguagesTextBox->Enabled = false;
				efSensesTextBox->Enabled = false;
				efAddlStatsTextBox->Enabled = false;

				efHPNumUpDown->Enabled = false;
				efStaminaCheckBox->Enabled = false;
				efSPNumUpDown->Enabled = false;
				efInitNumUpDown->Enabled = false;

				efDef1TextBox->Enabled = false;
				efDef2TextBox->Enabled = false;
				efDef3TextBox->Enabled = false;
				efDef1NumUpDown->Enabled = false;
				efDef2NumUpDown->Enabled = false;
				efDef3NumUpDown->Enabled = false;
				efDef2UseCheckBox->Enabled = false;
				efDef3UseCheckBox->Enabled = false;

				efSavesTextBox->Enabled = false;
				efSavesNumUpDown->Enabled = false;
				efSavesAddButton->Enabled = false;
				efSavesDeleteButton->Enabled = false;
				efSkillsTextBox->Enabled = false;
				efSkillsNumUpDown->Enabled = false;
				efSkillsAddButton->Enabled = false;
				efSkillsDeleteButton->Enabled = false;

				efTSocTextBox->Enabled = false;
				efTComTextBox->Enabled = false;
				efTMorTextBox->Enabled = false;

				efIdealsTextBox->Enabled = false;
				efBondsTextBox->Enabled = false;
				efFlawsTextBox->Enabled = false;
				efIAddButton->Enabled = false;
				efIViewButton->Enabled = false;
				efIDelButton->Enabled = false;
				efBAddButton->Enabled = false;
				efBViewButton->Enabled = false;
				efBDelButton->Enabled = false;
				efFAddButton->Enabled = false;
				efFViewButton->Enabled = false;
				efFDelButton->Enabled = false;
				// End initial control lock.
				msg += "The wizard will guide you through the NPC creation process.";
				msg += "\nYou can find a copy of everything the wizard tells you in the external documentation.";
				msg += "\n\nBegin by deciding the NPC's name, race, alignment, and type.";
				msg += "\nIf \"race\" is known by a different term not listed, you can manually type it.";
				msg += "\nAlignment is optional as not all systems use it.";
				msg += "\nType has two boxes, the left box is the mandatory creature type, such as Humanoid or Dragon.";
				msg += "\nThe right box is an optional tag. You see tags in the parenthesis in types such as Humanoid (human). ";
				msg += "Parenthesis are not required in this context.";
				msg += "\n\nWhen you are ready to proceed to the next step, click the Next button.";
				MessageBox::Show(msg, cap, bt);
				stepSeen[0] = true;
			}
			else {
				bool v1 = (!String::IsNullOrEmpty(efNameTextBox->Text));
				bool v2 = (!String::IsNullOrEmpty(efRaceComboBox->Text));
				bool v3 = (!String::IsNullOrEmpty(efRaceTextBox->Text));
				bool v4 = (!String::IsNullOrEmpty(efTypeTextBox->Text));
				if (v1 && v2 && v3 && v4) {
					++wizardStep;
					efNextButton_Click(NULL, EventArgs::Empty);
				}
				else {
					msg = missing;
					msg += "\nName, Race, Race Alias, and Type.";
					MessageBox::Show(msg, cap, bt);
				}
			}
			break;
		case 1:
			if (!stepSeen[1]) {
				efLanguagesTextBox->Enabled = true;
				efSensesTextBox->Enabled = true;
				efAddlStatsTextBox->Enabled = true;

				msg += "The next step is to fill out the NPC's Languages, Senses, and Statistics.";
				msg += "\nLanguages and Senses can be added by putting each on a new line. You must have at least one of each.";
				msg += "\nStatistics covers any feature of the NPC not covered in future segments. ";
				msg += "This segment is optional, and you may want to come back to it later.";
				MessageBox::Show(msg, cap, bt);
				stepSeen[1] = true;
			}
			else {
				bool v1 = (!String::IsNullOrEmpty(efLanguagesTextBox->Text));
				bool v2 = (!String::IsNullOrEmpty(efSensesLabel->Text));
				if (v1 && v2) {
					++wizardStep;
					efNextButton_Click(NULL, EventArgs::Empty);
				}
				else {
					msg = missing;
					msg += "\nLanguages and Senses.";
					MessageBox::Show(msg, cap, bt);
				}
			}
			break;
		case 2:
			if (!stepSeen[2]) {
				efTabControl->TabPages[1]->Enabled = true;
				efTabControl->SelectedIndex = 1;

				msg += "The next step is to establish the NPC's ability scores.";
				msg += "\nThe traditional scores have been implemented by default, ";
				msg += "but you can use custom scores by unchecking the \"Use Traditional?\" checkbox.";
				msg += "\nAbility scores can be generated randomly using the 4d6d1 method, click the \"Roll Random?\" button to do so.";
				MessageBox::Show(msg, cap, bt);
				stepSeen[2] = true;
			}
			else {
				bool v1 = (!String::IsNullOrEmpty(efStat1TextBox->Text));
				bool v2 = (!String::IsNullOrEmpty(efStat2TextBox->Text));
				bool v3 = (!String::IsNullOrEmpty(efStat3TextBox->Text));
				bool v4 = (!String::IsNullOrEmpty(efStat4TextBox->Text));
				bool v5 = (!String::IsNullOrEmpty(efStat5TextBox->Text));
				bool v6 = (!String::IsNullOrEmpty(efStat6TextBox->Text));

				if (v1 && v2 && v3 && v4 && v5 && v6) {
					++wizardStep;
					efNextButton_Click(NULL, EventArgs::Empty);
				}
				else {
					msg = missing;
					msg += "\nAll six ability score fields must be filled out!";
					MessageBox::Show(msg, cap, bt);
				}
			}
			break;
		case 3:
			if (!stepSeen[3]) {
				efHPNumUpDown->Enabled = true;
				efStaminaCheckBox->Enabled = true;
				efInitNumUpDown->Enabled = true;

				msg += "The next step is to determine your NPC's hit points, stamina points (if applicable) and initiative bonus.";
				msg += "\nIf your system uses stamina points, you can enable them with the associated checkbox.";
				msg += "\nMake sure you disable stamina if you don't use it, otherwise your NPC will have at least 1 point.";
				MessageBox::Show(msg, cap, bt);
				stepSeen[3] = true;
			}
			else {
				// Nothing to verify here.
				++wizardStep;
				efNextButton_Click(NULL, EventArgs::Empty);
			}
			break;
		case 4:
			if (!stepSeen[4]) {
				efDef1TextBox->Enabled = true;
				efDef1NumUpDown->Enabled = true;
				efDef2UseCheckBox->Enabled = true;
				efDef3UseCheckBox->Enabled = true;

				msg += "The next step is to set up your NPC's defenses.";
				msg += "\nThe default defense type AC has already been set, but you can change this.";
				msg += "\nYou can add up to two additional defenses using the checkboxes.";
				MessageBox::Show(msg, cap, bt);
				stepSeen[4] = true;
			}
			else {
				bool v1 = (!String::IsNullOrEmpty(efDef1TextBox->Text));
				bool v2 = true, v3 = true;
				if (efDef2UseCheckBox->Checked) { v2 = (!String::IsNullOrEmpty(efDef2TextBox->Text)); }
				if (efDef3UseCheckBox->Checked) { v3 = (!String::IsNullOrEmpty(efDef3TextBox->Text)); }
				
				if (v1 && v2 && v3) {
					++wizardStep;
					efNextButton_Click(NULL, EventArgs::Empty);
				}
				else {
					msg = missing;
					msg += "\nYou must fill out defense names if they're being used.";
					MessageBox::Show(msg, cap, bt);
				}
			}
			break;
		case 5:
			if (!stepSeen[5]) {
				efSavesTextBox->Enabled = true;
				efSavesNumUpDown->Enabled = true;
				efSavesAddButton->Enabled = true;;
				efSavesDeleteButton->Enabled = true;
				efSkillsTextBox->Enabled = true;
				efSkillsNumUpDown->Enabled = true;
				efSkillsAddButton->Enabled = true;
				efSkillsDeleteButton->Enabled = true;

				msg += "The next step is to establish your NPC's saves and skills.";
				msg += "\nType the name of the Save/Skill in the appropriate box, then set their numerical bonus/detriment.";
				msg += "\nA save or skill can be deleted by selecting them in the list, and pressing Delete.";
				msg += "\nThese segments are optional, if your NPC does not have any save or skills mods.";
				MessageBox::Show(msg, cap, bt);
				stepSeen[5] = true;
			}
			else {
				// Nothing to verify here.
				++wizardStep;
				efNextButton_Click(NULL, EventArgs::Empty);
			}
			break;
		case 6:
			if (!stepSeen[6]) {
				efTabControl->TabPages[2]->Enabled = true;
				efTabControl->SelectedIndex = 2;

				msg += "The next step is to establish your NPC's Actions, Weapons, and Spells.";
				msg += "\nYour NPC only requires one entry in any of the three.";
				msg += "\n\nThe Actions section allows you to define an Action name in the top box, ";
				msg += "and the Action's description in the box below it. Click the Add button to add it to the list.";
				msg += "\nActions in the list can be viewed or deleted by selected them and clicking the appropriate button.";
				msg += "\n\nThe weapons section has its own dedicated weapon creator. Click the Create Weapon button to launch it.";
				msg += "\nThe weapon creator allows you to define a weapon's Name, Ability Mod, bonus to atk and dmg, and type.";
				msg += "\nA Weapon can do up to 2 types of damage, but at least one is required. The Weapon Creator will not let you ";
				msg += "save unless all required fields are filled out.";
				msg += "\n\nSpells can be added by typing the spell name into the appropriate text box, and then incrementing the ";
				msg += "counter to match the spell's level, levels 0-9 are supported.";
				msg += "Spells added are displayed sorted by their level, to delete the last spell in a row, select a row and click the Remove Last button";
				
				MessageBox::Show(msg, cap, bt);
				stepSeen[6] = true;
			}
			else {
				bool v1 = (efActionListBox->Items->Count > 0);
				bool v2 = (efWeaponsListBox->Items->Count > 0);
				bool v3 = false;
				for (int i = 0; i <= 9; ++i) {
					if (n->spells[i]->Count > 0) {
						v3 = true;
						break;
					}
				}

				if (v1 || v2 || v3) {
					++wizardStep;
					efNextButton_Click(NULL, EventArgs::Empty);
				}
				else {
					msg = missing;
					msg += "\nYou must have at least one Action, Weapon, or Spell!";
					MessageBox::Show(msg, cap, bt);
				}
			}
			break;
		case 7:
			if (!stepSeen[7]) {
				efTabControl->TabPages[3]->Enabled = true;
				efTabControl->SelectedIndex = 3;

				msg += "The next step is to define your NPC's traits and items.";
				msg += "\nTrait names are in the topmost textbox, and their descriptions go in the box below.";
				msg += "\nTraits can be viewed by selecting them and clicking the View button.";
				msg += "\n\nItems can be added by typing in the item's name in the textbox, and incrementing its counter for quantity.";
				msg += "\n\nBoth of these are optional if your NPC doesn't have anything of note.";
				MessageBox::Show(msg, cap, bt);
				stepSeen[7] = true;
			}
			else {
				// Nothing to verify here.
				++wizardStep;
				efNextButton_Click(NULL, EventArgs::Empty);
			}
			break;
		case 8:
			if (!stepSeen[8]) {
				efTabControl->TabPages[4]->Enabled = true;
				efTabControl->SelectedIndex = 4;

				msg += "The next step is to establish your NPC's personality and description.";
				msg += "\nBegin by describing their Appearance, Personality, and their current Goals/Motives.";
				MessageBox::Show(msg, cap, bt);
				stepSeen[8] = true;
			}
			else {
				bool v1 = !String::IsNullOrEmpty(efAppearTextBox->Text);
				bool v2 = !String::IsNullOrEmpty(efPersoTextBox->Text);
				bool v3 = !String::IsNullOrEmpty(efGoalMotTextBox->Text);

				if (v1 && v2 && v3) {
					++wizardStep;
					efNextButton_Click(NULL, EventArgs::Empty);
				}
				else {
					msg = missing;
					msg += "\nAppearance, Personality, and Goals/Motives.";
					MessageBox::Show(msg, cap, bt);
				}
			}
			break;
		case 9:
			if (!stepSeen[9]) {
				efTSocTextBox->Enabled = true;
				efTComTextBox->Enabled = true;
				efTMorTextBox->Enabled = true;

				msg += "Next, define your NPC's tactics when it comes to Social encounters, Combat encounters, and their morale.";
				MessageBox::Show(msg, cap, bt);
				stepSeen[9] = true;
			}
			else {
				bool v1 = !String::IsNullOrEmpty((efTSocTextBox->Text));
				bool v2 = !String::IsNullOrEmpty((efTComTextBox->Text));
				bool v3 = !String::IsNullOrEmpty((efTMorTextBox->Text));

				if (v1 && v2 && v3) {
					++wizardStep;
					efNextButton_Click(NULL, EventArgs::Empty);
				}
				else {
					msg = missing;
					msg += "\nTactics (Social), Tactics (Combat), and Tactics (Morale)";
					MessageBox::Show(msg, cap, bt);
				}
			}
			break;
		case 10:
			if (!stepSeen[10]) {
				efIdealsTextBox->Enabled = true;
				efBondsTextBox->Enabled = true;
				efFlawsTextBox->Enabled = true;
				efIAddButton->Enabled = true;
				efIViewButton->Enabled = true;
				efIDelButton->Enabled = true;
				efBAddButton->Enabled = true;
				efBViewButton->Enabled = true;
				efBDelButton->Enabled = true;
				efFAddButton->Enabled = true;
				efFViewButton->Enabled = true;
				efFDelButton->Enabled = true;

				msg += "The final step is to establish your NPC's Ideals, Bonds, and Flaws.";
				msg += "\nEach of the three has an appropriate text box for input, and buttons for adding, viewing, and deleting.";
				msg += "\nIf you cannot see that segment, try scrolling down.";
				MessageBox::Show(msg, cap, bt);
				stepSeen[10] = true;
			}
			else {
				bool v1 = (efIdealsListBox->Items->Count > 0);
				bool v2 = (efBondsListBox->Items->Count > 0);
				bool v3 = (efFlawsListBox->Items->Count > 0);

				if (v1 && v2 && v3) {
					msg = "Congratulations! You've successfully completed the NPC!";
					msg += "\nThe entire form is now open to you to make tweaks. ";
					msg += "When you're finished, click the save button to save your NPC.";
					msg += "\n\nRefer to the external documentation for information on what else you can do. Click the ? button in the home screen.";
					MessageBox::Show(msg, cap, bt);
					efSaveButton->Enabled = true;
					efNextButton->Visible = false;
					wizardStep = -1;
				}
				else {
					msg = missing;
					msg += "\nYou must have at least one Ideal, Bond, and Flaw!";
					MessageBox::Show(msg, cap, bt);
				}
			}
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

	bool EditorForm::ValidateEditorFormSave() {
		// Time to validate a bunch of stuff. Anything that fails validation gets highlighted in red.
		array<bool>^ valid = gcnew array<bool>(25);

		valid[0] = !String::IsNullOrEmpty(efNameTextBox->Text); // Name
		if (!valid[0]) { efNameTextBox->BackColor = System::Drawing::Color::LightCoral; }
		valid[1] = !String::IsNullOrEmpty(efRaceComboBox->Text); // Race name
		if (!valid[1]) { efRaceComboBox->BackColor = System::Drawing::Color::LightCoral; }
		valid[2] = !String::IsNullOrEmpty(efRaceTextBox->Text); // Race
		if (!valid[2]) { efRaceTextBox->BackColor = System::Drawing::Color::LightCoral; }
		valid[3] = !String::IsNullOrEmpty(efTypeTextBox->Text); // Type
		if (!valid[3]) { efTypeTextBox->BackColor = System::Drawing::Color::LightCoral; }
		valid[4] = !String::IsNullOrEmpty(efLanguagesTextBox->Text); // Languages
		if (!valid[4]) { efLanguagesTextBox->BackColor = System::Drawing::Color::LightCoral; }
		valid[5] = !String::IsNullOrEmpty(efSensesTextBox->Text); // Languages
		if (!valid[5]) { efSensesTextBox->BackColor = System::Drawing::Color::LightCoral; }

		if (efStatsCheckBox->Checked) { // Using traditional ability scores skips this segment. 
			for (int i = 6; i <= 11; ++i) { valid[i] = true; }
		}
		else {
			valid[6] = !String::IsNullOrEmpty(efStat1TextBox->Text);
			if (!valid[6]) { efStat1TextBox->BackColor = System::Drawing::Color::LightCoral; }
			valid[7] = !String::IsNullOrEmpty(efStat2TextBox->Text);
			if (!valid[7]) { efStat2TextBox->BackColor = System::Drawing::Color::LightCoral; }
			valid[8] = !String::IsNullOrEmpty(efStat3TextBox->Text);
			if (!valid[8]) { efStat3TextBox->BackColor = System::Drawing::Color::LightCoral; }
			valid[9] = !String::IsNullOrEmpty(efStat4TextBox->Text);
			if (!valid[9]) { efStat4TextBox->BackColor = System::Drawing::Color::LightCoral; }
			valid[10] = !String::IsNullOrEmpty(efStat5TextBox->Text);
			if (!valid[10]) { efStat5TextBox->BackColor = System::Drawing::Color::LightCoral; }
			valid[11] = !String::IsNullOrEmpty(efStat6TextBox->Text);
			if (!valid[11]) { efStat6TextBox->BackColor = System::Drawing::Color::LightCoral; }
		}

		valid[12] = !String::IsNullOrEmpty(efDef1TextBox->Text); // Defense 1
		if (!valid[12]) { efDef1TextBox->BackColor = System::Drawing::Color::LightCoral; }

		if (efDef2UseCheckBox->Checked) {
			valid[13] = !String::IsNullOrEmpty(efDef2TextBox->Text); // Defense 2 (if enabled)
			if (!valid[13]) { efDef2TextBox->BackColor = System::Drawing::Color::LightCoral; }
		} else { valid[13] = true; }

		if (efDef3UseCheckBox->Checked) {
			valid[14] = !String::IsNullOrEmpty(efDef3TextBox->Text); // Defense 3 (if enabled)
			if (!valid[14]) { efDef3TextBox->BackColor = System::Drawing::Color::LightCoral; }
		}
		else { valid[14] = true; }

		// Spell checker because the listbox can't be counted.
		bool spell;
		for (int i = 0; i <= 9; ++i) {
			if (n->spells[i]->Count > 0) {
				spell = true;
				break;
			}
		}
		// Must have at least one weapon, action, or spell. 
		valid[15] = ((efWeaponsListBox->Items->Count > 0) || (efActionListBox->Items->Count > 0) || spell);
		if (!valid[15]) { efTabPage3->BackColor = System::Drawing::Color::LightCoral; } 
		
		valid[16] = !String::IsNullOrEmpty(efAppearTextBox->Text); // Appearance
		if (!valid[16]) { efAppearTextBox->BackColor = System::Drawing::Color::LightCoral; }
		valid[17] = !String::IsNullOrEmpty(efPersoTextBox->Text); // Personality
		if (!valid[17]) { efPersoTextBox->BackColor = System::Drawing::Color::LightCoral; }
		valid[18] = !String::IsNullOrEmpty(efGoalMotTextBox->Text); // Goals & Motives
		if (!valid[18]) { efGoalMotTextBox->BackColor = System::Drawing::Color::LightCoral; }
		valid[19] = !String::IsNullOrEmpty(efTSocTextBox->Text); // Tactics - Social
		if (!valid[19]) { efTSocTextBox->BackColor = System::Drawing::Color::LightCoral; }
		valid[20] = !String::IsNullOrEmpty(efTComTextBox->Text); // Tactics - Combat
		if (!valid[20]) { efTComTextBox->BackColor = System::Drawing::Color::LightCoral; }
		valid[21] = !String::IsNullOrEmpty(efTMorTextBox->Text); // Tactics - Morale
		if (!valid[21]) { efTMorTextBox->BackColor = System::Drawing::Color::LightCoral; }
		valid[22] = (efIdealsListBox->Items->Count > 0); // Ideals
		if (!valid[22]) { efIdealsTextBox->BackColor = System::Drawing::Color::LightCoral; }
		valid[23] = (efBondsListBox->Items->Count > 0); // Bonds
		if (!valid[23]) { efBondsTextBox->BackColor = System::Drawing::Color::LightCoral; }
		valid[24] = (efFlawsListBox->Items->Count > 0); // Flaws
		if (!valid[24]) { efFlawsTextBox->BackColor = System::Drawing::Color::LightCoral; }

		for each (bool b in valid) {
			if (!b) { return false; }
		}
		return true;
	}

	// Event removes the red highlight on invalid fields when they're edited again.
	System::Void EditorForm::ValidateUndoRed(System::Object^ sender, System::EventArgs^ e) {
		efUnsaved = true;
		TextBox^ t = safe_cast<TextBox^>(sender);
		if (t->BackColor == System::Drawing::Color::LightCoral) {
			t->BackColor = System::Drawing::SystemColors::Window;
		}
	}

	// Racename combo box is the odd one out and requires its own event. 
	System::Void EditorForm::efRaceComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		efUnsaved = true;
		if (efRaceComboBox->BackColor == System::Drawing::Color::LightCoral) {
			efRaceComboBox->BackColor = System::Drawing::SystemColors::Window;
		}
	}

	// Loader stuff. Should be self explanatory, just putting things where they belong. 
	System::Void EditorForm::LoadMyNPC() {
		DisplaySpellsInListBox();
		efNameTextBox->Text = n->name;
		efRaceTextBox->Text = n->race;
		efRaceComboBox->Text = n->raceName;
		efAlignmentTextBox->Text = n->alignment;
		efTypeTextBox->Text = n->creatureType;
		efTSocTextBox->Text = n->tacticsSocial;
		efTComTextBox->Text = n->tacticsCombat;
		efTMorTextBox->Text = n->tacticsMorale;
		efPersoTextBox->Text = n->personality;
		efAppearTextBox->Text = n->appearance;
		efGoalMotTextBox->Text = n->goalsMotives;
		efInitNumUpDown->Value = n->initBonus;
		efHPNumUpDown->Value = n->hp;
		efSPNumUpDown->Value = n->sp;
		String^ tag;
		if (n->ctTag->Length > 0) { tag = n->ctTag->Substring(1, n->ctTag->Length - 2); }// Remove embedded parenthesis.
		efTagTextBox->Text = tag;
		if (n->sp == 0) { efStaminaCheckBox->Checked = false; }
		String^ sen;
		for each (String ^ s in n->senses) {
			sen += s;
			sen += "\n";
		}
		efSensesTextBox->Text = sen;
		String^ lan;
		for each (String ^ l in n->languages) {
			lan += l;
			lan += "\n";
		}
		efLanguagesTextBox->Text = lan;
		String^ add;
		for each (String ^ a in n->addnlStatistics) {
			add += a;
			add += "\n";
		}
		efAddlStatsTextBox->Text = add;
		efDef1TextBox->Text = n->defenseDesc[0];
		efDef1NumUpDown->Value = n->defenseVal[0];
		if (!String::IsNullOrEmpty(n->defenseDesc[1])) {
			efDef2TextBox->Text = n->defenseDesc[1];
			efDef2NumUpDown->Value = n->defenseVal[1];
			efDef2UseCheckBox->Checked = true;
		}
		if (!String::IsNullOrEmpty(n->defenseDesc[2])) {
			efDef3TextBox->Text = n->defenseDesc[2];
			efDef3NumUpDown->Value = n->defenseVal[2];
			efDef3UseCheckBox->Checked = true;
		}
		efStat1TextBox->Text = n->statDesc[0];
		efStat2TextBox->Text = n->statDesc[1];
		efStat3TextBox->Text = n->statDesc[2];
		efStat4TextBox->Text = n->statDesc[3];
		efStat5TextBox->Text = n->statDesc[4];
		efStat6TextBox->Text = n->statDesc[5];
		efStat1NumUpDown->Value = n->statVal[0];
		efStat2NumUpDown->Value = n->statVal[1];
		efStat3NumUpDown->Value = n->statVal[2];
		efStat4NumUpDown->Value = n->statVal[3];
		efStat5NumUpDown->Value = n->statVal[4];
		efStat6NumUpDown->Value = n->statVal[5];
		int ind = n->weapons->Count - 1;
		if (ind > -1) {
			for (int i = 0; i <= ind; ++i) { UpdateWeaponsListBox(i); }
		}
		String^ s;
		int skind = n->skillDesc->Count - 1;
		if (skind > -1) {
			for (int j = 0; j <= skind; ++j) {
				s = Listerizer(n->skillDesc[j], n->skillVal[j]);
				efSkillsListBox->Items->Add(s);
			}
		}
		int saind = n->savesDesc->Count - 1;
		if (saind > -1) {
			for (int k = 0; k <= saind; ++k) {
				s = Listerizer(n->savesDesc[k], n->savesVal[k]);
				efSavesListBox->Items->Add(s);
			}
		}
		for each (String^ a in n->actionsName) { efActionListBox->Items->Add(a); }
		for each (String^ t in n->traitsName) { efTraitsListBox->Items->Add(t); }
		for each (String^ b in n->bonds) { efBondsListBox->Items->Add(b); }
		for each (String^ d in n->ideals) { efIdealsListBox->Items->Add(d);}
		for each (String^ f in n->flaws) { efFlawsListBox->Items->Add(f); }
		for each (String^ m in n->items) { efItemsListBox->Items->Add(m); }
	}

	System::Void CoreForm::DataGridRowUpdate() {
		cfEditButton->Enabled = (cfDataGrid->Rows->Count > 0);
		cfSaveButton->Enabled = (cfDataGrid->Rows->Count > 0);
	}

	// Can't mix event args for these events. Annyoing. 
	System::Void CoreForm::cfDataGrid_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e) {
		DataGridRowUpdate();
	}

	
	System::Void CoreForm::cfDataGrid_RowsRemoved(System::Object^ sender, System::Windows::Forms::DataGridViewRowsRemovedEventArgs^ e) {
		DataGridRowUpdate();
	}
	// Annoyances stop here.

	System::Void EditorForm::efTabControl_Selecting(System::Object^ sender, System::Windows::Forms::TabControlCancelEventArgs^ e) {
		if (!e->TabPage->Enabled) { e->Cancel = true; }
	}
}