#pragma once

class Player
{
public:
	Player();
	Player(float zeroW, float zeroH, float WIDTH, float HEIGHT, Rectangle body, Texture2D *texture);
	~Player();

	void draw();
	void update(int tileSize);
private:

	Rectangle body;
	Texture2D texture;
	int speed;
	float zeroW, zeroH;
	float WIDTH, HEIGHT;

	void checkInput();
	void checkCollision(int tileSize);
};