#include "Ball.h"



Ball::Ball()
{
}

Ball::Ball(const int& r, const int& s, const std::string& path) : radius(r), speed(s)
{
	ballID = "Ball";
	Renderer::Instance()->LoadTexture(ballID, path);

	position = Vec2{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	speedDirection = Vec2{ 0,0 };
	rect = SDL_Rect{position.x, position.y, 2*radius, 2*radius};
}

void Ball::Update()
{
}

void Ball::GoalKick(const int & = 1)
{
}

void Ball::Render()
{
	Renderer::Instance()->PushImage(ballID, rect);
}


Ball::~Ball()
{
}
