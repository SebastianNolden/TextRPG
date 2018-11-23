#include "Mon.h"
#include "Displaystats.h"
#include "Skills.h"
#include "Stats.h"
#include <iostream>
#include <string>
#include "Main.h"

using namespace std;

	int mon::goblin(int currentLv, int recievedDamage, int displayCheck,bool reset) {
		int baseStat(6);
		char monName[7]("Goblin");
		stats monster;

		//calculate Status Values for monster character
		vitality = monster.vit(currentLv, baseStat);
		strength = monster.str(currentLv, baseStat);
		dexterity = monster.dex(currentLv, baseStat);
		intelligence = monster.inte(currentLv, baseStat);
		wisdom = monster.wis(currentLv, baseStat);
		maxHp = monster.hp(currentLv, baseStat);
		accumulatedDamage =  accumulatedDamage + recievedDamage ;
		currentHp = maxHp -  accumulatedDamage;
		if (reset == true) {
			currentHp = maxHp;
			accumulatedDamage = 0;
		}
		currentAtk = monster.atk(currentLv, baseStat);

		displayStats display;
		if (displayCheck == 1) {
			display.statWindow(currentLv, 0, maxHp, currentHp, currentAtk, vitality, strength, dexterity, intelligence, wisdom, monName);
		}
		if (displayCheck == 2) {
			display.combatStats(currentLv, maxHp, currentHp, monName);
		}
		return currentHp;
	}
