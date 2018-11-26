#include "Skills.h"
#include <iostream>
#include <string>
#include <random>
//#include <time.h>			//Do not include when time is not used in functions

using namespace std;

float skills::random() {
	/*srand(time(NULL));	//Random number generator
	ran = rand() % 100+1;*/

	//creates Random numbers (apparantly better)
	random_device r; //Seed
	seed_seq seed{ r(), r(), r(), r(), r(), r(), r(), r(), }; //Get more than 32 bits of random data combined
	mt19937 eng(seed); //Mersenne Twister randomness source
	uniform_int_distribution<> dist{ 1,100 }; //Get's a distribution to produce uniform ints from 1 to 100

    /*for (int i = 0; i <= 100; ++i) {		//Controll check if the random values work
	  cout << dist(eng) << '\n';
	  }*/

	ran = dist(eng);

	if (ran >= 51) {
		//ran = (rand() % 50 + 1);		//Random number generator again to get negativ numbers
		ran = -ran;
	}
	mod = ran / 100;
	return mod;
}

int skills::basicAttack(int atkStat) {
	int damage(atkStat);
	mod = random();
	damage = damage + round((damage*mod) / 4); //This, using the random above, gives damage a +-25% fluctuation
	return damage;
}

int skills::heal(int wisStat) {
	int health(wisStat);
	mod = random();
	health = health + round((health*mod)/4); //This also has a +- 25% fluctuation
	health = health * 100;	//Overpowered Heal to test stuff
	return -health;
}
void skills::skillRegister() {		
	string skillList[25];
	skillList[0] = { "|0: Basic Attack| " };
	skillList[1] = { "|1: Heal| " };
	for (int i = 0; i < 2; ++i) {
		cout << skillList[i];
	}
	cout << ":";
}

