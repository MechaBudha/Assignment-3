#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Game.h"
#include "Definitions.h"
using namespace std;

int main(int argc, char** argv)
{
	ALLEGRO_DISPLAY* display;
	Game* game;

	if (!al_init())
	{
		cerr << "Error initializing Allegro." << endl;
		return 1;
	}

	display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!display)
	{
		cerr << "Error creating display." << endl;
		return 1;
	}

	if (!al_install_keyboard())
	{
		cerr << "Error installing keyboard." << endl;
		return 1;
	}

	if (!al_init_image_addon())
	{
		cerr << "Error initializing Allefro Image." << endl;
		return 1;
	}

	game = new Game(display);
	game->run();

	al_destroy_display(display);
	al_uninstall_keyboard();
	return 0;
}