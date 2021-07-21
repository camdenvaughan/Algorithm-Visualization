#include "SelectionSort.h"

SelectionSort::SelectionSort(std::vector<AlgData>& data, sf::RenderWindow& window)
	: m_Data(data)
{
	m_Window = &window;
}

void SelectionSort::OnRun(int value, sf::Time waitTime)
{
	std::vector<AlgData> sortedData;
	int size = m_Data.size();
	sortedData.reserve(size);

	sf::Vector2f newVectorPosition = sf::Vector2f(0.0f, 256.f);

	for (int i = 0; i < size; i++)
	{
		// Get index of smallest value
		int smallestIndex = FindSmallest(m_Data);

		// Set the state of that item to Searching to change the texture
		m_Data[smallestIndex].SetSearchState(State::SEARCHING);

		// Add smallest item as the last value to the new vector
		sortedData.push_back(m_Data[smallestIndex]);

		// Update position to place new vector below old one
		sortedData[i].UpdatePositon(newVectorPosition);

		// Update possition for the next entry to vector
		newVectorPosition.x += 64.f;
		if (newVectorPosition.x > m_Window->getSize().x - 65)
		{
			newVectorPosition.x = 0.0f;
			newVectorPosition.y += 65.0f;
		}

		// Render both vectors
		m_Window->clear();
		Renderer::DrawVector(*m_Window, m_Data, false);
		Renderer::DrawVector(*m_Window, sortedData, false);
		m_Window->display();

		Helpers::Wait(waitTime);

		m_Data.erase(m_Data.begin() + smallestIndex);

		// Render old vector
		m_Window->clear();
		Renderer::DrawVector(*m_Window, m_Data, false);
		Renderer::DrawVector(*m_Window, sortedData, false);
		m_Window->display();

	}
	m_Data = sortedData;
	
	// Reset Position and Texture
	for (AlgData& item : m_Data)
	{
		sf::Vector2f position = item.GetPositon();
		position.y -= 246.f;
		item.UpdatePositon(position);
		item.SetSearchState(State::EMPTY);
	}
}

int SelectionSort::FindSmallest(std::vector<AlgData>& data)
{
	int smallest = data[0].GetValue();
	int smallestIndex = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].GetValue() < smallest)
		{
			smallest = data[i].GetValue();
			smallestIndex = i;
		}
	}
	return smallestIndex;
}
