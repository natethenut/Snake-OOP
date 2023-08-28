#pragma once

#include <array>
#include "Renderer.h" //Has needed variables


class Snake {
public:
	void updateSnake(int direction);
	bool hasCollided();
	void newApple();
	void startSnake();
	std::array<int, GAME_WIDTH * GAME_HEIGHT + 1> getSnake() const {
		return snake;
	}
	int getSize() const {
		return size;
	}
	int getApple() const {
		return apple;
	}
private:
	int apple = GAME_HEIGHT / 2 * GAME_WIDTH + (GAME_WIDTH * 2) / 3;
	std::array<int, GAME_WIDTH* GAME_HEIGHT + 1> snake{}; //Adding 1 so that reaching max size doesn't lead to an Out of Bounds exception
	int size = 3;
};