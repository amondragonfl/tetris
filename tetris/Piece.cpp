#include "Piece.hpp"
#include <algorithm> 
#include <iterator>

Piece::Piece(int type, Board* brd)
{
	board = brd;
	for (int i = 0; i < 4; i++)
	{
		blockArr[i] = new Block("assets/sprites/blueblock25px.png", BLOCK_PX_SIZE);
	}
	int width = 3;
	switch (type)
	{
	case 2: 
		width = 2;
		break;
	case 6:
		width = 4;
		break;
	default:
		break;
	}
	int xShift = (int)floor((NUM_COLS - width) / 2); // Distance from left to leftmost block in piece
	int pattern[7][4][2] = // coordinates for 4 blocks in each different piece 
	{
		{{0, xShift}, {1, xShift}, {1, xShift+1}, {1, xShift+2}}, // :..  
		{{0, xShift+2}, {1, xShift}, {1, xShift + 1}, {1, xShift + 2}}, // ..:
		{{0, xShift}, {0, xShift+1}, {1, xShift}, {1, xShift + 1}}, // ::
		{{1, xShift}, {1, xShift+1}, {0, xShift + 1}, {0, xShift + 2}}, // .:'
		{{1, xShift}, {1, xShift + 1}, {1, xShift + 2}, {0, xShift + 1}}, // .:.
		{{0, xShift}, {0, xShift + 1}, {1, xShift + 1}, {1, xShift + 2}}, // ':.
		{{0, xShift}, {0, xShift + 1}, {0, xShift + 2}, {0, xShift + 3}}, // ....
	};
	
	enoughSpace = true;
	for (int i = 0; i < 4; i++)
	{
		if (board->getBlock(pattern[type][i][0], pattern[type][i][1]) != nullptr)
		{
			enoughSpace = false;
			break;
		}
	}
	if (enoughSpace) 
	{
		for (int i = 0; i < 4; i++)
		{
			board->addBlock(blockArr[i], pattern[type][i][0], pattern[type][i][1]);
		}
	}
}

void Piece::dropPiece()
{
	bool canDrop = true;
	Block* blockBelow;
	for (int i = 0; i < 4; i++) // check if all blocks of piece can drop 
	{
		blockBelow = board->getBlock(blockArr[i]->getRow() + 1, blockArr[i]->getCol());
		if (blockBelow != nullptr)
		{
			auto iter = std::find(std::begin(blockArr), std::end(blockArr), blockBelow);
			if (iter == std::end(blockArr)) {
				canDrop = false; // block below doesn't belong to piece so piece can't drop 
			}
		}
	}
	if (canDrop) 
	{
		for (int i = 0; i < 4; i++)
		{
			board->moveBlock(blockArr[i], blockArr[i]->getRow() + 1, blockArr[i]->getCol());
		}
	}
}