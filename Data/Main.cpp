#include <iostream>
#include <SDL.h>
#include "Main.h"
#include "Player.h"
#include "Combat.h"
#include "Game.h"
#include <string>
using namespace std;

//Globale Variablen für FähigkeitsExp
extern int g_magicManipulationSkillExp(0), g_swordArtsSkillExp(0); 

//Globale Variable für aufgebrauchtes Mana
extern int g_playerSpendMp(0);

//Globale Variable für maximales Mana
extern int g_maxMp(0);

//Gobale Variable für Max-HP-Debuff (Verringerung der maximalen Leben)
extern int g_HpRed(0);

//Globale Variable für Spieler Leben
extern int g_playerHp(0), g_playerTotalDamage(0);

//Globale Variable für Monster Leben
extern double g_monHp(0), g_monTotalDamage(0);


int main(int argc, char* argv[]){
	long double currentExp, totalExp(0);
	bool stop(false), controlStop(false);
	string charName;
	char YN;

	Game game;

	std::cout << "Input your character name: ";
	std::getline(cin,charName);
	std::cout << "\n\n";
	cin >> totalExp;
	cin >> g_magicManipulationSkillExp;
	cin >> g_swordArtsSkillExp;
	player player1;
	combat battle;
	player1.character(totalExp, 0, 0, 1, charName, false); //Zeigt Charakterfenster an
	cout << "\n\n";

	//Initiates combat //Starte Kampfphase
	do {

		currentExp = battle.battle(totalExp,charName);
		totalExp = currentExp + totalExp;
		player1.character(totalExp, 0, g_playerSpendMp, 0, charName, false);
		
		//Displays player Status 
		//Zeigt spieler Status an wenn Exp nicht 0 ist (In diesem Falle würde der Status in combat.cpp dargestellt
		if (currentExp != 0) {
			player1.character(totalExp, 0, g_playerSpendMp, 1, charName, false);
		}

		//Fragt ob die Schleife abgebrochen werden soll
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

