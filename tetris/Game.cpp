#include "Game.hpp"
#include <iostream>
#include "TextureManager.hpp"
#include "Block.hpp"

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized succesfully" << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window initialized succesfully" << std::endl;
		}
		Game::renderer = SDL_CreateRenderer(window, -1, 0);
		if (Game::renderer)
		{
			SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
			std::cout << "Renderer initialized succesfully" << std::endl;
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
}


void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
	}

}

void Game::update()
{}

void Game::render()
{
	SDL_RenderClear(Game::renderer);
	// Render stuff 
	SDL_RenderPresent(Game::renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Game::renderer);
	SDL_Quit();
	std::cout << "game cleaned" << std::endl;
}
