#include "MenuScene.h"
#include <iostream>

MenuScene::MenuScene()
{

}
MenuScene::~MenuScene()
{

}

void MenuScene::Draw()
{
	sf::RectangleShape shape(sf::Vector2f(100.0f, 100.0f));
	shape.setFillColor(sf::Color::Green);
    

}

void MenuScene::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    sf::RectangleShape shape(sf::Vector2f(100.0f, 100.0f));
    shape.setFillColor(sf::Color::Green);
    target.draw(shape);
}

SceneState MenuScene::PollEvents(sf::Event& event)
{
    if (event.type == sf::Event::Closed)
        return SceneState::CLOSE;
    if (event.type == sf::Event::KeyReleased)
    {
        //keyboard input
        if (event.key.code == sf::Keyboard::Space)
            return SceneState::BINARY;
    }

    return SceneState::DEFAULT;
}
