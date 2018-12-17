#include "Controller.h"


Controller::Controller()
{
	scene = new SplashScene();
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
			scene = new SplashScene();
			break;
		case SceneType::MENU:
			delete scene;
			scene = new MenuScene();
			break;
		case SceneType::GAME:
			delete scene;
			scene = new GameScene();
			break;
		case SceneType::RANKING:
			delete scene;
			scene = new RankingScene();
			break;
		default:
		}
	}

	//Close game
	EndGame();

}

void Controller::EndGame()
{
	delete scene;
	//renderer->Instance()->Close();
}




Controller::~Controller()
{
	delete scene;
}
