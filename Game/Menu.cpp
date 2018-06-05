#include "Menu.h"

Menu::Menu(bool &jugarSalir, ALLEGRO_DISPLAY* display) : State(display)
{
	_title = GAME_NAME;
	_instructionsEnter = "Presione enter para jugar.";
	_instructionsExit = "Presione escape para salir.";
	_font = al_load_font(FONT_PATH, HUD_FONT_SIZE, false);

	al_clear_to_color(al_map_rgba(0, 0, 0, 0));

	al_draw_text(_font, al_map_rgb_f(HUD_RED), SCREEN_WIDTH / 2, 10, ALLEGRO_ALIGN_CENTER, _title.c_str());
	al_draw_text(_font, al_map_rgb_f(HUD_YELLOW), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, ALLEGRO_ALIGN_CENTER, _instructionsEnter.c_str());
	al_draw_text(_font, al_map_rgb_f(HUD_YELLOW), SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + (HUD_FONT_SIZE * 2), ALLEGRO_ALIGN_CENTER, _instructionsExit.c_str());

	al_flip_display();

	bool esperando = true;

	while (esperando) {
		ALLEGRO_KEYBOARD_STATE keyState;
		al_get_keyboard_state(&keyState);

		if (al_key_down(&keyState, ALLEGRO_KEY_ENTER)) { esperando = false; jugarSalir = true; }
		if (esperando) { if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE)) { esperando = false; jugarSalir = false; } }
	}

	al_clear_to_color(al_map_rgba(0, 0, 0, 0));
	al_flip_display();
}


Menu::~Menu()
{
	al_destroy_font(_font);
}


void Menu::draw() {}
void Menu::input() {}
void Menu::update() {}
