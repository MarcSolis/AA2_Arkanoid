#pragma once
#include "Common.h"
#include "InputManager.h"


class Scene
{
protected:
//Atributes
	Uint32 frameStart, frameTime;
	int frame = 0;
	int counter = MATCH_TIME, initClock, playtime = 0;
	SceneType nextScene{ CURRENT };

public:
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

