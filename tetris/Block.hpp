#pragma once
#include "Game.hpp"

class Block 
{
public:
	Block(const char* texturePath, int sizePX);
	~Block();
	void update();
	void render();
	inline void setX(int x) { xpos = x; }
	inline void setY(int y) { ypos = y; }
	inline void setRow(int r) { row = r; }
	inline void setCol(int c) { col = c;  }
	inline int getRow() const { return row; }
	inline int getCol() const { return col; }
	
private:
	SDL_Texture* texture; 
	SDL_Rect destRect;
	int xpos, ypos;
	int row, col; 

};
