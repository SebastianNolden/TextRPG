#pragma once

class skills {
private: 
	float ran, mod, skillFail;
	float random();
public:
	int magicManipulation(int skillExp);
	int swordArts(int skillExp);
	int basicAttack(int attackStat);
	int heal(int wisStat);
	void skillRegister();
	int skillType(int type);
};