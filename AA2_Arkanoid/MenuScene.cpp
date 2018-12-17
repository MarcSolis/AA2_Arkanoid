#include "MenuScene.h"
#include "Renderer.h"

MenuScene::MenuScene() 
{
	timer = 6;
	Renderer::Instance()->LoadTexture("MenuBackground", "../res/Menu.jpg");
}

void MenuScene::Update(const InputManager &)
{
	if (playtime >= timer) nextScene = GAME;
}

void MenuScene::FixedUpdate()
{
}

void MenuScene::Render()
{
	Renderer::Instance()->PushImage("MenuBackground", bgRect);
	Renderer::Instance()->Render();
}

MenuScene::~MenuScene()
{	
}
