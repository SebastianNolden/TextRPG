#include "Goblin.h"
#include "Skills.h"
#include "Stats.h"
#include <string>


Goblin::Goblin(){}

Goblin::Goblin(int currentLv, int recievedDamage, int spendMp) {
	stats monster;
	this->monLv = currentLv;
	this->baseStat = 6;
	extern int g_damageType;
	double damageMod = 1;

	//Berechner Spielerresitenzen (Standart 0)
	slashingResMod = monster.slashingRes(0);
	crushingResMod = monster.crushingRes(0);

	if (g_damageType == 2) {
		damageMod = slashingResMod;
	}
	if (g_damageType == 3) {
		damageMod = crushingResMod;
	}

	tempRecDmg = round(recievedDamage * damageMod);
	monTotalDamage += tempRecDmg;
	totalSpendMp += spendMp;

	//calculate Status Values for monster character
	//Berechnet Statuswerte für ein Monster 
	maxHp = monster.hp(currentLv, baseStat);
	currentHp = maxHp - monTotalDamage;
	maxMp = monster.mp(currentLv, baseStat);
	currentMp = maxMp - totalSpendMp;

	vitality = monster.vit(currentLv, baseStat);
	strength = monster.str(currentLv, baseStat);
	dexterity = monster.dex(currentLv, baseStat);
	intelligence = monster.inte(currentLv, baseStat);
	wisdom = monster.wis(currentLv, baseStat);
	currentAtk = monster.atk(currentLv, baseStat);

	/*if (recievedDamage > 0) {
	cout << playerName << " got hit! " << tempRecDmg << " Damage!\n"
	<< "~~~~~~~~~~~~~~~~~~~~\n";
	}
	if (recievedDamage < 0) {
	cout << "\n~~~~~~~~~~~~~~~~~~~~\n"
	<< playerName << " got healed! " << -tempRecDmg << " Health recovered!";
	}*/

	if (currentHp < maxHp) {
		currentHp = 0;
	}
}

Goblin::~Goblin()
{
}

int Goblin::getGoblinCurrentHp() {
	return this->currentHp;
}

int Goblin::getGoblinMaxHp() {
	return this->maxHp;
}

int Goblin::getGoblinCurrentMp() {
	return this->currentHp;
}

int Goblin::getGoblinMaxMp() {
	return this->maxMp;
}

std::string Goblin::getName() {
	return this->monNameGoblin;
}

int Goblin::getGoblinLv() {
	return this->monLv;
}


int Goblin::goblinAttack() {
	skills skill;

	attackDamage = skill.basicAttack(currentAtk);
	skill.skillType(3);

	return attackDamage;
}


void Goblin::Reset() {
	//Heilt Monster wenn es zurückgesetzt wird
	this->currentHp = this->maxHp;
	this->currentMp = this->maxMp;
	this->monTotalDamage = 0;
}
