#pragma once
#include "AlgData.h"

class SimpleSearch
{
public:

	SimpleSearch(sf::RenderWindow& window, sf::Sprite& sprite, std::vector<AlgData>& data);

	void OnRun(int value);

private:
	class sf::RenderWindow* m_Window;
	class sf::Sprite* m_Sprite;

	std::vector<AlgData>& m_Data;
};

