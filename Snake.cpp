#include "Snake.h"
#include <random>


void Snake::updateSnake(int direction) {
	int i = size;
	while (i > 0) {
		snake[i] = snake[i - 1];
		i--;
	}
	snake[0] += direction;
}

bool Snake::hasCollided() {
	if (snake[0] == apple) {
		apple = -1;
		size++;
		if (size == GAME_HEIGHT * GAME_WIDTH)
			return true; //Break the game loop if the snake has reached max size
		newApple();
	}
	if (snake[0] % (GAME_WIDTH) == 0 && snake[1] % (GAME_WIDTH) == GAME_WIDTH - 1)
		return true;
	if (snake[0] % (GAME_WIDTH) == GAME_WIDTH - 1 && snake[1] % (GAME_WIDTH) == 0)
		return true;
	if (snake[0] < 0 || snake[0] > (GAME_WIDTH * GAME_HEIGHT))
		return true;
	for (int i = size - 1; i > 0; i--) {
		if (snake[0] == snake[i]) {
			return true;
		}
	}
	return false;
}

void Snake::newApple() {
	std::random_device rd;
	std::uniform_int_distribution<int> randPos(0, snake.size() - 1);

	apple = randPos(rd);

	for (int i = 0; i < size; i++) {
		if (apple == snake[i])
			newApple();
	}
}

void Snake::startSnake() {
	snake[0] = GAME_HEIGHT / 2 * GAME_WIDTH + GAME_WIDTH / 3;
	snake[1] = snake[0] - 1;
	snake[2] = snake[1] - 1;
}
