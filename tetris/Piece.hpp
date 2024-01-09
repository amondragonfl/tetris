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
	bool moveDown(); //True if it could drop the piece
	void update();
	bool isPieceSettled() { return isSettled; }



private:
	Block* blockArr[4];
	Board* board; 
	bool enoughSpace; 
	bool isSettled; 

};
