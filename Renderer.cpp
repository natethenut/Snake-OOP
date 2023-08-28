#include "Renderer.h"

Renderer::Renderer() {
	window.reset(SDL_CreateWindow("SNAKE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN));
	renderer.reset(SDL_CreateRenderer(window.get(), SDL_RENDERER_SOFTWARE, SDL_RENDERER_ACCELERATED));
	color = Color::White;
}
void Renderer::showRenderer() {
	SDL_RenderPresent(renderer.get());
}
void Renderer::clearRenderer() {
	SDL_RenderClear(renderer.get());
}

void Renderer::drawBorder() {
	for (int i = 0; i < GAME_WIDTH; i++) {
		SDL_SetRenderDrawColor(renderer.get(), grayflag, grayflag, grayflag, grayflagopacity);
		SDL_RenderDrawLine(renderer.get(), i * SIZE, 0, i * SIZE, HEIGHT);
	}
	for (int i = 0; i < GAME_HEIGHT; i++) {
		SDL_SetRenderDrawColor(renderer.get(), grayflag, grayflag, grayflag, grayflagopacity);
		SDL_RenderDrawLine(renderer.get(), 0, i * SIZE, WIDTH, i * SIZE);
	}
	SDL_SetRenderDrawColor(renderer.get(), noflag, noflag, noflag, noflag);
}

void Renderer::drawBoard(int x, int y, int size, Color color) {
	switch (color) {
	case Color::Red:
		SDL_SetRenderDrawColor(renderer.get(), redflag, noflag, noflag, fullopacity);
		break;
	case Color::White:
		SDL_SetRenderDrawColor(renderer.get(), whiteflag, whiteflag, whiteflag, fullopacity);
		break;
	}
	SDL_Rect rect{};
	rect.x = x * size;
	rect.y = y * size;
	rect.w = size;
	rect.h = size;
	SDL_RenderFillRect(renderer.get(), &rect);
	SDL_SetRenderDrawColor(renderer.get(), noflag, noflag, noflag, noflag);

}