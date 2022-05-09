#pragma once

namespace NSNPC {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace cliext;

	public ref struct Weapon {
		String^ wpName;
		int atkBonus;
		String^ dmgA;
		String^ typeA;
		String^ dmgB;
		String^ typeB;
		String^ range;

		Weapon(String^ n, int a, String^ da, String^ ta, String^ db, String^ tb, String^ r)
			: wpName(n), atkBonus(a), dmgA(da), typeA(ta), dmgB(db), typeB(tb), range(r) {}
		~Weapon() {}
		Weapon^ operator=(const Weapon% other) {
			wpName = other.wpName;
			atkBonus = other.atkBonus;
			dmgA = other.dmgA;
			typeA = other.typeA;
			dmgB = other.dmgB;
			typeB = other.typeB;
			return this;
		}
	};

	public ref struct NPC {
		String^ name = "";
		String^ race = "";
		String^ raceName = ""; // if "race" is known as Ancestry or something.
		String^ alignment = "";
		String^ creatureType = "";
		String^ ctTag = ""; // The tag goes in the parentheses for cases such as "Humanoid (human)".
		String^ tacticsSocial = "";
		String^ tacticsCombat = "";
		String^ tacticsMorale = "";
		String^ personality = "";
		String^ appearance = "";
		int initBonus = 0;
		int hp = 0; // hit points
		int sp = 0; // (optional) stamina points
		List<String^>^ senses;
		List<String^>^ languages;
		List<String^>^ addnlStatistics;
		List<String^>^ skillDesc;
		List<String^>^ savesDesc;
		List<String^>^ actionsName ;
		List<String^>^ actionsDesc;
		List<String^>^ traitsName; // Traits are mechanical, not personality-wise.
		List<String^>^ traitsDesc;
		List<String^>^ bonds;
		List<String^>^ flaws;
		List<String^>^ ideals;
		List<String^>^ goalsMotives;
		List<String^>^ items;
		List<int>^ skillVal;
		List<int>^ savesVal;
		List<Weapon^>^ weapons;
		array<String^>^ defenseDesc;
		array<String^>^ statDesc;
		array<int>^ defenseVal;
		array<int>^ statVal;
		// List of lists of strings to manage spells. Spells start at level 0 which is nifty for index matching.
		List<List<String^>^>^ spells;

		NPC(void) {
			senses = gcnew List<String^>();
			languages = gcnew List<String^>();
			addnlStatistics = gcnew List<String^>();
			skillDesc = gcnew List<String^>();
			savesDesc = gcnew List<String^>();
			actionsName = gcnew List<String^>();
			actionsDesc = gcnew List<String^>();
			traitsName = gcnew List<String^>();
			traitsDesc = gcnew List<String^>();
			bonds = gcnew List<String^>();
			flaws = gcnew List<String^>();
			ideals = gcnew List<String^>();
			goalsMotives = gcnew List<String^>();
			items = gcnew List<String^>();
			skillVal = gcnew List<int>();
			savesVal = gcnew List<int>();
			weapons = gcnew List<Weapon^>();
			defenseDesc = gcnew array<String^>(3);
			statDesc = gcnew array<String^>(6);
			defenseVal = gcnew array<int>(3);
			statVal = gcnew array<int>(6);
			spells = gcnew List<List<String^>^>();
		}
		~NPC() {}
		NPC^ operator=(const NPC% other) {
			name = other.name;
			race = other.race;
			raceName = other.raceName;
			alignment = other.alignment;
			creatureType = other.creatureType;
			ctTag = other.ctTag;
			tacticsSocial = other.tacticsSocial;
			tacticsCombat = other.tacticsCombat;
			tacticsMorale = other.tacticsMorale;
			personality = other.personality;
			appearance = other.appearance;
			initBonus = other.initBonus;
			hp = other.hp;
			sp = other.sp;
			senses = other.senses;
			languages = other.languages;
			addnlStatistics = other.addnlStatistics;
			skillDesc = other.skillDesc;
			savesDesc = other.savesDesc;
			actionsName = other.actionsName;
			actionsDesc = other.actionsDesc;
			traitsName = other.traitsName;
			traitsDesc = other.traitsDesc;
			bonds = other.bonds;
			flaws = other.flaws;
			ideals = other.ideals;
			goalsMotives = other.goalsMotives;
			items = other.items;
			skillVal = other.skillVal;
			savesVal = other.savesVal;
			weapons = other.weapons;
			defenseDesc = other.defenseDesc;
			statDesc = other.statDesc;
			defenseVal = other.defenseVal;
			statVal = other.statVal;
			spells = other.spells;
			return this;
		}
	};
}