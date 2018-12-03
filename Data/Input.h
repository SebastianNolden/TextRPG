#pragma once

#include <map>
#include <SDL.h>

class Input
{
private:
	std::map<SDL_Scancode, bool>_heldKeys;
	std::map<SDL_Scancode, bool>_pressedKeys;
	std::map<SDL_Scancode, bool>_releasedKeys;
public:
	//Aufruf zu jedem neuen Frame
	//Setzt nicht mehr genutze Tasten zurück
	void startFrame();
	//Aufruf wenn eine Taste losgelassen wird
	void keyUpEvent(const SDL_Event& event);
	//Aufruf wenn eine Taste gedrückt wird
	void keyDownEvent(const SDL_Event& event);

	//Prüft ob eine bestimmte Taste während des jetzigen Frame gerückt wurde
	bool wasKeyPressed(SDL_Scancode key);
	//Prüft ob eine bestimmte Taste während des jetzigen Frame losgelassen wurde
	bool wasKeyReleased(SDL_Scancode key);
	//Prüft ob eine bestimmte Taste während des jetzigen Frame gehalten wird
	bool isKeyHeld(SDL_Scancode key);
};

