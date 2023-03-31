#include "pch.hpp"
#include "App.hpp"

App::App()
{
	InitWindow(0, 0, "Magnetrix");
	ToggleFullscreen();

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			grid[i][j] = 0;
}
App::~App()
{
	CloseWindow();
}
void App::loop() 
{
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		//draw something
		EndDrawing();

	}
}
