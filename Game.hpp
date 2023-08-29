#pragma once

#include <random>

#include <SDL2/SDL.h>

#include "Snake.hpp"
#include "Globals.hpp"
#include "Renderer.hpp"

class Game {
public:
	const Game();
	void loop();
	void renderApple();
	void renderSnake();;
	void makeMove();
	void gotApple();
	void newApple();

private:
	std::default_random_engine gen;
	int apple = game_height / 2 * game_width + (game_width * 2) / 3; //calculation for apple coordinates (apple % width) = x
	SDL_Event e;																							   //(apple - x) / width = y
	const Renderer renderer;
	Snake snake;
	Moves move = Moves::Right;
};