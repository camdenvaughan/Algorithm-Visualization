#pragma once
#include "Scene.h"
#include "AlgData.h"
#include "SimpleSearch.h"

class SimpleScene : public Scene
{
public:
	SimpleScene(unsigned int windowWidth, unsigned int windowHeight);

	void OnUpdate(float deltaTime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	SceneState PollEvents(sf::Event& event, sf::Vector2i mousePos) override;

private:
	bool isSearching = false;

	std::vector<AlgData> m_Data;

	SimpleSearch m_Alg;
	AlgInfo m_AlgInfo;


	std::vector<Button> m_Buttons;
	std::vector<TextBox> m_TextDisplay;
};

