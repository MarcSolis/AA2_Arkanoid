#pragma once
#include "Scene.h"
#include "Button.h"
#include "UIText.h"

class RankingScene : public Scene
{
private:
	int numPosX = int(SCREEN_WIDTH * 0.1f);
	//Title
	Vec2 rankingPos{ int(SCREEN_WIDTH * 0.3f), int(SCREEN_HEIGHT * 0.05f) };

	UIText rankingText;
	//Ranking
	Vec2 num1Pos{ numPosX, int(SCREEN_HEIGHT * 0.25f)};
	Vec2 num2Pos{ numPosX, int(SCREEN_HEIGHT * 0.3f) };
	Vec2 num3Pos{ numPosX, int(SCREEN_HEIGHT * 0.35f) };
	Vec2 num4Pos{ numPosX, int(SCREEN_HEIGHT * 0.4f) };
	Vec2 num5Pos{ numPosX, int(SCREEN_HEIGHT * 0.45f) };
	Vec2 num6Pos{ numPosX, int(SCREEN_HEIGHT * 0.5f) };
	Vec2 num7Pos{ numPosX, int(SCREEN_HEIGHT * 0.55f) };
	Vec2 num8Pos{ numPosX, int(SCREEN_HEIGHT * 0.6f) };
	Vec2 num9Pos{ numPosX, int(SCREEN_HEIGHT * 0.65f) };
	Vec2 num10Pos{ numPosX, int(SCREEN_HEIGHT * 0.7f) };

	UIText num1Text, num2Text, num3Text, num4Text, num5Text, num6Text, num7Text, num8Text, num9Text, num10Text;

	//Buttons
	Vec2 menuButtPos{numPosX, int(SCREEN_HEIGHT /1.2f)};
	Button menuButton;

public:
	//Constructor
	RankingScene();
	//Functions
	void Update(const InputManager &) override;
	void FixedUpdate() override;
	void Render() override;
	//Destructor
	~RankingScene();
};

