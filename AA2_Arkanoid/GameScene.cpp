#include "GameScene.h"


GameScene::GameScene() :
	players({ Player(1, 10, "../res/platform.png"), Player(2,10,"../res/platform.png") }),
	ball(10, 3, 6, "../res/ball.png"),
	startGame(startGamePos, "Start Game", "B_sunspire", WHITE),
	spaceBarToStart(spaceBarToStartPos, "Space Bar To Start", "S_sunspire", WHITE),
	pause(pausePos, "...Pause...", "B_sunspire", WHITE),
	pl1(pl1Pos, "PL1:", "sunspire", UIRED),
	pl1Score(pl1ScorePos, std::to_string(players[0].GetScore()), "sunspire", UIRED),
	pl2(pl2Pos, "PL2:", "sunspire", UIRED),
	pl2Score(pl2ScorePos, std::to_string(players[1].GetScore()), "sunspire", UIRED),
	soundButton(soundButtPos, "Sound ON", "Sound OFF", "S_sunspire")
{
	//UploadData();
	GenerateBlocks(3, 5, HEAVY);
	GenerateBlocks(0, 0, FIX);
	GenerateBlocks(11, 10, NORMAL);
	GenerateBlocks(1, 0, HEAVY);
	GenerateBlocks(2, 0, HEAVY);
	GenerateBlocks(3, 0, HEAVY);
	GenerateBlocks(4, 0, HEAVY);
	GenerateBlocks(5, 0, HEAVY);
	GenerateBlocks(6, 0, HEAVY);
	GenerateBlocks(7, 0, HEAVY);
	GenerateBlocks(8, 0, HEAVY);
	GenerateBlocks(9, 0, HEAVY);
	GenerateBlocks(10, 0, HEAVY);
	GenerateBlocks(11, 0, HEAVY);
	GenerateBlocks(0, 1, HEAVY);
	GenerateBlocks(0, 2, HEAVY);
	GenerateBlocks(0, 3, HEAVY);
	GenerateBlocks(0, 4, HEAVY);
	GenerateBlocks(0, 5, HEAVY);
	GenerateBlocks(0, 6, HEAVY);
	GenerateBlocks(0, 7, HEAVY);
	GenerateBlocks(0, 8, HEAVY);
	GenerateBlocks(0, 9, HEAVY);
	GenerateBlocks(0, 10, HEAVY);

	Renderer::Instance()->LoadTexture(livesHUD.id, livesHUD.path);
	int offset = 5;
	for (int i = 0; i < 6; i++) {
		if (i < 3) {
			livesPosPl1.push_back({ pl1Pos.x + offset, pl1Pos.y + 48, livesSize.x, livesSize.y });
		}
		else livesPosPl2.push_back({ pl2Pos.x + offset, pl2Pos.y + 48, livesSize.x, livesSize.y });
		offset += livesSize.x + 30;
		if (i == 2) offset = 5;

	}

	timeToPressAgain = 0;
	nextState = START_GAME;

	maxPointsForLives = 100;
	minPointsForLives = -50;

	Renderer::Instance()->LoadTexture("GameBackground", "../res/Backgroung.jpg");

	music = Mix_LoadMUS("../res/music.mp3");
	Mix_VolumeMusic(MIX_MAX_VOLUME / 10);
	Mix_PlayMusic(music, -1);
}

