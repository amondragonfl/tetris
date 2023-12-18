#pragma once
#include "SDL.h"

class Game
{
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	inline bool running(){ return isRunning; }

private:
	SDL_Window *window;
	SDL_Renderer* renderer;
	bool isRunning;

};

