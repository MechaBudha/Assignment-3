#ifndef ENTITY_H
#define ENTITY_H

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "Definitions.h"

class Entity
{
protected:
	ALLEGRO_BITMAP* _sprite;

	float _x;
	float _y;

public:
	Entity(float x, float y, const char* imagePath);
	~Entity();
	
	ALLEGRO_BITMAP* getSprite() { return _sprite; }
	inline float getX() { return _x; }
	inline float getY() { return _y; }
};

#endif