void GameScene::Update(const InputManager &input)
{
	Renderer::Instance()->PushImage("GameBackground", bgRect);
	pl1.Render();
	pl2.Render();
	ball.Render();
	pl1Score.Render();
	pl2Score.Render();

	switch (nextState)
	{
		case START_GAME:
			if (input.esc)
				nextScene = MENU;
			if (input.space)
			{
				ball.ApplyInitVelocity();
				nextState = RUNNING;
			}

			ball.SetScored(false);
			if (ball.GetFirstPlayerHasBall())
				ball.SetInitPosition(players[0].ReturnInitBallPosition());
			else
				ball.SetInitPosition(players[1].ReturnInitBallPosition());

			startGame.Render();
			spaceBarToStart.Render();
			break;
		case RUNNING:
			if (input.p || input.esc)
			{
				nextState = PAUSED;
				timeToPressAgain = playtime + 10000;
			}

			players[0].Update(input, ball);
			players[1].Update(input, ball);

			ball.Update();

			if (ball.GetScored())
			{
				nextState = START_GAME;
				if (ball.GetFirstPlayerHasBall())
				{
					UpdatePlayerLives(players[0]);
					AddOrSusbsPoints(players[0], minPointsForLives);
					AddOrSusbsPoints(players[1], maxPointsForLives);
				}
				else
				{
					UpdatePlayerLives(players[1]);
					AddOrSusbsPoints(players[0], maxPointsForLives);
					AddOrSusbsPoints(players[1], minPointsForLives);
				}
			}

			break;
		case PAUSED:
			soundButton.IsHover(input.mousePos);

			if (input.esc && playtime >= timeToPressAgain)
				nextScene = MENU;

			if (input.space)
				nextState = RUNNING;

			if (input.mouseClicked && playtime >= timeToPressAgain)
				soundButton.OnClick(true, [&]() {
				timeToPressAgain = playtime + 10000;
				if (!soundButton.GetActivated())
					Mix_PauseMusic();
				else
					Mix_ResumeMusic();
			});

			if (!input.esc && !input.mouseClicked)
				timeToPressAgain = 0;

			pause.Render();
			soundButton.Render();
			break;
		case GAME_OVER:
			std::cout << "Write the winner's name: ";
			std::cin >> winnerName;
			std::cout << std::endl << "Congratulations, " << winnerName << ", you WON obtaining " << (players[0].GetScore() > players[1].GetScore() ? players[0].GetScore() : players[1].GetScore())
				<<" points!" << std::endl <<"If you got a nice score you might be on Top 10. Check out the rankings." << std::endl;
			nextScene = MENU;
			break;
		default:
			break;
	}
	players[0].Render();
	players[1].Render();

	for (int i = 0; i < livesPosPl1.size(); i++)
		Renderer::Instance()->PushImage("Life", { livesPosPl1[i].x, livesPosPl1[i].y, livesPosPl1[i].w, livesPosPl1[i].h });
	for (int i = 0; i < livesPosPl2.size(); i++)
		Renderer::Instance()->PushImage("Life", { livesPosPl2[i].x, livesPosPl2[i].y, livesPosPl2[i].w, livesPosPl2[i].h });

	for (int i = 0; i < blocks.size(); i++)
	{
		blocks[i].Render();
	}
}

void GameScene::FixedUpdate()
{
}

void GameScene::Render()
{
	Renderer::Instance()->Render();
}

void GameScene::UploadData()
{
	rapidxml::xml_document<> doc;
	std::ifstream file(".. / res / files / config.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	rapidxml::xml_node<> *pRoot = doc.first_node();
	rapidxml::xml_node<> *pNode = pRoot->first_node("BrickInfo");
	//NormalMin = std::stoi(*pNode->first_node("Normal")->first_attribute("min")->value);
	//NormalMax = std::stoi(*pNode->first_node("Normal")->first_attribute("max")->value);
	//HeavyMin = std::stoi(*pNode->first_node("Heavy")->first_attribute("min")->value);
	//HeavyMax = std::stoi(*pNode->first_node("Heavy")->first_attribute("max")->value);
}

void GameScene::GenerateBlocks(const int& i, const int& j, const Type& t) {
	Vec2 pos = { DefaultGridPosX + cell.x*i, DefaultGridPosY + cell.y*j };
	blocks.push_back({ pos, t, NormalMin, NormalMax, HeavyMin, HeavyMax});
}

void GameScene::UpdatePlayerLives(Player &p)
{
	int lives = p.GetLives();
	lives--;
	p.SetLives(lives);

	if (p.GetLives() < 0)
		nextState = GAME_OVER;
	else
	{
		if(p.GetTag() == 1)
			livesPosPl1.pop_back();
		else if(p.GetTag() == 2)
			livesPosPl2.pop_back();
	}
}

void GameScene::AddOrSusbsPoints(Player &pl, const int &po)
{
	int score = pl.GetScore();
	score += po;
	if (score < 0) score = 0;
	pl.SetScore(score);
	if (pl.GetTag() == 1)
		pl1Score.ChangeTexture(pl1ScorePos, std::to_string(players[0].GetScore()), "sunspire", UIRED);
	else if(pl.GetTag() == 2)
		pl2Score.ChangeTexture(pl2ScorePos, std::to_string(players[1].GetScore()), "sunspire", UIRED);
}

GameScene::~GameScene()
{
	startGame.Destroy(startGame);
	spaceBarToStart.Destroy(spaceBarToStart);
	pause.Destroy(pause);
	pl1.Destroy(pl1);
	pl2.Destroy(pl2);
	soundButton.Destroy(soundButton);
}
