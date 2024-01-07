#pragma once
#include "Block.hpp"
#include "Board.hpp"
#include <cmath>

class Piece 
{

public:
	Piece(int type, Board* board);
	~Piece();


private:
	Block* blockArr[4];

};
