#include <chrono>

#include "Game.hpp"

Game::Game() {
	gen.seed(std::chrono::system_clock::now().time_since_epoch().count());
	loop();
}

void Game::renderApple() {
	int x = (apple % game_width);
	int y = (apple - x) / game_width;
	renderer.draw(x, y, size, PieceToDraw::Apple);
}

void Game::renderSnake() {
	for (int i = 0; i < snake.getSnakeSize(); ++i) {
		int x = (snake.getSnake()[i] % game_width);
		int y = (snake.getSnake()[i] - x) / game_width;
		renderer.draw(x, y, size, PieceToDraw::Snake);
	}
}

void Game::gotApple() {
	if (snake.gotApple(apple)) {
		newApple();
	}
}

void Game::makeMove() {
	while (SDL_PollEvent(&e) != 0) {
		switch (e.type) {
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym) {
			case SDLK_LEFT:
				if (snake.isValidMove(Moves::Left)) {
					move = Moves::Left;
				}
				break;
			case SDLK_RIGHT:
				if (snake.isValidMove(Moves::Right)) {
					move = Moves::Right;
				}
				break;
			case SDLK_DOWN:
				if (snake.isValidMove(Moves::Down)) {
					move = Moves::Down;
				}
				break;
			case SDLK_UP:
				if (snake.isValidMove(Moves::Up)) {
					move = Moves::Up;
				}
				break;
			default:
				break;
			}
		default:
			break;
		}
	}
}

void Game::loop() {
	while (!quit) {
		renderer.clearRenderer();
		if (!snake.hasCollided()) {
			makeMove();
			snake.updateSnake(move);
			gotApple();
			renderSnake();
			renderApple();
			renderer.drawBorder();
			renderer.showRenderer();
		}
		else {
			quit = true;
		}

		SDL_Delay(100);
	}
	SDL_Quit();
}

void Game::newApple() {
	std::uniform_int_distribution<int> randPos(0, snake.getSnake().size() - 1);
	apple = randPos(gen);

	while (snake.isSnakeBody(apple)) {
		apple = randPos(gen);
	}
}

