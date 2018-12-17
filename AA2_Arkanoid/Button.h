#pragma once
#include "Vec2.h"
#include <SDL.h>
#include <string>
#include <functional>
#include "Renderer.h"

class Button
{
private:
	//Atributtes
	SDL_Rect rect;
	std::string normalID, hoverID;

	bool isHover;

public:
	//Constructor
	Button(const Vec2&, const std::string&);
	Button();
	//Functions
	void Render();
	void IsHover(const Vec2&);
	void OnClick(const std::function<void()>& func);
	//Destructor
	~Button();
};

