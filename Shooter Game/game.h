#ifndef GAME_H
#define GAME_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER


#include "sprite.h"

class game
{
private:
	void init();
	void handleEvents();
	bool running;
	SDL_Window* window;
	
	SDL_Renderer* windowRenderer;

public:
	game();
	
	void run();
};

#endif // GAME_H
