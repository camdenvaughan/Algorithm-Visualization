#include "Resources.h"

sf::Texture& Resources::LoadTextureImpl(const char* path)
{
	if (!m_TextureAtlas.loadFromFile(path))
	{
		std::cout << "Texture failed to load" << std::endl;
	}
	return m_TextureAtlas;
}

sf::Font& Resources::LoadFontImpl(const char* path)
{
	if (!m_Font.loadFromFile(path))
	{
		std::cout << "Font failed to load" << std::endl;
	}
	return m_Font;
}

Resources::Resources()
	: m_TextureAtlas(sf::Texture()), m_Font(sf::Font())
{
	
}
Resources& Resources::GetInstance()
{
	static Resources instance;
	
	return instance;
}