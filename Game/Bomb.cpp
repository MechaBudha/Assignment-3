#include "Bomb.h"

Bomb::Bomb(int x, int y, const char* imagePath) : Entity(x, y, imagePath)
{
	disable();
	_spawnTime = rand() % (BOMB_MAX_SPAWN_TIME - BOMB_MIN_SPAWN_TIME + 1) + BOMB_MIN_SPAWN_TIME;
	_onScreenTime = rand() % (BOMB_MAX_DURATION - BOMB_MIN_DURATION + 1) + BOMB_MIN_DURATION;
}

Bomb::~Bomb()
{

}

void Bomb::update(float elapsed)
{
	if (_enabled)
	{
		_onScreenTime -= elapsed;
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
}