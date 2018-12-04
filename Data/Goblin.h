#pragma once
#include <string>

class Goblin {
private:
	int baseStat = 0;

	int maxHp = 0, currentHp = 0, monLv = 0, maxMp = 0, currentMp = 0, currentAtk = 0, vitality = 0, strength = 0, dexterity = 0, intelligence = 0, wisdom = 0;
	int attackDamage = 0;

	double slashingResMod = 0, crushingResMod = 0;

	double monTotalDamage = 0, totalSpendMp;

	double tempRecDmg = 0;

	std::string monNameGoblin = ("Goblin");
public:
	Goblin();
	Goblin(int currentLv, int recievedDamage, int spendMp);
	~Goblin();
	
	int getGoblinLv();

	int getGoblinCurrentHp();

	int getGoblinMaxHp();
	
	int getGoblinCurrentMp();
	
	int getGoblinMaxMp();
		
	std::string getName();
	
	int goblinAttack();
	
	void Reset();

};

