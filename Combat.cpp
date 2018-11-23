#include "Combat.h"
#include "Player.h"
#include "Displaystats.h"
#include "Stats.h"
#include <time.h>
#include <iostream>
#include <string>
#include "Mon.h"
#include "Main.h"
using namespace std;


mon monster;
	int combat::encounter1(int monRecievedDamage) {
		srand(time(NULL));
		ran = rand() % 20;
		int storage;
		if (ran >= 0 && ran <= 15) {
			monster.goblin(1, monRecievedDamage, 0, true);
			storage = 1;
		}
		if (ran >= 16 && ran <= 18) {
			monster.goblin(2, monRecievedDamage, 0, true);
			storage = 2;
		}
		if (ran == 19) {
			monster.goblin(3, monRecievedDamage, 0, true);
			storage = 3;
		}
		return storage;
	}

	int combat::battle(int totalExp,char charName[25]) {
		player player1;
		displayStats display;

		int eHp, pHp, monRecievedDamage(0), playerRecievedDamage(0), actionChoice;
		bool close(false);
		int monLevel = encounter1(monRecievedDamage);

		do {
			cout << "\n"
				<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

			eHp = monster.goblin(monLevel, monRecievedDamage, 2, false);
			pHp = player1.character(totalExp, playerRecievedDamage, 2, charName);

			if (eHp <= 0) {
				close = true;
				cout << "\nThe enemie was defeated!\n";
			}
			if (pHp <= 0) {
				close = true;
				cout << "\nYou were defeated!\n";
			}
			if (close == true) {
				break;
			}
			cout << "~~~~~~~~~~~~~~~~~~~~"
				<< "\nChoose your actions!"
				;
			display.skillWindow();

			cin >> actionChoice;
			while (1) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please input a full number\n";
					cin >> actionChoice;
				}
				if (!cin.fail()) {
					break;
				}
			}
			monRecievedDamage = player1.attack(totalExp, actionChoice);
		} while (close == false);
		recievedExp = round(pow(monLevel * 10, 1.5));
		return recievedExp;
	}


