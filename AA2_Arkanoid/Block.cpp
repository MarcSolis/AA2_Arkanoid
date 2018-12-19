#include "Block.h"
#include "Renderer.h"

Block::Block(const Vec2 &_pos, const Type _type)
{
	Renderer::Instance()->LoadTexture("block", "../res/bricks.jpg");
	rect.x = _pos.x;
	rect.y = _pos.y;
	type = _type;

	switch (type) {
	case NORMAL:
		health = 1;
		color = GREEN;
		min = NormalMin;
		max = NormalMax;
		break;
	case HEAVY:
		health = 3;
		color = RED;
		min = HeavyMin;
		max = HeavyMax;
		break;
	case FIX:
		health = -1;
		color = BROWN;
	case NONE:
		color = TRANSPARENT;
		break;
	}

	points = rand() % (max + 1 - min) + min;
}

void Block::Run()
{
	frameStart = SDL_GetTicks();
	playtime = counter + (clock() - initClock) / CLOCKS_PER_SEC;

	Update();
	FixedUpdate();

	frameTime = SDL_GetTicks() - frameStart;
	if (frameTime < DELAY_TIME) {
		frameTime = 0;
		SDL_Delay((int)(DELAY_TIME - frameTime));
	}
	frame++;

	Render();
}

void Block::Update()
{
}

void Block::FixedUpdate()
{
}

void Block::Render()
{
}


Block::~Block()
{
}
