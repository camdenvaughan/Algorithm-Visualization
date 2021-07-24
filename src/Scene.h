#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Renderer.h"

enum class SceneState
{
	DEFAULT, CLOSE, MENU, BINARY, SIMPLE
};

class Scene : public sf::Drawable
{

public:
	Scene() {};
	virtual ~Scene() {};

	virtual void OnUpdate(float deltaTime) {}
	virtual void Draw();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const {}
	virtual SceneState PollEvents(sf::Event& event) { return SceneState::DEFAULT; }
};

