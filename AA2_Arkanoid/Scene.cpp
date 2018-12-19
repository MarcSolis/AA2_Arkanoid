#include "Scene.h"

Scene::Scene() {}

void Scene::Run(const InputManager &input)
{
	FixedUpdate();

	frameStart = SDL_GetTicks();
	playtime = counter + (clock() - initClock) / CLOCKS_PER_SEC;

	Update(input);

	frameTime = SDL_GetTicks() - frameStart;
	if (frameTime < DELAY_TIME) {
		frameTime = 0;
		SDL_Delay((int)(DELAY_TIME - frameTime));
	}
	frame++;

	Render();
}

SceneType Scene::Transition() {	return nextScene; }

Scene::~Scene() {}
