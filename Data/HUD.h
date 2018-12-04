#pragma once
#include "Player.h"
#include "Displaystats.h"

class Window;

class HUD
{
public:
	HUD();
	HUD(Window &screen, player &player);
	void draw(Window &screen);
private:
	player _player;

	displayStats _displayLevel;
	displayStats _displayName;
	displayStats _displayHP;
	displayStats _displayMP;
};

