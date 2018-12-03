#include "Stats.h"
#include <iostream>

using namespace std;

//Berechnet Level abhänig von der momentanigen EXP eingegeben
	int stats::level(long double currentExp) {
		int currentLv(1);
		int x = 2, c = 100;
		long double expToLvUp = c * pow(currentLv, x); //Quadratische Funktion
		while (currentExp >= expToLvUp) {
			++currentLv;
			expToLvUp = c * pow(currentLv, x);
		}
		return currentLv;
	}

	//Berechnet Vitalität abhänig vom Level und des allgemeinen Anfangsstatuswertes 
	int stats::vit(int currentLv, int baseStat) {
		int vitality, baseVit(baseStat), vitPerLv(1), oldLv(0);
		vitality = baseVit + vitPerLv * (currentLv); ;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			vitality = baseVit + vitPerLv * (currentLv);
		}
		return vitality;
	}

	//Berechnet Stärke abhänig vom Level und des allgemeinen Anfangsstatuswertes 
	int stats::str(int currentLv, int baseStat) {
		int strength, baseStr(baseStat), strPerLv(1), oldLv(0);
		strength = baseStr + strPerLv * (currentLv); ;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			strength = baseStr + strPerLv * (currentLv);
		}
		return strength;
	}

	//Berechnet Beweglichkeit abhänig vom Level und des allgemeinen Anfangsstatuswertes 
	int stats::dex(int currentLv, int baseStat) {
		int dexterity, baseDex(baseStat), dexPerLv(1), oldLv(0);
		dexterity = baseDex + dexPerLv * (currentLv); ;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			dexterity = baseDex + dexPerLv * (currentLv);
		}
		return dexterity;
	}

	//Berechnet Intelligenz abhänig vom Level und des allgemeinen Anfangsstatuswertes 
	int stats::inte(int currentLv, int baseStat) {
		int intelligence, baseInt(baseStat), intPerLv(1), oldLv(0);
		intelligence = baseInt + intPerLv * (currentLv); ;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			intelligence = baseInt + intPerLv * (currentLv);
		}
		return intelligence;
	}

	//Berechnet Weisheit abhänig vom Level und des allgemeinen Anfangsstatuswertes 
	int stats::wis(int currentLv, int baseStat) {
		int wisdom, baseWis(baseStat), wisPerLv(1), oldLv(0);
		wisdom = baseWis + wisPerLv * (currentLv); ;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			wisdom = baseWis + wisPerLv * (currentLv);
		}
		return wisdom;
	}

	//Berechnet Lebenspunkte abhänig vom Level und des allgemeinen Anfangsstatuswertes 
	int stats::hp(int currentLv, int baseStat) {
		int startingHp(baseStat), baseHpPerLv(1), maxHp, oldLv(0), hpMod;
		hpMod = vit(currentLv, baseStat);
		maxHp = (startingHp + (baseHpPerLv * (currentLv)))*hpMod;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			maxHp = (startingHp + (baseHpPerLv * (currentLv)))*hpMod;
		}
		return maxHp;
	}

	//Berechnet Mana abhänig vom Level und des allgemeinen Anfangsstatuswertes 
	int stats::mp(int currentLv, int baseStat) {
		int startingMp(baseStat), baseMpPerLv(1), maxMp, oldLv(0), mpMod;
		mpMod = wis(currentLv, baseStat);
		maxMp = (startingMp + (baseMpPerLv * (currentLv)))*mpMod;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			maxMp = (startingMp + (baseMpPerLv * (currentLv)))*mpMod;
		}
		return maxMp;
	}

	//Temp Attack Value - Placeholder until Damage Type System and Skill System are implemented
	//Temporärer Wert für allgemeine ATK(Schaden) - Platzhalter für ein System von verschiedenen Schadenstypen und genaueren Fähigkeiten
	//Berechnet Angriffswert abhänig vom Level und des allgemeinen Anfangsstatuswertes 
	int stats::atk(int currentLv, int baseStat) {
		int baseAtk(baseStat / 5), atkPerLv(1), oldLv(0), currentAtk, strMod;
		strMod = str(currentLv, baseStat);
		currentAtk = (baseAtk + (atkPerLv * (currentLv)))*strMod;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			currentAtk = (baseAtk + (atkPerLv * (currentLv)))*strMod;
		}
		return currentAtk;
	}

	//Missing Values: Defense, Luck, Status Resistence Values, Damage Resistence Values
	//Fehlende Werte: Verteidigung, Glück, Statuseffektresistenzwerte, Schadensresistenzwerte

	double stats::holyRes(double baseRes) {
		double damageMod, resMod;
		resMod = baseRes / 100;
		if (resMod > 1) {
			damageMod = - resMod;
		}
		else {
			damageMod = 1 - resMod;
		}
		return damageMod;
	}

	double stats::slashingRes(double baseRes) {
		double damageMod, resMod;
		resMod = baseRes / 100;
		if (resMod > 1) {
			damageMod = - resMod;
		}
		else {
			damageMod = 1 - resMod;
		}
		return damageMod;
	}

	double stats::crushingRes(double baseRes) {
		double damageMod, resMod;
		resMod = baseRes / 100;
		if (resMod > 1) {
			damageMod = -resMod;
		}
		else {
			damageMod = 1 - resMod;
		}
		return damageMod;
	}