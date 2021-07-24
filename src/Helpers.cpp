#include "Helpers.h"

void Helpers::Wait(sf::Time time)
{
    sf::Time t1 = time;
    sf::Clock clock;
    while (clock.getElapsedTime() < t1);
}

sf::Vector2f Helpers::GetCenterObjectOnBackgroundPosition(sf::Vector2f backgroundPosition, sf::FloatRect backgroundObjectBounds, sf::FloatRect foregroundObjectBounds)
{
    float xPos = (backgroundPosition.x + backgroundObjectBounds.width / 2) - (foregroundObjectBounds.width / 2);
    float yPos = (backgroundPosition.y + backgroundObjectBounds.height / 2) - (foregroundObjectBounds.height / 1.5);
    return sf::Vector2f(xPos, yPos);
}

void Helpers::OrganizePositions(std::vector<AlgData>& data, sf::Vector2f startingPos, bool shouldWrap, const unsigned int windowHeight, const unsigned int windowWidth)
{
    sf::Vector2f position = startingPos;
    for (int i = 0; i < 30; i++)
    {
        data[i].UpdatePositon(position);
        position.x += 65;
        if (shouldWrap)
            if (position.x > windowWidth - 65)
            {
                position.x = 0.0f;
                position.y += 65.0f;
            }
    }
}