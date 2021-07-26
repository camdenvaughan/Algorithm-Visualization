#include "Renderer.h"

sf::Texture& Renderer::LoadTextureImpl(const char* path)
{
	if (!m_TextureAtlas.loadFromFile(path))
	{
		std::cout << "Texture failed to load" << std::endl;
	}
	return m_TextureAtlas;
}

sf::Font& Renderer::LoadFontImpl(const char* path)
{
	if (!m_Font.loadFromFile(path))
	{
		std::cout << "Font failed to load" << std::endl;
	}
	return m_Font;
}

Renderer::Renderer()
	: m_TextureAtlas(sf::Texture()), m_Font(sf::Font())
{
	
}
Renderer& Renderer::GetInstance()
{
	static Renderer instance;
	
	return instance;
}