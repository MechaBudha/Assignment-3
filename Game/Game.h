#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include "State.h"
#include "Player.h"
#include "Candy.h"
#include "HUD.h"

class Game : public State
{
private:
	Player* _player;
	Candy* _candies[CANDIES];
	HUD* _hud;

	bool _gameOver;

protected:
	void input();
	void update();
	void draw();

public:
	Game(ALLEGRO_DISPLAY* display);
	~Game();

	void run();
};

#endif
