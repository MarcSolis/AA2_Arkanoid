#pragma once
#include <string>
#include <SDL.h>

class Text {
public:
	Text(const std::string&, const std::string&, const SDL_Color&);
	~Text();

	std::string id, text;
	SDL_Color color;
};


