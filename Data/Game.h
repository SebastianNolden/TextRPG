#pragma once

//#include "Sprite.h"
#include "Player.h"
#include "Goblin.h"
#include "Window.h"
#include "HUD.h"
#include "monHUD.h"


class Game
{
private:
	//Erstellt das Hauptfenster und lässt alles laufen
	void running();
	void draw(Window &window);
	void update(float elapsedTime);

	//Sprite _sprite;
	player _character;
	Goblin _goblin;
	Window _screen;
	HUD _HUD;
	monHUD _monHUD;
public:
	Game();
	~Game();
};

