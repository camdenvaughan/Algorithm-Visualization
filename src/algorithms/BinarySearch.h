#pragma once

#include "Algorithm.h"

struct SearchBounds
{
	SearchBounds(int low, int high) : low(low), high(high) {}
	SearchBounds() : low(0), high(0) {}
	int low, high;
	bool found = false;
};

class BinarySearch : public Algorithm
{
public:

	BinarySearch(std::vector<AlgData>& data);

	void OnRun(int value, sf::Time waitTime) override;

	SearchBounds& RunSearchPass(int value, SearchBounds& bounds);

private:
	std::vector<AlgData>& m_Data;
};

