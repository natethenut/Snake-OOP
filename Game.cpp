#include "Game.h"

void Game::start() {
	snake.startSnake();
}

void Game::viewBoard() {
	for (int i = 0; i < GAME_WIDTH; i++) {
		for (int j = 0; j < GAME_HEIGHT; j++) {
			if (board[j * GAME_WIDTH + i]) {
				renderer.color = board[j * GAME_WIDTH + i] == 2 ? Renderer::Color::Red : Renderer::Color::White;
				renderer.drawBoard(i, j, SIZE, renderer.color);
			}
		}
	}
}

void Game::addToBoard() {
	for (int i = 0; i < snake.getSize(); i++) {
		board[snake.getSnake()[i]] = 1;
	}

	board[snake.getApple()] = 2;
}

bool Game::isValidMove(Moves move) {
	switch (move) {
	case Moves::Left:
		return (snake.getSnake()[0] - 1 != snake.getSnake()[1]);
	case Moves::Right:
		return (snake.getSnake()[0] + 1 != snake.getSnake()[1]);
	case Moves::Up:
		return (snake.getSnake()[0] - GAME_WIDTH != snake.getSnake()[1]);
	case Moves::Down:
		return (snake.getSnake()[0] + GAME_WIDTH != snake.getSnake()[1]);
	}
	return false;
}

void Game::makeMove(SDL_Event &e) {
	while (SDL_PollEvent(&e) != 0) {
		switch (e.type) {
		case SDL_QUIT:
			move = Moves::Quit;
			break;
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym) {
			case SDLK_LEFT:
				if (isValidMove(Moves::Left))
					move = Moves::Left;
				break;
			case SDLK_RIGHT:
				if (isValidMove(Moves::Right))
					move = Moves::Right;
				break;
			case SDLK_DOWN:
				if (isValidMove(Moves::Down))
					move = Moves::Down;
				break;
			case SDLK_UP:
				if (isValidMove(Moves::Up))
					move = Moves::Up;
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
	SDL_Event e;
	while (move != Moves::Quit) {
		renderer.clearRenderer();
		makeMove(e);
		updateBoard();
		if (!snake.hasCollided()) {
			addToBoard();
			viewBoard();
			renderer.drawBorder();
			renderer.showRenderer();
		}
		else {
			move = Moves::Quit;
		}

		SDL_Delay(100);
	}
}

void Game::updateBoard() {
	snake.updateSnake((int)move);
	board[snake.getSnake()[snake.getSize()]] = 0; //Instead of clearing the entire board and refilling it, 
	//just remove the snake's tail after it moves
}

