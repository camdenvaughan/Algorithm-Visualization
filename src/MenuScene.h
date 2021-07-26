#pragma once
#include "Scene.h"

class MenuScene : public Scene
{
	
public:
	MenuScene(unsigned int windowWidth, unsigned int windowHeight);
	~MenuScene();

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	SceneState PollEvents(sf::Event& event, sf::Vector2i mousePos) override;
private:
	unsigned int m_WindowWidth;
	unsigned int m_WindowHeight;

	std::vector<Button> m_Buttons;
	std::vector<sf::Text> m_TextDisplay;
};

