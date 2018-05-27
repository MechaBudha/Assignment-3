#ifndef GAME_H
#define GAME_H

#include "State.h"
#include "Player.h"

class Game : public State
{
private:
	Player* _player;
	
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
