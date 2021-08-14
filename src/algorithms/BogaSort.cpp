#include "BogaSort.h"
#include <random>

BogaSort::BogaSort(std::vector<AlgData>& data, AlgInfo& info)
    : m_Data(data), m_AlgInfo(info)
{
}

std::vector<AlgData> BogaSort::RunAlgPass()
{
    std::shuffle(std::begin(m_Data), std::end(m_Data), std::default_random_engine(time(0)));

	m_AlgInfo.done = IsSorted(m_Data);

    return m_Data;
}

bool BogaSort::IsSorted(std::vector<AlgData>& data)
{
	for (int i = 0; i < data.size() - 1; i++)
	{
		if (data[i].GetValue() > data[i + 1].GetValue())
			return false;
	}
	return true;
}