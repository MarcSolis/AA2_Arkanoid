#include "Texture.h"


Texture::Texture() {}

Texture::Texture(const std::string &_id, const std::string &_path) {
	id = _id;
	path = _path;
}

Texture::~Texture()
{
}
