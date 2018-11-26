#include "Mon.h"
#include "Displaystats.h"
#include "Skills.h"
#include "Stats.h"
#include <iostream>
#include <string>
#include "Main.h"

using namespace std;

	int mon::goblin(int currentLv, int recievedDamage, int displayCheck,bool reset) {
		string monName("Goblin");
		stats monster;

		//calculate Status Values for monster character
		vitality = monster.vit(currentLv, baseStatGoblin);
		strength = monster.str(currentLv, baseStatGoblin);
		dexterity = monster.dex(currentLv, baseStatGoblin);
		intelligence = monster.inte(currentLv, baseStatGoblin);
		wisdom = monster.wis(currentLv, baseStatGoblin);
		maxHp = monster.hp(currentLv, baseStatGoblin);
		currentHp = maxHp -  recievedDamage;
		if (reset == true) {
			currentHp = maxHp;
		}
		currentAtk = monster.atk(currentLv, baseStatGoblin);

		displayStats display;
		if (displayCheck == 1) {
			display.statWindow(currentLv, 0, maxHp, currentHp, currentAtk, vitality, strength, dexterity, intelligence, wisdom, monName);
		}
		if (displayCheck == 2) {
			display.combatStats(currentLv, maxHp, currentHp, monName);
		}
		return currentHp;
	}

	int mon::attack(int currentLv, string monType) {
		stats monster;
		skills skill;

		if (monType == "Goblin") {
			currentAtk = monster.atk(currentLv, baseStatGoblin);
			attackDamage = skill.basicAttack(currentAtk);
			cout << monType << " attacked! " << attackDamage << " Damage!\n"
				;
		}
		return attackDamage;
	}
