#include "pch.hpp"
#include "Player.hpp"

Player::Player() : body(Rectangle())
{
}

Player::Player(Rectangle body, Texture2D *texture) :
	body(body), texture(*texture)
{
}

Player::~Player()
{
}

void Player::update()
{
}
