#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Main.h"
#include "Player.h"
#include "Combat.h"
#include "Game.h"
#include "Window.h"
#include <string>
using namespace std;

//Globale Variablen für Fenstergröße (17/9) (1020 x 940)
extern float g_x(17 * 60), g_y(9 * 60);

extern char *g_path = NULL;

extern TTF_Font * Georgia = NULL;

int main(int argc, char* argv[]){



	int init = TTF_WasInit();

	if (init == 0) {
		TTF_Init();
		if (TTF_Init() != 0) {
			cerr << "TFF_Ini() Failed: " << TTF_GetError() << endl;
			SDL_Quit();
			exit(1);
		}
	}

	char *base_path = SDL_GetBasePath();
	if (base_path) {
		g_path = base_path;
	}
	else {
		g_path = SDL_strdup("./)");
	}
	
	string file = "fonts\\georgia.ttf";
	string dir(g_path + file);
	
	Georgia = TTF_OpenFont(dir.c_str(), 15);
	if (Georgia == NULL) {
		cerr << "TTF_OpenFont() Failed: " << TTF_GetError << endl;
		cerr << dir << endl;
		TTF_Quit();
		SDL_Quit();
		exit(1);
	}

	//Staret Spiel
	Game Game;

	TTF_CloseFont(Georgia);
	TTF_Quit();

	return 0;
	}

