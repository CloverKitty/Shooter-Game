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
