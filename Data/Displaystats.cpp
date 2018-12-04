#include "Displaystats.h"
#include "Skills.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include "Window.h"
#include "Misc.h"
#include <SDL_ttf.h>
using namespace std;


/*skills skill;
 void displayStats::statWindow(int currentLv, int currentExp, int maxHp, int currentHp, int maxMp, int currentMp, int currentAtk, int vitality, int strength, int dexterity, int intelligence, int wisdom, string typeName) {
	cout
		<< "\n"
		<< "\n~~~~~~~~~~~"
		<< "\nName: " << typeName
		<< "\n~~~Stats~~~"
		<< "\nLv : " << misc.turnNumberIntoString(currentLv)
		<< "\nExp: " << misc.turnNumberIntoString(currentExp)
		<< "\nHP : " << misc.turnNumberIntoString(currentHp) << "/" << misc.turnNumberIntoString(maxHp)
		<< "\nMP : " << misc.turnNumberIntoString(currentMp) << "/" << misc.turnNumberIntoString(maxMp)
		<< "\nAtk: " << misc.turnNumberIntoString(currentAtk)
		<< "\nVit: " << misc.turnNumberIntoString(vitality)
		<< "\nStr: " << misc.turnNumberIntoString(strength)
		<< "\nDex: " << misc.turnNumberIntoString(dexterity)
		<< "\nInt: " << misc.turnNumberIntoString(intelligence)
		<< "\nWis: " << misc.turnNumberIntoString(wisdom)
		<< "\n~~~~~~~~~~~"
		<< "\n"
		;
}
 void displayStats::combatStats(int currentLv, int maxHp, int currentHp, int maxMp, int currentMp, string typeName) {
	 cout
				<< "\nName: " << typeName
				<< "\nLv  : " << misc.turnNumberIntoString(currentLv)
				<< "\nHP  : " << misc.turnNumberIntoString(currentHp) << "/" << misc.turnNumberIntoString(maxHp)
				<< "\nMP  : " << misc.turnNumberIntoString(currentMp) << "/" << misc.turnNumberIntoString(maxMp)
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
		 << "\nMagic Manipulation |Lv:" << magicManipulationLv << "| |Exp: " << misc.turnNumberIntoString(g_magicManipulationSkillExp) << "|"
		 << "\nSword Arts |Lv:" << swordArtsLv << "| |Exp: " << misc.turnNumberIntoString(g_swordArtsSkillExp) << "|"
		 << "\n"
		 ;
 }
 */

 displayStats::displayStats() {}

 displayStats::displayStats(Window &screen, string content)
 {
	 extern TTF_Font * Georgia;
	 int temp_w, temp_h;

	 SDL_Color White = {255, 255, 255, 255};

	 this->_textContent = TTF_RenderText_Solid(Georgia, content.c_str(), White);

	 this->_textTexture = SDL_CreateTextureFromSurface(screen.getRenderer(), _textContent);

	 TTF_SizeText(Georgia, content.c_str(), &temp_w, &temp_h);

	 this->_source_Rect.x = 0;
	 this->_source_Rect.y = 0;
	 this->_source_Rect.w = temp_w;
	 this->_source_Rect.h = temp_h;

 }

 displayStats::~displayStats() {

 }

 void displayStats::draw(Window &screen, int x, int y) {
	 SDL_Rect destinationRectangel = { x, y, this->_source_Rect.w, this->_source_Rect.h };
	 screen.blitSurface(this->_textTexture, &this->_source_Rect, &destinationRectangel);
 }


