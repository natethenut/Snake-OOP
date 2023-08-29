#define SDL_MAIN_HANDLED
#include "Game.hpp"


int main() {
	SDL_Init(SDL_INIT_EVERYTHING);
	Game game{};
	return 0;
}