#include <iostream>
#include <SDL.h>
#include "Main.h"
#include "Player.h"
#include "Combat.h"
#include "Game.h"
#include "Window.h"
#include <string>
using namespace std;

//Globale Variablen für FähigkeitsExp
extern int g_magicManipulationSkillExp(0), g_swordArtsSkillExp(0), g_currentExp(0); 

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

//Globale Variablen für Fenstergröße (17/9)
extern float g_x(17 * 60), g_y(9 * 60);

int main(int argc, char* argv[]){
	long double currentExp, totalExp(0);
	
	

	//Staret Spiel
	Game game;

	

	return 0;
	}

