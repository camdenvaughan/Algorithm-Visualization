#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "algorithms/AlgData.h"

class Renderer
{
private:

	sf::Texture m_TextureAtlas;
	sf::Font m_Font;

public:
	static Renderer& GetInstance();

	sf::Texture& LoadTexture(const char* path);
	sf::Font& LoadFont(const char* path);

	inline sf::Texture& GetTexture() { return m_TextureAtlas; }
	inline sf::Font& GetFont() { return m_Font;  }

private:

	Renderer();
	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;
};