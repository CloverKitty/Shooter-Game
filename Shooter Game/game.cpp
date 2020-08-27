#include "game.h"

game::game() {
	running = false;
	window = nullptr;
	windowRenderer = nullptr;
}

void game::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Unable to initialize SDL: %s \n", SDL_GetError());
	}

	int imgflags = IMG_INIT_JPG | IMG_INIT_PNG;
	int initted = IMG_Init(imgflags);
	if ((initted & imgflags) != imgflags) {
		printf("IMG_Init: Failed to init required png support!\n");
		printf("IMG_Init: %s\n", IMG_GetError());
	}

	window = SDL_CreateWindow("Cool", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, SDL_WINDOW_SHOWN);
	windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	running = true;
}

void game::run() {
	init();

	player coolio = player("playa", "res/sprite.png", 100, 100, 64, 64, windowRenderer);
	coolio.create();

	while (running == true) {

		handleEvents();
		if (key_w == true){
			if (coolio.path != "res/sprite-ghost.png") {
				coolio.loadImage("res/sprite-ghost.png");
				printf("w\n");
			}
		}
		else {
			if (coolio.path != "res/sprite.png") {
				coolio.loadImage("res/sprite.png");
			}
		}

		SDL_Delay(1);

		SDL_RenderClear(windowRenderer);

		coolio.render();

		SDL_RenderPresent(windowRenderer);


	}


	SDL_DestroyRenderer(windowRenderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
	printf("Game quit successfully! \n");
}

void game::handleEvents() {
	SDL_Event event;

	const Uint8* keystate = SDL_GetKeyboardState(NULL);

	if (keystate[SDL_SCANCODE_W] && SDL_KEYDOWN) {
		key_w = true;
	}
	else {
		key_w = false;
	}

	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		running = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			running = false;
			break;
		}

	default:
		break;
	}
}