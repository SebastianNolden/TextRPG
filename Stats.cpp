#include "Stats.h"
#include <iostream>

using namespace std;


	int stats::level(int currentExp) {
		int currentLv(1);
		int x = 2, c = 100;
		double expToLvUp = c * pow(currentLv, x);
		while (currentExp >= expToLvUp) {
			++currentLv;
			expToLvUp = c * pow(currentLv, x);

			//Control for EXP values

			//cout << expToLvUp << "  " << currentLv+1 << "\n" ; //Displays required total Exp for all avalible leves +1
			/*int numCheck(1), x, y;  //Displays the required additional Exp values for 10 levels
			while (numCheck < 10) {
			x = 100 * pow(numCheck, 2);
			y = 100 * pow(numCheck  , 2);
			cout << x - y << "\n";
			++numCheck;
			} */
		}

		return currentLv;
	}

	int stats::vit(int currentLv, int baseStat) {
		int vitality, baseVit(baseStat), vitPerLv(1), oldLv(0);
		vitality = baseVit + vitPerLv * (currentLv); ;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			vitality = baseVit + vitPerLv * (currentLv);
		}
		return vitality;
	}

	int stats::str(int currentLv, int baseStat) {
		int strength, baseStr(baseStat), strPerLv(1), oldLv(0);
		strength = baseStr + strPerLv * (currentLv); ;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			strength = baseStr + strPerLv * (currentLv);
		}
		return strength;
	}

	int stats::dex(int currentLv, int baseStat) {
		int dexterity, baseDex(baseStat), dexPerLv(1), oldLv(0);
		dexterity = baseDex + dexPerLv * (currentLv); ;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			dexterity = baseDex + dexPerLv * (currentLv);
		}
		return dexterity;
	}

	int stats::inte(int currentLv, int baseStat) {
		int intelligence, baseInt(baseStat), intPerLv(1), oldLv(0);
		intelligence = baseInt + intPerLv * (currentLv); ;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			intelligence = baseInt + intPerLv * (currentLv);
		}
		return intelligence;
	}

	int stats::wis(int currentLv, int baseStat) {
		int wisdom, baseWis(baseStat), wisPerLv(1), oldLv(0);
		wisdom = baseWis + wisPerLv * (currentLv); ;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			wisdom = baseWis + wisPerLv * (currentLv);
		}
		return wisdom;
	}

	int stats::hp(int currentLv, int baseStat) {
		int startingHp(baseStat), baseHpPerLv(1), maxHp, oldLv(0), hpMod;
		hpMod = vit(currentLv, baseStat);
		maxHp = (startingHp + (baseHpPerLv * (currentLv)))*hpMod;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			maxHp = (startingHp + (baseHpPerLv * (currentLv)))*hpMod;
		}
		return maxHp;
	}
	//Temp Attack Value - Placeholder until Damage Type System and Skill System are implemented

	int stats::atk(int currentLv, int baseStat) {
		int baseAtk(baseStat / 5), atkPerLv(1), oldLv(0), currentAtk, strMod;
		strMod = str(currentLv, baseStat);
		currentAtk = (baseAtk + (atkPerLv * (currentLv)))*strMod;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			currentAtk = (baseAtk + (atkPerLv * (currentLv)))*strMod;
		}
		return currentAtk;
	}
	// Missing Values: Defense, Luck, Status Resitence Values, Damage Resistence Values

