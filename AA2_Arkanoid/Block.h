#pragma once
#include "Common.h"
#include "Vec2.h"
class Block
{
private:
	//Atributtes
	Vec2 position;
	SDL_Rect snippet;
	int textWidth, textHeight, frameWidth, frameHeight;
	int NormalMin, NormalMax, HeavyMin, HeavyMax;
	std::string texture;

public:
	//Atributtes
	SDL_Rect rect{ 0, 0, DEFAULT_BLOCK_WIDTH, DEFAULT_BLOCK_HEIGHT };
	int health, points, min, max;
	Type type;
	Color color;

	Uint32 frameStart, frameTime;
	int frame = 0;
	int counter = 0, initClock = 0, playtime = 0;
	//Constructor
	Block(const Vec2&, const Type);
	//Functions
	void Run();
	void Update();
	void FixedUpdate();
	void Render();
	//Destructor
	~Block();
};

