#include "Block.h"
#include "Renderer.h"

Block::Block()
{
}

Block::Block(const Vec2 &_pos, const Type _type, const int& nMin, const int& nMax, const int& hMin, const int& hMax) :
	normalMin(nMin), normalMax(nMax), heavyMin(hMin), heavyMax(hMax)
{
	if (_type != NONE) {
		Renderer::Instance()->LoadTexture(texture.id, texture.path);
		Vec2 size = Renderer::Instance()->GetTextureSize("block");
		textWidth = size.x;
		textHeight = size.y;
		frameWidth = textWidth / 5;
		frameHeight = textHeight / 3;
		snippet.x = 0;
		snippet.h = frameHeight;
		snippet.w = frameWidth;
		type = _type;
		position.x = _pos.x;
		position.y = _pos.y;
	}

	switch (type) {
	case NORMAL:
		life = 1;
		color = GREEN;
		snippet.y = 0;
		points = rand() % (normalMax - normalMin + 1) + normalMin;
		break;
	case HEAVY:
		life = 3;
		color = RED;
		snippet.y = frameHeight;
		rand() % (heavyMax - heavyMin + 1) + heavyMin;
		break;
	case FIX:
		life = -1;
		color = BROWN;
		snippet.y = frameHeight * 2;
	case NONE:
		color = TRANSPARENT;
		//destroy
		break;
	}
}


void Block::Update()
{
}

void Block::FixedUpdate()
{
}

void Block::Render()
{
	//Renderer::Instance()->PushRotatedSprite(texture.id, snippet, position, 90, Vec2{ position.w / 2, position.h });
}


Block::~Block()
{
}
