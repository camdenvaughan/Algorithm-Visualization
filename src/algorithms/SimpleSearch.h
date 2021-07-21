#pragma once

#include "Algorithm.h"

class SimpleSearch : public Algorithm
{
public:

	SimpleSearch(std::vector<AlgData>& data, sf::RenderWindow& window);

	void OnRun(int value, sf::Time waitTime) override;

private:
	std::vector<AlgData>& m_Data;
};

