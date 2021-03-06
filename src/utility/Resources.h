#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "algorithms/AlgData.h"

class Resources
{
private:

	sf::Texture m_TextureAtlas;
	sf::Font m_Font;

public:
	static Resources& GetInstance();

	static inline sf::Texture& LoadTexture(const char* path) { return GetInstance().LoadTextureImpl(path); }
	static inline sf::Font& LoadFont(const char* path) { return GetInstance().LoadFontImpl(path); }

	static inline sf::Texture& GetTexture() { return GetInstance().GetTextureImpl(); }
	static inline sf::Font& GetFont() { return GetInstance().GetFontImpl(); }

private:

	sf::Texture& LoadTextureImpl(const char* path);
	sf::Font& LoadFontImpl(const char* path);
	inline sf::Texture& GetTextureImpl() { return m_TextureAtlas; }
	inline sf::Font& GetFontImpl() { return m_Font;  }

	Resources();
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;
};