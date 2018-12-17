#pragma once
#include "Scene.h"

class SplashScene : public Scene
{
private:
	int timer;
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

