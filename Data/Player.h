#pragma once
#include <string>

class player {
private:
	int maxHp, maxMp, currentAtk, vitality, strength, dexterity, intelligence, wisdom;
	int magicManipulationLv, swordArtsLv;
	double slashingResMod, crushingResMod;
	int baseStat = 9;
	int currentHp = 0, currentMp = 0;
	double tempRecDmg = 0;
	int oldLv = 1;
public:
	int currentLv;
	void character(long double playerExp, int playerRecievedDamage, int spendMp, int displayCheck, std::string playerName, bool reset);
	int attack(long double playerExp, int attackChoice, std::string playerName);
};