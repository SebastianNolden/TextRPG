#pragma once
#include <string>
class combat {
private:
	double recievedExp;
	int ran;
	int encounter1();
	int random();
	std::string monType;
public:
	int playerSpendMp = 0;
	double battle(double totalPlayerExp,std::string playerName);

};