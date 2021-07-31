#include "QuickSort.h"

QuickSort::QuickSort(std::vector<AlgData>& data)
	: m_Data(data), m_Step(0)
{
}

std::vector<AlgData> QuickSort::RunAlgPass(AlgInfo& info)
{

	m_Step = 0;

	m_DisplayData.erase(std::begin(m_DisplayData), std::end(m_DisplayData));

	m_Data = Sort(m_Data, info);

	return m_DisplayData;
}

std::vector<AlgData> QuickSort::Sort(std::vector<AlgData>& data, AlgInfo& info)
{
	if (info.searchIterator == info.maxIterations || info.searchIterator > info.maxIterations)
	{
		std::cout << "done\n";
		info.done = true;
		return data;
	}
	if (data.size() < 2)
	{
		return data;
	}
	m_Step += 2;

	if (!(m_Step < info.searchIterator))
	{
		info.searchIterator += 2;
		return data;
	}


	AlgData pivot = data[data.size() / 2 - 1];
	std::vector<AlgData> less;
	std::vector<AlgData> greater;

	sf::Vector2f pivotPosition = sf::Vector2f(2000 / 2, m_Step * 32.f);
	sf::Vector2f lessPosition = sf::Vector2f(0.0f, (m_Step + 1) * 32.0f);
	sf::Vector2f greaterPosition = sf::Vector2f(2000, (m_Step + 1) * 32.0f);
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].GetValue() == pivot.GetValue())
		{
			m_DisplayData.push_back(data[i]);
			m_DisplayData.back().SetSearchState(State::SEARCHING);
			m_DisplayData.back().UpdatePositon(pivotPosition);
			continue;
		}
		if (data[i].GetValue() < pivot.GetValue())
		{
			less.push_back(data[i]);
			m_DisplayData.push_back(data[i]);
			m_DisplayData.back().UpdatePositon(lessPosition);
			m_DisplayData.back().SetSearchState(State::FOUND);

			lessPosition.x += 32.f;

		}
		else
		{
			greater.push_back(data[i]);
			m_DisplayData.push_back(data[i]);
			m_DisplayData.back().UpdatePositon(greaterPosition);
			m_DisplayData.back().SetSearchState(State::FOUND);
			greaterPosition.x -= 32.f;
		}
	}
	m_Step++;

	std::vector<AlgData> sortedLess = Sort(less, info);
	std::vector<AlgData> sortedGreater = Sort(greater, info);

	sortedLess.push_back(pivot);
	for (int i = 0; i < sortedGreater.size(); i++)
	{
		sortedLess.push_back(sortedGreater[i]);
	}
	Helpers::OrganizePositions(sortedLess, sf::Vector2f(0.0f, 100.f));
	sf::Vector2f newVectorPosition;

	return sortedLess;
}
