#pragma once

class skills {
private: 
	float ran, mod, skillFail;
	int spendMp = 0, hpReduction = 0;
public:
	int magicManipulation(int skillExp);
	int swordArts(int skillExp);
	int basicAttack(int attackStat);
	int heal(int wisStat, int maxMp);
	void skillRegister();
	int skillType(int type);
	float random();
};