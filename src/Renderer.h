#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "algorithms/AlgData.h"

class Renderer
{
private:

	sf::Font m_Font;
public:
	static Renderer* GetInstance();
	~Renderer();


	sf::Font& GetFont() { return m_Font;  }

private:

	Renderer();
	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;
};