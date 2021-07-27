#pragma once
#include "Algorithm.h"

class SelectionSort : public Algorithm
{
public:
	SelectionSort(std::vector<AlgData>& data);

	void OnRun(int value, sf::Time waitTime);

private:
	std::vector<AlgData>& m_Data;
private:
	int FindSmallest(std::vector<AlgData>& data);
};

