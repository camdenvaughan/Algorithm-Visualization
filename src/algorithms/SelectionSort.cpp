#include "SelectionSort.h"

SelectionSort::SelectionSort(std::vector<AlgData>& data, AlgInfo& info)
	: m_Data(data), m_AlgInfo(info)
{
}

std::vector<AlgData> SelectionSort::RunAlgPass()
{
	std::vector<AlgData> sortedData;
	sortedData.reserve(m_AlgInfo.maxIterations);

	int i = 0;
	do
	{
		// Check is algorithm is completed
		if (i == m_AlgInfo.maxIterations)
		{
			m_AlgInfo.done = true;
			return sortedData;
		}

		// Find the smallest index, push it into sortedData, then erase it from m_Data
		int smallestIndex = FindSmallest(m_Data);
		sortedData.push_back(m_Data[smallestIndex]);
		m_Data.erase(m_Data.begin() + smallestIndex);
	} while (i++ < m_AlgInfo.searchIterator);

	return sortedData;
}



int SelectionSort::FindSmallest(std::vector<AlgData>& data)
{
	// Check vector for the smallest value and return the index
	int smallest = data[0].GetValue();
	int smallestIndex = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].GetValue() < smallest)
		{
			smallest = data[i].GetValue();
			smallestIndex = i;
		}
	}
	return smallestIndex;
}
