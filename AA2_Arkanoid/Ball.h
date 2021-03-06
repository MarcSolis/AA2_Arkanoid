#pragma once
#include "Common.h"
#include "Vec2.h"
#include "Renderer.h"

class Ball
{
private:
	//Atributtes
	int radius;
	int minSpeed, maxSpeed;

	bool firstPlayerHasBall = true;
	bool scored = false;

	std::string ballID;

	Vec2 position;
	Vec2 speedDirection;
	Rect rect;

public:
	//Constructor
	Ball();
	Ball(const int&, const int&, const int&, const std::string&);

	//Functions
	void Update();
	void CheckGoal();
	void Render();
	void ApplyInitVelocity();
	void StayOnField();

	int GetRadius();
	bool GetFirstPlayerHasBall();
	bool GetScored();
	Rect GetRect();
	Vec2 GetSpeedDirection();
	void SetScored(const bool&);
	void SetInitPosition(const Vec2&);
	void SetSpeedDirection(const Vec2&);
	void SetRect(const Rect&);
	//Destructor
	~Ball();
};

