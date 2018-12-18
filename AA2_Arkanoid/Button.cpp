#include "Button.h"

//Constructor
Button::Button(const Vec2 &pos, const std::string &text, const std::string &font)
{
	normalID = "buttonNormal_" + text;
	hoverID = "buttonHover_" + text;

	Renderer::Instance()->LoadTextureText(font, { normalID, text,{ 255, 255, 255, 255 } });
	Renderer::Instance()->LoadTextureText(font, { hoverID, text,{ 100, 100, 255, 255 } });

	activated = false;

	Vec2 size = Renderer::Instance()->GetTextureSize(normalID);
	rect = SDL_Rect{ pos.x, pos.y, size.x, size.y };
}

Button::Button(const Vec2 &pos, const std::string &text1, const std::string &text2, const std::string &font)
{
	normalID = "buttonNormal_" + text1;
	hoverID = "buttonHover_" + text1;

	Renderer::Instance()->LoadTextureText(font, { normalID, text1,{ 255, 255, 255, 255 } });
	Renderer::Instance()->LoadTextureText(font, { hoverID, text1,{ 100, 100, 255, 255 } });

	normalID2 = "buttonNormal_" + text2;
	hoverID2 = "buttonHover_" + text2;

	Renderer::Instance()->LoadTextureText(font, { normalID2, text2,{ 255, 255, 255, 255 } });
	Renderer::Instance()->LoadTextureText(font, { hoverID2, text2,{ 100, 100, 255, 255 } });

	activated = false;

	Vec2 size = Renderer::Instance()->GetTextureSize(normalID);
	rect = SDL_Rect{ pos.x, pos.y, size.x, size.y };
}

Button::Button() {};

//Functions
void Button::Render() {
	if(!activated)
		Renderer::Instance()->PushImage(isHover ? hoverID : normalID, rect);
	else
		Renderer::Instance()->PushImage(isHover ? hoverID2 : normalID2, rect);
}

void Button::IsHover(const Vec2& pos) {

	if (rect.x < pos.x && (rect.x + rect.w) > pos.x && rect.y < pos.y && (rect.y + rect.h) > pos.y) isHover = true;
	else isHover = false;
}

void Button::OnClick(const bool &change, const std::function<void()>& func)
{
	if (isHover) {
		func();
		if(change)
			activated = !activated;
	}
}

//Destructor
Button::~Button() {}
