#pragma once
#include <SDL.h>
#include <time.h>
#include <iostream>

// Game general information.
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MATCH_TIME 60

const int FPS = 60;
const float DELAY_TIME = 1000.0f / FPS;

enum SceneType { SPLASHSCREEN, MENU, GAME, RANKING, CURRENT };