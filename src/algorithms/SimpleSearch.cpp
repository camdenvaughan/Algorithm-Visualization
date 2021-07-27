#include "SimpleSearch.h"

#include <iostream>


SimpleSearch::SimpleSearch(std::vector<AlgData>& data)
	: m_Data(data)
{
}

AlgInfo& SimpleSearch::RunAlgPass(AlgInfo& info)
{
	if (m_Data[info.currentSearchLoc].GetValue() == info.value)
	{
		m_Data[info.currentSearchLoc].SetSearchState(State::FOUND);
		info.found = true;
		return info;
	}
	m_Data[info.currentSearchLoc++].SetSearchState(State::SEARCHING);
	if (info.currentSearchLoc < m_Data.size())
		return info;
	
	info.isNotInContainer = true;
	return info;
}