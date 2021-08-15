#pragma once
#include "Scene.h"
#include "AlgData.h"
#include "BogaSort.h"

class BogaScene : public Scene
{
public:
	BogaScene(unsigned int windowWidth, unsigned int windowHeight);

	void OnUpdate() override;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	SceneState PollEvents(sf::Event& event, sf::Vector2i mousePos) override;

private:
	bool isSearching = false;

	std::vector<AlgData> m_Data;
	std::vector<AlgData> m_OriginalData;

	BogaSort m_Alg;
	AlgInfo m_AlgInfo;

	std::vector<Button> m_Buttons;
	std::vector<TextBox> m_TextDisplay;

	TextBox* m_IteratorText;
};

