#pragma once

#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>


struct SDL_Window;
struct SDL_Renderer;

class Window {
public: 
	Window();
	~Window();

	//Läd ein Bild in die _spriteSheets map wenn es noch nicht existert
	//Dadurch wird ein Bild nur einmal geladen
	//Gibt das Bild aus der map wieder egal ob es gerade geladen wurde oder nicht
	SDL_Surface* loadImage(const std::string &filePath);
	
	//Zeichnet eine Textur zu einem bestimmten Bildschirmteil
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destiantionRectangle);

	//Renders alles zum Bildschirm
	void flip();

	//Leert den Bildschirm
	void clear();

	//Gibt Renderer wieder
	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	//std::map<std::string, SDL_Surface*> _spriteSheets;
};