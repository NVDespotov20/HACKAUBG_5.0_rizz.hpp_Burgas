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
	void setCurrentLevel(int l);
	void drawTiles();
	void drawTile(int tile, Vector2 pos);
	void rotateGrid(short dir);
	bool checkCollisionGrid();

	FileReader setLevel;
	Button backButton;
	int fontSize;

	Vector2 mousePoint;
	float tileSize;

	short dir;
	float zeroW, zeroH;
	float WIDTH, HEIGHT;
	int grid[NUMBER_OF_TILES][NUMBER_OF_TILES];
	int level, levelEndTimer;
	Texture2D tileTexture;
	Texture2D bgTexture;
	Player pl;
};