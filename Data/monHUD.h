#pragma once
#include "Goblin.h"
#include "Displaystats.h"

class Window;

class monHUD
{
public:
	monHUD();
	monHUD(Window & creen, Goblin &goblin);
	void draw(Window & screen, std::string monType);
private:
	Goblin _goblin;

	displayStats _displayMonLevel;
	displayStats _displayMonName;
	displayStats _displayMonHP;
	displayStats _displayMonMP;
};

