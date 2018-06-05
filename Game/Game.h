#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include "State.h"
#include "Player.h"
#include "Candy.h"
#include "Bomb.h"
#include "HUD.h"
#include "Bullet.h"

class Game : public State
{
private:
	Player* _player;
	Candy* _candies[CANDIES];
	Bomb* _bombs[BOMBS];
	Bullet* _bullets[BULLETS];
	HUD* _hud;

	bool _gameOver;
	int _score;

protected:
	void input();
	void update();
	void draw();

	bool collide(Entity* a, Entity* b);
	void playerCandyCollision(Player* p, Candy* c);
	void playerBombCollision(Player* p, Bomb* b);
	void bulletBombCollision(Bullet* a, Bomb* b);

public:
	Game(ALLEGRO_DISPLAY* display);
	~Game();

	void run();
};

#endif
