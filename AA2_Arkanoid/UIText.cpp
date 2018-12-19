#include "UIText.h"



UIText::UIText()
{
}

UIText::UIText(const Vec2 &pos, const std::string &text, const std::string &font, const SDL_Color &color)
{
	textID = text;

	Renderer::Instance()->LoadTextureText(font, { textID, text, color });

	Vec2 size = Renderer::Instance()->GetTextureSize(textID);
	rect = SDL_Rect{ pos.x, pos.y, size.x, size.y };
}

void UIText::Render() {
	Renderer::Instance()->PushImage(textID, rect);
}

void UIText::Destroy(UIText &uiText)
{
	Renderer::Instance()->DeleteTexture(uiText.textID);
}


UIText::~UIText()
{
	Destroy(*this);
}
