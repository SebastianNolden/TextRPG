#include "Mon.h"
#include "Skills.h"
#include "Stats.h"
#include <string>

mon::mon(){}

mon::mon(int currentLv, int recievedDamage, int spendMp) {
		stats monster;
		extern int g_damageType;
		double tempRecDmg(0);

		//Berechner Spielerresitenzen (Standart 0)
		slashingResMod = monster.slashingRes(0);
		crushingResMod = monster.crushingRes(0);

		if (g_damageType == 1) {
			damageMod = slashingResMod;
		}
		if (g_damageType == 2) {
			damageMod = crushingResMod;
		}

		//calculate Status Values for monster character
		//Berechnet Statuswerte für ein Monster 
		vitality = monster.vit(currentLv, baseStat);
		strength = monster.str(currentLv, baseStat);
		dexterity = monster.dex(currentLv, baseStat);
		intelligence = monster.inte(currentLv, baseStat);
		wisdom = monster.wis(currentLv, baseStat);

		maxHp = monster.hp(currentLv, baseStat);

		tempRecDmg = round(recievedDamage * damageMod);
		monTotalDamage += tempRecDmg;
		currentHp = maxHp - monTotalDamage;

		maxMp = monster.mp(currentLv, baseStat);

		totalSpendMp += spendMp;
		currentMp = maxMp - totalSpendMp;

		if (currentHp < maxHp) {
			currentHp = 0;
		}

		currentAtk = monster.atk(currentLv, baseStat);

		/*displayStats display;
		if (displayCheck == 1) {
			display.statWindow(currentLv, 0, maxHp, g_monHp, maxMp, currentMp, currentAtk, vitality, strength, dexterity, intelligence, wisdom, monName);
		}
		if (displayCheck == 2) {
			display.combatStats(currentLv, maxHp, g_monHp, maxMp, currentMp, monName);
		}*/
	}

int mon::getMonCurrentHp() {
	return this->currentHp;
}

int mon::getMonMaxHp() {
	return this->maxHp;
}

int mon::getMonCurrentMp() {
	return this->currentHp;
}

int mon::getMonMaxMp() {
	return this->maxMp;
}

std::string mon::getName() {
	return this->monName;
}

int mon::attack() {
	skills skill;

	attackDamage = skill.basicAttack(currentAtk);
	skill.skillType(3);

	return attackDamage;
}

void mon::reset(){
	//Heilt Monster wenn es zurückgesetzt wird
		this->currentHp = this->maxHp;
		this->currentMp = this->maxMp;
		this->monTotalDamage = 0;
	}

mon::~mon() {}