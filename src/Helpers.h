#pragma once
#include "SFML/Graphics.hpp"
#include "algorithms/AlgData.h"
class Helpers
{
public:

static void Wait(sf::Time time);

static sf::Vector2f GetCenterObjectOnBackgroundPosition(sf::Vector2f backgroundPosition, sf::FloatRect backgroundObjectBounds, sf::FloatRect foregroundObjectBounds);

static void OrganizePositions(std::vector<AlgData>& data, sf::Vector2f startingPos = sf::Vector2f(0.0f, 0.0f), float xIncrement = 32.0f, float yIncrement = 0.0f, bool shouldWrap = true, float wrapYIncrement = 32.0f, const unsigned int windowHeight = 1300, const unsigned int windowWidth = 2000);
private:
	Helpers() {};
};