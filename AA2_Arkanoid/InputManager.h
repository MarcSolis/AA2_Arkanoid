#pragma once
#include "Vec2.h"
#include <SDL.h>

class InputManager
{

public:

//Atributes
	SDL_Event event;
	///mouse
	Vec2 mousePos;
	bool mouseClicked;
	///keyboard
	bool up, down;
	bool w, s;
	bool p, esc, space;


//Constructor
	InputManager();

//Function
	void Update();

//Desctructor
	~InputManager();
};

