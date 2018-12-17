#include "Button.h"

//Constructor
Button::Button(const Vec2 &pos, const std::string &text)
{
	normalID = "buttonNormal_" + text;
	hoverID = "buttonHover_" + text;
	Renderer::Instance()->LoadTextureText("Sayain", { normalID, text, { 255, 255, 255, 255 } });
	Renderer::Instance()->LoadTextureText("Sayain", { hoverID, text, { 255, 255, 255, 255 } });

	std::cout << "Created Button" << std::endl;

	Vec2 size = Renderer::Instance()->GetTextureSize(normalID);
	rect = SDL_Rect{ pos.x, pos.y, size.x, size.y };
}

Button::Button()
{
}

//Functions
	void Button::Render() {
		Renderer::Instance()->PushImage(isHover ? normalID : hoverID, rect);
	}

	void Button::IsHover(const Vec2& pos) {

		if (rect.x < pos.x && (rect.x + rect.w) > pos.x && rect.y < pos.y && (rect.y + rect.h) > pos.y) isHover = true;
		else isHover = false;
	}

	void Button::OnClick(const std::function<void()>& func) {
		if (isHover) func();
	}

//Destructor
	Button::~Button() {}
