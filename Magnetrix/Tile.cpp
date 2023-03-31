#include "pch.hpp"
#include "Tile.hpp"

Tile::Tile()
{
}

Tile::~Tile()
{
}

inline void Tile::draw(Vector2 pos, Texture2D* texture)
{
	DrawTextureV(*texture, pos, WHITE);
}