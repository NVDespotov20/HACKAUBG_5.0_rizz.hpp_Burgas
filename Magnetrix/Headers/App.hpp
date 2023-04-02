#pragma once
#include "Player.hpp"
#include "Button.hpp"
#include "Navigator.hpp"
#include "FileReader.hpp"

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
	void checkCollisionGrid();

	FileReader setLevel;
	Button backButton;
	int fontSize;

	Vector2 mousePoint;
	float tileSize;

	short dir;
	float zeroW, zeroH;
	float WIDTH, HEIGHT;
	int grid[NUMBER_OF_TILES][NUMBER_OF_TILES];

	Texture2D tileTexture;
	Texture2D bgTexture;
	Player pl;
};