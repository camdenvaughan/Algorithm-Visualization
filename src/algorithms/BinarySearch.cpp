#include "BinarySearch.h"

#include <iostream>

BinarySearch::BinarySearch(std::vector<AlgData>& data, AlgInfo& info)
    : m_Data(data), m_AlgInfo(info)
{
}

std::vector<AlgData> BinarySearch::RunAlgPass()
{
    // cache index of mid point
    int mid = (m_AlgInfo.low + m_AlgInfo.high) / 2;

    // Check if you have found the value
    if (m_Data[mid].GetValue() == m_AlgInfo.value)
    {
        m_Data[mid].SetSearchState(State::FOUND);
        m_AlgInfo.done = true;
        return m_Data;
    }

    m_Data[mid].SetSearchState(State::SEARCHING);

    // lower the high value if you are searching for a value lower than the mid
    if (m_Data[mid].GetValue() > m_AlgInfo.value)
    {
        m_AlgInfo.high = mid - 1;
    }
    else // raise the low value
    {
        m_AlgInfo.low = mid + 1;
    }
    return m_Data;
}