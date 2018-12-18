#include "MenuScene.h"

MenuScene::MenuScene() :
	playButton(playButtPos, "Play", "sunspire"),
	rankingButton(rankingButtPos, "Ranking", "sunspire"),
	quitButton(quitButtPos, "Quit", "sunspire"),
	soundButton(soundButtPos, "Sound ON", "Sound OFF", "S_sunspire")
{
	Renderer::Instance()->LoadTexture("MenuBackground", "../res/Menu.jpg");
}

void MenuScene::Update(const InputManager &input)
{
	playButton.IsHover(input.mousePos);
	rankingButton.IsHover(input.mousePos);
	quitButton.IsHover(input.mousePos);
	soundButton.IsHover(input.mousePos);

	if (input.mouseClicked) {
		playButton.OnClick(false, [&]() {nextScene = GAME; });
		rankingButton.OnClick(false, [&]() {nextScene = RANKING; });
		quitButton.OnClick(false, [&]() {nextScene = EXIT; });

		if (playtime >= timeToClickAgain)
			soundButton.OnClick(true, [&]() {timeToClickAgain = playtime + 10000; });
	}
	else
		timeToClickAgain = playtime;
}

void MenuScene::FixedUpdate()
{
}

void MenuScene::Render()
{
	Renderer::Instance()->PushImage("MenuBackground", bgRect);
	playButton.Render();
	rankingButton.Render();
	quitButton.Render();
	soundButton.Render();

	Renderer::Instance()->Render();
}

MenuScene::~MenuScene()
{	
}
