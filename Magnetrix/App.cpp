#include "pch.hpp"
#include "App.hpp"
#include "FileReader.hpp"

App::App()
{
	mousePoint = { 0,0 };
	HEIGHT = 1080;
	WIDTH = 1920;
	tileSize = GetScreenHeight() / 12.f;
	dir = NO_ROTATE;
	fontSize = HEIGHT / 36;
	backButton = Button("Menu", 0, 0, HEIGHT / 8, HEIGHT / 21.6, fontSize);
	zeroW = (GetScreenWidth() - NUMBER_OF_TILES * tileSize) / 2;
	zeroH = (GetScreenHeight() - NUMBER_OF_TILES * tileSize) / 2;

	WIDTH = NUMBER_OF_TILES * tileSize;
	HEIGHT = NUMBER_OF_TILES * tileSize;

	setLevel.openFile("level0.txt"); 
	setLevel.getText(grid);

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
	

}
void App::loop()
{

	//back button
	mousePoint = GetMousePosition();
	if (CheckCollisionPointRec(mousePoint, backButton.getBoundingBox()) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		auto manager = Navigator::getInstantiation();
		manager->dir = Navigator::Navigate::MENU;
	}

	dir = NO_ROTATE;

	if (IsKeyPressed(KEY_E))
		dir = RIGHT;
	else if (IsKeyPressed(KEY_Q))
		dir = LEFT;

	DrawTexture(bgTexture, 0, 0, WHITE);
	backButton.draw(0.4f, 1, RED, BLACK);
	DrawText(TextFormat("Mouse: %f, %f", mousePoint.x, mousePoint.y), 0, 50, 40, BLACK);
	rotateGrid(dir);
	drawTiles();
	pl.update(tileSize, dir);
	checkCollisionGrid();
	pl.draw();
		
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
	for (int i = 0; i < 4; ++i)
		std::cout << "x" << i << ": " << x[i] << ", y" << i << ": " << y[i]<< '\n';

	if (grid[y[0]][x[0]] != 0 && grid[y[0]][x[0]] != 4) // Top left
	{ 
		if (pl.body.x - zeroW > (x[0]) * tileSize)
			pl.body.x = (x[0] + 1) * tileSize + zeroW;
		//else if (pl.body.y - zeroH > y[0] * tileSize)
			//pl.body.y = (x[0] + 1) * tileSize + zeroH;
	}
	if (grid[y[1]][x[1]] != 0 && grid[y[1]][x[1]] != 4) // Top right
	{ 
		if (pl.body.x + pl.body.width - zeroW > (x[0]) * tileSize)
			pl.body.x = (x[0]) * tileSize + zeroW - 5;
		//else if (pl.body.y - zeroH > y[0] * tileSize)
			//pl.body.y = (x[0] + 1) * tileSize + zeroH;
	}
	if (grid[y[2] + 1][x[2]] != 0 && grid[y[2]][x[2]] != 4) // Bottom left
	{
		if (pl.body.x - zeroW > (x[0]) * tileSize && ((grid[y[2]+1][x[2]] != 1 && y[2] + 1 != NUMBER_OF_TILES)))
			pl.body.x = (x[0] + 1) * tileSize + zeroW;

		 if (pl.body.y + pl.body.height - zeroH > (y[0]) * tileSize)
			pl.body.y = (y[0]) * tileSize + zeroH - 1;

	}
	if (grid[y[3]][x[3]] != 0 && grid[y[3]][x[3]] != 4) // Bottom right
	{ 
		if (pl.body.x + pl.body.width - zeroW > (x[0]) * tileSize)
			pl.body.x = (x[0]) * tileSize + zeroW - 5;
		//else if (pl.body.y + pl.body.height - zeroH > (y[0]- 1) * tileSize)
			//pl.body.y = (y[0]-1) * tileSize + zeroH - 5;
	}
}