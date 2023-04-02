#include "pch.hpp"
#include "App.hpp"

App::App()
{
	InitWindow(0, 0, "Magnetrix");
	SetTargetFPS(60);
	//ToggleFullscreen();

	tileSize = GetScreenHeight() / 12.f;
	dir = NO_ROTATE;

	zeroW = (GetScreenWidth() - NUMBER_OF_TILES * tileSize) / 2;
	zeroH = (GetScreenHeight() - NUMBER_OF_TILES * tileSize) / 2;

	WIDTH = NUMBER_OF_TILES * tileSize;
	HEIGHT = NUMBER_OF_TILES * tileSize;

	/*for (int i = 0; i < NUMBER_OF_TILES; i++)
		for (int j = 0; j < NUMBER_OF_TILES; j++)
			grid[i][j] = 0;*/

	pl = Player(zeroW, zeroH, WIDTH, HEIGHT,
		Rectangle{ zeroW - 1,
		zeroH + HEIGHT - 2 * tileSize,
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

		dir = NO_ROTATE;

		if (IsKeyPressed(KEY_E))
			dir = RIGHT;
		else if (IsKeyPressed(KEY_Q))
			dir = LEFT;

		DrawTexture(bgTexture, 0, 0, WHITE);

		rotateGrid(dir);
		drawTiles();
		pl.update(tileSize, dir);
		checkCollisionGrid();
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
void App::rotateGrid(short dir)
{
	if (dir == NO_ROTATE)
		return;

	int tmp[NUMBER_OF_TILES][NUMBER_OF_TILES];

	for (int i = 0; i < NUMBER_OF_TILES; ++i)
		for (int j = 0; j < NUMBER_OF_TILES; ++j)
			tmp[i][j] = grid[i][j];

	if (dir == RIGHT)
	{
		for (int i = 0; i < NUMBER_OF_TILES; ++i)
			for (int j = NUMBER_OF_TILES - 1, k = 0; j >= 0 && k < NUMBER_OF_TILES; --j, ++k)
				grid[i][j] = tmp[k][i];
		return;
	}
	// dir == LEFT
	for (int i = NUMBER_OF_TILES - 1, k = 0; i >= 0 && k < NUMBER_OF_TILES; --i, ++k)
		for (int j = NUMBER_OF_TILES - 1; j >= 0; --j)
			grid[i][j] = tmp[j][k];
}

void App::checkCollisionGrid()
{
	int x[4],y[4];
	pl.getPosInGrid(x, y, tileSize);

	if (grid[y[0]][x[0]] != 0 && grid[y[0]][x[0]] != 4) { pl.setbackPos(x[0], y[0], tileSize); }
	if (grid[y[1]][x[1]] != 0 && grid[y[1]][x[1]] != 4) { pl.setbackPos(x[1], y[1], tileSize); }
	if (grid[y[2]][x[2]] != 0 && grid[y[2]][x[2]] != 4) { pl.setbackPos(x[2], y[2], tileSize); }
	if (grid[y[3]][x[3]] != 0 && grid[y[3]][x[3]] != 4) { pl.setbackPos(x[3], y[3], tileSize); }
}