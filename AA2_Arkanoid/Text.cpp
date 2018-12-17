#include "Text.h"


Text::Text(const std::string &id, const std::string &text, const SDL_Color &color) :
	id(id), text(text), color(color)
{}

Text::~Text()
{
}
