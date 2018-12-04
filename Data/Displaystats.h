#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <map>

class Window;

class displayStats
{
public:
	/*void combatStats(int currentLv, int maxHp, int currentHp, int maxMp, int currentMp, std::string);
	void statWindow(int currentLv, int currentExp, int maxHp, int currentHp, int maxMp, int currentMp, int currentAtk, int vitality, int strength, int dexterity, int intelligence, int wisdom, std::string typeName);
	void skillWindow();
	void skillExp(int magicManipulationLv, int swordArtsLv);*/

	displayStats();
	displayStats(Window & screen, std::string content);
	~displayStats();
	void draw(Window & window, int x, int y);
private:
	SDL_Rect _source_Rect;
	SDL_Surface* _textContent;
	SDL_Texture* _textTexture;
};

