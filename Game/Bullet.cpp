#include "Bullet.h"



Bullet::Bullet(int x, int y, const char* imagePath) : Entity(x,y,imagePath)
{
	disable();
	_direction = 0;
}

Bullet::~Bullet()
{
}

void Bullet::disable() {
	_enabled = false;
}

void Bullet::update(float elapsed) {
	if (_enabled)
	{
		movement(elapsed);
		OOB();
	}
}

void Bullet::movement(float elapsed){
	switch (_direction)
	{
	case MOV_DIREC_UP:
		_y -= BULLET_SPEED * elapsed;
		break;
	case MOV_DIREC_RIGHT:
		_x += BULLET_SPEED * elapsed;
		break;
	case MOV_DIREC_DOWN:
		_y += BULLET_SPEED * elapsed;
		break;
	case MOV_DIREC_LEFT:
		_x -= BULLET_SPEED * elapsed;
		break;
	default:
		_x += BULLET_SPEED * elapsed;
		break;
	}
}

void Bullet::OOB() {
	if (_x <= 0 || _x + BULLET_WIDTH >= SCREEN_WIDTH || _y<= 0 || _y + BULLET_HEIGHT >= SCREEN_HEIGHT){
		disable();
		_x = 0;
		_y = 0;
	}
}

void Bullet::shoot(int direc, int x, int y) {
	_direction = direc;
	_x = x - (BULLET_WIDTH /2);
	_y = y - (BULLET_HEIGHT /2);
	_enabled = true;
}

bool Bullet::isEnabled() {
	return _enabled;
}
