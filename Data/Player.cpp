#include "Player.h"
#include "Skills.h"
#include "Stats.h"
#include <string>

player::player() {}

player::player(long double recievedExp, int recievedDamage, int spendMp, std::string playerName) {
		stats character;
		skills skill;
		extern int g_damageType;
		double damageMod = 1;

		name = playerName;

		//Berechnet Spielerlevel (Standart 1)
		currentExp += recievedExp;
		currentLv = character.level(currentExp);
		
		//Berechnet Spielerfähigkeitslevel (Standart 0)
		magicManipulationLv = skill.magicManipulation(magicManipulationSkillExp);
		swordArtsLv = skill.swordArts(swordArtsSkillExp);

		//Berechner Spielerresitenzen (Standart 0)
		slashingResMod = character.slashingRes(0);
		crushingResMod = character.crushingRes(0);

		//Setzt Modifier für erhaltenen Schaden abhänig von der ausgewählten Resistenz
		if (g_damageType == 2) {
			damageMod = slashingResMod;
		}
		if (g_damageType == 3) {
			damageMod = crushingResMod;
		}

		tempRecDmg = round(recievedDamage * damageMod);
		playerTotalDamage += + tempRecDmg;
		playerSpendMp += spendMp;

		// calculate Status Values for player character
		// Berechnet Statuswerte für den Spielercharakter
		maxHp = character.hp(currentLv, baseStat) - HpRed;
		currentHp = maxHp - playerTotalDamage;
		maxMp = character.mp(currentLv, baseStat);
		currentMp = maxMp - playerSpendMp;

		vitality = character.vit(currentLv, baseStat) + (swordArtsLv * 2 * currentLv);
		strength = character.str(currentLv, baseStat) + (swordArtsLv * 3 * currentLv);
		dexterity = character.dex(currentLv, baseStat);
		intelligence = character.inte(currentLv, baseStat) + (magicManipulationLv * 3 * currentLv);
		wisdom = character.wis(currentLv, baseStat) + (magicManipulationLv * 2 * currentLv);
		currentAtk = character.atk(currentLv, baseStat);

		/*if (recievedDamage > 0) {
			cout << playerName << " got hit! " << tempRecDmg << " Damage!\n"
				<< "~~~~~~~~~~~~~~~~~~~~\n";
		}
		if (recievedDamage < 0) {
			cout << "\n~~~~~~~~~~~~~~~~~~~~\n"
				<< playerName << " got healed! " << -tempRecDmg << " Health recovered!";
		}*/

		if (currentHp > maxHp) {
			currentHp = maxHp;
			tempRecDmg = 0;
			playerTotalDamage = 0;
		}

		if (currentHp < maxHp) {
			currentHp = 0;
		}

		//Heals the player on level up
		//Heilt spieler wenn er ein Level aufsteigt
		if (oldLv < currentLv) {
			oldLv = currentLv;
			playerSpendMp = 0;
			playerTotalDamage = 0;
			currentHp = maxHp;
		}
	}

player::~player()
{
}

int player::getPlayerLv() {
	return this->currentLv;
}

int player::getPlayerCurrentHp() {
	return this->currentHp;
}

int player::getPlayerMaxHp() {
	return this->maxHp;
}

int player::getPlayerCurrentMp() {
	return this->currentMp;
}

int player::getPlayerMaxMp() {
	return this->maxHp;
}

std::string player::getName() {
	return this->name;
}


int player::attack(int attackChoice) {
		skills skill;
		int attackDamage;

		// selects attack chosen
		// wählt eingegebene Attacke aus
		if (attackChoice == 0) {
			attackDamage = skill.basicAttack(currentAtk);
			swordArtsSkillExp += 10;
		}
		if (attackChoice == 1) {
			attackDamage = skill.heal(wisdom, this->maxMp);
			magicManipulationSkillExp += 10;//Heilung ist ein Zauber, also erhöht sich die Erfahrung für Zauberkontrolle
			playerSpendMp += 10;
		}

		if (attackChoice == 1 && playerSpendMp > maxMp) {
			float skillFail = skill.random();
			if (skillFail < 0) {
				attackDamage = 0;
				insufficientMana = "\nInsufficient Mana! The Spell failed to activate!"
					;
			}
			if (skillFail > 0) {
				HpRed = HpRed + 10;
				insufficientMana =  "\nInsufficient Mana! The Spell consumed your lifefoce!"
					;
			}
			playerSpendMp = maxMp;
		}
		// gives back the damage value
		// Gibt den Schaden wieder
		return attackDamage;
	}

void player::reset() {
	currentExp = 0;
	currentHp = maxHp;
	playerTotalDamage = 0;
}
