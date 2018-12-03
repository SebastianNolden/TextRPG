#pragma once
#include <string>

class mon {
private:
	int maxHp, currentHp, maxMp, currentMp, currentAtk, vitality, strength, dexterity, intelligence, wisdom;
	int attackDamage;
	double damageMod = 1, slashingResMod, crushingResMod;
	int baseStatGoblin = 6;
public:
	void goblin(int monLevel, int monRecievedDamage, int monSpendMp, int displayCheck, bool reset);
	int attack(int monLevel, std::string monType);
};

