#include "SimpleSearch.h"

#include <iostream>


SimpleSearch::SimpleSearch(std::vector<AlgData>& data, AlgInfo& info)
	: m_Data(data), m_AlgInfo(info)
{
}

std::vector<AlgData> SimpleSearch::RunAlgPass()
{
	if (m_Data[m_AlgInfo.searchIterator].GetValue() == m_AlgInfo.value)
	{
		m_Data[m_AlgInfo.searchIterator].SetSearchState(State::FOUND);
		m_AlgInfo.done = true;
		return m_Data;
	}
	m_Data[m_AlgInfo.searchIterator++].SetSearchState(State::SEARCHING);
	if (m_AlgInfo.searchIterator < m_Data.size())
		return m_Data;
	
	m_AlgInfo.isNotInContainer = true;
	return m_Data;
}