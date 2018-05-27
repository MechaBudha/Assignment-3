#include "Player.h"

Player::Player(float x, float y, const char* imagePath) : Entity(x, y , imagePath)
{
	_speed = PLAYER_SPEED;
}

Player::~Player()
{

}

void Player::move(Direction direction)
{
	switch (direction)
	{
		case Left:
			if (_x > PLAYER_MIN_X)
				_x -= _speed;
			break;
		case Right:
			if (_x + PLAYER_WIDTH < PLAYER_MAX_X)
				_x += _speed;
			break;
		case Up:
			if (_y > PLAYER_MIN_Y)
				_y -= _speed;
			break;
		case Down:
			if (_y + PLAYER_HEIGHT < PLAYER_MAX_Y)
				_y += _speed;
			break;
	}
}