#pragma once

#include <SFML/Graphics.hpp>
#include "AlgData.h"
#include "../Renderer.h"
#include "../Helpers.h"

class Algorithm 
{
	virtual void OnRun(int value, sf::Time waitTime) = 0;

protected:
	sf::RenderWindow* m_Window;
};
