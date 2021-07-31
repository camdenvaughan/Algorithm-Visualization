#pragma once
#include "Algorithm.h"

class SelectionSort : public Algorithm
{
public:
	SelectionSort(std::vector<AlgData>& data);

	std::vector<AlgData> RunAlgPass(AlgInfo& info) override;

private:
	std::vector<AlgData>& m_Data;
private:
	int FindSmallest(std::vector<AlgData>& data);
};

