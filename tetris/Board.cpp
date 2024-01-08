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
		blockptr->setRow(r);
		blockptr->setCol(c);
		boardArr[r][c] = blockptr;
	}
}

Block* Board::getBlock(int r, int c)
{
	if (r < NUM_ROWS && c < NUM_COLS)
	{
		return boardArr[r][c];
	}
	return nullptr;
}

// if the passed block argument is not in board it will add it instead of "moving" it
void Board::moveBlock(Block* blockptr, int nr, int nc) 
{
	if (boardArr[blockptr->getRow()][blockptr->getCol()] == blockptr) 
	{
		boardArr[blockptr->getRow()][blockptr->getCol()] = nullptr; 
	}
	addBlock(blockptr, nr, nc);
}