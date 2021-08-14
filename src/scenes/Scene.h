#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Resources.h"
#include "Button.h"
#include "TextBox.h"

// Enum handling current scene
enum class SceneState
{
	DEFAULT, CLOSE, MENU, BINARY, SIMPLE, SELECTION, QUICK, BOGA
};

class Scene : public sf::Drawable
{

public:
	Scene() {}
	virtual ~Scene() {}

	virtual void OnUpdate(float deltaTime) {}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const {}
	virtual SceneState PollEvents(sf::Event& event, sf::Vector2i mousePos) { return SceneState::DEFAULT; }

};

