#include "QuickSort.h"

QuickSort::QuickSort(std::vector<AlgData>& data)
	: m_Data(data), m_Step(0)
{
}

std::vector<AlgData> QuickSort::RunAlgPass(AlgInfo& info)
{
	std::vector<AlgData> copyDebug = m_Data;
	m_Step = 0;

	std::vector<std::vector<AlgData>> displayData;

	m_Data = Sort(m_Data, info, displayData);

	if (IsSorted(m_Data))
		info.done = true;

	
	std::vector<AlgData> returnData;

	for (int i = 0; i < displayData.size(); i++)
	{
		for (AlgData item : displayData[i])
		{
			sf::Vector2f position(item.GetPosition().x, 300 + (32.0f * i));
			item.UpdatePosition(position);
			returnData.push_back(item);
		}
	}
	return returnData;
}


std::vector<AlgData> QuickSort::Sort(std::vector<AlgData>& data, AlgInfo& info, std::vector<std::vector<AlgData>>& displayData)
{
	if (m_Step++ > info.searchIterator)
		return data;

	if (data.size() < 2)
	{
		return data;
	}

	AlgData pivot = data[data.size() / 2 - 1];
	m_Step++;
	std::vector<AlgData> less;
	std::vector<AlgData> greater;
	sf::Vector2f leftPosition(0.0f, 0.0f);
	sf::Vector2f rightPosition(2000.0f, 0.0f);
	std::vector<AlgData> displayLine;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].GetValue() == pivot.GetValue())
		{
			displayLine.push_back(data[i]);
			displayLine.back().SetSearchState(State::FOUND);
			sf::Vector2f centerPosition = sf::Vector2f(1000.0f, 0.0f);
			displayLine.back().UpdatePosition(centerPosition);
			continue;
		}
		if (data[i].GetValue() < pivot.GetValue())
		{
			less.push_back(data[i]);
			displayLine.push_back(data[i]);
			displayLine.back().SetSearchState(State::SEARCHING);
			displayLine.back().UpdatePosition(leftPosition);
			leftPosition.x += 32.0f;
		}
		else
		{
			greater.push_back(data[i]);
			displayLine.push_back(data[i]);
			displayLine.back().SetSearchState(State::EMPTY);
			displayLine.back().UpdatePosition(rightPosition);
			rightPosition.x -= 32.0f;
		}
	}
	displayData.push_back(displayLine);

	std::vector<AlgData> sortedLess = Sort(less, info, displayData);
	std::vector<AlgData> sortedGreater = Sort(greater, info, displayData);

	sortedLess.push_back(pivot);
	for (int i = 0; i < sortedGreater.size(); i++)
	{
		sortedLess.push_back(sortedGreater[i]);
	}
	Helpers::OrganizePositions(sortedLess, sf::Vector2f(0.0f, 100.f));
	sf::Vector2f newVectorPosition;

	return sortedLess;
}

std::vector<std::vector<AlgData>> QuickSort::SortDisplayLinesBySize(std::vector<std::vector<AlgData>> displayData)
{
	if (displayData.size() < 2)
	{
		return displayData;
	}

	std::vector<AlgData> pivot = displayData[displayData.size() / 2 - 1];
	std::vector<std::vector<AlgData>> less;
	std::vector<std::vector<AlgData>> greater;
	std::vector<std::vector<AlgData>> middle;

	for (int i = 0; i < displayData.size(); i++)
	{
		if (displayData[i].size() == pivot.size())
		{
			middle.push_back(displayData[i]);
			continue;
		}
		if (displayData[i].size() < pivot.size())
			less.push_back(displayData[i]);
		else
			greater.push_back(displayData[i]);
	}

	std::vector<std::vector<AlgData>> sortedLess = SortDisplayLinesBySize(less);
	std::vector<std::vector<AlgData>> sortedGreater = SortDisplayLinesBySize(greater);

	for (std::vector<AlgData> data : middle)
		sortedLess.push_back(data);
	for (std::vector<AlgData> data : sortedGreater)
		sortedLess.push_back(data);
	

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
