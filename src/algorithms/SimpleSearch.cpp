#include "SimpleSearch.h"

#include <iostream>


SimpleSearch::SimpleSearch(std::vector<AlgData>& data)
	: m_Data(data)
{
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

		//Renderer::GetInstance()->DrawVector(m_Data);

		Helpers::Wait(waitTime);
	}
	std::cout << "Could not find" << std::endl;
}
