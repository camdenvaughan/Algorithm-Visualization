#pragma once

#include <SFML/Graphics.hpp>
#include "AlgData.h"
#include "../Renderer.h"
#include "../Helpers.h"

struct AlgInfo
{
	AlgInfo(int value, int low, int high) : value(value), low(low), high(high) {}
	AlgInfo(int value) : value(value), low(0), high(0) {}
	AlgInfo() : value(0), low(0), high(0) {}

	int value, low, high;
	unsigned int searchIterator = 0;
	unsigned int maxIterations = 0;
	bool done = false;
	bool isNotInContainer = false;
};
class Algorithm 
{
	virtual std::vector<AlgData> RunAlgPass(AlgInfo& info) = 0;
};
