#include "HUD.h"

HUD::HUD(ALLEGRO_DISPLAY* display)
{
	_display = display;
	_font = al_load_font(FONT_PATH, HUD_FONT_SIZE, false);
	_scoreText = "Score: 0";
}

HUD::~HUD()
{
	al_destroy_font(_font);
}

void HUD::update(Element element, int amount)
{
	switch (element)
	{
		case Score:
			_scoreText = "Score: " + to_string(amount);
			break;
	}
}

void HUD::draw()
{
	al_draw_text(_font, al_map_rgb_f(HUD_YELLOW), 0, 10, ALLEGRO_ALIGN_LEFT, _scoreText.c_str());
}