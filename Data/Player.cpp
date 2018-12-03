#include "Player.h"
#include "Displaystats.h"
#include "Skills.h"
#include "Stats.h"
#include <iostream>
#include <string>
#include "Main.h"
#include "Window.h"
#include "Combat.h"

using namespace std;


	void player::character(long double currentExp, int recievedDamage, int spendMp, string playerName, bool reset) {
		stats character;
		skills skill;
		extern int g_magicManipulationSkillExp, g_playerSpendMp, g_maxMp, g_HpRed, g_playerHp, g_playerTotalDamage, g_swordArtsSkillExp;
		extern int g_damageType;
		double damageMod = 1;

		//Berechnet Spielerlevel (Standart 1)
		currentLv = character.level(currentExp);
		
		//Berechnet Spielerfähigkeitslevel (Standart 0)
		magicManipulationLv = skill.magicManipulation(g_magicManipulationSkillExp);
		swordArtsLv = skill.swordArts(g_swordArtsSkillExp);

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
		g_playerTotalDamage += + tempRecDmg;

		// calculate Status Values for player character
		// Berechnet Statuswerte für den Spielercharakter
		maxHp = character.hp(currentLv, baseStat) - g_HpRed;
		g_playerHp = maxHp - g_playerTotalDamage;
		maxMp = character.mp(currentLv, baseStat);
		g_maxMp = maxMp;
		currentMp = maxMp - spendMp;
		vitality = character.vit(currentLv, baseStat) + (swordArtsLv * 2 * currentLv);
		strength = character.str(currentLv, baseStat) + (swordArtsLv * 3 * currentLv);
		dexterity = character.dex(currentLv, baseStat);
		intelligence = character.inte(currentLv, baseStat) + (magicManipulationLv * 3 * currentLv);
		wisdom = character.wis(currentLv, baseStat) + (magicManipulationLv * 2 * currentLv);
		currentAtk = character.atk(currentLv, baseStat);

		if (recievedDamage > 0) {
			cout << playerName << " got hit! " << tempRecDmg << " Damage!\n"
				<< "~~~~~~~~~~~~~~~~~~~~\n";
		}
		if (recievedDamage < 0) {
			cout << "\n~~~~~~~~~~~~~~~~~~~~\n"
				<< playerName << " got healed! " << -tempRecDmg << " Health recovered!";
		}

		if (g_playerHp > maxHp) {
			g_playerHp = maxHp;
			tempRecDmg = 0;
			g_playerTotalDamage = 0;
		}

		if (g_playerHp < maxHp) {
			g_playerHp = 0;
		}

		//Heals the player on level up
		//Heilt spieler wenn er ein Level aufsteigt
		if (oldLv < currentLv) {
			oldLv = currentLv;
			g_playerSpendMp = 0;
			g_playerTotalDamage = 0;
			g_playerHp = maxHp;
		}

		
		if (reset == true) {
			currentExp = 0;
			g_playerHp = maxHp;
			g_playerTotalDamage = 0;
		}

	}

	void player::displayStatsWindow(Window &screen, int displayCheck, string playerName) {
		displayStats display;
		extern int g_playerHp;

		if (displayCheck == 1) {
			display.statWindow(currentLv, currentExp, maxHp, g_playerHp, maxMp, currentMp, currentAtk, vitality, strength, dexterity, intelligence, wisdom, playerName);
			display.skillExp(magicManipulationLv, swordArtsLv);
		}
		if (displayCheck == 2) {
			display.combatStats(currentLv, maxHp, g_playerHp, maxMp, currentMp, playerName);
		}
		if (displayCheck == 3) {
			display.battleWindow(screen, 10, 200, currentLv, maxHp, g_playerHp, maxMp, currentMp, playerName);
		}

	}

	int player::attack(int attackChoice, string playerName) {
		skills skill;
		int attackDamage;
		extern int g_swordArtsSkillExp, g_magicManipulationSkillExp;

		// selects attack chosen
		// wählt eingegebene Attacke aus
		if (attackChoice == 0) {
			attackDamage = skill.basicAttack(currentAtk);
			g_swordArtsSkillExp += +10;
				;
		}
		if (attackChoice == 1) {
			attackDamage = skill.heal(wisdom);
			g_magicManipulationSkillExp = g_magicManipulationSkillExp + 10;//Heilung ist ein Zauber, also erhöht sich die Erfahrung für Zauberkontrolle
				;
		}

		// gives back the damage value
		// Gibt den Schaden wieder
		return attackDamage;
	}

