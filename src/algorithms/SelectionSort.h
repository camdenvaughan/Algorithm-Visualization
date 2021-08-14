#pragma once
#include "Algorithm.h"

class SelectionSort : public Algorithm
{
public:
	SelectionSort(std::vector<AlgData>& data, AlgInfo& info);

	std::vector<AlgData> RunAlgPass() override;

private:
	std::vector<AlgData>& m_Data;
	AlgInfo& m_AlgInfo;

private:
	int FindSmallest(std::vector<AlgData>& data);
};

