#pragma once
#include <string>

class mon {
protected:
	int baseStat = 0;

	int maxHp = 0, currentHp = 0, monLv = 0, maxMp = 0, currentMp = 0, currentAtk = 0, vitality = 0, strength = 0, dexterity = 0, intelligence = 0, wisdom = 0;
	int attackDamage = 0;

	double monTotalDamage = 0, totalSpendMp;

	double damageMod = 1, slashingResMod = 0, crushingResMod = 0;
	std::string monName;
public:
	mon();
	mon(int monLevel, int monRecievedDamage, int monSpendMp);
	~mon();

	int getMonCurrentHp();

	int getMonMaxHp();

	int getMonCurrentMp();

	int getMonMaxMp();

	std::string getName();

	int attack();

	void reset();
};

