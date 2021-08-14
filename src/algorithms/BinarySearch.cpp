#include "BinarySearch.h"

#include <iostream>

BinarySearch::BinarySearch(std::vector<AlgData>& data, AlgInfo& info)
    : m_Data(data), m_AlgInfo(info)
{
}

std::vector<AlgData> BinarySearch::RunAlgPass()
{
    int mid = (m_AlgInfo.low + m_AlgInfo.high) / 2;
    if (m_Data[mid].GetValue() == m_AlgInfo.value)
    {
        m_Data[mid].SetSearchState(State::FOUND);
        m_AlgInfo.done = true;
        return m_Data;
    }

    m_Data[mid].SetSearchState(State::SEARCHING);


    if (m_Data[mid].GetValue() > m_AlgInfo.value)
    {
        m_AlgInfo.high = mid - 1;
    }
    else
    {
        m_AlgInfo.low = mid + 1;
    }
    return m_Data;
}