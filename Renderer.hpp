#pragma once

#include <memory>

#include <SDL2/SDL.h>

#include "Globals.hpp"

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
public:
	const Renderer();
	void clearRenderer() const;
	void showRenderer() const;
	void draw(int x, int y, int size, PieceToDraw piece) const;
	void drawBorder() const;

private:
	std::unique_ptr<SDL_Window, SDLWindowDestroyer> window;
	std::unique_ptr<SDL_Renderer, SDLRendererDestroyer> renderer;

	//Easier to see what color will be presented without thinking about rgb values mixing	
	const std::uint8_t redflag = 255;
	const std::uint8_t whiteflag = 255;
	const std::uint8_t grayflag = 70;
	const std::uint8_t grayflagopacity = 5;
	const std::uint8_t fullopacity = 255;
	const std::uint8_t noflag = 0;

};
