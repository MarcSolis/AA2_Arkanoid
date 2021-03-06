#include "Renderer.h"


//Constructor
Renderer::Renderer()
{
	// --- INIT ---
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) throw "No es pot inicialitzar SDL subsystems";

	// --- WINDOW ---
	m_window = SDL_CreateWindow("SDL...", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (m_window == nullptr) throw "No es pot inicialitzar SDL_Window";

	// --- RENDERER ---
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == nullptr) throw "No es pot inicialitzar SDL_Renderer";

	//Initialize renderer color
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

	//Initialize PNG loading
	const Uint8 imgFlags{ IMG_INIT_PNG | IMG_INIT_JPG };
	if (!(IMG_Init(imgFlags) & imgFlags)) throw "Error: SDL_imageinit";

	// ---- TTF ----
	if (TTF_Init() != 0) throw "No es pot inicialitzar SDL_ttf";
};

//Functions

	//Clean renderer
	void Renderer::Clear() { SDL_RenderClear(m_renderer); };

	//Print renderer
	void Renderer::Render() { SDL_RenderPresent(m_renderer); };

	void Renderer::LoadFont(Font font) {
		TTF_Font *ttfFont{ TTF_OpenFont(font.path.c_str(), font.size) };
		if (ttfFont == nullptr) throw"No espot inicialitzar TTF_Font";
		m_fontData[font.id] = ttfFont;
	};

	void Renderer::LoadTexture(const std::string &id, const std::string &path) {
		SDL_Texture *texture{ IMG_LoadTexture(m_renderer, path.c_str()) };
		if (texture == nullptr) throw "No s'han pogut crear les textures";
		m_textureData[id] = texture;
	};

	void Renderer::LoadTextureText(const std::string &fontId, Text text) {
		SDL_Surface	*tmpSurf = TTF_RenderText_Blended(m_fontData[fontId], text.text.c_str(), SDL_Color{ (uint8_t)text.color.r, (uint8_t)text.color.g, (uint8_t)text.color.b,(uint8_t)text.color.a });
		if (tmpSurf == nullptr) throw "Unable to create the SDL text surface";
		SDL_Texture *texture{ SDL_CreateTextureFromSurface(m_renderer, tmpSurf) };
		m_textureData[text.id] = texture;
	};

	Vec2 Renderer::GetTextureSize(const std::string &id) {
		int w; int h;
		SDL_QueryTexture(m_textureData[id], NULL, NULL, &w, &h);
		return { w, h };
	}

	void Renderer::PushImage(const std::string &id, const SDL_Rect &rect) {
		SDL_RenderCopy(m_renderer, m_textureData[id], nullptr, &rect);
	};



	void Renderer::PushSprite(const std::string &id, const SDL_Rect &rectSprite, const SDL_Rect &rectPos) {
		SDL_RenderCopy(m_renderer, m_textureData[id], &rectSprite, &rectPos);
	}

	void Renderer::PushRotatedImage(const std::string &id, const SDL_Rect &rect, float angle) {
		SDL_Point center = { rect.w / 2, rect.h / 2 };
		SDL_RenderCopyEx(m_renderer, m_textureData[id], nullptr, &rect, angle, &center, SDL_FLIP_NONE);
	}

	void Renderer::PushRotatedSprite(const std::string & id, const SDL_Rect & rectSprite, const SDL_Rect & rectPos, float angle) {
		SDL_Point center = { rectPos.w / 2, rectPos.h / 2 };
		SDL_RenderCopyEx(m_renderer, m_textureData[id], &rectSprite, &rectPos, angle, &center, SDL_FLIP_NONE);
	}

	void Renderer::SetRenderDrawColor(int r, int g, int b)
	{
		SDL_SetRenderDrawColor(m_renderer, r, g, b, 255);
	}

	void Renderer::DeleteTexture(const std::string &name)
	{
		auto it = m_textureData.find(name);
		SDL_DestroyTexture(it->second);
		it->second = nullptr;
		m_textureData.erase(it);
	}

	Renderer* Renderer::renderer = nullptr;

//Destructor
Renderer::~Renderer()
{
	//Delete textures
	for (auto &t : m_textureData) SDL_DestroyTexture(t.second), t.second = nullptr;
	//Delete fonts
	for (auto &f : m_fontData) TTF_CloseFont(f.second), f.second = nullptr;
	//Delete renderer and his pointer
	SDL_DestroyRenderer(m_renderer);
	m_renderer = nullptr;
	//Delete window and his pointer
	SDL_DestroyWindow(m_window);
	m_window = nullptr;

	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}
