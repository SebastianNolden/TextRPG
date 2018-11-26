#pragma once
#include <string>

class mon {
private:
	int maxHp, currentHp, currentAtk, vitality, strength, dexterity, intelligence, wisdom;
	int attackDamage;
	int baseStatGoblin = 6;
public:
	int goblin(int, int, int, bool);
	int attack(int, std::string);
};

