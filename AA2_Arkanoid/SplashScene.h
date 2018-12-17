#pragma once
#include "Scene.h"

class SplashScene : public Scene
{
private:
	int timer;
	SDL_Texture* bgTexture;
	SDL_Rect bgRect{ 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
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

