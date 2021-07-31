#include "SimpleSearch.h"

#include <iostream>


SimpleSearch::SimpleSearch(std::vector<AlgData>& data)
	: m_Data(data)
{
}

std::vector<AlgData> SimpleSearch::RunAlgPass(AlgInfo& info)
{
	if (m_Data[info.searchIterator].GetValue() == info.value)
	{
		m_Data[info.searchIterator].SetSearchState(State::FOUND);
		info.done = true;
		return m_Data;
	}
	m_Data[info.searchIterator++].SetSearchState(State::SEARCHING);
	if (info.searchIterator < m_Data.size())
		return m_Data;
	
	info.isNotInContainer = true;
	return m_Data;
}