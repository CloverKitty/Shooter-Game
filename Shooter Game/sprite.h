#ifndef SPRITE_H
#define SPRITE_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <iostream> 
//#include <SDL.h> 
#include <SDL2/SDL.h>
//#include <SDL_image.h>
#include <SDL2/SDL_image.h>


class sprite
{
private:
	const char* path;
	SDL_Texture* texture;
	SDL_Renderer* renderer;

	SDL_Texture* processImage();

protected:
	SDL_Rect dstrect; // maybe need to be pointer

public:
	sprite();
	sprite(const char* path, SDL_Renderer* renderer);
	sprite(const char* path, SDL_Renderer* renderer, int x, int y, int w, int h);
	~sprite();

	bool loadImage(const char* path);
	void create();
	void render();
};

#endif // SPRITE_H
