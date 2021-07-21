#include "SFML/Graphics.hpp"
#include "algorithms/AlgData.h"
class Helpers
{
public:

static void Wait(sf::Time time);

static void OrganizePositions(std::vector<AlgData>& data, sf::Vector2f startingPos = sf::Vector2f(0.0f, 0.0f), bool shouldWrap = true, const unsigned int windowHeight = 1300, const unsigned int windowWidth = 2000);
private:
	Helpers() {};
};