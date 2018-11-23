#pragma once
class player {
private:
	int currentLv, maxHp, currentHp, currentAtk, vitality, strength, dexterity, intelligence, wisdom;
	int oldLv = 0;
	int accumulatedDamage;

public:
	int character(int, int, int, char[25]);
	int attack(int, int);
};