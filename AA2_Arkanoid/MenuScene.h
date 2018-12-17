#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "Button.h"

class MenuScene : public Scene
{
private: 
	int timer;
	Vec2 playButtPos = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	Button b;
public:
	//Constructor
	MenuScene();
	//Functions
	void Update(const InputManager &) override;
	void FixedUpdate() override;
	void Render() override;
	void GoToPlay();
	//Destructor
	~MenuScene();
};

