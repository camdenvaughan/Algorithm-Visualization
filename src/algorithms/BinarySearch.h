#pragma once

#include "Algorithm.h"

class BinarySearch : public Algorithm
{
public:

	BinarySearch(std::vector<AlgData>& data);

	void OnRun(int value, sf::Time waitTime) override;

private:
	std::vector<AlgData>& m_Data;
};

