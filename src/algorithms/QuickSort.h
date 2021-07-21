#pragma once
#include "Algorithm.h"
class QuickSort : public Algorithm
{
public:
	QuickSort(std::vector<AlgData>& data, sf::RenderWindow& window);

	void OnRun(int value, sf::Time waitTime) override;

private:
	std::vector<AlgData>& m_Data;
	unsigned int m_Step;

	std::vector<AlgData> m_DisplayData;

private:
	std::vector<AlgData> Sort(std::vector<AlgData>& data);

};

