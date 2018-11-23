#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int baseStat(9);

class stats {
public:
	int level(int currentExp) {
		int currentLv(1);
		int x = 2, c = 100;
		double expToLvUp = c * pow(currentLv, x);
		while (currentExp >= expToLvUp) {
			++currentLv;
			expToLvUp = c * pow(currentLv, x);

			//Control for EXP values

			//cout << expToLvUp << "  " << currentLv+1 << "\n" ; //Displays required total Exp for all avalible leves +1
			/*int numCheck(1), x, y;  //Displays the required additional Exp values for 10 levels
			while (numCheck < 10) {
				x = 100 * pow(numCheck, 2);
				y = 100 * pow(numCheck  , 2);
				cout << x - y << "\n";
				++numCheck;
			} */
		}

		return currentLv;
	}

	int vit(int currentLv, int baseStat) {
		int vitality, baseVit(baseStat), vitPerLv(1), oldLv(0);
		vitality = baseVit + vitPerLv * (currentLv  ); ;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			vitality = baseVit + vitPerLv * (currentLv  );
		}
		return vitality;
	}

	int str(int currentLv, int baseStat) {
		int strength, baseStr(baseStat), strPerLv(1), oldLv(0);
		strength = baseStr + strPerLv * (currentLv  ); ;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			strength = baseStr + strPerLv * (currentLv  );
		}
		return strength;
	}

	int dex(int currentLv, int baseStat) {
		int dexterity, baseDex(baseStat), dexPerLv(1), oldLv(0);
		dexterity = baseDex + dexPerLv * (currentLv  ); ;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			dexterity = baseDex + dexPerLv * (currentLv  );
		}
		return dexterity;
	}

	int inte(int currentLv, int baseStat) {
		int intelligence, baseInt(baseStat), intPerLv(1), oldLv(0);
		intelligence = baseInt + intPerLv * (currentLv  ); ;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			intelligence = baseInt + intPerLv * (currentLv  );
		}
		return intelligence;
	}

	int wis(int currentLv, int baseStat) {
		int wisdom, baseWis(baseStat), wisPerLv(1), oldLv(0);
		wisdom = baseWis + wisPerLv * (currentLv  ); ;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			wisdom = baseWis + wisPerLv * (currentLv  );
		}
		return wisdom;
	}

	int hp(int currentLv, int baseStat) {
		int startingHp(baseStat), baseHpPerLv(1), maxHp, oldLv(0), hpMod;
		hpMod = vit(currentLv, baseStat);
		maxHp = (startingHp + (baseHpPerLv * (currentLv  )))*hpMod;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			maxHp = (startingHp + (baseHpPerLv * (currentLv  )))*hpMod;
		}
		return maxHp;
	}
	//Temp Attack Value - Placeholder until Damage Type System and Skill System are implemented

	int atk(int currentLv, int baseStat) {
		int baseAtk(baseStat/5), atkPerLv(1), oldLv(0), currentAtk, strMod;
		strMod = str(currentLv, baseStat);
		currentAtk = (baseAtk + (atkPerLv * (currentLv  )))*strMod;
		while (oldLv < currentLv) {
			oldLv = currentLv;
			currentAtk = (baseAtk + (atkPerLv * (currentLv  )))*strMod;
		}
		return currentAtk;
	}
	// Missing Values: Defense, Luck, Status Resitence Values, Damage Resistence Values

};

class skills {
	stats stat;
public:
	int basicAttack(int atkStat) {
		int damage(atkStat);
		return damage;
	}
	void skillRegister() {		// 20 Symbols per Skill list
		string skillList[25];
		skillList[0] = {"|0: Basic Attack   |"};
		cout << skillList[0]
			<< "\n"
			;
	}
};

class displayStats {
private:
	skills skill;
public: void statWindow(int currentLv, int currentExp, int maxHp, int currentHp, int currentAtk, int vitality, int strength, int dexterity, int intelligence, int wisdom, char typeName[25]) {
	cout
		<< "\n"
		<< "\n~~~~~~~~~~~"
		<< "\nName: " << typeName
		<< "\n~~~Stats~~~"
		<< "\nLv : " << currentLv
		<< "\nExp: " << currentExp
		<< "\nHP : " << maxHp << "/" << currentHp
		<< "\nAtk: " << currentAtk
		<< "\nVit: " << vitality
		<< "\nStr: " << strength
		<< "\nDex: " << dexterity
		<< "\nInt: " << intelligence
		<< "\nWis: " << wisdom
		<< "\n~~~~~~~~~~~"
		<< "\n"
		;
}
		void combatStats(int currentLv,int maxHp, int currentHp, char typeName[25]) {
			cout
				<< "\n"
				<< "\nName: " << typeName
				<< "\nLv: " << currentLv
				<< "\nHp: " << maxHp << "/" << currentHp
				<< "\n"
				;
		}
		void skillWindow() {
			cout
				<< "\nSkills: \n"; 
			skill.skillRegister();
				
		}
};
int accumulatedDamage[15];

