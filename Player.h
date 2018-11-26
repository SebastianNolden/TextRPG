#pragma once
#include <string>

class player {
private:
	int maxHp, currentAtk, vitality, strength, dexterity, intelligence, wisdom;
	int baseStat = 9;
	int currentHp = 0;
public:
	int currentLv;
	int character(int, int, int, std::string playerName, bool reset);
	int attack(int, int, std::string playerName);
};