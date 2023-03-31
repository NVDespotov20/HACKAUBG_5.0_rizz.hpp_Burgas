#pragma once

class Player
{
public:
	Player();
	Player(Rectangle body, Texture2D *texture);
	~Player();
	void update();
private:
	Rectangle body;
	Texture2D texture;

};