#include "Font.h"


Font::Font(const std::string &id, const std::string &path, const int &size) :
	id(id), path(path), size(size)
{}

Font::~Font()
{
}
