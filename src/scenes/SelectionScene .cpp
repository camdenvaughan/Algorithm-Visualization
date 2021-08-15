#include "SelectionScene.h"
#include "Helpers.h"
#include <algorithm>
#include <random>


SelectionScene::SelectionScene(unsigned int windowWidth, unsigned int windowHeight)
    : m_Alg(SelectionSort(m_CopyData, m_AlgInfo))
{
    // Set Up Text
    m_TextDisplay.emplace_back("Selection Sort", 40U, sf::Vector2f(windowWidth / 2, 50.0f));

    // Set Up Buttons
    m_Buttons.emplace_back("Sort", sf::Vector2f(windowWidth / 2, windowHeight - 100.0f), SceneState::DEFAULT);
    m_Buttons.emplace_back("Back", sf::Vector2f(windowWidth / 4, windowHeight - 100.0f), SceneState::MENU);
    m_Buttons.emplace_back("Randomize", sf::Vector2f(windowWidth - (windowWidth / 4), windowHeight - 100.0f), SceneState::SELECTION);


    // Reserve space in m_Data
    m_Data.reserve(100);

    // Fill vector
    for (int i = 0; i < m_Data.capacity(); i++)
        m_Data.emplace_back(i, sf::Vector2f(0.0f, 10.f));

    // Randomize vector
    std::shuffle(std::begin(m_Data), std::end(m_Data), std::default_random_engine(time(0)));

    // Set positions of data
    Helpers::OrganizePositions(m_Data, sf::Vector2f(0.0f, 100.f));

    // Set copy of data
    m_CopyData = m_Data;

    // Set the max amount of times it will take to sort
    m_AlgInfo.maxIterations = m_Data.size();
}

void SelectionScene::OnUpdate()
{
    if (isSearching)
    {
        // Reset copy of m_Data
        m_CopyData = m_Data;

        // Run pass of Algorithm
        m_SortedData = m_Alg.RunAlgPass();

        // Set Positions of Sorted data
        Helpers::OrganizePositions(m_SortedData, sf::Vector2f(0.0f, 300.f));

        // Increment search iterator
        m_AlgInfo.searchIterator++;

        if (m_AlgInfo.done)
        {
            // Change top text
            m_TextDisplay[0].SetString("Sorted Data");

            // Create new text
            m_TextDisplay.emplace_back("Old Data", 40U, sf::Vector2f(m_TextDisplay.back().GetPosition().x, 250.0f));

            // Reset Positions of sorted data
            Helpers::OrganizePositions(m_SortedData, sf::Vector2f(0.0f, 100.f));

            // Reset Copy Data
            m_CopyData = m_Data;

            // change the color of all the items in both sorted data and copy data
            for (int i = 0; i < m_SortedData.size(); i++)
            {
                m_SortedData[i].SetSearchState(State::FOUND);
                m_CopyData[i].SetSearchState(State::EMPTY);
            }

            // Set positions of copy Data
            Helpers::OrganizePositions(m_CopyData, sf::Vector2f(0.0f, 300.f));

            // Turn off search
            isSearching = false;
        }
    }
}

void SelectionScene::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (const AlgData& item : m_CopyData)
        target.draw(item);    
    for (const AlgData& item : m_SortedData)
        target.draw(item);
    for (const TextBox& text : m_TextDisplay)
        target.draw(text);
    for (const Button& button : m_Buttons)
        target.draw(button);
}

SceneState SelectionScene::PollEvents(sf::Event& event, sf::Vector2i mousePos)
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
                    isSearching = true;
                return button.GetSceneState();
            }
        }
    }
    return SceneState::DEFAULT;
}
