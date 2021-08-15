#include "BogaScene.h"
#include "Helpers.h"
#include <algorithm>
#include <random>


BogaScene::BogaScene(unsigned int windowWidth, unsigned int windowHeight)
    : m_Alg(BogaSort(m_Data, m_AlgInfo))
{
    // Set Up Text
    m_TextDisplay.reserve(5);
    m_TextDisplay.emplace_back("Boga Sort", 40U, sf::Vector2f(windowWidth / 2, 50.0f));
    m_TextDisplay.emplace_back("Iterations: ", 20U, sf::Vector2f(windowWidth / 2, 500.0f));
    m_IteratorText = &m_TextDisplay.emplace_back("0", 20U, sf::Vector2f(windowWidth / 2, 520.0f));

    // Set Up Buttons
    m_Buttons.emplace_back("Sort", sf::Vector2f(windowWidth / 2, windowHeight - 100.0f), SceneState::DEFAULT);
    m_Buttons.emplace_back("Back", sf::Vector2f(windowWidth / 4, windowHeight - 100.0f), SceneState::MENU);
    m_Buttons.emplace_back("Reset", sf::Vector2f(windowWidth - (windowWidth / 4), windowHeight - 100.0f), SceneState::BOGA);

    // Reserve space in m_Original Data
    m_OriginalData.reserve(5);

    // Fill vector
    for (int i = 0; i < m_OriginalData.capacity(); i++)
        m_OriginalData.emplace_back(i, sf::Vector2f(0.0f, 10.f));

    // Randomize vector
    std::shuffle(std::begin(m_OriginalData), std::end(m_OriginalData), std::default_random_engine(time(0)));

    // Set positions of data
    Helpers::OrganizePositions(m_OriginalData, sf::Vector2f(0.0f, 100.f));

    // Set up Data
    m_Data = m_OriginalData;
}

void BogaScene::OnUpdate()
{
    if (isSearching)
    {
        // Run Algortihm and Organize positions of m_Data
        m_Alg.RunAlgPass();
        Helpers::OrganizePositions(m_Data, sf::Vector2f(0.0f, 300.0f));

        // Display the Iteration Count
        m_IteratorText->SetString(std::to_string(++m_AlgInfo.searchIterator));

        // Check if the algorithm has finished
        if (m_AlgInfo.done)
        {
            // Create new titles
            m_TextDisplay[0].SetString("Sorted Data");
            m_TextDisplay.emplace_back("Old Data", 40U, sf::Vector2f(m_TextDisplay.back().GetPosition().x, 250.0f));

            // Flip the positions of the original and the new sorted data and change color of sorted data
            for (int i = 0; i < m_Data.size(); i++)
            {
                m_Data[i].SetSearchState(State::FOUND);
                m_OriginalData[i].UpdatePosition(m_Data[i].GetPosition());
                m_Data[i].UpdatePosition(sf::Vector2f(m_Data[i].GetPosition().x, m_Data[i].GetPosition().y - 200.0f));
            }

            // turn off search
            isSearching = false;
        }
    }
}

void BogaScene::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (const AlgData& item : m_OriginalData)
        target.draw(item);    
    for (const AlgData& item : m_Data)
        target.draw(item);
    for (const TextBox& text : m_TextDisplay)
        target.draw(text);
    for (const Button& button : m_Buttons)
        target.draw(button);
}

SceneState BogaScene::PollEvents(sf::Event& event, sf::Vector2i mousePos)
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
                if (button.name == "Sort")
                {
                    isSearching = true;
                }
                return button.GetSceneState();
            }
        }
    }
    return SceneState::DEFAULT;
}
