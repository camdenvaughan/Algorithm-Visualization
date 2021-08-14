#include "SimpleSearch.h"

#include <iostream>


SimpleSearch::SimpleSearch(std::vector<AlgData>& data, AlgInfo& info)
	: m_Data(data), m_AlgInfo(info)
{
}

std::vector<AlgData> SimpleSearch::RunAlgPass()
{
	// Check if you have found the value
	if (m_Data[m_AlgInfo.searchIterator].GetValue() == m_AlgInfo.value)
	{
		m_Data[m_AlgInfo.searchIterator].SetSearchState(State::FOUND);
		m_AlgInfo.done = true;
		return m_Data;
	}
	else
	{
		// Increment iterator, change texture
		m_Data[m_AlgInfo.searchIterator++].SetSearchState(State::SEARCHING);

		// Return to try again after visualizing this search
		return m_Data;
	}

}