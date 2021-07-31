#pragma once
#include "Scene.h"
#include "algorithms/AlgData.h"
#include "algorithms/QuickSort.h"

class QuickScene : Scene
{
public:
	QuickScene(unsigned int windowWidth, unsigned int windowHeight);
	~QuickScene();
	void OnUpdate(float deltaTime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	SceneState PollEvents(sf::Event& event, sf::Vector2i mousePos) override;

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

