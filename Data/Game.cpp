#include "Game.h"
#include <SDL.h>
#include <algorithm>
#include "Player.h"
#include "Window.h"
#include "Input.h"
#include "Displaystats.h"


namespace {
	const int FPS = 60;
	const int MAX_FRAME_TIME = 1000 / FPS;
}


void Game::running()
{
	Window window;
	Input input;
	SDL_Event event;

	//this->_player = Sprite(graphics, "INSERT FILEPATH HERE", START X, STRT Y, END X, END Y, SCREEN POS X, SCREEN POS Y);

	this->draw(window);

	int LAST_UPDATE_TIME = SDL_GetTicks();

	//Startet Spielschleife
	while (true) {
		input.startFrame();

		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT) {
				return;
			}
		}
		//Schließt das Programm wenn ALT + F4 gedrückt wird
		if (input.wasKeyPressed(SDL_SCANCODE_LALT) == true){
			if (input.wasKeyPressed(SDL_SCANCODE_F4) == true) {
				return;
			}
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;
		

	}
}

void Game::draw(Window & window)
{
	window.clear();

	//this->_player.draw(window, SCREEN POS X, SCREEN POS Y);
	this->_battleWindow.battleWindow(window, window.getRenderer(), 1, 100, 100, 100, 100, "Void");

	window.flip();
}

void Game::update(float elapsedTime)
{

}

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	this->running();
}


Game::~Game()
{
}

