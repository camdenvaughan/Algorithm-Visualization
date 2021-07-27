#include "BinarySearch.h"

#include <iostream>

BinarySearch::BinarySearch(std::vector<AlgData>& data)
    : m_Data(data)
{
}

AlgInfo& BinarySearch::RunAlgPass(AlgInfo& info)
{
    int mid = (info.low + info.high) / 2;
    if (m_Data[mid].GetValue() == info.value)
    {
        m_Data[mid].SetSearchState(State::FOUND);
        info.found = true;
        return info;
    }

    m_Data[mid].SetSearchState(State::SEARCHING);


    if (m_Data[mid].GetValue() > info.value)
    {
        info.high = mid - 1;
    }
    else
    {
        info.low = mid + 1;
    }
    return info;
}