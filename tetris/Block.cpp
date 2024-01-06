#pragma once
#include "Block.hpp"
#include "TextureManager.hpp"

Block::Block(const char* texturePath, int sizePX)
{
	texture = TextureManager::LoadTexture(texturePath);
	xpos = 0;
	ypos = 0;
	row = 0;
	col = 0;
	pxSize = sizePX;
}

void Block::update()
{
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = pxSize;
	destRect.h = pxSize;
}

void Block::render()
{
	SDL_RenderCopy(Game::renderer, texture, NULL, &destRect);
}
