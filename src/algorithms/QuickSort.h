#pragma once
#include "Algorithm.h"
class QuickSort : public Algorithm
{
public:
	QuickSort(std::vector<AlgData>& data, AlgInfo& info);

	std::vector<AlgData> RunAlgPass() override;

private:
	std::vector<AlgData>& m_Data;
	AlgInfo& m_AlgInfo;

	std::vector<AlgData> m_DisplayData;

private:
	std::vector<AlgData> Sort(std::vector<AlgData>& data, std::vector<std::vector<AlgData>>& displayData);

	bool IsSorted(std::vector<AlgData>& data);

};

