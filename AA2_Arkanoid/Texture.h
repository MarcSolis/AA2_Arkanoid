#pragma once
#include "Common.h"
class Texture
{
public:

	std::string id;
	std::string path;

	Texture();
	Texture(const std::string &, const std::string &);
	~Texture();
};

