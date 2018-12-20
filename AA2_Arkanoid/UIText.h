#pragma once
#include "Common.h"
#include "Vec2.h"
#include "Renderer.h"

class UIText
{
private:
	//Atributes
	SDL_Rect rect;
	std::string textID;
	
	bool toRender;
public:
	//Constructor
	UIText();
	UIText(const Vec2&, const std::string&, const std::string&, const SDL_Color& = WHITE); ///Posició, Text, FontID, Color
	//Functions
	void Render();
	static void Destroy(UIText&);
	void SetToRender(const bool&);
	//Destructor
	~UIText();
};

