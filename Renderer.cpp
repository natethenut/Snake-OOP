#include "Renderer.hpp"

Renderer::Renderer() {
	window.reset(SDL_CreateWindow("SNAKE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN));
	renderer.reset(SDL_CreateRenderer(window.get(), SDL_RENDERER_SOFTWARE, SDL_RENDERER_ACCELERATED));
}
void Renderer::showRenderer() const{
	SDL_RenderPresent(renderer.get());
}
void Renderer::clearRenderer() const{
	SDL_RenderClear(renderer.get());
}

void Renderer::draw(int x, int y, int size, PieceToDraw piece) const{
	switch (piece) {
	case PieceToDraw::Apple:
		SDL_SetRenderDrawColor(renderer.get(), redflag, noflag, noflag, fullopacity);
		break;
	case PieceToDraw::Snake:
		SDL_SetRenderDrawColor(renderer.get(), whiteflag, whiteflag, whiteflag, fullopacity);
		break;
	}
	SDL_Rect rect{x * size, y * size, size, size};

	SDL_RenderFillRect(renderer.get(), &rect);

	SDL_SetRenderDrawColor(renderer.get(), noflag, noflag, noflag, noflag);
}

void Renderer::drawBorder() const{
	for (int i = 0; i < game_width; ++i) {
		SDL_SetRenderDrawColor(renderer.get(), grayflag, grayflag, grayflag, grayflagopacity);
		SDL_RenderDrawLine(renderer.get(), i * size, 0, i * size, height);
	}
	for (int i = 0; i < game_height; ++i) {
		SDL_SetRenderDrawColor(renderer.get(), grayflag, grayflag, grayflag, grayflagopacity);
		SDL_RenderDrawLine(renderer.get(), 0, i * size, width, i * size);
	}
	SDL_SetRenderDrawColor(renderer.get(), noflag, noflag, noflag, noflag);
}
