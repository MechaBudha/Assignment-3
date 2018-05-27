#include "Game.h"

Game::Game(ALLEGRO_DISPLAY* display) : State(display)
{
	_gameOver = false;
}

Game::~Game()
{

}

void Game::input()
{
	ALLEGRO_EVENT event;
	ALLEGRO_TIMEOUT timeout;

	al_init_timeout(&timeout, 1);
	
	if (al_wait_for_event_until(_queue, &event, &timeout))
		switch (event.type)
		{
			case ALLEGRO_EVENT_TIMER:
				_canDraw = true;
				break;
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				_gameOver = true;
				break;
		}
}

void Game::update()
{

}

void Game::draw()
{
	if (_canDraw)
	{
		_canDraw = false;
		al_flip_display();
	}
}

void Game::run()
{
	while (!_gameOver)
	{
		input();
		update();
		draw();
	}
}