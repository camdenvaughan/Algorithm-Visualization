#include "SimpleSearch.h"

#include <iostream>


SimpleSearch::SimpleSearch(std::vector<AlgData>& data, sf::RenderWindow& window)
	: m_Data(data)
{
	m_Window = &window;
}

void SimpleSearch::OnRun(int value, sf::Time waitTime)
{
	int i = 0;
	while (i < m_Data.size())
	{
		if (m_Data[i].GetValue() == value)
		{
			m_Data[i].SetSearchState(State::FOUND);
			return;
		}
		else
		{
			m_Data[i].SetSearchState(State::SEARCHING);
			++i;
		}

		Renderer::DrawVector(*m_Window, m_Data);

		Helpers::Wait(waitTime);
	}
	std::cout << "Could not find" << std::endl;
}
