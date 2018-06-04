#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// Display Settings
#define GAME_NAME "The Gluttonous of Rhodes"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FRAME_TIME 1.0 / 60
#define TIMEOUT 1.0 / 120

// Player Attributes
#define PLAYER_WIDTH 64
#define PLAYER_HEIGHT 64
#define PLAYER_MIN_X 32
#define PLAYER_MAX_X 768
#define PLAYER_MIN_Y 64
#define PLAYER_MAX_Y 568
#define PLAYER_SPEED 300
#define PLAYER_LIVES 3

// Candy Attributes
#define CANDIES 10
#define CANDY_SCORE 5
#define CANDY_WIDTH 32
#define CANDY_HEIGHT 16
#define CANDY_MIN_X 32
#define CANDY_MAX_X 768
#define CANDY_MIN_Y 64
#define CANDY_MAX_Y 568
#define CANDY_MIN_SPAWN_TIME 2
#define CANDY_MAX_SPAWN_TIME 7
#define CANDY_MIN_DURATION 3
#define CANDY_MAX_DURATION 5

// Bomb Attributes
#define BOMBS 3
#define BOMB_WIDTH 32
#define BOMB_HEIGHT 32
#define BOMB_MIN_X 32
#define BOMB_MAX_X 768
#define BOMB_MIN_Y 64
#define BOMB_MAX_Y 568
#define BOMB_MIN_SPAWN_TIME 5
#define BOMB_MAX_SPAWN_TIME 10
#define BOMB_MIN_DURATION 5
#define BOMB_MAX_DURATION 7
#define BOMB_DIREC_UP 1
#define BOMB_DIREC_RIGHT 2
#define BOMB_DIREC_DOWN 3
#define BOMB_DIREC_LEFT 4
#define BOMB_DIREC_MIN BOMB_DIREC_UP
#define BOMB_DIREC_MAX BOMB_DIREC_LEFT
#define BOMB_MOV_SPEED 150

// HUD Attributes
#define HUD_FONT_SIZE 24
#define HUD_YELLOW 0.6, 0.45, 0.1
#define HUD_RED 0.95, 0.15, 0.15

// Image Paths
#define PLAYER_PATH "Assets/Images/Player.png"
#define CANDY_PATH "Assets/Images/Candy.png"
#define BOMB_PATH "Assets/Images/Bomb.png"
#define ICON_PATH "Assets/Images/Icon.png"

// Font Paths
#define FONT_PATH "Assets/Fonts/Candy Shop Black.ttf"

#endif
