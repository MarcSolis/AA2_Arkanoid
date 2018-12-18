#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "Button.h"

class MenuScene : public Scene
{
private: 
	int timeToClickAgain;
	Vec2 playButtPos = { SCREEN_WIDTH / 2.5f, SCREEN_HEIGHT / 2 };
	Vec2 rankingButtPos = { SCREEN_WIDTH / 2.85f, SCREEN_HEIGHT / 1.5f };
	Vec2 quitButtPos = { SCREEN_WIDTH / 2.37f, SCREEN_HEIGHT / 1.2f };
	Vec2 soundButtPos = { SCREEN_WIDTH * 0.84f, SCREEN_HEIGHT * 0.01f };
	Button playButton, rankingButton, quitButton, soundButton;
public:
	//Constructor
	MenuScene();
	//Functions
	void Update(const InputManager &) override;
	void FixedUpdate() override;
	void Render() override;
	//Destructor
	~MenuScene();
};

