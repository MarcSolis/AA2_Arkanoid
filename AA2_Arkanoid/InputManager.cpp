#include "InputManager.h"
#include "Common.h"

//Constructor
InputManager::InputManager() {}

//Functions
void InputManager::Update()
{
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		///exit
		case SDL_QUIT:
			esc = true;
			break;

		///mouse input
		case SDL_MOUSEMOTION:
			mousePos = Vec2(event.motion.x, event.motion.y);
			break;

		case SDL_MOUSEBUTTONDOWN:
			mouseClicked = true;
			break;

		case SDL_MOUSEBUTTONUP:
			mouseClicked = false;
			break;

		///keyboard input
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)esc = true;
			if (event.key.keysym.sym == SDLK_p)		p = true;
			if (event.key.keysym.sym == SDLK_SPACE)	space = true;
			if (event.key.keysym.sym == SDLK_w)		w = true;
			if (event.key.keysym.sym == SDLK_s)		s = true;
			if (event.key.keysym.sym == SDLK_UP)	up = true;
			if (event.key.keysym.sym == SDLK_DOWN)	down = true;
			break;
		case SDL_KEYUP:
			if (event.key.keysym.sym == SDLK_ESCAPE)esc = false;
			if (event.key.keysym.sym == SDLK_p)		p = false;
			if (event.key.keysym.sym == SDLK_SPACE)	space = false;
			if (event.key.keysym.sym == SDLK_w)		w = false;
			if (event.key.keysym.sym == SDLK_s)		s = false;
			if (event.key.keysym.sym == SDLK_UP)	up = false;
			if (event.key.keysym.sym == SDLK_DOWN)	down = false;
		default:;
		}
	}
}

//Destructor
InputManager::~InputManager() {}
