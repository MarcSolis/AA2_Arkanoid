#include "Ball.h"



Ball::Ball()
{
}

Ball::Ball(const int& r, const int& s, const std::string& path) : radius(r), speed(s)
{
	ballID = "Ball";
	Renderer::Instance()->LoadTexture(ballID, path);

	firstPlayerHasBall = false;

	position = Vec2{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	speedDirection = Vec2{ 0,0 };
	rect = SDL_Rect{position.x, position.y, 2*radius, 2*radius};
}

void Ball::Update()
{
	position = Vec2{position.x + speedDirection.x, position.y + speedDirection.y};

	rect = SDL_Rect{ position.x, position.y, rect.w, rect.h};
	
	StayOnField();
	GoalKick();
}

void Ball::GoalKick()
{
	if (position.x <= FIELD_LEFT)
	{
		std::cout << "Player 2 scored" << std::endl;
		firstPlayerHasBall = true;
		scored = true;
	}
	else if (position.x >= SCREEN_WIDTH - FIELD_LEFT - radius * 2)
	{
		std::cout << "Player 1 scored" << std::endl;
		firstPlayerHasBall = false;
		scored = true;
	}
}

void Ball::Render()
{
	Renderer::Instance()->PushImage(ballID, rect);
}

void Ball::ApplyInitVelocity()
{
	if (position.x < SCREEN_WIDTH / 2)
		speedDirection.x = speed;
	else
		speedDirection.x = -speed;

	int random = rand() % 2;
	if (random == 0)
		speedDirection.y = speed;
	else
		speedDirection.y = -speed;
}

void Ball::StayOnField()
{
	if (position.y < FIELD_TOP)
	{
		position.y = FIELD_TOP;
		speedDirection.y *= -1;
	}
	else if (position.y > FIELD_BOTTOM - 2 * radius)
	{
		position.y = FIELD_BOTTOM - 2 * radius;
		speedDirection.y *= -1;
	}
}

int Ball::GetRadius()
{
	return radius;
}

bool Ball::GetFirstPlayerHasBall()
{
	return firstPlayerHasBall;
}

bool Ball::GetScored()
{
	return scored;
}

void Ball::SetScored(const bool &s)
{
	scored = s;
}

void Ball::SetInitPosition(const Vec2& pos)
{
	position = pos;
	position = Vec2{ position.x, position.y - radius };
	rect = SDL_Rect{ position.x, position.y, rect.w, rect.h };
}

Ball::~Ball()
{
}
