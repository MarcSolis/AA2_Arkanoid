#include "SplashScene.h"
#include "Renderer.h"

SplashScene::SplashScene()
{
	timer = 3;
	ballSpeed = 2;
	Renderer::Instance()->LoadTexture("SplashBackground", "../res/Menu.jpg");
	Renderer::Instance()->LoadTexture("Platform", "../res/platform.png");
	Renderer::Instance()->LoadTexture("BallSplashScreen", "../res/ball.png");
}

void SplashScene::Update(const InputManager &)
{
	Renderer::Instance()->PushImage("SplashBackground", bgRect);
	Renderer::Instance()->PushImage("Platform", platformRect);

	ballRect.y += ballSpeed;

	Renderer::Instance()->PushImage("BallSplashScreen", ballRect);

	if (playtime >= timer)	nextScene = MENU;
}

void SplashScene::FixedUpdate() {}

void SplashScene::Render() 
{
	Renderer::Instance()->Render();
}

SplashScene::~SplashScene() {}
