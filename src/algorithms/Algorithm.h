#pragma once
#include <SFML/Graphics.hpp>
class Algorithm 
{
	virtual void OnRun(int value, sf::Time waitTime) = 0;

protected:
	sf::RenderWindow* m_Window;
};
