#pragma once

#include "Algorithm.h"
struct SimpleSearchBounds {
	unsigned int currentSearch = 0;
	bool isFound;
};

class SimpleSearch : public Algorithm
{
public:

	SimpleSearch(std::vector<AlgData>& data, AlgInfo& info);

	std::vector<AlgData> RunAlgPass() override;

private:
	std::vector<AlgData>& m_Data;
	AlgInfo& m_AlgInfo;
};

