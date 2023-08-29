#pragma once

#include <array>

#include "Globals.hpp"


class Snake {
public:
	const Snake();
	void updateSnake(Moves &move);
	bool hasCollided() const&;
	bool gotApple(int apple);
	bool isValidMove(Moves move) const&;
	bool isSnakeBody(int position) const&;
	std::array<int, game_width * game_height> getSnake() const& {
		return snake;
	}
	int getSnakeSize() const& {
		return snakeSize;
	}
private:
	std::array<int, game_width * game_height> snake{};
	int snakeSize = 3;
	int direction = 1;
};