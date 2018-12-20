#pragma once
#include "Common.h"
#include "Vec2.h"
#include "Renderer.h"

class UIText
{
private:
	//Atributes
	Rect rect;
	std::string textID;
	
	bool toRender;
public:
	//Constructor
	UIText();
	UIText(const Vec2&, const std::string&, const std::string&, const Color& = WHITE);
	//Functions
	void Render();
	static void Destroy(UIText&);
	void ChangeTexture(const Vec2&, const std::string&, const std::string&, const Color& = WHITE);
	void SetToRender(const bool&);
	//Destructor
	~UIText();
};

