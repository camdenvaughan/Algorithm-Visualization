#pragma once

#include "Algorithm.h"


class BinarySearch : public Algorithm
{
public:

	BinarySearch(std::vector<AlgData>& data);

	AlgInfo& RunAlgPass(AlgInfo& info) override;

private:
	std::vector<AlgData>& m_Data;
};

