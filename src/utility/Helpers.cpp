#include "Helpers.h"

void Helpers::Wait(sf::Time time)
{
    sf::Time t1 = time;
    sf::Clock clock;
    while (clock.getElapsedTime() < t1);
}

sf::Vector2f Helpers::GetCenterPositionOnBackgroundObject(sf::Vector2f backgroundPosition, sf::FloatRect backgroundObjectBounds, sf::FloatRect foregroundObjectBounds)
{
    float xPos = (backgroundPosition.x + backgroundObjectBounds.width / 2.0f) - (foregroundObjectBounds.width / 2.0f);
    float yPos = (backgroundPosition.y + backgroundObjectBounds.height / 2.0f) - (foregroundObjectBounds.height / 1.5f);
    return sf::Vector2f(xPos, yPos);
}

// Returns the amount of times that a data was wrapped
int Helpers::OrganizePositions(std::vector<AlgData>& data, sf::Vector2f startingPos, float xIncrement, float yIncrement, bool shouldWrap, float wrapYIncrement, const unsigned int windowHeight, const unsigned int windowWidth)
{
    int amountWrapped = 0;
    sf::Vector2f position = startingPos;
    for (int i = 0; i < data.size(); i++)
    {
        data[i].UpdatePosition(position);
        position.x += xIncrement;
        position.y += yIncrement;
        if (shouldWrap)
            if (position.x > windowWidth - xIncrement + 1)
            {
                position.x = 0.0f;
                position.y += wrapYIncrement;
                ++amountWrapped;
            }
    }
    return amountWrapped;
}