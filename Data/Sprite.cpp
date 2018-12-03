#include "Sprite.h"
#include "Window.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

Window window;

Sprite::Sprite()
{
}

Sprite::Sprite(Window &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) {
	this->_sourceRect.x = sourceX;
	this->_sourceRect.y = sourceY;
	this->_sourceRect.w = width;
	this->_sourceRect.h = height;

	this->_spriteSheet = SDL_CreateTextureFromSurface(window.getRenderer(), window.loadImage(filePath));
	if (this->_spriteSheet == NULL){
		std::cout << "\nError: Unable to load image\n";
	}
}

Sprite::~Sprite()
{
}

void Sprite::update()
{
}

void Sprite::draw(Window & graphics, int x, int y)
{
	SDL_Rect destinationRectangel = { x,y, this->_sourceRect.w, this->_sourceRect.h };
	window.blitSurface(this->_spriteSheet, &this->_sourceRect, &destinationRectangel);
}
