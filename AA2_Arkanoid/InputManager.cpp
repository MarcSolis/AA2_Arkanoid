#include "InputManager.h"


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
			esc = (event.key.keysym.sym == SDLK_ESCAPE);
			p = (event.key.keysym.sym == SDLK_p);
			space = (event.key.keysym.sym == SDLK_SPACE);

			w = (event.key.keysym.sym == SDLK_w);
			s = (event.key.keysym.sym == SDLK_s);

			up = (event.key.keysym.sym == SDLK_UP);
			down = (event.key.keysym.sym == SDLK_DOWN);
			break;
		
		default:;
		}
	}
}

//Destructor
InputManager::~InputManager() {}
