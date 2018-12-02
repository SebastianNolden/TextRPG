#include "Skills.h"
#include <iostream>
#include <string>
#include <random>

using namespace std;

extern int g_damageType(0);


float skills::random() {
	//creates Random numbers (apparantly better than rand())
	//Erstellt Zufallszahlen (Bessere Methode als verwendung von rand())
	random_device r; //Seed
	seed_seq seed{ r(), r(), r(), r(), r(), r(), r(), r(), }; //Get more than 32 bits of random data combined//Erstellt mehr als 32 bit von zufälligen Daten
	mt19937 eng(seed); //Mersenne Twister randomness source //Methode für zufällige Berechnung: Mersenne Twister
	uniform_int_distribution<> dist{ 1,100}; //Gets a distribution to produce uniform ints from 1 to 100 //Gibt eine Verteilung von Ints wieder (1 bis 100)
	ran = dist(eng);

	if (ran >= 51) { //Werte über 50 werden um 50 reduziert und negativ gemacht
		ran = -(ran-50);
	}
	mod = ran / 100; //Wandelt die Werte in Prozent um
	return mod;
}

int skills::skillType(int type) {
	switch (type) {
	case 1:
		//g_damageType = "Holy";
		g_damageType = 1;
		break;
	case 2:
		//g_damageType = "Slashing";
		g_damageType = 2;
		break;
	case 3:
		//g_damageType = "Crushing";
		g_damageType = 3;
		break;
	case 4:
		//g_damageType = "Fire";
		g_damageType = 4;
		break;
	case 5:
		//g_damageType = "Water";
		g_damageType = 5;
		break;
	case 6:
		//g_damageType = "Wind";
		g_damageType = 6;
		break;
	case 7:
		//g_damageType = "Earth";
		g_damageType = 7;
		break;
	case 8:
		//g_damageType = "Piercing";
		g_damageType = 8;
		break;
	case 9:
		//g_damageType = "Dark";
		g_damageType = 9;
		break;
	case 10:
		//g_damageType = "Space-Time";
		g_damageType = 10;
		break;
	case 11:
		//g_damageType = "Necrotic";
		g_damageType = 11;
		break;
	case 12:
		//g_damageType = "Spiritual";
		g_damageType = 12;
		break;
	}
	return g_damageType;
}

int skills::magicManipulation(int skillExp) {
	int currentLv(0);
	int x = 3, c = 100;
	double expToLvUp = c * pow(currentLv+1, x); // It's +1 because it calculates the required Exp to the next level// +1 da die Berechnung für das jeweils nächste Level erfolgt
	while (skillExp >= expToLvUp && currentLv+1 < 11) {	//Exp to Lv. 10 (Max) = 100.000 
		++currentLv;
		expToLvUp = c * pow(currentLv+1, x);
	}
	return currentLv;
}

int skills::swordArts(int skillExp) {
	int currentLv(0);
	int x = 3, c = 100;
	double expToLvUp = c * pow(currentLv + 1, x); // It's +1 because it calculates the required Exp to the next level// +1 da die Berechnung für das jeweils nächste Level erfolgt
	while (skillExp >= expToLvUp && currentLv + 1 < 11) {	//Exp to Lv. 10 (Max) = 100.000 
		++currentLv;
		expToLvUp = c * pow(currentLv + 1, x);
	}
	return currentLv;
}

int skills::basicAttack(int atkStat) {
	int damage(atkStat);
	mod = random();
	damage = damage + round((damage * mod) / 2); //This, using the random above, gives damage a +-25% fluctuation //Ergibt eine +-25% Schwankung der Werte
	skillType(2);
	return damage;
}

int skills::heal(int wisStat) {
	int health(wisStat);
	extern int g_playerSpendMp;
	extern int g_maxMp;
	extern int g_HpRed;

	mod = random();
	health = round(pow(health, 2));
	health = health + round((health * mod) / 2); //This also has a +- 25% fluctuation // +-25% Schwankung der Werte
	skillType(1);
	g_playerSpendMp = g_playerSpendMp + 10;

	if (g_playerSpendMp > g_maxMp) {
		skillFail = random();
		if (skillFail < 0) {
			health = 0;
			cout << "\nInsufficient Mana! The Spell failed to activate!"
				;
		}
		if (skillFail > 0) {
			g_HpRed = g_HpRed + 10;
			cout << "\nInsufficient Mana! The Spell consumed your lifefoce!" 
				;
		}
		g_playerSpendMp = g_maxMp;
	}
	return -health;
}

void skills::skillRegister() {		//Index der Skills für die Anzeige
	string skillList[25];
	skillList[0] = { "|0: Basic Attack| " };
	skillList[1] = { "|1: Heal| " };
	for (int i = 0; i < 2; ++i) {
		cout << skillList[i];
	}
	cout << ":";
}

