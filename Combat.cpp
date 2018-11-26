#include "Combat.h"
#include "Player.h"
#include "Displaystats.h"
#include "Stats.h"
#include <random>
#include <iostream>
#include <string>
#include "Mon.h"
#include "Main.h"
using namespace std;

int combat::random() {
	/*srand(time(NULL));	//Random number generator
	ran = rand() % 100+1;*/

	//creates Random numbers (apparantly better)
	random_device r; //Seed
	seed_seq seed{ r(), r(), r(), r(), r(), r(), r(), r(), }; //Get more than 32 bits of random data combined
	mt19937 eng(seed); //Mersenne Twister randomness source
	uniform_int_distribution<> dist{ 0,19 }; //Get's a distribution to produce uniform ints from 0 to 19

											  /*for (int i = 0; i <= 100; ++i) {		//Controll check if the random values work
											  cout << dist(eng) << '\n';
											  }*/

	ran = dist(eng);

	return ran;
}

mon monster;
	int combat::encounter1(int monRecievedDamage) {
		int storage(0);
		random();
		if (ran >= 0 && ran <= 15) {
			monster.goblin(1, monRecievedDamage, 0, true);
			storage = 1;
			monType = "Goblin";
		}
		if (ran >= 16 && ran <= 18) {
			monster.goblin(2, monRecievedDamage, 0, true);
			storage = 2;
			monType = "Goblin";
		}
		if (ran == 19) {
			monster.goblin(3, monRecievedDamage, 0, true);
			storage = 3;
			monType = "Goblin";
		}
		return storage;
	}

	int combat::battle(int totalExp,string charName) {
		player player1;
		displayStats display;

		int eHp, pHp, monRecievedDamage(0), actionChoice;
		bool close(false);
		int monLevel = encounter1(monRecievedDamage);

		do {
			cout << "\n"
				<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

			eHp = monster.goblin(monLevel, monRecievedDamage, 2, false);
			pHp = player1.character(totalExp, playerRecievedDamage, 2, charName,false);

			if (eHp <= 0) {
				close = true;
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
				cout << "\nThe enemie was defeated!\n";
			}
			if (pHp <= 0) {
				close = true;
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
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
			while (1) {		//Check if input is invalid
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
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

			//attacking a Monster
			if (actionChoice == 0) {
				monRecievedDamage = monRecievedDamage + player1.attack(totalExp, actionChoice, charName);
			}
			//Healing the player
			if (actionChoice == 1) {
				playerRecievedDamage = playerRecievedDamage + player1.attack(totalExp, actionChoice, charName);
				if (playerRecievedDamage < 0) {
					playerRecievedDamage = 0;
				}
			}
			//Monster can't attack a dead player
			if (eHp > 0 ) {
				playerRecievedDamage = playerRecievedDamage + monster.attack(monLevel, monType);
			}
		} while (close == false);
		//Player not dead
		if (pHp > 0) {
			recievedExp = round(pow(monLevel * 10, 1.5));
			return recievedExp;
		}
		//Player dead
		if (pHp <= 0) {
			player1.character(0, playerRecievedDamage, 1, charName, true);
			playerRecievedDamage = 0;
			return 0; 
		}
	}


