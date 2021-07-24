#pragma once
#include "Scene.h"

class MenuScene : public Scene
{
	
public:
	MenuScene();
	~MenuScene();

	void Draw() override;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	SceneState PollEvents(sf::Event& event, sf::Vector2i mousePos) override;
private:
	Button m_BinarySearchButton;
};

