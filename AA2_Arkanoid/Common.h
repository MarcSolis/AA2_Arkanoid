#pragma once
#include <SDL.h>
#include <time.h>

// Game general information.
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define MATCH_TIME 60

const int FPS = 60;
const float DELAY_TIME = 1000.0f / FPS;

enum SceneType { SPLASHSCREEN, MENU, GAME, RANKING, CURRENT };