#pragma once
#include <string>

class player {
private:
	int baseStat = 9;

	int maxHp = 0, playerHp = 0, currentLv = 0, maxMp = 0, currentAtk = 0, vitality = 0, strength = 0, dexterity = 0, intelligence = 0, wisdom = 0;
	int currentHp = 0, currentMp = 0, currentExp = 0;

	int magicManipulationLv = 0, swordArtsLv = 0;
	int magicManipulationSkillExp = 0, swordArtsSkillExp = 0;

	double slashingResMod = 0, crushingResMod = 0;

	double tempRecDmg = 0, playerTotalDamage = 0, HpRed = 0, playerSpendMp = 0;

	int oldLv = 1;

	std::string name, insufficientMana;

public:
	
	player();
	player(long double currentExp, int recievedDamage, int spendMp, std::string playerName);
	~player();

	int getPlayerLv();

	int getPlayerCurrentHp();

	int getPlayerMaxHp();

	int getPlayerCurrentMp();

	int getPlayerMaxMp();

	std::string getName();

	int attack(int attackChoice);
	
	void reset();
};