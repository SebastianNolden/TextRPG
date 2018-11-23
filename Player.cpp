#include "Player.h"
#include "Displaystats.h"
#include "Skills.h"
#include "Stats.h"
#include <iostream>
#include <string>
#include "Main.h"
#include "Combat.h"

using namespace std;

int baseStat(9);

	int player::character(int currentExp, int recievedDamage, int displayCheck, char playerName[25]) {
		stats character;
		displayStats display;

		// calculate Status Values for player character
		currentLv = character.level(currentExp);
		if (oldLv < currentLv) {
			oldLv = currentLv;
			 accumulatedDamage=0;
		}
		maxHp = character.hp(currentLv, baseStat);
		currentAtk = character.atk(currentLv, baseStat);
		accumulatedDamage = {  accumulatedDamage + recievedDamage };
		currentHp = maxHp -  accumulatedDamage;
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
		return currentHp;
	}
	int player::attack(int currentExp, int attackChoice) {
		stats character;
		skills skill;
		int attackDamage;

		currentLv = character.level(currentExp);
		currentAtk = character.atk(currentLv, baseStat);

		if (attackChoice == 0) {
			attackDamage = skill.basicAttack(currentAtk);
		}
		return attackDamage;
	}

