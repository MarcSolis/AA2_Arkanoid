#pragma once
#include <string>
#include <SDL.h>
#include "Common.h"

class Text {
public:
	Text(const std::string&, const std::string&, const Color&);
	~Text();

	std::string id, text;
	Color color;
};


