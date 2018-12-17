#pragma once
#include "Scene.h"

class GameScene :public Scene
{
public:
	//Constructor
	GameScene();
	//Functions
	void Update(const InputManager &) override;
	void FixedUpdate() override;
	void Render() override;
	//Destructor
	~GameScene();
};

