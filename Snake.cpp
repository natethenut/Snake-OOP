#include "Snake.hpp"

Snake::Snake() {
	snake[0] = game_height / 2 * game_width + game_width / 3;
	snake[1] = snake[0] - 1;
	snake[2] = snake[1] - 1;
}

void Snake::updateSnake(Moves &move) {
	int i = snakeSize;
	while (i > 0) {
		snake[i] = snake[i - 1];
		i--;
	}

	switch (move) {
	case Moves::Right:
		direction = 1;
		break;
	case Moves::Left:
		direction = -1;
		break;
	case Moves::Up:
		direction = -game_width;
		break;
	case Moves::Down:
		direction = game_width;
		break;
	default:
		break;
	}

	snake[0] += direction;
}

bool Snake::isValidMove(Moves move) const& {
	switch (move) {
	case Moves::Right:
		return (snake[0] + 1 != snake[1]);
	case Moves::Left:
		return (snake[0] - 1 != snake[1]);
	case Moves::Down:
		return (snake[0] + game_width != snake[1]);
	case Moves::Up:
		return (snake[0] - game_width != snake[1]);
	default:
		return false;
	}
}

bool Snake::isSnakeBody(int position) const& {
	return std::find(std::begin(snake), std::end(snake), position) != std::end(snake);
}

bool Snake::hasCollided() const& {
	if (snake[0] % game_width == 0 && snake[1] % game_width == game_width - 1) {
		return true;
	}
	if (snake[0] % game_width == game_width - 1 && snake[1] % game_width == 0) {
		return true;
	}
	if (snake[0] < 0 || snake[0] > (game_width * game_height)) {
		return true;
	}
	for (int i = snakeSize - 1; i > 0; --i) {
		if (snake[0] == snake[i]) {
			return true;
		}
	}
	return false;
}

bool Snake::gotApple(int apple) {
	if (snake[0] == apple) {
		++snakeSize;
		return true;
	}
	return false;
}