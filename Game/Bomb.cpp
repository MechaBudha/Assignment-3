#include "Bomb.h"

Bomb::Bomb(int x, int y, const char* imagePath) : Entity(x, y, imagePath)
{
	disable();
	_spawnTime = rand() % (BOMB_MAX_SPAWN_TIME - BOMB_MIN_SPAWN_TIME + 1) + BOMB_MIN_SPAWN_TIME;
	_onScreenTime = rand() % (BOMB_MAX_DURATION - BOMB_MIN_DURATION + 1) + BOMB_MIN_DURATION;
	_direction = rand() % (BOMB_DIREC_MAX - BOMB_DIREC_MIN + 1);
}

Bomb::~Bomb()
{

}

void Bomb::update(float elapsed)
{
	if (_enabled)
	{
		_onScreenTime -= elapsed;
		movement(elapsed);
		if (_onScreenTime <= 0)
			disable();
	}
	else
	{
		_spawnTime -= elapsed;
		if (_spawnTime <= 0)
			respawn();
	}
}

void Bomb::disable()
{
	_enabled = false;
}

void Bomb::respawn()
{
	_enabled = true;
	_spawnTime = rand() % (BOMB_MAX_SPAWN_TIME - BOMB_MIN_SPAWN_TIME + 1) + BOMB_MIN_SPAWN_TIME;
	_onScreenTime = rand() % (BOMB_MAX_DURATION - BOMB_MIN_DURATION + 1) + BOMB_MIN_DURATION;
	_x = rand() % (BOMB_MAX_X - BOMB_MIN_X - BOMB_WIDTH + 1) + BOMB_MIN_X;
	_y = rand() % (BOMB_MAX_Y - BOMB_MIN_Y - BOMB_HEIGHT + 1) + BOMB_MIN_Y;
	_direction = rand() % (BOMB_DIREC_MAX - BOMB_DIREC_MIN + 1);
}

void Bomb::movement(float elapsed) {
	switch (_direction)
	{
	case BOMB_DIREC_UP:
		_y -= BOMB_MOV_SPEED * elapsed;
		break;
	case BOMB_DIREC_RIGHT:
		_x += BOMB_MOV_SPEED * elapsed;
		break;
	case BOMB_DIREC_DOWN:
		_y += BOMB_MOV_SPEED * elapsed;
		break;
	case BOMB_DIREC_LEFT:
		_x -= BOMB_MOV_SPEED * elapsed;
		break;
	default:
		break;
	}
	OOB();
}

void Bomb::OOB() {
	if (_x <= BOMB_MIN_X || _x + BOMB_WIDTH >= BOMB_MAX_X || _y <= BOMB_MIN_Y || _y + BOMB_HEIGHT >= BOMB_MAX_Y)
	{
		switch (_direction)
		{
		case BOMB_DIREC_UP:
			_direction = BOMB_DIREC_DOWN;
			break;
		case BOMB_DIREC_RIGHT:
			_direction = BOMB_DIREC_LEFT;
			break;
		case BOMB_DIREC_DOWN:
			_direction = BOMB_DIREC_UP;
			break;
		case BOMB_DIREC_LEFT:
			_direction = BOMB_DIREC_RIGHT;
			break;
		default:
			_direction = 0;
			break;
		}
	}
}