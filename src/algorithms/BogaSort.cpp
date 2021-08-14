#include "BogaSort.h"
#include <random>

BogaSort::BogaSort(std::vector<AlgData>& data, AlgInfo& info)
    : m_Data(data), m_AlgInfo(info)
{
}

std::vector<AlgData> BogaSort::RunAlgPass()
{
	// Shuffle data
    std::shuffle(std::begin(m_Data), std::end(m_Data), std::default_random_engine(time(0)));

	// Check if the data is sorted
	m_AlgInfo.done = IsSorted(m_Data);

    return m_Data;
}