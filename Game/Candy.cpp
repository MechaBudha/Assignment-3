#include "Candy.h"

Candy::Candy(int x, int y, const char* imagePath) : Entity(x, y, imagePath)
{
	disable();
	_spawnTime = rand() % (CANDY_MAX_SPAWN_TIME - CANDY_MIN_SPAWN_TIME + 1) + CANDY_MIN_SPAWN_TIME;
	_onScreenTime = rand() % (CANDY_MAX_DURATION - CANDY_MIN_DURATION + 1) + CANDY_MIN_DURATION;
}

Candy::~Candy()
{

}

void Candy::update(float elapsed)
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

void Candy::disable()
{
	_enabled = false;
}

void Candy::respawn()
{
	_enabled = true;
	_spawnTime = rand() % (CANDY_MAX_SPAWN_TIME - CANDY_MIN_SPAWN_TIME + 1) + CANDY_MIN_SPAWN_TIME;
	_onScreenTime = rand() % (CANDY_MAX_DURATION - CANDY_MIN_DURATION + 1) + CANDY_MIN_DURATION;
	_x = rand() % (CANDY_MAX_X - CANDY_MIN_X - CANDY_WIDTH + 1) + CANDY_MIN_X;
	_y = rand() % (CANDY_MAX_Y - CANDY_MIN_Y - CANDY_HEIGHT + 1) + CANDY_MIN_Y;
}