#pragma once
#include "Common.h"
#include "Scene.h"
#include <vector>

#include "UIText.h"
#include "Button.h"
#include "Texture.h"

#include "Block.h"
#include "Player.h"
#include "Ball.h"

class GameScene :public Scene
{
private: 
	enum GameStates {START_GAME, RUNNING, PAUSED, GAME_OVER};
	GameStates nextState{ START_GAME };
	int timeToPressAgain;
	bool firstPlayerHasBall;
	std::string winnerName;

	std::vector<Player> players;
	Ball ball;

	Vec2 startGamePos{SCREEN_WIDTH * 0.2f, SCREEN_HEIGHT * 0.3f};
	Vec2 spaceBarToStartPos{SCREEN_WIDTH / 3.67f, SCREEN_HEIGHT * 0.4f};
	Vec2 pausePos{ SCREEN_WIDTH * 0.288f, SCREEN_HEIGHT * 0.2f };
	Vec2 pl1Pos{ SCREEN_WIDTH * 0.1f, SCREEN_HEIGHT * 0.835f };
	Vec2 pl1ScorePos{ SCREEN_WIDTH * 0.15f, SCREEN_HEIGHT * 0.835f };
	Vec2 pl2Pos{ SCREEN_WIDTH * 0.58f, SCREEN_HEIGHT * 0.835f };
	Vec2 pl2ScorePos{ SCREEN_WIDTH * 0.63f, SCREEN_HEIGHT * 0.835f };

	Texture texture_startGame, texture_spaceBarToStart, texture_pause, texture_pl1, texture_pl2, texture_pl1Score, texture_pl2Score;
	UIText startGame, spaceBarToStart, pause, pl1, pl2, pl1Score, pl2Score;

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

