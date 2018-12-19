#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "UIText.h"
#include "Button.h"

class GameScene :public Scene
{
private: 
	enum GameStates {START_GAME, RUNNING, PAUSED, GAME_OVER, CURRENT};
	GameStates nextState{ START_GAME };
	int timeToPressAgain;
	std::string winnerName;

	Vec2 startGamePos{SCREEN_WIDTH * 0.2f, SCREEN_HEIGHT * 0.3f};
	Vec2 spaceBarToStartPos{SCREEN_WIDTH / 3.67f, SCREEN_HEIGHT * 0.4f};
	Vec2 pausePos{ SCREEN_WIDTH * 0.288f, SCREEN_HEIGHT * 0.2f };
	Vec2 pl1Pos{ SCREEN_WIDTH * 0.1f, SCREEN_HEIGHT * 0.835f };
	Vec2 pl2Pos{ SCREEN_WIDTH * 0.58f, SCREEN_HEIGHT * 0.835f };
	UIText startGame, spaceBarToStart, pause, pl1, pl2;

	Vec2 soundButtPos{ SCREEN_WIDTH * 0.4f, SCREEN_HEIGHT * 0.5f };
	Button soundButton;

public:
	//Constructor
	GameScene();
	//Functions
	void Update(const InputManager &) override;
	void FixedUpdate() override;
	void Render() override;
	//Destructor
	~GameScene();
};

