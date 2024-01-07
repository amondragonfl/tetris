#pragma once
#include "Block.hpp"
#include "Board.hpp"
#include <cmath>

class Piece 
{

public:
	Piece(int type, Board* brd);
	~Piece();
	bool isEnoughSpace() { return enoughSpace; }
	void dropPiece();



private:
	Block* blockArr[4];
	Board* board; 
	bool enoughSpace; 

};
