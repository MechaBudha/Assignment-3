#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

enum Direction
{
	Left, Right, Up, Down
};

class Player : public Entity
{
private :
	float _speed;

	void move(Direction direction, float elapsed);

public:
	Player(float x, float y, const char* imagePath);
	~Player();

	void update(float elapsed);
};

#endif
