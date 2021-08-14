#pragma once
#include "Scene.h"
#include "AlgData.h"
#include "SelectionSort.h"

class SelectionScene : public Scene
{
public:
	SelectionScene(unsigned int windowWidth, unsigned int windowHeight);

	void OnUpdate(float deltaTime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	SceneState PollEvents(sf::Event& event, sf::Vector2i mousePos) override;

private:
	bool isSearching = false;

	std::vector<AlgData> m_Data;
	std::vector<AlgData> m_CopyData;
	std::vector<AlgData> m_SortedData;

	SelectionSort m_Alg;
	AlgInfo m_AlgInfo;

	std::vector<Button> m_Buttons;
	std::vector<TextBox> m_TextDisplay;
};

