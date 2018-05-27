#ifndef CANDY_H
#define CANDY_H

#include "Entity.h"

class Candy : public Entity
{
private:
	bool _enabled;
	float _spawnTime;
	float _onScreenTime;

public:
	Candy(float x, float y, const char* imagePath);
	~Candy();

	void update(float elapsed);
	void disable();
	void respawn();

	inline bool isEnabled() { return _enabled; }
};

#endif
