#pragma once
#include "Common.h"
#include "Ball.h"
#include "Renderer.h"
#include "InputManager.h"

class Player
{
private:
	//Atributes
	int tag;
	int speed;

	std::string playerID;

	Vec2 position;
	Vec2 dimensions;
	int speedDirection;
	SDL_Rect rect;

public:
	//Constructor
	Player();
	Player(const int&, const int&, const std::string&);

	//Functions
	void Update(const InputManager &);
	void DetectBallCollision(Ball &);
	void Render();

	//Destructor
	~Player();
};