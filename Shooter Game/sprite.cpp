#include "sprite.h"

sprite::sprite() {
	
}

sprite::sprite(const char* path, SDL_Renderer* renderer) {
	texture = nullptr;
	this->path = path;
	this->renderer = renderer;
	dstrect.x = 0;
	dstrect.y = 0;
	dstrect.w = 0;
	dstrect.h = 0;
}

sprite::sprite(const char* path, SDL_Renderer* renderer, int x, int y, int w, int h) {
	texture = nullptr;
	this->path = path;
	this->renderer = renderer;
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = w;
	dstrect.h = h;
}

sprite::~sprite() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
}

SDL_Texture* sprite::processImage() {
	SDL_Texture* newTexture = nullptr;

	SDL_Surface* loadedSurface = IMG_Load(path);
	if (loadedSurface == nullptr)
	{
		printf("Unable to load image %s\n", path);
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == nullptr)
		{
			printf("Unable to create texture %s\n", path);
		}

		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

bool sprite::loadImage(const char* path) {
	bool sucess = true;
	texture = processImage();
	if (texture == nullptr) {
		sucess = false;
	}
	return sucess;
}

void sprite::create() {
	loadImage(path);
}

void sprite::render() {
	SDL_RenderCopy(renderer, texture, NULL, &dstrect);
}