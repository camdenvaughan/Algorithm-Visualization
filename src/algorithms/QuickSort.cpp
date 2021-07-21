#include "QuickSort.h"

QuickSort::QuickSort(std::vector<AlgData>& data, sf::RenderWindow& window)
	: m_Data(data), m_Step(0)
{
	m_Window = &window;
}

void QuickSort::OnRun(int value, sf::Time waitTime)
{
	m_Data = Sort(m_Data);
	sf::Vector2f position;
	Helpers::OrganizePositions(m_Data, sf::Vector2f(0.0f, 10.0f));
	for (AlgData& item : m_Data)
		item.SetSearchState(State::FOUND);
	m_Window->clear();
	Renderer::DrawVector(*m_Window, m_Data, false);
	Renderer::DrawVector(*m_Window, m_DisplayData, false);
	m_Window->display();
	Helpers::Wait(sf::milliseconds(600));
	for (AlgData& item : m_Data)
		item.SetSearchState(State::EMPTY);
}

std::vector<AlgData> QuickSort::Sort(std::vector<AlgData>& data)
{
	if (data.size() < 2)
	{
		return data;
	}
	m_Step += 2;

	AlgData pivot = data[data.size() / 2 - 1];
	std::vector<AlgData> less;
	std::vector<AlgData> greater;

	sf::Vector2f pivotPosition = sf::Vector2f(m_Window->getSize().x / 2 - 64, m_Step * 65.0f);
	sf::Vector2f lessPosition = sf::Vector2f(0.0f, (m_Step + 1) * 65.0f);
	sf::Vector2f greaterPosition = sf::Vector2f(m_Window->getSize().x - 64, (m_Step + 1) * 65.0f);
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
			lessPosition.x += 64.f;

		}
		else
		{
			greater.push_back(data[i]);
			m_DisplayData.push_back(data[i]);
			m_DisplayData.back().UpdatePositon(greaterPosition);
			greaterPosition.x -= 64.f;
		}
	}

	m_Window->clear();
	Renderer::DrawVector(*m_Window, m_Data, false);
	Renderer::DrawVector(*m_Window, m_DisplayData, false);
	m_Window->display();
	Helpers::Wait(sf::milliseconds(100));

	std::vector<AlgData> sortedLess = Sort(less);
	std::vector<AlgData> sortedGreater = Sort(greater);

	sortedLess.push_back(pivot);
	for (int i = 0; i < sortedGreater.size(); i++)
	{
		sortedLess.push_back(sortedGreater[i]);
	}

	sf::Vector2f newVectorPosition;
	for (AlgData& item : sortedLess)
	{
		item.UpdatePositon(newVectorPosition);
		newVectorPosition.x += 64.f;
		if (newVectorPosition.x > 950)
		{
			newVectorPosition.x = 0.0f;
			newVectorPosition.y += 65.0f;
		}
	}

	return sortedLess;
}
