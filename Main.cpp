#include <iostream>
#include "Main.h"
#include "Player.h"
#include "Combat.h"
#include <string>
#include <sstream>
using namespace std;

int main(){
	int currentExp, totalExp(0);
	int oldLv(1);
	bool stop(false), controlStop(false);
	string charName;
	char YN;
	std::cout << "Input your character name: ";
	getline(cin,charName);
	std::cout << "\n\n";
	player player1;
	combat battle;
	player1.character(totalExp, 0, 1, charName, false);


	//Diretly increases character experience/level
	/*do {
		std::cout << "Input current Exp: ";
		std::cin >> currentExp;
		totalExp = currentExp + totalExp;
		player1.character(totalExp, 0, 1, charName); 

		std::cout << "\nStop? Y/N\n";		//Asks for continuation of increasing character level/ simple loop
		std::cin >> YN;
		if (YN == 'Y') {
			stop = true;
		}
		else if (YN == 'y') {
			stop = true;
		}
	} while (stop==false); */

	//Initiates combat
	do {
		/*std::cout << "Input monster level: ";			//Inputs a monster level to manually check that data
		std::cin >> monLevel;
		while (1) {			//Errorcheck for Input
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				std::cout << "Please input a full number\n";
				std::cin >> monLevel;
			}
			if (!std::cin.fail()) {
				break;
			}
		}
		std::cout << "\n\n";

		monster.goblin(monLevel, 0, 1); */			//Creates a goblin with the previously input level

		currentExp = battle.battle(totalExp,charName);
		totalExp = currentExp + totalExp;
		player1.character(totalExp, battle.playerRecievedDamage, 0, charName, false);
		if (oldLv < player1.currentLv) {
			battle.playerRecievedDamage = 0;
		}
		if (currentExp != 0) {
			player1.character(totalExp, battle.playerRecievedDamage, 1, charName, false);
		}
		while (1)  {		//Asks for continuation of monster encounters/ simple loop
			std::cout << "\nStop? Y/N\n";		
			std::cin >> YN;
			if (YN == 'Y') {
				stop = true;
				break;
			}
			if (YN == 'y') {
				stop = true;
				break;
			}
			if (YN == 'n') {
				stop = false;
				break;
			}
			if (YN == 'N') {
				stop = false;
				break;
			}
		}
		} while (stop == false);
	

	return 0;
	}

