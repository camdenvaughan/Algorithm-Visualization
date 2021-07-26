#include "MenuScene.h"
#include <iostream>


MenuScene::MenuScene(unsigned int windowWidth, unsigned int windowHeight)
    : m_WindowWidth(windowWidth), m_WindowHeight(windowHeight)
{

    sf::Text text;
    text.setFont(Renderer::GetFont());
    text.setCharacterSize(40);
    text.setString("Algorithm Visualizer");
    text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2));
    text.setPosition(sf::Vector2f(windowWidth / 2, 50.0f));
    m_TextDisplay.push_back(text);
    text.setString("by Camden Vaughan");
    text.setCharacterSize(20);
    text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2));
    text.setPosition(sf::Vector2f(windowWidth / 2, 100.0f));
    m_TextDisplay.push_back(text);

    m_Buttons.emplace_back("Binary Search", SceneState::BINARY);
    m_Buttons.back().SetPosition(sf::Vector2f(400.0f, 200.0f));
    m_Buttons.emplace_back("Simple Search", SceneState::SIMPLE);
    m_Buttons.back().SetPosition(sf::Vector2f(400.0f, 400.0f));
    m_Buttons.emplace_back("Selection Sort", SceneState::SELECTION);
    m_Buttons.back().SetPosition(sf::Vector2f(400.0f, 600.0f));
    m_Buttons.emplace_back("Quick Sort", SceneState::QUICK);
    m_Buttons.back().SetPosition(sf::Vector2f(400.0f, 800.0f));
}
MenuScene::~MenuScene()
{

}

void MenuScene::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (const Button& button : m_Buttons)
        target.draw(button);

    for (const sf::Text& text : m_TextDisplay)
        target.draw(text);
}

SceneState MenuScene::PollEvents(sf::Event& event, sf::Vector2i mousePos)
{
    if (event.type == sf::Event::Closed)
        return SceneState::CLOSE;

    for (Button& button : m_Buttons)
    {
        if (button.MouseIsOver(mousePos))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                button.ClickButton();
                return SceneState::DEFAULT;
            }
            if (button.hasBeenClicked)
            {
                button.hasBeenClicked = false;
                return button.GetSceneState();
            }
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
