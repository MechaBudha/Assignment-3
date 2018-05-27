#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// Display Settings
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

// Candy Attributes
#define CANDIES 10
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

// Image Paths
#define PLAYER_PATH "Assets/Images/Player.png"
#define CANDY_PATH "Assets/Images/Candy.png"

#endif
