#include "BinaryScene.h"
#include "Helpers.h"


BinaryScene::BinaryScene(unsigned int windowWidth, unsigned int windowHeight)
    : m_Alg(BinarySearch(m_Data, m_AlgInfo))
{
    // Set Up Text
    m_TextDisplay.emplace_back("Binary Search", 40U, sf::Vector2f(windowWidth / 2, 50.0f));

    // Set Up Buttons
    m_Buttons.emplace_back("Start Search", sf::Vector2f(windowWidth / 2, windowHeight - 100.0f), SceneState::DEFAULT);
    m_Buttons.emplace_back("Back", sf::Vector2f(windowWidth / 4, windowHeight - 100.0f), SceneState::MENU);
    m_Buttons.emplace_back("Reset", sf::Vector2f(windowWidth - (windowWidth / 4), windowHeight - 100.0f), SceneState::BINARY);


    // Reserve Space in vector
    m_Data.reserve(100);

    // Fill Vector
    for (int i = 0; i < m_Data.capacity(); i++)
        m_Data.emplace_back(i, sf::Vector2f(0.0f, 10.f));

    // Set Positions of each element
    Helpers::OrganizePositions(m_Data, sf::Vector2f(0.0f, 100.f));

    // Set up algorithm info
    m_AlgInfo.low = 0;
    m_AlgInfo.high = m_Data.size();

    // Set search value for 2 less than vector size for worst case scenario.
    m_AlgInfo.value = m_Data.size() - 2;
}

void BinaryScene::OnUpdate(float deltaTime)
{
    // If the search has started, run the algorithm pass, check if search has finished
    if (isSearching)
    {
        Helpers::Wait(sf::milliseconds(100)); // wait for 100 milliseconds in order to slow down and visualize the search

        m_Alg.RunAlgPass();
        if (m_AlgInfo.done)
            isSearching = false;
    }
}

void BinaryScene::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (const AlgData& item : m_Data)
        target.draw(item);
    for (const TextBox& text : m_TextDisplay)
        target.draw(text);
    for (const Button& button : m_Buttons)
        target.draw(button);
}

SceneState BinaryScene::PollEvents(sf::Event& event, sf::Vector2i mousePos)
{
    // Check events

    if (event.type == sf::Event::Closed)
        return SceneState::CLOSE;

    // Check for buttons
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
