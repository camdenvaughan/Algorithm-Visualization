#pragma once

#include "Algorithm.h"


class BinarySearch : public Algorithm
{
public:

	BinarySearch(std::vector<AlgData>& data, AlgInfo& info);

	std::vector<AlgData> RunAlgPass() override;

private:
	std::vector<AlgData>& m_Data;
	AlgInfo& m_AlgInfo;
};

