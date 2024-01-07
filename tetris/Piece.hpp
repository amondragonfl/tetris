#pragma once
#include "Block.hpp"
#include "Board.hpp"
#include <cmath>

class Piece 
{

public:
	Piece(int type, Board* board);
	~Piece();
	bool isEnoughSpace() { return enoughSpace; }


private:
	Block* blockArr[4];
	bool enoughSpace; 

};
