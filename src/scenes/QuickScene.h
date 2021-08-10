#pragma once
#include "Scene.h"
#include "AlgData.h"
#include "QuickSort.h"

class QuickScene : public Scene
{
public:
	QuickScene(unsigned int windowWidth, unsigned int windowHeight);

	void OnUpdate(float deltaTime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	SceneState PollEvents(sf::Event& event, sf::Vector2i mousePos) override;

private:
	void ScrollScreen(float scrollDelta);

private:
	bool isSearching = false;

	std::vector<AlgData> m_Data;
	std::vector<AlgData> m_CopyData;
	std::vector<AlgData> m_SortedData;

	QuickSort m_Search;
	AlgInfo m_AlgInfo;

	std::vector<Button> m_Buttons;
	std::vector<sf::Text> m_TextDisplay;
};

