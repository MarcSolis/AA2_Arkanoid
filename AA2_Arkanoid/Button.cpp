#include "Button.h"

//Constructor
Button::Button(const Vec2 &pos, const std::string &text, const std::string &font, const SDL_Color& normalColor, const SDL_Color& hoverColor)
{
	normalID = "buttonNormal_" + text;
	hoverID = "buttonHover_" + text;

	Renderer::Instance()->LoadTextureText(font, { normalID, text, normalColor });
	Renderer::Instance()->LoadTextureText(font, { hoverID, text, hoverColor });

	activated = false;

	Vec2 size = Renderer::Instance()->GetTextureSize(normalID);
	rect = SDL_Rect{ pos.x, pos.y, size.x, size.y };
}

Button::Button(const Vec2 &pos, const std::string &text1, const std::string &text2, const std::string &font, const SDL_Color& normalColor, const SDL_Color& hoverColor)
{
	normalID = "buttonNormal_" + text1;
	hoverID = "buttonHover_" + text1;

	Renderer::Instance()->LoadTextureText(font, { normalID, text1, normalColor });
	Renderer::Instance()->LoadTextureText(font, { hoverID, text1, hoverColor });

	normalID2 = "buttonNormal_" + text2;
	hoverID2 = "buttonHover_" + text2;

	Renderer::Instance()->LoadTextureText(font, { normalID2, text2,{ normalColor.r, normalColor.g, normalColor.b, normalColor.a } });
	Renderer::Instance()->LoadTextureText(font, { hoverID2, text2,{ hoverColor.r, hoverColor.g, hoverColor.b, hoverColor.a } });

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

void Button::OnClick(const bool &change, const std::function<void()>& func) {
	if (isHover) {
		func();
		if(change)
			activated = !activated;
	}
}

void Button::Destroy(Button &button)
{
	Renderer::Instance()->DeleteTexture(button.normalID);
	Renderer::Instance()->DeleteTexture(button.hoverID);
	Renderer::Instance()->DeleteTexture(button.normalID2);
	Renderer::Instance()->DeleteTexture(button.hoverID2);
}

bool Button::GetActivated()
{
	return activated;
}

//Destructor
Button::~Button() {
	Destroy(*this);
}
