#pragma once

#include <SDL.h>
#include <string>

class Window;

class Sprite
{
private:
	SDL_Rect _sourceRect;
	//SDL_Texture* _spriteSheet;

	float _x, _y;
public:
	Sprite();
	Sprite(Window &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
	virtual ~Sprite();
	virtual void update();
	void draw(Window &graphics, int x, int y);
};

