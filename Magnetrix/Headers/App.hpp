#pragma once
#include "Player.hpp"

class App 
{
public:
	App();
	~App();
	void loop();

private:

	void drawTiles();
	void drawTile(int tile, Vector2 pos);
	void rotateGrid(short right);

	int tileSize;
	short rightOrLeft;
	float zeroW, zeroH;
	float WIDTH, HEIGHT;

	int grid[NUMBER_OF_TILES][NUMBER_OF_TILES] = {
		{1,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,4},
		{1,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0}
	};
	Texture2D tileTexture;
	Texture2D bgTexture;
	Player pl;
};