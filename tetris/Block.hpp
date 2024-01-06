#pragma once
#include "Game.hpp"

class Block 
{
public:
	Block(const char* texturePath, int sizePX);
	~Block();
	void update();
	void render();
	void setX(int x) { xpos = x; }
	void setY(int y) { ypos = y; }
	void setRow(int r) { row = r; }
	void setCol(int c) { col = c;  }
	int getRow() const { return row; }
	int getCol() const { return col; }
	void setPxSize(int px) { pxSize = px; }
	
private:
	SDL_Texture* texture; 
	SDL_Rect destRect;
	int xpos, ypos;
	int pxSize;
	int row, col; 

};
