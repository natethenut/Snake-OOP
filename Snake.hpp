#pragma once

#include <array>

#include "Globals.hpp"


class Snake {
public:
	const Snake();
	void updateSnake(const Moves &move);
	bool hasCollided() const&;
	bool isValidMove(const Moves &move) const&;
	bool isSnakeBody(const int position) const&;
	bool gotApple(const int apple);
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