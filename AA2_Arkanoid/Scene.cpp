#include "Scene.h"

Scene::Scene() {}

void Scene::Run(const InputManager &input)
{
	frameStart = SDL_GetTicks();
	playtime = counter + (clock() - initClock) / CLOCKS_PER_SEC;

	Update(input);
	FixedUpdate();

	frameTime = SDL_GetTicks() - frameStart;
	if (frameTime < DELAY_TIME) {
		frameTime = 0;
		SDL_Delay((int)(DELAY_TIME - frameTime));
	}
	frame++;

	Render();

}

void Scene::SetNextSceneToCurrent()
{
	nextScene = CURRENT;
}

SceneType Scene::Transition() {	return nextScene; }

Scene::~Scene() {}
