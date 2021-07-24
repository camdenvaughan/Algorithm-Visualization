#include "Renderer.h"

Renderer::Renderer()
{
	
}
Renderer* Renderer::GetInstance()
{
	static Renderer* instance;
	return instance;
}

sf::Texture* Renderer::LoadTexture(const char* path)
{
	if (!m_TextureAtlas->loadFromFile(path))
	{
		std::cout << "Texture failed to load" << std::endl;
	}
	return m_TextureAtlas;
}

sf::Font* Renderer::LoadFont(const char* path)
{
	if (!m_Font->loadFromFile(path))
	{
		std::cout << "Font failed to load" << std::endl;
	}
	return m_Font;
}
