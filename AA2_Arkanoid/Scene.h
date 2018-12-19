#pragma once
#include "Common.h"
#include "InputManager.h"


class Scene
{
protected:
//Atributes
	Uint32 frameStart, frameTime;
	int frame = 0;
	int counter = 0, initClock = 0, playtime = 0;

	SDL_Rect bgRect{ 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };

public:
	SceneType nextScene{ CURRENT };
//Constructor
	Scene();
//Functions
	void Run(const InputManager &);
	virtual void Update(const InputManager &) = 0;
	virtual void FixedUpdate() = 0;
	virtual void Render() = 0;

	SceneType Transition();

//Destructor 
	~Scene();
};

