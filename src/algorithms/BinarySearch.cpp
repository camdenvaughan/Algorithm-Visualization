#include "BinarySearch.h"
#include "../Helpers.h"

#include <iostream>

BinarySearch::BinarySearch(std::vector<AlgData>& data, sf::RenderWindow& window)
    : m_Data(data)
{
    m_Window = &window;
}
void BinarySearch::OnRun(int value, sf::Time waitTime)
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
            m_Window->draw(m_Data[i].GetSprite());
        m_Window->display();

        if (m_Data[mid].GetValue() > value)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

        Wait(waitTime);
    }
    std::cout << "Could not find" << std::endl;
}
