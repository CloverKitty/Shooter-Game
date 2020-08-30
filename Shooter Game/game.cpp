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
		if (movePlayerUp == true){
			if (coolio.path != "res/sprite-ghost.png") {
				coolio.changeImage("res/sprite-ghost.png");
				printf("UP\n");
			}
			coolio.movement(true, false, false, false);
		}
		else {
			if (coolio.path != "res/sprite.png") {
				coolio.changeImage("res/sprite.png");
			}
		}

		if (movePlayerDown == true) {
			coolio.movement(false, true, false, false);
		}

		if (movePlayerLeft == true) {
			coolio.movement(false, false, true, false);
		}

		if (movePlayerRight == true) {
			coolio.movement(false, false, false, true);
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
		movePlayerUp = true;
	}
	else {
		movePlayerUp = false;
	}

	if (keystate[SDL_SCANCODE_S] && SDL_KEYDOWN) {
		movePlayerDown = true;
	}
	else {
		movePlayerDown = false;
	}

	if (keystate[SDL_SCANCODE_A] && SDL_KEYDOWN) {
		movePlayerLeft = true;
	}
	else {
		movePlayerLeft = false;
	}

	if (keystate[SDL_SCANCODE_D] && SDL_KEYDOWN) {
		movePlayerRight = true;
	}
	else {
		movePlayerRight = false;
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