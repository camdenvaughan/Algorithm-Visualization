#include "QuickSort.h"

QuickSort::QuickSort(std::vector<AlgData>& data, AlgInfo& info)
	: m_Data(data), m_AlgInfo(info)
{
}

std::vector<AlgData> QuickSort::RunAlgPass()
{
	// Create a vector of vectors that will hold each rucursive line of quicksort
	std::vector<std::vector<AlgData>> displayData;

	// Run Quicksort
	m_Data = Sort(m_Data, displayData);

	// Confirm that data is sorted
	m_AlgInfo.done = IsSorted(m_Data);

	// Move and orginize the positions on all of the elements from each vector in displayData into a single vector of AlgData
	std::vector<AlgData> returnData;
	int j = 0;
	for (int i = 0; i < displayData.size(); i++)
	{
		j += Helpers::OrganizePositions(displayData[i], sf::Vector2f(0.0f, 500 + (32.0f * j))) + 2;

		for (AlgData item : displayData[i])
			returnData.push_back(item);
	}
	return returnData;
}


std::vector<AlgData> QuickSort::Sort(std::vector<AlgData>& data, std::vector<std::vector<AlgData>>& displayData)
{
	// Base case
	if (data.size() < 2)
	{
		return data;
	}
	
	// Create a pivot in the center
	AlgData& pivot = data[data.size() / 2 - 1];

	// Create vectors to hold what is greater and less than the pivot
	std::vector<AlgData> less;
	std::vector<AlgData> greater;

	// Compare data with pivot
	for (int i = 0; i < data.size(); i++)
	{
		if (i == data.size() / 2 - 1)
			continue;
		if (data[i].GetValue() < pivot.GetValue())
			less.push_back(data[i]);
		else
			greater.push_back(data[i]);
	}

	// create a vector this will be one line of the visualization
	std::vector<AlgData> displayLine;

	for (AlgData item : less)
		displayLine.push_back(item);

	displayLine.push_back(pivot);
	displayLine.back().SetSearchState(State::SEARCHING);

	for (AlgData item : greater)
		displayLine.push_back(item);

	// Push back the line
	displayData.push_back(displayLine);

	// recursively run quicksort on less and greater vectors
	std::vector<AlgData> sortedLess = Sort(less, displayData);
	std::vector<AlgData> sortedGreater = Sort(greater, displayData);

	// combine the data from sortedLess and sortedGreater
	sortedLess.push_back(pivot);
	for (AlgData& item : sortedGreater)
		sortedLess.push_back(item);

	return sortedLess;
}

