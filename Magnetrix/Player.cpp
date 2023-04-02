#include "pch.hpp"
#include "Player.hpp"

Player::Player() :
	zeroW(0), zeroH(0), WIDTH(0), HEIGHT(0),
	body(Rectangle()), texture(Texture2D()), speed(3), gravity(10.f), noGravity(false), nGFcounter(0)
{
}

Player::Player(float zeroW, float zeroH, float WIDTH, float HEIGHT, Rectangle body, Texture2D* texture) :
	zeroW(zeroW), zeroH(zeroH), WIDTH(WIDTH), HEIGHT(HEIGHT),
	body(body), speed(3), gravity(10.f), noGravity(false), nGFcounter(0)
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
	applyGravity();
	checkCollision(tileSize);
	rotate(dir);
}

void Player::setbackPos(short x, short y, float tileSize)
{
	std::cout << body.x - zeroW << ", " << body.y - zeroH << "\n";
	 if (body.x + body.width - zeroW > x * tileSize)
		body.x = x * tileSize  -body.width + zeroW;
	 else if(body.x - zeroW < (x+1) * tileSize  + 50)
		body.x = (x+1) * tileSize + zeroW+50;

	/*if (body.y + body.height - zeroW > y * tileSize)
		body.y = y * tileSize - tileSize + zeroH - body.height - 2;
	else
		body.y = y * tileSize + tileSize + zeroH + 2;*/
}

void Player::getPosInGrid(int x[4], int y[4], float tileSize)
{
	x[0] = floor((body.x - zeroW + .1f * body.width) / tileSize);
	y[0] = floor((body.y - zeroH + .1f * body.height) / tileSize);

	x[1] = ceil((body.x - zeroW + .1f * body.width) / tileSize);
	y[1] = floor((body.y - zeroH + .1f * body.height) / tileSize);

	x[2] = floor((body.x - zeroW + .1f * body.width) / tileSize);
	y[2] = ceil((body.y - zeroH + .1f * body.height) / tileSize);

	x[3] = ceil((body.x - zeroW + .1f * body.width) / tileSize);
	y[3] = ceil((body.y - zeroH + .1f * body.height) / tileSize);
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

void Player::applyGravity()
{
	if (noGravity)
		++nGFcounter;
	else
		body.y += gravity;

	if (noGravity && nGFcounter == noGravityFrames)
	{
		noGravity = false;
		nGFcounter = 0;
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
	if (!dir)
		return;
	noGravity = true;
	nGFcounter = 1;

	static short orientation = 3;

	orientation += dir;
	if (orientation == 4) orientation = 0;
	else if (orientation == -1) orientation = 3;
	if (dir == RIGHT)
	{
		Vector2 n = { (zeroH + HEIGHT) - (body.y + body.height) + zeroW, body.x - zeroW + zeroH };
		switch (orientation)
		{
		case 1:
			n = { (zeroH + HEIGHT) - (body.y + body.width) + zeroW, body.x - zeroW + zeroH };
			break;

		case 2:
			n = { (zeroH + HEIGHT) - (body.y + body.width) + zeroW, body.x - body.width - zeroW + zeroH };
			break;

		case 3:
			n = { (zeroH + HEIGHT) - (body.y + body.height) + zeroW, body.x - body.width - zeroW + zeroH };
			break;
		}

		body = Rectangle{ n.x, n.y, body.width, body.height };
		return;
	}

	Vector2	n = { body.y - zeroH + zeroW, (zeroW + WIDTH) - (body.x + body.width) + zeroH };

	switch (orientation)
	{
	case 1:
		n = { body.y - zeroH + body.width + zeroW, (zeroW + WIDTH) - (body.x + body.width) + zeroH };
		break;

	case 2:
		n = { body.y - zeroH + body.width + zeroW, (zeroW + WIDTH) - (body.x + body.height) + zeroH };
		break;

	case 3:
		n = { body.y - zeroH + zeroW, (zeroW + WIDTH) - (body.x + body.height) + zeroH };
		break;
	}
	body = Rectangle{ n.x, n.y, body.width, body.height };
}

