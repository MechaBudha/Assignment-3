#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"
#include <random>
class Bullet : public Entity
{
	bool _enabled;
	int _direction;
	void movement(float elapsed);
	void OOB();
	
public:
	Bullet(int x, int y, const char* imagePath);
	~Bullet();
	void shoot(int direc, int x, int y);
	void update(float elapsed);
	void disable();
	bool isEnabled();
};
#endif // !BULLET_H

