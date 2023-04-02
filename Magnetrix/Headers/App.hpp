#pragma once
#include "Player.hpp"
#include "Button.hpp"
#include "Navigator.hpp"

class App 
{
public:
	App();
	~App();
	void loop();

private:

	void drawTiles();
	void drawTile(int tile, Vector2 pos);
	void rotateGrid(short dir);
<<<<<<< Updated upstream
	void checkCollisionGrid();
	float tileSize;
=======

	Button backButton;
	int fontSize;
	Vector2 mousePoint;

	int tileSize;
>>>>>>> Stashed changes
	short dir;
	float zeroW, zeroH;
	float WIDTH, HEIGHT;

	int grid[NUMBER_OF_TILES][NUMBER_OF_TILES] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0,0,0,4},
		{0,0,0,0,1,1,1,0,0,1},
		{0,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0}
	};
	Texture2D tileTexture;
	Texture2D bgTexture;
	Player pl;
};