#pragma once
#include "Scene.h"

class MenuScene : public Scene
{
private: 
	int timer;
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

