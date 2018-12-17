#pragma once
#include "Vec2.h"
#include <SDL.h>
#include <string>
#include <functional>
#include "Renderer.h"

class Button
{
private:
	SDL_Rect rect;
	std::string normalID, hoverID;

	bool isHover;

public:

	Button(Vec2&, const std::string&);

	void Render();
	void IsHover(const Vec2&);
	void OnClick(const std::function<void()>& func);

	~Button();
};

