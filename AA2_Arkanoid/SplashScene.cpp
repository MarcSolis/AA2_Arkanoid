#include "SplashScene.h"


SplashScene::SplashScene() : timer(3) , bgTexture(IMG_Load)
{}

void SplashScene::Update(const InputManager &)
{
	std::cout << "MENU" << std::endl;
	if (playtime >= timer)	nextScene = MENU;
}

void SplashScene::FixedUpdate() {}

void SplashScene::Render() {}

SplashScene::~SplashScene() {}
