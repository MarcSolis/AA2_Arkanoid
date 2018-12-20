#pragma once
#include "Common.h"
#include "Vec2.h"
#include "Renderer.h"
#include "Texture.h"
#include "Rect.h"

class Block
{
private:
	//Atributes
	Rect snippet;
	int textWidth, textHeight, frameWidth, frameHeight;

	int normalMin, normalMax, heavyMin, heavyMax;

public:
	Rect position{ 0, 0, DEFAULT_BLOCK_HEIGHT, DEFAULT_BLOCK_WIDTH };
	Texture texture{ "block", "../res/bricks.jpg" };
	int life = 0, points, min = 0, max = 0;
	Type type;
	Color color;

	Uint32 frameStart, frameTime;
	int frame = 0;
	int counter = 0, initClock = 0, playtime = 0;

	//Constructor
	Block();
	Block(const Vec2&, const Type, const int&, const int&, const int&, const int&);

	//Functions
	void Update();
	void FixedUpdate();
	void Render();

	//Destructor
	~Block();
};

