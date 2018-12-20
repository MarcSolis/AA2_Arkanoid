#include "UIText.h"



UIText::UIText()
{
}

UIText::UIText(const Vec2 &pos, const std::string &text, const std::string &font, const Color &color)
{
	textID = text;

	Renderer::Instance()->LoadTextureText(font, { textID, text, color });

	Vec2 size = Renderer::Instance()->GetTextureSize(textID);
	rect = Rect{ pos.x, pos.y, size.x, size.y };
}

void UIText::Render() {
	Renderer::Instance()->PushImage(textID, { rect.x, rect.y, rect.w, rect.h });
}

void UIText::Destroy(UIText &uiText)
{
	Renderer::Instance()->DeleteTexture(uiText.textID);
}

void UIText::ChangeTexture(const Vec2 &pos, const std::string &text, const std::string &font, const Color &color)
{
	textID = text;

	Renderer::Instance()->LoadTextureText(font, { textID, text, color });

	Vec2 size = Renderer::Instance()->GetTextureSize(textID);
	rect = Rect{ pos.x, pos.y, size.x, size.y };
}

void UIText::SetToRender(const bool &r)
{
	toRender = r;
}


UIText::~UIText()
{
	Destroy(*this);
}