class mon {
private:
	int maxHp, currentHp, currentAtk, vitality, strength, dexterity, intelligence, wisdom;
	

public:
	int goblin(int currentLv, int recievedDamage, int displayCheck) {
		int baseStat(6);
		char monName[7]("Goblin");
		stats monster;
		
		//calculate Status Values for monster character
		vitality = monster.vit(currentLv,baseStat);
		strength = monster.str(currentLv, baseStat);
		dexterity = monster.dex(currentLv, baseStat);
		intelligence = monster.inte(currentLv, baseStat);
		wisdom = monster.wis(currentLv, baseStat);
		maxHp = monster.hp(currentLv, baseStat);
		accumulatedDamage[1] = { accumulatedDamage[1] + recievedDamage };
		currentHp = maxHp - accumulatedDamage[1];
		currentAtk = monster.atk(currentLv, baseStat);
	
		displayStats display;
		if (displayCheck == 1) {
			display.statWindow(currentLv, 0, maxHp, currentHp, currentAtk, vitality, strength, dexterity, intelligence, wisdom, monName);
		}
		if (displayCheck == 2) {
			display.combatStats(currentLv, maxHp, currentHp, monName);
		}
		return currentHp;
			}
	};

class player {
private: 	
	int currentLv, maxHp, currentHp, currentAtk, vitality, strength, dexterity, intelligence, wisdom;
	

public: 
	int oldLv = 0;
	int character(int currentExp, int recievedDamage, int displayCheck, char playerName[25]) {
		stats character;
		displayStats display;

	// calculate Status Values for player character
	currentLv = character.level(currentExp);
	if (oldLv < currentLv) {
		oldLv = currentLv;
		accumulatedDamage[0] = { 0 };
	}
	maxHp = character.hp(currentLv, baseStat);
	currentAtk = character.atk(currentLv, baseStat);
	accumulatedDamage[0] = { accumulatedDamage[0] + recievedDamage };
	currentHp = maxHp - accumulatedDamage[0];
	vitality = character.vit(currentLv, baseStat);
	strength = character.str(currentLv, baseStat);
	dexterity = character.dex(currentLv, baseStat);
	intelligence = character.inte(currentLv, baseStat);
	wisdom = character.wis(currentLv, baseStat);
	
		if (displayCheck == 1) {
		display.statWindow(currentLv, currentExp, maxHp, currentHp, currentAtk, vitality, strength, dexterity, intelligence, wisdom, playerName);
		}
		if (displayCheck == 2) {
		display.combatStats(currentLv, maxHp, currentHp, playerName);
		}
	return currentHp;
	}
	int attack(int currentExp, int attackChoice) {
		stats character;
		skills skill;
		int attackDamage(0);

		currentLv = character.level(currentExp);
		currentAtk = character.atk(currentLv, baseStat);

		if (attackChoice == 0) {
			attackDamage = skill.basicAttack(currentAtk);
		}
		return attackDamage;
	}
};

class combat {
	int currentExp, totalExp, recievedExp;
private:
	int ran;
	mon monster;
	int encounter1(int monRecievedDamage) {
		srand(time(NULL));
		ran = rand() % 20;
		int storage;
		if (ran>=0 && ran <=15) {
			monster.goblin(1, monRecievedDamage, 0) ;
			storage =  1 ;
		}
		if (ran>=16 && ran <=18) {
			monster.goblin(2, monRecievedDamage, 0) ;
			storage =  2 ;
		}
		if (ran == 19) {
			monster.goblin(3, monRecievedDamage, 0) ;
			storage =  3 ;
		}
		return storage;
	}
public:
	int battle(char charName[25]) {
		player player1;
		displayStats display;

		int eHp, pHp, monRecievedDamage(0), playerRecievedDamage(0), actionChoice;
		bool close(false);
		int monLevel = encounter1(monRecievedDamage);

		do {
			cout << "\n"
				<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

			eHp = monster.goblin(monLevel, monRecievedDamage, 2);
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
				accumulatedDamage[1] = { 0 };
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
		recievedExp = round(pow(monLevel*10,1.5));
		return recievedExp;
	}


};

int main(){
	int currentExp, totalExp(0);
	bool stop(false), controlStop(false);
	char charName[25];
	char YN;
	std::cout << "Input your character name: ";
	std::cin >> charName;
	std::cout << "\n\n";
	player player1;
	combat battle;


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

		currentExp = battle.battle(charName);
		totalExp = currentExp + totalExp;
		player1.character(totalExp, 0, 1, charName);

		while (1)  {
			std::cout << "\nStop? Y/N\n";		//Asks for continuation of monster encounters/ simple loop
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

