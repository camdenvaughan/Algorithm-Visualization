#pragma once

#include <SFML/Graphics.hpp>
#include "AlgData.h"
#include "Resources.h"
#include "Helpers.h"

// stuct containing information about the current algorithm. Helps remember the state of an algorithm in between update calls.
struct AlgInfo
{
	inline AlgInfo(int value, int low, int high) : value(value), low(low), high(high) {}
	inline AlgInfo(int value) : value(value), low(0), high(0) {}
	inline AlgInfo() : value(0), low(0), high(0) {}

	int value, low, high;
	unsigned int searchIterator = 0;
	unsigned int maxIterations = 0;
	bool done = false;
	bool isNotInContainer = false;
};

// pure virtual function for algorithms
class Algorithm 
{
	virtual std::vector<AlgData> RunAlgPass() = 0;
public:
	bool IsSorted(std::vector<AlgData>& data)
	{
		for (int i = 0; i < data.size() - 1; i++)
		{
			if (data[i].GetValue() > data[i + 1].GetValue())
				return false;
		}
		return true;
	}
};
