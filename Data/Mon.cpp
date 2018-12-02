#include "Mon.h"
#include "Displaystats.h"
#include "Skills.h"
#include "Stats.h"
#include <iostream>
#include <string>
#include "Main.h"

using namespace std;


void mon::goblin(int currentLv, int recievedDamage, int spendMp, int displayCheck,bool reset) {
		string monName("Goblin");
		stats monster;
		extern double g_monHp, g_monTotalDamage;
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
		//Berechnet Statuswerte für ein Monster (Goblin)
		vitality = monster.vit(currentLv, baseStatGoblin);
		strength = monster.str(currentLv, baseStatGoblin);
		dexterity = monster.dex(currentLv, baseStatGoblin);
		intelligence = monster.inte(currentLv, baseStatGoblin);
		wisdom = monster.wis(currentLv, baseStatGoblin);
		maxHp = monster.hp(currentLv, baseStatGoblin);
		tempRecDmg = recievedDamage * damageMod;
		g_monTotalDamage += + tempRecDmg;
		g_monHp = maxHp - g_monTotalDamage;
		maxMp = monster.mp(currentLv, baseStatGoblin);
		currentMp = maxMp - spendMp;

		if (g_monHp < maxHp) {
			g_monHp = 0;
		}

		if (displayCheck == 2) {
			if (recievedDamage > 0) {
				cout 
					<< monName << " got hit! " << tempRecDmg << " Damage!\n";
				cout << "~~~~~~~~~~~~~~~~~~~~\n";

			}
			if (recievedDamage < 0) {
				cout 
					<< monName << " got healed! " << tempRecDmg << " Health recovered!\n";
				cout << "~~~~~~~~~~~~~~~~~~~~\n";
			}
		}

		if (reset == true) { //Heilt Monster wenn es zurückgesetzt wird
			g_monHp = maxHp;
			currentMp = maxMp;
			g_monTotalDamage = 0;
		}

		currentAtk = monster.atk(currentLv, baseStatGoblin);

		displayStats display;
		if (displayCheck == 1) {
			display.statWindow(currentLv, 0, maxHp, g_monHp, maxMp, currentMp, currentAtk, vitality, strength, dexterity, intelligence, wisdom, monName);
		}
		if (displayCheck == 2) {
			display.combatStats(currentLv, maxHp, g_monHp, maxMp, currentMp, monName);
		}
	}

	int mon::attack(int currentLv, string monType) {
		stats monster;
		skills skill;

		if (monType == "Goblin") { //Wenn der Gegner ein "Goblin" ist, wird der Schaden von einem Goblin berechnet
			currentAtk = monster.atk(currentLv, baseStatGoblin);
			attackDamage = skill.basicAttack(currentAtk);
			skill.skillType(3);
				;
		}
		return attackDamage;
	}
