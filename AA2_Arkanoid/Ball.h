#pragma once
#include "Common.h"
#include "Vec2.h"
#include "Renderer.h"

class Ball
{
private:
	//Atributtes
	int radius;
	int speed;

	std::string ballID;

	Vec2 position;
	Vec2 speedDirection;
	SDL_Rect rect;

public:
	//Constructor
	Ball();
	Ball(const int&, const int&, const std::string&);

	//Functions
	void Update();
	void GoalKick(const int&);
	void Render();

	//Destructor
	~Ball();
};

