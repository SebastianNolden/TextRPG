#pragma once
#include <string>
class combat {
private:
	int currentExp;
	double recievedExp;
	int ran;
	int encounter1(int);
	int random();
	std::string monType;
public:
	int playerRecievedDamage = 0;
	int battle(int,std::string);

};