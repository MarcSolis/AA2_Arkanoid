#pragma once
#include <string>

class Font
{
public:
	Font(const std::string&, const std::string&, const int&);
	~Font();

	std::string path, id;
	int size;
};

