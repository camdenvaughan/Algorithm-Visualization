#include "SimpleSearch.h"
#include "../Helpers.h"

#include <iostream>


SimpleSearch::SimpleSearch(sf::RenderWindow& window, sf::Sprite& sprite, std::vector<AlgData>& data)
	: m_Window(&window), m_Sprite(&sprite), m_Data(data)
{
}

void SimpleSearch::OnRun(int value)
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

		for (size_t i = 0; i < m_Data.size(); i++)
		{
			m_Sprite->setTextureRect(m_Data[i].GetTexCoords());
			m_Sprite->setPosition(m_Data[i].GetPosition());
			m_Window->draw(*m_Sprite);
		}
		m_Window->display();
		Wait(sf::seconds(1.0f));
	}
	std::cout << "Could not find" << std::endl;
}
