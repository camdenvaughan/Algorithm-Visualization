#pragma once
#include "Scene.h"
#include "algorithms/AlgData.h"
#include "algorithms/SelectionSort.h"

class SelectionScene : Scene
{
public:
	SelectionScene(unsigned int windowWidth, unsigned int windowHeight);
	~SelectionScene();
	void OnUpdate(float deltaTime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	SceneState PollEvents(sf::Event& event, sf::Vector2i mousePos) override;

private:
	bool isSearching = false;

	std::vector<AlgData> m_Data;
	std::vector<AlgData> m_CopyData;
	std::vector<AlgData> m_SortedData;

	SelectionSort m_Search;
	AlgInfo m_AlgInfo;

	std::vector<Button> m_Buttons;
	std::vector<sf::Text> m_TextDisplay;
};

