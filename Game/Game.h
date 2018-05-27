#ifndef GAME_H
#define GAME_H

#include "State.h"

class Game : public State
{
private:
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
