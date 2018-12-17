#include "MenuScene.h"

MenuScene::MenuScene() : b(playButtPos, "Play")
{
	timer = 6000;
	Renderer::Instance()->LoadTexture("MenuBackground", "../res/Menu.jpg");
}

void MenuScene::Update(const InputManager &input)
{
	//if (playtime >= timer) nextScene = GAME;
	//b.IsHover(input.mousePos);
	//b.OnClick(GoToPlay());
}

void MenuScene::FixedUpdate()
{
}

void MenuScene::Render()
{
	Renderer::Instance()->PushImage("MenuBackground", bgRect);
	Renderer::Instance()->Render();
	b.Render();
}

void MenuScene::GoToPlay()
{
	nextScene = GAME;
}

MenuScene::~MenuScene()
{	
}
