#include "Player.h"
#include "Displaystats.h"
#include "Skills.h"
#include "Stats.h"
#include <iostream>
#include <string>
#include "Main.h"
#include "Combat.h"

using namespace std;


	int player::character(int currentExp, int recievedDamage, int displayCheck, string playerName, bool reset) {
		stats character;
		displayStats display;

		currentLv = character.level(currentExp);
		
		// calculate Status Values for player character
		maxHp = character.hp(currentLv, baseStat);
		// Heals the player on level up
		currentAtk = character.atk(currentLv, baseStat);
		currentHp = maxHp -  recievedDamage;
		vitality = character.vit(currentLv, baseStat);
		strength = character.str(currentLv, baseStat);
		dexterity = character.dex(currentLv, baseStat);
		intelligence = character.inte(currentLv, baseStat);
		wisdom = character.wis(currentLv, baseStat);

		

		if (displayCheck == 1) {
			display.statWindow(currentLv, currentExp, maxHp, currentHp, currentAtk, vitality, strength, dexterity, intelligence, wisdom, playerName);
		}
		if (displayCheck == 2) {
			display.combatStats(currentLv, maxHp, currentHp, playerName);
		}
		if (reset == true) {
			currentExp = 0;
			currentHp = maxHp;
		}

		return currentHp;
	}
	int player::attack(int currentExp, int attackChoice, string playerName) {
		stats character;
		skills skill;
		int attackDamage;

		// calculates Status Values for player character relevant for attack
		currentLv = character.level(currentExp);
		currentAtk = character.atk(currentLv, baseStat);
		wisdom = character.wis(currentLv, baseStat);

		// selects attack chosen
		if (attackChoice == 0) {
			attackDamage = skill.basicAttack(currentAtk);
			cout << playerName << " attacked! " << attackDamage << " Damage!\n"
				;
		}
		if (attackChoice == 1) {
			attackDamage = skill.heal(wisdom);
			cout << playerName << " cast Heal! " << -attackDamage << " Health recovered!\n"
				;
		}

		// gives back the damage value
		return attackDamage;
	}

