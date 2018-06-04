#ifndef BOMB_H
#define BOMB_H

#include "Entity.h"
#include <random>

class Bomb : public Entity
{
private:
	bool _enabled;
	float _spawnTime;
	float _onScreenTime;
	int _direction;
	void movement(float elapsed);
	void OOB();
public:
	Bomb(int x, int y, const char* imagePath);
	~Bomb();

	void update(float elapsed);
	void disable();
	void respawn();

	inline bool isEnabled() { return _enabled; }
};

#endif
