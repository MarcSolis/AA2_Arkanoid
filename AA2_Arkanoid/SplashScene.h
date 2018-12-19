#pragma once
#include "Scene.h"

class SplashScene : public Scene
{
private:
	int timer;
	int ballSpeed;

	SDL_Rect platformRect{ 400, 500, 200, 60 };
	SDL_Rect ballRect{ 465, 135, 60,60 };
public:
	//Constructor
	SplashScene();

	//Functions
	void Update(const InputManager &) override;
	void FixedUpdate() override;
	void Render() override;
	//Destructor
	~SplashScene();
};

