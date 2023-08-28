#pragma once

#include <SDL2/SDL.h>
#include <array>

#include "Snake.h"


class Game {
public:
	enum class Moves { Up = -GAME_WIDTH, Down = GAME_WIDTH, Left = - 1, Right = 1, Quit = 0};
	Moves move = Moves::Right;
	void start();
	void loop();
	void viewBoard();
	void addToBoard();
	void updateBoard();
	void makeMove(SDL_Event &e);
	bool isValidMove(Moves move);
private:
	std::array<int, GAME_WIDTH* GAME_HEIGHT> board{};
	Renderer renderer;
	Snake snake;
};