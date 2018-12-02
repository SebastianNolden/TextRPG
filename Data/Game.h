#pragma once

#include "Sprite.h"
#include "Displaystats.h"

class Window;

class Game
{
private:
	//Erstellt das Hauptfenster und l�sst alles laufen
	void running();
	void draw(Window &window);
	void update(float elapsedTime);

	Sprite _player;
	displayStats _battleWindow;
public:
	Game();
	~Game();
};

