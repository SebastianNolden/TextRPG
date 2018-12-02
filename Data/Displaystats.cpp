#include "Displaystats.h"
#include "Skills.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include "Window.h"
#include "Misc.h"
#include "SDL_FontCache.h"

using namespace std;



skills skill;
 void displayStats::statWindow(int currentLv, int currentExp, int maxHp, int currentHp, int maxMp, int currentMp, int currentAtk, int vitality, int strength, int dexterity, int intelligence, int wisdom, string typeName) {
	cout
		<< "\n"
		<< "\n~~~~~~~~~~~"
		<< "\nName: " << typeName
		<< "\n~~~Stats~~~"
		<< "\nLv : " << currentLv
		<< "\nExp: " << currentExp
		<< "\nHP : " << currentHp << "/" << maxHp
		<< "\nMP : " << currentMp << "/" << maxMp
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
 void displayStats::combatStats(int currentLv, int maxHp, int currentHp, int maxMp, int currentMp, string typeName) {
			cout
				<< "\nName: " << typeName
				<< "\nLv  : " << currentLv
				<< "\nHP  : " << currentHp << "/" << maxHp
				<< "\nMP  : " << currentMp << "/" << maxMp
				<< "\n"
				;
		}
 void displayStats::skillWindow() {
			cout
				<< "\nSkills: \n";
			skill.skillRegister();
		}
 void displayStats::skillExp(int magicManipulationLv, int swordArtsLv) {
	 extern int g_magicManipulationSkillExp, g_swordArtsSkillExp;
	 cout << "\nSkills:"
		 << "\nMagic Manipulation |Lv:" << magicManipulationLv << "| |Exp: " << g_magicManipulationSkillExp << "|"
		 << "\nSword Arts |Lv:" << swordArtsLv << "| |Exp: " << g_swordArtsSkillExp << "|"
		 << "\n"
		 ;
 }

 void displayStats::battleWindow(Window &window, struct SDL_Renderer *_renderer ,int currentLv, int maxHp, int currentHp, int maxMp, int currentMp, string typeName)
 {
	 Misc misc;

	 FC_Font* font = FC_CreateFont();

	 FC_LoadFont(font, _renderer, "fonts/georgia.ttf", 15, FC_MakeColor(255, 255, 255, 255), TTF_STYLE_NORMAL);

	 string name("\nName: "), Lv("\nLv  : "), HP("\nHP  : "), MP("\nMP  : "), div("/");

	 FC_Draw(font, _renderer, 10, 155, (name + typeName).c_str());
	 FC_Draw(font, _renderer, 10, 170, (Lv + to_string(currentLv)).c_str());
	 FC_Draw(font, _renderer, 10, 185, (HP + to_string(currentHp) + div + to_string(maxHp)).c_str());
	 FC_Draw(font, _renderer, 10, 200, (MP + to_string(currentMp) + div + to_string(maxMp)).c_str());


	 FC_FreeFont(font);
 }


