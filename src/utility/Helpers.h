#pragma once
#include "SFML/Graphics.hpp"
#include "algorithms/AlgData.h"
class Helpers
{
public:

static void Wait(sf::Time time);

static sf::Vector2f GetCenterPositionOnBackgroundObject(sf::Vector2f backgroundPosition, sf::FloatRect backgroundObjectBounds, sf::FloatRect foregroundObjectBounds);

static int OrganizePositions(std::vector<AlgData>& data, sf::Vector2f startingPos = sf::Vector2f(0.0f, 0.0f), float xIncrement = 32.0f, float yIncrement = 0.0f, bool shouldWrap = true, float wrapYIncrement = 32.0f, const unsigned int windowHeight = 900, const unsigned int windowWidth = 1000);
private:
	Helpers() {};
};