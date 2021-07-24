#include "MenuScene.h"
#include <iostream>


MenuScene::MenuScene()
    : m_BinarySearchButton(Button("Binary Search", 20))
{
    m_BinarySearchButton.SetPosition(sf::Vector2f(100.f, 100.f));
    m_BinarySearchButton.SetTextFillColor(sf::Color::Black);
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

    target.draw(m_BinarySearchButton);
}

SceneState MenuScene::PollEvents(sf::Event& event, sf::Vector2i mousePos)
{
    if (event.type == sf::Event::Closed)
        return SceneState::CLOSE;
    if (m_BinarySearchButton.MouseIsOver(mousePos))
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_BinarySearchButton.ClickButton();
            return SceneState::DEFAULT;
        }
        if (m_BinarySearchButton.hasBeenClicked)
        {
            m_BinarySearchButton.hasBeenClicked = false;
            return SceneState::BINARY;
        }
    }
        
    if (event.type == sf::Event::KeyReleased)
    {
        //keyboard input
        if (event.key.code == sf::Keyboard::Space)
            return SceneState::BINARY;
    }

    return SceneState::DEFAULT;
}
