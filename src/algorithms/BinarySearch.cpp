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

SearchBounds& BinarySearch::RunSearchPass(int value, SearchBounds& bounds)
{
    int mid = (bounds.low + bounds.high) / 2;
    if (m_Data[mid].GetValue() == value)
    {
        m_Data[mid].SetSearchState(State::FOUND);
        bounds.found = true;
        return bounds;
    }

    m_Data[mid].SetSearchState(State::SEARCHING);


    if (m_Data[mid].GetValue() > value)
    {
        bounds.high = mid - 1;
    }
    else
    {
        bounds.low = mid + 1;
    }
    return bounds;
}

SearchBounds::SearchBounds(int low, int high)
    : low(low), high(high)
{}
