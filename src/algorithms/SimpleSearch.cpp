#include "SimpleSearch.h"
#include "../Helpers.h"

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

		m_Window->clear();
		for (size_t i = 0; i < m_Data.size(); i++)
			m_Window->draw(m_Data[i].GetSprite());
		m_Window->display();

		Wait(waitTime);
	}
	std::cout << "Could not find" << std::endl;
}
