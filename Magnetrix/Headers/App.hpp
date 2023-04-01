#pragma once
class App 
{
public:
	App();
	~App();
	void loop();
	void drawTiles();
	void drawTile(int tile, Vector2 pos);
	void rotateGrid(short right);
private:
	int tileSize;
	short rightOrLeft;
	float WIDTH, HEIGHT;
	int grid[NUMBER_OF_TILES][NUMBER_OF_TILES] = {
		{1,0,0,0,0,0,0,0,0,0},
		{1,0,0,1,0,0,0,0,0,0},
		{1,0,0,1,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0},
		{1,0,0,1,0,0,1,0,0,0},
		{1,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0}
	};
	Texture2D tileTexture, bgTexture;
};