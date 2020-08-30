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

/*assign parameters keys (up, down, left, right)*/
int player::movement(bool up, bool down, bool left, bool right) {

	if (up && !down && !left && !right) {
		dstrect.y = dstrect.y - 1;
	}

	if (!up && down && !left && !right) {
		dstrect.y = dstrect.y + 1;
	}

	if (!up && !down && left && !right) {
		dstrect.x = dstrect.x - 1;
	}

	if (!up && !down && !left && right) {
		dstrect.x = dstrect.x + 1;
	}

	return 0;
}