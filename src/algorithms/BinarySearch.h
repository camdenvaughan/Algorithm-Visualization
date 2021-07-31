#pragma once

#include "Algorithm.h"


class BinarySearch : public Algorithm
{
public:

	BinarySearch(std::vector<AlgData>& data);

	std::vector<AlgData> RunAlgPass(AlgInfo& info) override;

private:
	std::vector<AlgData>& m_Data;
};

