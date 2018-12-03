#pragma once

#include "Sprite.h"
#include "Displaystats.h"
#include "Player.h"
#include "Window.h"


class Game
{
private:
	//Erstellt das Hauptfenster und lässt alles laufen
	void running();
	void draw(Window &window);
	void update(float elapsedTime);

	Sprite _sprite;
	displayStats _battleWindow;
	player _character;
	Window _screen;
public:
	Game();
	~Game();
};

