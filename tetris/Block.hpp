#pragma once
#include "Game.hpp"

class Block 
{
public:
	Block(const char* texturePath, SDL_Renderer* ren, int sizePX);
	~Block();
	void update();
	void render();
	
private:
	SDL_Renderer* renderer; 
	SDL_Texture* texture; 
	SDL_Rect destRect;
	int xpos, ypos;
	int row, col; 

};
