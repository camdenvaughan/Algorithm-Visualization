#include "QuickSort.h"

QuickSort::QuickSort(std::vector<AlgData>& data, AlgInfo& info)
	: m_Data(data), m_AlgInfo(info)
{
}

std::vector<AlgData> QuickSort::RunAlgPass()
{
	std::vector<std::vector<AlgData>> displayData;

	m_Data = Sort(m_Data, displayData);

	if (IsSorted(m_Data))
		m_AlgInfo.done = true;

	
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
	if (data.size() < 2)
	{
		return data;
	}

	AlgData pivot = data[data.size() / 2 - 1];

	std::vector<AlgData> less;
	std::vector<AlgData> greater;
	for (int i = 0; i < data.size(); i++)
	{
		if (i == data.size() / 2 - 1)
			continue;
		if (data[i].GetValue() < pivot.GetValue())
			less.push_back(data[i]);
		else
			greater.push_back(data[i]);
	}

	std::vector<AlgData> displayLine;

	for (AlgData item : less)
		displayLine.push_back(item);

	displayLine.push_back(pivot);
	displayLine.back().SetSearchState(State::SEARCHING);

	for (AlgData item : greater)
		displayLine.push_back(item);

	displayData.push_back(displayLine);

	std::vector<AlgData> sortedLess = Sort(less, displayData);
	std::vector<AlgData> sortedGreater = Sort(greater, displayData);

	sortedLess.push_back(pivot);
	for (AlgData& item : sortedGreater)
		sortedLess.push_back(item);
	
	Helpers::OrganizePositions(sortedLess, sf::Vector2f(0.0f, 100.f));

	return sortedLess;
}

bool QuickSort::IsSorted(std::vector<AlgData>& data)
{
	for (int i = 0; i < data.size() - 1; i++)
	{
		if (data[i].GetValue() > data[i + 1].GetValue())
			return false;
	}
	return true;
}
