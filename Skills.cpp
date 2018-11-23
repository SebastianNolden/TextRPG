#include "Skills.h"
#include <iostream>
#include <string>
using namespace std;

	int skills::basicAttack(int atkStat) {
		int damage(atkStat);
		return damage;
	}
	void skills::skillRegister() {		// 20 Symbols per Skill list
		string skillList[25];
		skillList[0] = { "|0: Basic Attack   |" };
		cout << skillList[0]
			<< "\n"
			;
	}

