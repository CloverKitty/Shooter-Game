#ifndef SPRITE_H
#define SPRITE_H

#ifdef _MSC_VER
#pragma once
#include <SDL2.h>
#include <SDL_image.h>
#endif // _MSC_VER

#ifdef __unix
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#endif 

#include <iostream> 
#include <string>


class sprite
{
private:
	SDL_Texture* texture;

	SDL_Texture* processImage();

protected:
	
public:
	SDL_Rect dstrect; // maybe need to be pointer
	const char* path;
	SDL_Renderer* renderer;

	sprite();
	sprite(const char* path, SDL_Renderer* renderer);
	sprite(const char* path, SDL_Renderer* renderer, int x, int y, int w, int h);
	~sprite();

	bool loadImage(const char* path);
	int changeImage(const char* path);
	void create();
	void render();
};

#endif // SPRITE_H
