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

#include <sstream>
#include "../dep/inc/XML/rapidxml.hpp"
#include "../dep/inc/XML/rapidxml_utils.hpp"
#include "../dep/inc/XML/rapidxml_iterators.hpp"
#include "../dep/inc/XML/rapidxml_print.hpp"

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
	int maxPointsForLives, minPointsForLives;

	int NormalMin, NormalMax, HeavyMin, HeavyMax;
	std::vector<Block> blocks;

	Vec2 startGamePos{int(SCREEN_WIDTH * 0.2f), int(SCREEN_HEIGHT * 0.3f)};
	Vec2 spaceBarToStartPos{int(SCREEN_WIDTH / 3.67f), int(SCREEN_HEIGHT * 0.4f)};
	Vec2 pausePos{ int(SCREEN_WIDTH * 0.288f), int(SCREEN_HEIGHT * 0.2f) };
	Vec2 pl1Pos{ int(SCREEN_WIDTH * 0.1f), int(SCREEN_HEIGHT * 0.835f) };
	Vec2 pl2Pos{ int(SCREEN_WIDTH * 0.58f), int(SCREEN_HEIGHT * 0.835f) };
	Vec2 pl1ScorePos{int(SCREEN_WIDTH * 0.25f), int(SCREEN_HEIGHT * 0.835f)};
	Vec2 pl2ScorePos{int(SCREEN_WIDTH * 0.76f), int(SCREEN_HEIGHT * 0.835f)};

	Texture texture_startGame, texture_spaceBarToStart, texture_pause, texture_pl1, texture_pl2, texture_pl1Score, texture_pl2Score;

	Texture livesHUD{ "Life", "../res/platform.png" };
	Vec2 livesSize{ 60,20 };
	std::vector<Rect> livesPosPl1;
	std::vector<Rect> livesPosPl2;

	Vec2 cell{ DEFAULT_BLOCK_WIDTH, DEFAULT_BLOCK_HEIGHT };
	Vec2 gridPosition;

	Vec2 soundButtPos{ int(SCREEN_WIDTH * 0.4f), int(SCREEN_HEIGHT * 0.5f) };

	UIText startGame, spaceBarToStart, pause, pl1, pl2, pl1Score, pl2Score;
	Button soundButton;

public:
	//Constructor
	GameScene();
	//Functions
	void Update(const InputManager &) override;
	void FixedUpdate() override;
	void Render() override;
	void UploadData();
	void GenerateBlocks(const int&, const int&, const Type&);
	void UpdatePlayerLives(Player&);
	void AddOrSusbsPoints(Player&, const int&);
	//Destructor
	~GameScene();
};

