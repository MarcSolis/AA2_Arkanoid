#include "GameScene.h"


GameScene::GameScene() :
	startGame(startGamePos, "Start Game", "B_sunspire", { 255,255,255,255 }),
	spaceBarToStart(spaceBarToStartPos, "Space Bar To Start", "S_sunspire", { 255,255,255,255 }),
	pause(pausePos, "...Pause...", "B_sunspire", {255,255,255,255}),
	pl1(pl1Pos, "PL1:", "sunspire", { 255,0,0,255 }),
	pl2(pl2Pos, "PL2:", "sunspire", { 255,0,0,255 }),
	soundButton(soundButtPos, "Sound ON", "Sound OFF", "S_sunspire")
{
	timeToPressAgain = 0;
	nextState = START_GAME;
	Renderer::Instance()->LoadTexture("GameBackground", "../res/Backgroung.jpg");
}

void GameScene::Update(const InputManager &input)
{
	Renderer::Instance()->PushImage("GameBackground", bgRect);
	pl1.Render();
	pl2.Render();

	switch (nextState)
	{
		case START_GAME:
			//SHOW START GAME SPACE BAR TO START
			if (input.esc)
				nextScene = MENU;
			if (input.space)
				nextState = RUNNING;
			startGame.Render();
			spaceBarToStart.Render();
			break;
		case RUNNING:
			if (input.p || input.esc)
			{
				nextState = PAUSED;
				timeToPressAgain = playtime + 10000;
			}
			break;
		case PAUSED:
			soundButton.IsHover(input.mousePos);

			if (input.esc && playtime >= timeToPressAgain)
				nextScene = MENU;

			if (input.space)
				nextState = RUNNING;

			if (input.mouseClicked && playtime >= timeToPressAgain)
				soundButton.OnClick(true, [&]() {timeToPressAgain = playtime + 10000; });

			if (!input.esc && !input.mouseClicked)
				timeToPressAgain = 0;

			pause.Render();
			soundButton.Render();
			break;
		case GAME_OVER:
			break;
		default:
			break;
	}
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
