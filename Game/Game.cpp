#include "Game.h"

Game::Game(ALLEGRO_DISPLAY* display) : State(display)
{
	_player = new Player(0, SCREEN_HEIGHT / 2, PLAYER_PATH);

	_gameOver = false;
}

Game::~Game()
{
	delete _player;
}

void Game::input()
{
	ALLEGRO_EVENT event;
	ALLEGRO_TIMEOUT timeout;
	ALLEGRO_KEYBOARD_STATE keyState;
	al_init_timeout(&timeout, TIMEOUT);
	al_get_keyboard_state(&keyState);

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

	if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
		_player->move(Left);
	if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
		_player->move(Right);
	if (al_key_down(&keyState, ALLEGRO_KEY_UP))
		_player->move(Up);
	if (al_key_down(&keyState, ALLEGRO_KEY_DOWN))
		_player->move(Down);
}

void Game::update()
{

}

void Game::draw()
{
	if (_canDraw)
	{
		_canDraw = false;
		al_clear_to_color(al_map_rgba(0, 0, 0, 0));
		al_draw_bitmap(_player->getSprite(), _player->getX(), _player->getY(), 0);		
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