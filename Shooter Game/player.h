#ifndef PLAYER_H
#define PLAYER_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include "sprite.h"
class player: public sprite

{
private:
	std::string name;

public:
	player();
	player(std::string name, const char* defaultSpritePath, int posX, int posY, int width, int height, SDL_Renderer* renderer);
	~player();

	//void render();
};

#endif // PLAYER_H
