#include "Window.h"
#include <SDL_image.h>
#include <SDL.h>

extern float g_x, g_y;

Window::Window() {
	SDL_CreateWindowAndRenderer(g_x, g_y, SDL_WINDOW_RESIZABLE, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Dreadfire");
}

Window::~Window() {
	SDL_DestroyWindow(this->_window);
	SDL_DestroyRenderer(this->_renderer);
}

/*SDL_Surface* Window::loadImage(const std::string &filePath) {
	if (this->_spriteSheets.count(filePath) == 0) {
		this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return this->_spriteSheets[filePath];
}*/

void Window::blitSurface(SDL_Texture * source, SDL_Rect * sourceRectangle, SDL_Rect * destiantionRectangle)
{
	SDL_RenderCopy(this->_renderer, source, sourceRectangle, destiantionRectangle);
}

void Window::flip()
{
	SDL_RenderPresent(this->_renderer);
}

void Window::clear()
{
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer * Window::getRenderer() const
{
	return this->_renderer;
}

