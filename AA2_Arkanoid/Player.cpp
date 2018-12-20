#include "Player.h"



Player::Player()
{

}

Player::Player(const int &playerTag, const int &playerSpeed, const std::string &path) : tag(playerTag)
{
	playerID = "Player" + playerTag;
	Renderer::Instance()->LoadTexture(playerID, path);

	speed = 10;

	if (tag == 1)
		position = Vec2{int(SCREEN_WIDTH * 0.1f), SCREEN_HEIGHT / 2};
	else if(tag == 2)
		position = Vec2{ int(SCREEN_WIDTH * 0.8f), SCREEN_HEIGHT / 2};

	dimensions = Vec2{60, 20};
	rect = SDL_Rect{ position.x, position.y, dimensions.x, dimensions.y };
}

void Player::Update(const InputManager &input, Ball &b)
{
	if (tag == 1)
	{
		//std::cout << input.mousePos.x << std::endl;
		if (input.w)
			position.y -= speed;
		else if (input.s)
			position.y += speed;
	}
	else if (tag == 2)
	{
		if (input.up)
			position.y -= speed;
		else if (input.down)
			position.y += speed;
	}
	StayOnField();
	rect = SDL_Rect{ position.x, position.y, rect.w, rect.h };

	DetectBallCollision(b);
}

void Player::DetectBallCollision(Ball &b)
{
	if (b.GetRect().y < rect.y + rect.w - rect.h && b.GetRect().y + b.GetRect().h > rect.y - rect.h &&
		b.GetRect().x < rect.x + rect.h * 2 && b.GetRect().x + b.GetRect().w > rect.x + rect.h)
	{	
			Vec2 ballSpeedDirection = b.GetSpeedDirection();
			ballSpeedDirection.x *= -1;
			b.SetSpeedDirection(ballSpeedDirection);
	}
}

void Player::Render()
{
	Renderer::Instance()->PushRotatedImage(playerID, rect, 90);
}

void Player::StayOnField()
{
	if (position.y < FIELD_TOP + dimensions.y)
		position.y = FIELD_TOP +  dimensions.y;
	else if (position.y > FIELD_BOTTOM - 2 * dimensions.y)
		position.y = FIELD_BOTTOM - 2 * dimensions.y;
}

Vec2 Player::ReturnInitBallPosition()
{
	Vec2 pos;
	if (tag == 1)
		pos = Vec2{position.x + dimensions.x, position.y + dimensions.y / 2};
	else if(tag == 2)
		pos = Vec2{ position.x , position.y + dimensions.y / 2 };

	return pos;
}


Player::~Player()
{
}