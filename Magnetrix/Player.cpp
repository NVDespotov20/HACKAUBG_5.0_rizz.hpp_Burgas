#include "pch.hpp"
#include "Player.hpp"

Player::Player() : 
	body(Rectangle()), texture(Texture2D()), speed(3), zeroW(0), zeroH(0), WIDTH(0), HEIGHT(0)
{
}

Player::Player(float zeroW, float zeroH, float WIDTH, float HEIGHT, Rectangle body, Texture2D* texture) :
	zeroW(zeroW), zeroH(zeroH), WIDTH(WIDTH), HEIGHT(HEIGHT), body(body), speed(3), gravity(1.5f)
{                             
	if (texture)
		this->texture = *texture;
	else
		this->texture = Texture();
}

Player::~Player()
{
}

void Player::update(int tileSize, short dir)
{
	checkInput();
	body.y += gravity;
	checkCollision(tileSize);
	rotate(dir);
}

void Player::draw()
{
	DrawRectangleRec(body, PURPLE);
}

void Player::checkInput()
{
	if (IsKeyDown(KEY_A)) 
	{
		body.x -= GetFrameTime() * body.width * speed;
		return;
	}
	if (IsKeyDown(KEY_D))
	{
		body.x += GetFrameTime() * body.width * speed;
		return;
	}
}

void Player::checkCollision(int tileSize)
{
	if (body.x < zeroW)
		body.x = zeroW;
	else if (body.x + body.width > zeroW + WIDTH)
		body.x = zeroW + WIDTH - body.width;

	if (body.y < zeroH)
		body.y = zeroH;
	else if (body.y + body.height > zeroH + HEIGHT)
		body.y = zeroH + HEIGHT - body.height;
}

void Player::rotate(short dir)
{
	if (dir == NO_ROTATE)
		return;

	if (dir == RIGHT)
	{
		Vector2 n = { (zeroH + HEIGHT) - (body.y + body.height) + zeroW, body.x - zeroW + zeroH };
		body = Rectangle{n.x, n.y, body.height, body.width };
		return;
	}
	Vector2 n = { body.y - zeroH + zeroW, (zeroW + WIDTH) - (body.x + body.width) + zeroH};
	body = Rectangle{ n.x, n.y, body.height, body.width };
}

