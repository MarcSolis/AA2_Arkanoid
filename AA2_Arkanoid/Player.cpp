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
		position = Vec2{ int(SCREEN_WIDTH * 0.9f), SCREEN_HEIGHT / 2};

	dimensions = Vec2{60, 10};
	rect = SDL_Rect{ position.x, position.y, dimensions.x, dimensions.y };
	std::cout << "CREATED PLAYER" << std::endl;
}



//Player::Player(const int &tag)
//{
//	Renderer::Instance()->LoadTexture("Player", "../res/platform.png");
//	Vec2 size = Renderer::Instance()->GetTextureSize("Player");
//	pos.w = size.x;
//	pos.h = size.y;
//	switch (tag) {
//		//Start position of PJ1
//	case 1:
//		pos.x = PLAYER1X;
//		pos.y = PLAYERY;
//		break;
//		//Start position of PJ2
//	case 2:
//		pos.x = PLAYER2X;
//		pos.y = PLAYERY;
//		break;
//		//In case of error, put the extra players out
//	default:
//		pos.x = -1 - pos.w;
//		pos.y = -1 - pos.h;
//	}
//}


//void Player::Update()//Ball &ball)
//{
//	//Movement
//	if (direction == UP) pos.y - speed > FIELD_TOP ? pos.y -= speed : pos.y = FIELD_TOP;
//	else if (direction == DOWN) pos.y + speed < FIELD_BOTTOM ? pos.y += speed : pos.y = FIELD_BOTTOM;
//	direction = IDLE;
//	//DetectBallCollision(ball);
//
//
//	Renderer::Instance()->PushRotatedSprite("Player", pos, pos, 90.0f);
//}

void Player::Update(const InputManager &input)
{
	if (tag == 1)
	{
		if (input.w)
			rect.y -= speed;
		else if (input.s)
			rect.y += speed;
	}
	else if (tag == 2)
	{
		if (input.up)
			rect.y -= speed;
		else if (input.down)
			rect.y += speed;
	}
}

void Player::DetectBallCollision(Ball &)
{
}

void Player::Render()
{
	Renderer::Instance()->PushRotatedSprite(playerID, rect);
}


Player::~Player()
{
}