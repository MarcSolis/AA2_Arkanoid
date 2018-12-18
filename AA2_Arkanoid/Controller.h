#pragma once
#include "Scene.h"
#include "InputManager.h"
#include "Renderer.h"

class Controller
{
private:
//Atributes
	Scene* scene;
	bool isRunning;
	InputManager input;

public:
//Constructor
	Controller();
//Functions
	void GameLoop();
	void EndGame();

//Destructor
	~Controller();
};

