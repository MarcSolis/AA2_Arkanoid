#include "Ball.h"



Ball::Ball()
{
}

Ball::Ball(const int& r, const int& minS, const int& maxS, const std::string& path) : radius(r), minSpeed(minS), maxSpeed(maxS)
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
	CheckGoal();
}

void Ball::CheckGoal()
{
	if (position.x <= FIELD_LEFT)
	{
		firstPlayerHasBall = true;
		scored = true;
	}
	else if (position.x >= SCREEN_WIDTH - FIELD_LEFT - radius * 2)
	{
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
	int speedX = rand() % (maxSpeed - minSpeed + 1) + minSpeed;
	int speedY = rand() % (maxSpeed - minSpeed + 1) + minSpeed;

	if (position.x < SCREEN_WIDTH / 2)
		speedDirection.x = speedX;
	else
		speedDirection.x = -speedX;
	
	int random = rand() % 2;
	if (random == 0)
		speedDirection.y = speedY;
	else
		speedDirection.y = -speedY;
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

SDL_Rect Ball::GetRect()
{
	return rect;
}

Vec2 Ball::GetSpeedDirection()
{
	return speedDirection;
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

void Ball::SetSpeedDirection(const Vec2& speedDir)
{
	speedDirection = speedDir;
}

void Ball::SetRect(const SDL_Rect &r)
{
	rect = r;
}

Ball::~Ball()
{
}
