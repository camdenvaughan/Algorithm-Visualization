#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "algorithms/AlgData.h"

class Renderer
{
public:
	static void DrawVector(sf::RenderWindow& window, std::vector<AlgData>& data, bool shouldClearAndDisplay = true)
	{
		if (shouldClearAndDisplay)
			window.clear();
		for (AlgData& item : data)
			item.Draw(window);
		if (shouldClearAndDisplay)
			window.display();
	}
};