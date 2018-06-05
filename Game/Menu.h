#ifndef MENU_H
#define MENU_H

#include "State.h"
#include "Definitions.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <string>
using namespace std;

class Menu : public State
{
	string _title;
	string _instructionsEnter;
	string _instructionsExit;

	ALLEGRO_FONT* _font;

	void input();
	void update();
	void draw();
public:
	Menu(bool &jugarSalir, ALLEGRO_DISPLAY* display);
	~Menu();
};

#endif // !MENU_H
