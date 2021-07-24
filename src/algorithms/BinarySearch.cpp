#include "BinarySearch.h"


#include <iostream>

BinarySearch::BinarySearch(std::vector<AlgData>& data)
    : m_Data(data)
{
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

        //Renderer::GetInstance()->DrawVector(m_Data);

        if (m_Data[mid].GetValue() > value)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

        Helpers::Wait(waitTime);
    }
    std::cout << "Could not find" << std::endl;
}
