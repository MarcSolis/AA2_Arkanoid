#include "GameScene.h"


GameScene::GameScene() :
	players({Player(1, 1, "../res/platform.png"), Player(2,1,"../res/platform.png")}),
	ball(10, 3, 6, "../res/ball.png"),
	startGame(startGamePos, "Start Game", "B_sunspire", { 255,255,255,255 }),
	spaceBarToStart(spaceBarToStartPos, "Space Bar To Start", "S_sunspire", { 255,255,255,255 }),
	pause(pausePos, "...Pause...", "B_sunspire", { 255,255,255,255 }),
	pl1(pl1Pos, "PL1:", "sunspire", { 255,0,0,255 }),
	//pl1Score(pl1ScorePos, player1.score.toString(), "sunspire", { 255,0,0,255 }),
	pl2(pl2Pos, "PL2:", "sunspire", { 255,0,0,255 }),
	//pl2Score(pl2ScorePos, player2.score.toString(), "sunspire", { 255,0,0,255 }),
	soundButton(soundButtPos, "Sound ON", "Sound OFF", "S_sunspire")
{
	timeToPressAgain = 0;
	nextState = START_GAME;
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

	switch (nextState)
	{
		case START_GAME:
			ball.SetScored(false);

			if (ball.GetFirstPlayerHasBall())
				ball.SetInitPosition(players[0].ReturnInitBallPosition());
			else
				ball.SetInitPosition(players[1].ReturnInitBallPosition());

			if (input.esc)
				nextScene = MENU;
			if (input.space)
			{
				ball.ApplyInitVelocity();
				nextState = RUNNING;
			}
			startGame.Render();
			spaceBarToStart.Render();
			break;
		case RUNNING:
			players[0].Update(input, ball);
			players[1].Update(input, ball);

			ball.Update();


			if (input.p || input.esc)
			{
				nextState = PAUSED;
				timeToPressAgain = playtime + 10000;
			}

			if (ball.GetScored())
				nextState = START_GAME;
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
			std::cout << "Congratulations, " << winnerName << ", you WON! If you got a high score you might be on Top 10. Check out the rankings." << std::endl;
			nextScene = MENU;
			break;
		default:
			break;
	}
	players[0].Render();
	players[1].Render();
}

void GameScene::FixedUpdate()
{
}

void GameScene::Render()
{
	Renderer::Instance()->Render();
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
