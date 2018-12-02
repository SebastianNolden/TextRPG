#pragma once
#include <string>

class Window;

class displayStats
{
public:
	void combatStats(int currentLv, int maxHp, int currentHp, int maxMp, int currentMp, std::string);
	void statWindow(int currentLv, int currentExp, int maxHp, int currentHp, int maxMp, int currentMp, int currentAtk, int vitality, int strength, int dexterity, int intelligence, int wisdom, std::string typeName);
	void skillWindow();
	void skillExp(int magicManipulationLv, int swordArtsLv);
	void battleWindow(Window &window, struct SDL_Renderer *_renderer, int currentLv, int maxHp, int currentHp, int maxMp, int currentMp, std::string typeName);
private:

};

