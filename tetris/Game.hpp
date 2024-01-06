#pragma once
#include "SDL.h"
#include "SDL_image.h"

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
	static SDL_Renderer* renderer;

private:
	SDL_Window *window;
	bool isRunning;

};

