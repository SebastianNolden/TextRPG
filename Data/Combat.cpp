#include "Combat.h"
#include "Player.h"
#include "Displaystats.h"
#include "Stats.h"
#include <random>
#include <iostream>
#include <string>
#include "Mon.h"
#include "Window.h"
#include "Main.h"
using namespace std;

int combat::random() {
	//creates Random numbers (apparantly better than rand())
	//Erstellt Zufallszahlen (Bessere Methode als verwendung von rand())
	random_device r; //Seed
	seed_seq seed{ r(), r(), r(), r(), r(), r(), r(), r(), }; //Get more than 32 bits of random data combined//Erstellt mehr als 32 bit von zufälligen Daten
	mt19937 eng(seed); //Mersenne Twister randomness source //Methode für zufällige Berechnung: Mersenne Twister
	uniform_int_distribution<> dist{ 0,19 }; //Gets a distribution to produce uniform ints from 0 to 19 //Gibt eine Verteilung von Ints wieder (0 bis 19)
	ran = dist(eng);
	return ran;
}

/*
	int combat::encounter1() {
		int storage(0); //Bestimmt das Level des Monsters)
		random();
		if (ran >= 0 && ran <= 15) { //Erstellt einen Goblin auf Lv. 1 mit 16/20 Chance (80%)
			monster.goblin(1, 0, 0, 0, true);
			storage = 1;
			monType = "Goblin";
		}
		if (ran >= 16 && ran <= 18) { //Erstellt einen Goblin auf Lv. 2 mit 3/20 Chance (15%)
			monster.goblin(2, 0, 0, 0, true);
			storage = 2;
			monType = "Goblin";
		}
		if (ran == 19) { //Erstellt einen Goblin auf Lv. 3 mit 1/20 Chance (5%)
			monster.goblin(3, 0, 0, 0, true);
			storage = 3;
			monType = "Goblin";
		}
		return storage;
	}
	*/

	/*
	double combat::battle(double totalExp,string charName) {
		extern int g_playerSpendMp;
		extern int g_HpRed, g_playerHp;
		extern double g_monHp;
		double playerRecievedDamage(0);

		int monRecievedDamage(0), monSpendMp(0), actionChoice;
		bool close(false);
		int monLevel = encounter1();

		cout << "\n"
			<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

		monster.goblin(monLevel, monRecievedDamage, monSpendMp, 2, false);
		player1.character(totalExp, playerRecievedDamage, g_playerSpendMp, charName, false);
		//player1.displayStatsWindow(window, 2, charName);


		while (close == false) { //Schleife
			
			cout << "~~~~~~~~~~~~~~~~~~~~"
				<< "\nChoose your actions!"
				;
			display.skillWindow();

			cin >> actionChoice;
			while (1) {		//Check if input is invalid //Prüft ob der Eingegebene Wert im Rahmen der Variable ist, d.h. es gibt einen Fehler wenn keine Zahl
				//continuirliche Schleife
				if (cin.fail()) {
					cin.clear();//löscht eingabe damit fehler entfernt wird
					cin.ignore(numeric_limits<streamsize>::max(), '\n');//ignoriert weitere fehler
					cout << "Please input a full number\n";
					cin >> actionChoice;//erneute eingabe
				}
				if (!cin.fail()) {//bricht Schleife ab
					break;
				}
			}
			cout << "\n~~~~~~~~~~~~~~~~~~~~\n";

			//attacking a Monster
			//Attacke auf den Gegner
			if (actionChoice == 0) {
				cout << charName << " attacked!";
				monRecievedDamage = player1.attack(actionChoice, charName);
			}

			//Healing the player
			//Heilung des Spielers
			if (actionChoice == 1) {
				cout << charName << " cast heal!";
				//Heilung ist negativer Eigenchaden
				playerRecievedDamage = player1.attack(actionChoice, charName);
				player1.character(totalExp, playerRecievedDamage, g_playerSpendMp, charName, false);
				}
			
			cout << "\n~~~~~~~~~~~~~~~~~~~~\n";

			monster.goblin(monLevel, monRecievedDamage, monSpendMp, 2, false);
			monRecievedDamage = 0;


			//Monster can't attack a dead player
			//Tote Monster können den Spieler nicht angreifen
			if (g_monHp > 0) {
				cout << "\n~~~~~~~~~~~~~~~~~~~~\n"
					<< monType << " attacked!"
					<< "\n~~~~~~~~~~~~~~~~~~~~\n";
				playerRecievedDamage = monster.attack(monLevel, monType);
			}

			player1.character(totalExp, playerRecievedDamage, g_playerSpendMp, charName, false);
			//player1.displayStatsWindow(window, 2, charName);
			playerRecievedDamage = 0;

			cout << "\n~~~~~~~~~~~~~~~~~~~~\n\n";


			//Gegner Tod
			if (g_monHp <= 0) {
				close = true;
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cout << "\nThe enemie was defeated!\n";
				break;
			}

			//Spieler Tod
			if (g_playerHp <= 0) {
				close = true;
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cout << "\nYou were defeated!\n";
				break;
			}

		} // Schleife Ende

		//Player not dead//Spieler überlebt
		if (g_playerHp > 0) {
			recievedExp = round(pow(monLevel * 10, 1.5));//Erhaltene EXP für besiegten Gegner
		}
		//Player dead//Spieler tot
		if (g_playerHp <= 0) {
			player1.character(0, playerRecievedDamage, g_playerSpendMp, charName, true);
			playerRecievedDamage = 0;//Setzt Spielerschaden zurück (Relevant für Neues Spiel)
			g_playerSpendMp = 0;
			g_HpRed = 0;
			g_playerHp = 0;
			recievedExp = 0; 
		}
		return recievedExp;
	}


	*/