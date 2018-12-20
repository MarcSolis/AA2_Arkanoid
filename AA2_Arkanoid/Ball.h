#pragma once
#include "Common.h"
#include "Vec2.h"
#include "Renderer.h"
#include "Player.h"

class Ball
{
private:
	//Atributtes
	int radius;
	int speed;

	bool firstPlayerHasBall = true;
	bool scored = false;

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
	void GoalKick();
	void Render();
	void ApplyInitVelocity();
	void StayOnField();

	int GetRadius();
	bool GetFirstPlayerHasBall();
	bool GetScored();
	void SetScored(const bool&);
	void SetInitPosition(const Vec2&);
	//Destructor
	~Ball();
};

