#pragma once
#include "Block.hpp"
#include "TextureManager.hpp"

Block::Block(const char* texturePath, SDL_Renderer* ren, int sizePX)
{
	renderer = ren;
	texture = TextureManager::LoadTexture(texturePath, renderer);
	xpos = 0;
	ypos = 0;
	row = 0;
	col = 0;
	destRect.w = sizePX;
	destRect.h = sizePX;
}

void Block::update()
{
	destRect.x = xpos;
	destRect.y = ypos;
}

void Block::render()
{
	SDL_RenderCopy(renderer, texture, NULL, &destRect);
}
