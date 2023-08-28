#define SDL_MAIN_HANDLED
#include "Game.h"


int main() {
	Game game{};
	game.start();

	game.loop();

	SDL_Quit();

	return 0;
}