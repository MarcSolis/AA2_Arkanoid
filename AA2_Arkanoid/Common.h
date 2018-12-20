#pragma once
#include <SDL.h>
#include <time.h>
#include <iostream>
#include <SDL_mixer.h>

// Game general information.
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FIELD_TOP 26
#define FIELD_BOTTOM 470
#define FIELD_LEFT 30
#define FIELD_RIGHT 570
#define MATCH_TIME 60
#define DEFAULT_BLOCK_WIDTH 10
#define DEFAULT_BLOCK_HEIGHT 40

#define PLAYER1X FIELD_LEFT + 5
#define PLAYER2X FIELD_RIGHT - 5
#define PLAYERY (FIELD_BOTTOM - FIELD_TOP) / 2

const int FPS = 60;
const float DELAY_TIME = 1000.0f / FPS;

const Uint8 mixFlags{ MIX_INIT_MP3 | MIX_INIT_OGG };

enum SceneType { SPLASHSCREEN, MENU, GAME, RANKING, CURRENT, EXIT };

enum Type { FIX, HEAVY, NORMAL, NONE };
struct Color { int r, g, b, a; };

const Color BROWN{ 85, 42, 0, 255 };
const Color RED{ 255, 0, 0, 255 };
const Color GREEN{ 0, 255, 0, 255 };
const Color TRANSPARENT{ 0, 0, 0, 0 };

const SDL_Color WHITE{ 255, 255, 255, 255 };
const SDL_Color LIGHTBLUE{ 100, 100, 255, 255 };
const SDL_Color GOLD{ 255,215,0,255 };
const SDL_Color SILVER{ 192,192,192,255 };
const SDL_Color BRONZE{ 205, 127, 50,255 };
