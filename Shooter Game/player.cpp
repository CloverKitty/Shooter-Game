#include "player.h"

player::player() {
}

player::player(std::string name, const char* defaultSpritePath, int posX, int posY, int width, int height, SDL_Renderer* renderer) {
	this->renderer = renderer;
	this->name = name;
	this->path = defaultSpritePath;
	dstrect.x = posX;
	dstrect.y = posY;
	dstrect.w = width;
	dstrect.h = height;
}

player::~player() {
	
}

/*
void player::render() {
	
}
*/