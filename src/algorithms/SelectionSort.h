#pragma once
#include "Algorithm.h"

class SelectionSort : public Algorithm
{
public:
	SelectionSort(std::vector<AlgData>& data, sf::RenderWindow& window);

	void OnRun(int value, sf::Time waitTime) override;

private:
	std::vector<AlgData>& m_Data;
private:
	int FindSmallest(std::vector<AlgData>& data);
};

