#include "BinarySearch.h"
#include "../Helpers.h"

#include <iostream>

BinarySearch::BinarySearch(sf::RenderWindow& window, sf::Sprite& sprite, std::vector<AlgData>& data)
    : m_Window(&window), m_Sprite(&sprite), m_Data(data)
{
}
void BinarySearch::OnRun(int value)
{
    int low = 0;
    int high = m_Data.size() - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (m_Data[mid].GetValue() == value)
        {
            m_Data[mid].SetSearchState(State::FOUND);
            return;
        }

        m_Data[mid].SetSearchState(State::SEARCHING);

        m_Window->clear();
        for (size_t i = 0; i < m_Data.size(); i++)
        {
            m_Sprite->setTextureRect(m_Data[i].GetTexCoords());
            m_Sprite->setPosition(m_Data[i].GetPosition());
            m_Window->draw(*m_Sprite);
        }
        m_Window->display();

        if (m_Data[mid].GetValue() > value)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

        Wait(sf::seconds(1.0f));
    }
    std::cout << "Could not find" << std::endl;
}
