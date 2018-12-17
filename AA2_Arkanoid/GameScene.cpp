#include "GameScene.h"
#include "Renderer.h"


GameScene::GameScene()
{
	Renderer::Instance()->LoadTexture("GameBackground", "../res/Backgroung.jpg");
}

void GameScene::Update(const InputManager &)
{
}

void GameScene::FixedUpdate()
{
}

void GameScene::Render()
{
	Renderer::Instance()->PushImage("GameBackground", bgRect);

	Renderer::Instance()->Render();
}


GameScene::~GameScene()
{
}
