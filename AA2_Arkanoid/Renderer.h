#pragma once
#include "Common.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "Vec2.h"
#include "Text.h"
#include "Font.h"
#include <unordered_map>

class Renderer	//Implemented with SDL
{
private:
//Attributes
	SDL_Renderer *m_renderer = nullptr;
	SDL_Window *m_window = nullptr;
	std::unordered_map<std::string, SDL_Texture*> m_textureData;
	std::unordered_map<std::string, TTF_Font*> m_fontData;

	static Renderer *renderer;

//Constructor
	Renderer();

public:

//Functions
	static Renderer *Instance() {
		if (renderer == nullptr) { renderer = new Renderer; }
		return renderer;
	}

	void Clear();
	void Render();
	void LoadFont(Font font);
	void LoadTexture(const std::string &id, const std::string &path);
	void LoadTextureText(const std::string &fontId, Text text);
	Vec2 GetTextureSize(const std::string &id);
	void PushImage(const std::string &id, const SDL_Rect &rect);
	void PushSprite(const std::string &id, const SDL_Rect &rectSprite, const SDL_Rect &rectPos);
	void PushRotatedSprite(const std::string &id, const SDL_Rect &rectSprite, const SDL_Rect &rectPos, float angle);
	void SetRenderDrawColor(int r, int g, int b);

//Destructor
	~Renderer();
};

