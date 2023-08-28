#define SDL_MAIN_HANDLED
#include "Game.h"


int main() {
	Game game{};
	game.start();

	SDL_Quit();

	return 0;
}