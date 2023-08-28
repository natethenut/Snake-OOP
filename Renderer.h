#pragma once

#include <memory>
#include <SDL2/SDL.h>

static constexpr int WIDTH = 600;
static constexpr int HEIGHT = 400;
static constexpr int SIZE = 10;
static constexpr int GAME_WIDTH = WIDTH / SIZE;
static constexpr int GAME_HEIGHT = HEIGHT / SIZE;

struct SDLWindowDestroyer {
	void operator()(SDL_Window* window) const {
		SDL_DestroyWindow(window);
	}
};

struct SDLRendererDestroyer {
	void operator()(SDL_Renderer* renderer) const {
		SDL_DestroyRenderer(renderer);
	}
};

class Renderer {
private:
	std::unique_ptr<SDL_Window, SDLWindowDestroyer> window;
	std::unique_ptr<SDL_Renderer, SDLRendererDestroyer> renderer;

	//Easier to see what color will be presented without thinking about rgb values mixing	
	const int redflag = 255;
	const int whiteflag = 255;
	const int grayflag = 70;
	const int grayflagopacity = 5;
	const int fullopacity = 255;
	const int noflag = 0;

public:
	enum class Color { Red, White };
	Color color;
	Renderer();
	void clearRenderer();
	void showRenderer();
	void drawBoard(int x, int y, int size, Color color);
	void drawBorder();
};
