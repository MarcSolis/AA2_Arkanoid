#include "SplashScene.h"
#include "Renderer.h"

SplashScene::SplashScene()
{
	timer = 3;
	Renderer::Instance()->LoadTexture("SplashBackground", "../res/SplashBG.png");
}

void SplashScene::Update(const InputManager &)
{
	if (playtime >= timer)	nextScene = MENU;
}

void SplashScene::FixedUpdate() {}

void SplashScene::Render() 
{
	Renderer::Instance()->PushImage("SplashBackground", bgRect);

	Renderer::Instance()->Render();
}

SplashScene::~SplashScene() {}
