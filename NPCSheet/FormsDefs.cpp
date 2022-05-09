#include "CoreForm.h"
#include "EditorForm.h"
#include <cliext/vector>
#include <random> 

namespace NPCSheet {

	typedef std::mt19937 MyRNG;
	uint32_t seed_val;
	MyRNG rng;
	
	int ModifierCalc(Decimal s) {
		s = Math::Floor(Decimal::Divide(Decimal::Subtract(s, 10), 2)); // Needlessly elaborate way of writing floor(s-10)/2. Thanks System class!
		return Decimal::ToInt32(s);
	}

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
		efTabControl_SelectedIndexChanged(NULL, EventArgs::Empty);
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

	// When something changes which tab the editor form is focused on.
	System::Void EditorForm::efTabControl_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		switch (efTabControl->SelectedIndex) {
		case 0:
			//efTableLayout->Width = 482;
			//this->Width = 518;
			break;
		case 1:
			//efTableLayout->Width = 957;
			//this->Width = 985;
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
	}

	// When the checkbox next to "Use Traditional?" is checked in the editor form.
	System::Void EditorForm::efStatsCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		array<TextBox^>^ statTextBoxes = gcnew array<TextBox^>{
			efStat1TextBox, efStat2TextBox, efStat3TextBox, efStat4TextBox, efStat5TextBox, efStat6TextBox
		};
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
		if (efSavesListBox->SelectedIndex > -1) {
			n->savesDesc->RemoveAt(efSavesListBox->SelectedIndex);
			n->savesVal->RemoveAt(efSavesListBox->SelectedIndex);
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

	// When the Add Action button is clicked in the editor form.
	System::Void EditorForm::efActionAddButton_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	// When the Weapon Creator button is clicked in the editor form.
	System::Void EditorForm::efWeaponCreatorButton_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	// When the View Weapon button is clicked in the editor form.
	System::Void EditorForm::efViewWeapButton_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	// When the Delete Weapon button is clicked in the editor form.
	System::Void EditorForm::efDeleteWeapButton_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	// When the View Action button is clicked in the editor form.
	System::Void EditorForm::efViewButton_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	// When the Delete Action button is clicked in the editor form.
	System::Void EditorForm::efActionDeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	// When the Add Spell button is clicked in the editor form.
	System::Void EditorForm::efSpellsAddButton_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	// When the Remove Last button is clicked in the editor form.
	System::Void EditorForm::efSpellsRemoveButton_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	NPC^ EditorForm::retNPC() {
		return n;
	}
}