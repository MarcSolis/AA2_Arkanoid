#include "SplashScene.h"


SplashScene::SplashScene()
{
	timer = 3;
}

void SplashScene::Update(const InputManager &)
{
	if (playtime > timer)	nextScene = MENU;
}

void SplashScene::FixedUpdate()
{

}

void SplashScene::Render()
{
}


SplashScene::~SplashScene()
{
}
