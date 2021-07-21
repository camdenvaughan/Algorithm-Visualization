#include "Helpers.h"

void Wait(sf::Time time)
{
    sf::Time t1 = time;
    sf::Clock clock;
    while (clock.getElapsedTime() < t1);
}