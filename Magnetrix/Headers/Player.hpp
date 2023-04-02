#pragma once

class Player
{
public:
	Player();
	Player(float zeroW, float zeroH, float WIDTH, float HEIGHT, Rectangle body, Texture2D *texture);
	~Player();

	void draw();
	void update(int tileSize, short dir);
	void setbackPos(short x, short y, float tileSize);
	void getPosInGrid(int x[4], int y[4], float tileSize);
	Rectangle body;
private:

	Texture2D texture;
	int speed;
	int noGravityFrames = 10;
	int nGFcounter;
	bool noGravity;
	float gravity;
	float zeroW, zeroH;
	float WIDTH, HEIGHT; 
	void checkInput();
	void applyGravity();
	void checkCollision(int tileSize);
	void rotate(short direction);
};