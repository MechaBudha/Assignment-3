#include "Game.h"

Game::Game(ALLEGRO_DISPLAY* display) : State(display)
{
	srand(time(0));

	_player = new Player(0, SCREEN_HEIGHT / 2, PLAYER_PATH);
	for (int i = 0; i < CANDIES; i++)
		_candies[i] = new Candy(0, 0, CANDY_PATH);
	_hud = new HUD(_display);

	_gameOver = false;
}

Game::~Game()
{
	if (_player)
		delete _player;
	for (int i = 0; i < CANDIES; i++)
		if (_candies[i])
			delete _candies[i];
	if (_hud)
		delete _hud;
}

void Game::input()
{
	ALLEGRO_EVENT event;
	ALLEGRO_TIMEOUT timeout;
	al_init_timeout(&timeout, TIMEOUT);

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
	float elapsed = al_get_time() - _timeAtLastFrame;
	_timeAtLastFrame = al_get_time();

	_player->update(elapsed);
	for (int i = 0; i < CANDIES; i++)
		_candies[i]->update(elapsed);
}

void Game::draw()
{
	if (_canDraw)
	{
		_canDraw = false;
		al_clear_to_color(al_map_rgba(0, 0, 0, 0));
		
		al_draw_bitmap(_player->getSprite(), _player->getX(), _player->getY(), false);
		for (int i = 0; i < CANDIES; i++)
			if (_candies[i]->isEnabled())
				al_draw_bitmap(_candies[i]->getSprite(), _candies[i]->getX(), _candies[i]->getY(), false);

		_hud->draw();

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