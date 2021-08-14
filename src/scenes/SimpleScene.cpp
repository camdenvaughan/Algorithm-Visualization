#include "SimpleScene.h"
#include "Helpers.h"


SimpleScene::SimpleScene(unsigned int windowWidth, unsigned int windowHeight)
    : m_Alg(SimpleSearch(m_Data, m_AlgInfo))
{
    // Set Up Text
    m_TextDisplay.emplace_back("Simple Search", 40U, sf::Vector2f(windowWidth / 2, 50.0f));

    // Set Up Buttons
    m_Buttons.emplace_back("Start Search", sf::Vector2f(windowWidth / 2, windowHeight - 100.0f), SceneState::DEFAULT);
    m_Buttons.emplace_back("Back", sf::Vector2f(windowWidth / 4, windowHeight - 100.0f), SceneState::MENU);
    m_Buttons.emplace_back("Reset", sf::Vector2f(windowWidth - (windowWidth / 4), windowHeight - 100.0f), SceneState::SIMPLE);

    // Setting up Search
    m_Data.reserve(100);

    for (int i = 0; i < m_Data.capacity(); i++)
        m_Data.emplace_back(i, sf::Vector2f(0.0f, 10.f));
    Helpers::OrganizePositions(m_Data, sf::Vector2f(0.0f, 100.f));

    // Set search value for 1 less than vector size for worst case scenario.
    m_AlgInfo.value = m_Data.size() - 1;
}

void SimpleScene::OnUpdate(float deltaTime)
{
    
    if (isSearching)
    {
        // Run Algorithm
        m_Alg.RunAlgPass();

        // Turn off serach if done
        if (m_AlgInfo.done)
            isSearching = false;
    }
}

void SimpleScene::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (const AlgData& item : m_Data)
        target.draw(item);
    for (const TextBox& text : m_TextDisplay)
        target.draw(text);
    for (const Button& button : m_Buttons)
        target.draw(button);
}

SceneState SimpleScene::PollEvents(sf::Event& event, sf::Vector2i mousePos)
{
    if (event.type == sf::Event::Closed)
        return SceneState::CLOSE;

    // Check for button input
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
                if (button.name == "Start Search")
                    isSearching = true;
                return button.GetSceneState();
            }
        }
    }
    return SceneState::DEFAULT;
}
