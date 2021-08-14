#include "MenuScene.h"
#include <iostream>


MenuScene::MenuScene(unsigned int windowWidth, unsigned int windowHeight)
    : m_WindowWidth(windowWidth), m_WindowHeight(windowHeight)
{
    // Setup Text
    m_TextDisplay.emplace_back("Algorithm Visualizer", 40U, sf::Vector2f(windowWidth / 2, 50.0f));
    m_TextDisplay.emplace_back("by Camden Vaughan", 20U, sf::Vector2f(windowWidth / 2, 100.0f));

    // Setup Buttons
    m_Buttons.emplace_back("Binary Search", sf::Vector2f(windowWidth / 2, 200.0f), SceneState::BINARY);
    m_Buttons.emplace_back("Simple Search", sf::Vector2f(windowWidth / 2, 300.0f), SceneState::SIMPLE);
    m_Buttons.emplace_back("Selection Sort", sf::Vector2f(windowWidth / 2, 400.0f), SceneState::SELECTION);
    m_Buttons.emplace_back("Quick Sort", sf::Vector2f(windowWidth / 2, 500.0f), SceneState::QUICK);
    m_Buttons.emplace_back("Boga Sort", sf::Vector2f(windowWidth / 2, 600.0f), SceneState::BOGA);
    m_Buttons.emplace_back("Quit", sf::Vector2f(windowWidth / 2, 700.0f), SceneState::CLOSE);
}

void MenuScene::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (const Button& button : m_Buttons)
        target.draw(button);

    for (const TextBox& text : m_TextDisplay)
        target.draw(text);
}

SceneState MenuScene::PollEvents(sf::Event& event, sf::Vector2i mousePos)
{
    // Check for events
    if (event.type == sf::Event::Closed)
        return SceneState::CLOSE;

    // Check Button input
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

    return SceneState::DEFAULT;
}
