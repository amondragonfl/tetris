#include "Game.hpp"

Game *game = nullptr;

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000/FPS; // target time per frame in ms

	Uint32 frameStart;
	int frameTime; 

	game = new Game();
	game->init("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, NUM_COLS*BLOCK_PX_SIZE, NUM_ROWS * BLOCK_PX_SIZE, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) { SDL_Delay(frameDelay - frameTime); } 

	}
	game->clean();

	return 0;
}