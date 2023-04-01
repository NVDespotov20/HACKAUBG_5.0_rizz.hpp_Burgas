#include "pch.hpp"
#include "App.hpp"

App::App()
{
	InitWindow(0, 0, "Magnetrix");
	ToggleFullscreen();

	tileSize = GetScreenHeight() / 12.f;
	rightOrLeft = -1;

	zeroW = (GetScreenWidth() - NUMBER_OF_TILES * tileSize) / 2;
	zeroH = (GetScreenHeight() - NUMBER_OF_TILES * tileSize) / 2;

	WIDTH = zeroW + NUMBER_OF_TILES * tileSize;
	HEIGHT = zeroH + NUMBER_OF_TILES * tileSize;

	/*for (int i = 0; i < NUMBER_OF_TILES; i++)
		for (int j = 0; j < NUMBER_OF_TILES; j++)
			grid[i][j] = 0;*/

	pl = Player( zeroW, zeroH, WIDTH, HEIGHT,
		Rectangle{zeroW - 1,
		HEIGHT - 2 * tileSize,
		(float)tileSize, 
		(float)(tileSize * 2)
		}, nullptr);

	tileTexture = LoadTexture("assets/Tile.png");
	bgTexture = LoadTexture("assets/bg.png");
}
App::~App()
{
	UnloadTexture(tileTexture);
	UnloadTexture(bgTexture);
	CloseWindow();

}
void App::loop()
{
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		rightOrLeft = -1;

		if (IsKeyPressed(KEY_E))
			rightOrLeft = 1;
		else if (IsKeyPressed(KEY_Q))
			rightOrLeft = 0;

		DrawTexture(bgTexture, 0, 0, WHITE);

		rotateGrid(rightOrLeft);
		drawTiles();
		pl.update(tileSize);
		pl.draw();
		//draw something
		EndDrawing();

	}
}

void App::drawTiles()
{
	for (int i = 0; i < NUMBER_OF_TILES; i++)
		for (int j = 0; j < NUMBER_OF_TILES; j++)
			drawTile(grid[i][j], Vector2{ zeroW + j * tileSize, zeroH + i * tileSize });
};

void App::drawTile(int tile, Vector2 pos)
{
	switch (tile)
	{
	case 0:
		return;
	case 1:
		DrawTextureV(tileTexture, pos, WHITE);
		break;
	case 2:
		// draw magnet;
		break;
	case 3:
		// draw magnet pulling path
		break;
	case 4:
		DrawRectangleV(pos, Vector2{ (float)tileSize, (float)tileSize }, GOLD);
		break;
	}
}
void App::rotateGrid(short right)
{
	if (right == -1)
		return;

	int tmp[NUMBER_OF_TILES][NUMBER_OF_TILES];

	for (int i = 0; i < NUMBER_OF_TILES; ++i)
		for (int j = 0; j < NUMBER_OF_TILES; ++j)
			tmp[i][j] = grid[i][j];

	if (right)
	{
		for (int i = 0; i < NUMBER_OF_TILES; ++i)
			for (int j = NUMBER_OF_TILES - 1, k = 0; j >= 0 && k < NUMBER_OF_TILES; --j, ++k)
				grid[i][j] = tmp[k][i];
		return;
	}

	for (int i = NUMBER_OF_TILES - 1, k = 0; i >= 0 && k < NUMBER_OF_TILES; --i, ++k)
		for (int j = NUMBER_OF_TILES - 1; j >= 0 ; --j)
			grid[i][j] = tmp[j][k];
}