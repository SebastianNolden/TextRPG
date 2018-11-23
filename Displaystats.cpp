#include "Displaystats.h"
#include "Skills.h"
#include <iostream>
#include <string>
using namespace std;



skills skill;
 void displayStats::statWindow(int currentLv, int currentExp, int maxHp, int currentHp, int currentAtk, int vitality, int strength, int dexterity, int intelligence, int wisdom, char typeName[25]) {
	cout
		<< "\n"
		<< "\n~~~~~~~~~~~"
		<< "\nName: " << typeName
		<< "\n~~~Stats~~~"
		<< "\nLv : " << currentLv
		<< "\nExp: " << currentExp
		<< "\nHP : " << maxHp << "/" << currentHp
		<< "\nAtk: " << currentAtk
		<< "\nVit: " << vitality
		<< "\nStr: " << strength
		<< "\nDex: " << dexterity
		<< "\nInt: " << intelligence
		<< "\nWis: " << wisdom
		<< "\n~~~~~~~~~~~"
		<< "\n"
		;
}
 void displayStats::combatStats(int currentLv, int maxHp, int currentHp, char typeName[25]) {
			cout
				<< "\n"
				<< "\nName: " << typeName
				<< "\nLv: " << currentLv
				<< "\nHp: " << maxHp << "/" << currentHp
				<< "\n"
				;
		}
 void displayStats::skillWindow() {
			cout
				<< "\nSkills: \n";
			skill.skillRegister();

		}

