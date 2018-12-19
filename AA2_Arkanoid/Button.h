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
	std::string normalID, hoverID, normalID2, hoverID2;

	bool isHover;
	bool activated; //En el cas del sound té dos estats que es poden representar amb un bool


public:
	//Constructor
	Button(const Vec2&, const std::string&, const std::string&, const SDL_Color& = WHITE, const SDL_Color& = LIGHTBLUE); //Constructor per botó de un sol estat
	Button(const Vec2&, const std::string&, const std::string&, const std::string&, const SDL_Color& = WHITE, const SDL_Color& = LIGHTBLUE); //Constructor per botó de dos estats
	Button();
	//Functions
	void Render();
	void IsHover(const Vec2&);
	void OnClick(const bool&, const std::function<void()>&); ///El bool sirve para determinar si el botón tiene un solo estado o dos 
	static void Destroy(Button&);
	//Destructor
	~Button();
};

