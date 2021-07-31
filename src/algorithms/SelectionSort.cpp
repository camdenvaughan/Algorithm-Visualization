#include "SelectionSort.h"

SelectionSort::SelectionSort(std::vector<AlgData>& data)
	: m_Data(data)
{
}

std::vector<AlgData> SelectionSort::RunAlgPass(AlgInfo& info)
{
	std::vector<AlgData> sortedData;
	sortedData.reserve(info.maxIterations);

	int i = 0;
	do
	{
		if (i == info.maxIterations)
		{
			std::cout << "done\n";
			info.done = true;
			return sortedData;
		}
		int smallestIndex = FindSmallest(m_Data);
		sortedData.push_back(m_Data[smallestIndex]);
		m_Data.erase(m_Data.begin() + smallestIndex);
	} while (i++ < info.searchIterator);


	return sortedData;
}



int SelectionSort::FindSmallest(std::vector<AlgData>& data)
{
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
