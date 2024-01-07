#pragma once
#include "Game.hpp"
#include "Block.hpp"

class Board
{
public:
	Board(int blockPxSize);
	~Board();
	void render();
	void addBlock(Block* blockptr, int r, int c);
	Block* getBlock(int r, int c);

private:
	SDL_Rect renderingRect; 
	Block* boardArr[NUM_ROWS][NUM_COLS];
};