#include "Controller.h"
#include "SplashScene.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "RankingScene.h"

Controller::Controller()
{
	Renderer::Instance()->LoadFont({ "B_sunspire", "../res/sunspire.ttf", 65 });
	Renderer::Instance()->LoadFont({ "sunspire", "../res/sunspire.ttf", 50 });
	Renderer::Instance()->LoadFont({ "S_sunspire", "../res/sunspire.ttf", 30 });
	Renderer::Instance()->LoadFont({ "XS_sunspire", "../res/sunspire.ttf", 20 });
	scene = new SplashScene;
	isRunning = true;
}

void Controller::GameLoop()
{
	//Game Loop
	while (isRunning) {

		//Update
		input.Update();
		scene->Run(input);

		//Logic
		switch (scene->Transition()) {
		case SceneType::SPLASHSCREEN:
			delete scene;
			scene = new SplashScene;
			break;
		case SceneType::MENU:
			delete scene;
			scene = new MenuScene;
			break;
		case SceneType::GAME:
			delete scene;
			scene = new GameScene;
			break;
		case SceneType::RANKING:
			delete scene;
			scene = new RankingScene;
			break;
		case SceneType::EXIT:
			isRunning = false;
			break;
		default:
			break;
		}
	}

	//Close game
	EndGame();

}

void Controller::EndGame()
{
	delete scene;
	//Renderer::Instance()-
}




Controller::~Controller()
{
}
