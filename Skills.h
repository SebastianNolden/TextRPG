#pragma once

class skills {
private: 
	float ran, mod;
	float random();
public:
	int basicAttack(int);
	int heal(int);
	void skillRegister();
};