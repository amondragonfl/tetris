#include "Board.hpp"

Board::Board(int blockPxSize)
{
	renderingRect.x = 0;
	renderingRect.y = 0;
	renderingRect.w = blockPxSize;
	renderingRect.h = blockPxSize;
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
			boardArr[i][j] = nullptr;
		}
	}
}

Board::~Board()
{
}

void Board::render()
{
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
			if (boardArr[i][j] != nullptr)
			{
				(*boardArr[i][j]).setX(renderingRect.x);
				(*boardArr[i][j]).setY(renderingRect.y);
				(*boardArr[i][j]).update();
				(*boardArr[i][j]).render();
			}
			renderingRect.x += renderingRect.w;
		}
		renderingRect.x = 0;
		renderingRect.y += renderingRect.h;
	}
	renderingRect.x = 0;
	renderingRect.y = 0;
}

void Board::addBlock(Block* blockptr, int r, int c)
{
	if (r < NUM_ROWS && c < NUM_COLS)
	{
		boardArr[r][c] = blockptr;
	}
}