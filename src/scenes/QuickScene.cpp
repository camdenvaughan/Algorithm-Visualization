#include "QuickScene.h"
#include "Helpers.h"
#include <algorithm>
#include <random>


QuickScene::QuickScene(unsigned int windowWidth, unsigned int windowHeight)
    : m_Alg(QuickSort(m_Data, m_AlgInfo))
{
    // Set Up Text
    m_TextDisplay.emplace_back("Quick Sort", 40U, sf::Vector2f(windowWidth / 2, 50.0f));

    // Set Up Buttons
    m_Buttons.emplace_back("Sort", sf::Vector2f(windowWidth / 2, windowHeight - 100.0f), SceneState::DEFAULT);
    m_Buttons.emplace_back("Back", sf::Vector2f(windowWidth / 4, windowHeight - 100.0f), SceneState::MENU);
    m_Buttons.emplace_back("Randomize", sf::Vector2f(windowWidth - (windowWidth / 4), windowHeight - 100.0f), SceneState::QUICK);

    // Reserve Space in Vector
    m_Data.reserve(100);

    // Fill Vector
    for (int i = 0; i < m_Data.capacity(); i++)
        m_Data.emplace_back(i, sf::Vector2f(0.0f, 10.f));

    // Randomize Vector
    std::shuffle(std::begin(m_Data), std::end(m_Data), std::default_random_engine(time(0)));

    // Set Positions of each element
    Helpers::OrganizePositions(m_Data, sf::Vector2f(0.0f, 100.f));
}

void QuickScene::OnUpdate(float deltaTime)
{
    if (isSearching)
    {
        isSearching = false;

        // Create a copy of m_Data
        std::vector<AlgData> copyData = m_Data;

        // Create a vector with the return of the algorithm pass for QuickSort
        std::vector<AlgData> sortedData = m_Alg.RunAlgPass();

        // Change top text
        m_TextDisplay[0].SetString("Sorted Data");

        // Create new text
        m_TextDisplay.emplace_back("Old Data", 40U, sf::Vector2f(m_TextDisplay.back().GetPosition().x, 250.0f));
        m_TextDisplay.emplace_back("Sub Arrays and Pivots(Pivots are Red)", 40U, sf::Vector2f(m_TextDisplay.back().GetPosition().x, 445.0f));
        m_TextDisplay.emplace_back("Scroll to see all", 20U, sf::Vector2f(m_TextDisplay.back().GetPosition().x, 480.0f));

        for (int i = 0; i < copyData.size(); i++)
        {
            // Move original data values to a position under sorted values in m_Data
            sf::Vector2f position(copyData[i].GetPosition().x, copyData[i].GetPosition().y + 200.0f);
            copyData[i].UpdatePosition(position);
            copyData[i].SetSearchState(State::EMPTY);

            // Add copy data values to back of m_Data for rendering
            m_Data.push_back(copyData[i]);

            // Set the color of the sorted data
            m_Data[i].SetSearchState(State::FOUND);
        }
        m_Data.insert(m_Data.end(), sortedData.begin(), sortedData.end());
    }
}

void QuickScene::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (const TextBox& text : m_TextDisplay)
        target.draw(text);
    for (const AlgData& item : m_Data)
        target.draw(item);
    for (const Button& button : m_Buttons)
        target.draw(button);
}

SceneState QuickScene::PollEvents(sf::Event& event, sf::Vector2i mousePos)
{
    // Check for events
    if (event.type == sf::Event::Closed)
        return SceneState::CLOSE;

    // Check for Button input
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

    // Check for scrolling
    if (event.type == sf::Event::MouseWheelScrolled && m_AlgInfo.done)
    {
        if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
        {
            ScrollScreen(5 * event.mouseWheelScroll.delta);
        }
    }

    return SceneState::DEFAULT;
}

void QuickScene::ScrollScreen(float scrollDelta)
{
    // Stop user from scrolling elements off of the screen
    if (m_TextDisplay[0].GetPosition().y >= 50.0f && scrollDelta > 0)
    {
        m_TextDisplay[0].SetPosition(sf::Vector2f(m_TextDisplay[0].GetPosition().x, 50.0f));
        return;
    } 
    if (m_Data.back().GetPosition().y <= 50.0f && scrollDelta < 0)
    {
        m_Data.back().UpdatePosition(sf::Vector2f(m_Data.back().GetPosition().x, 50.0f));
        return;
    }

    // Update positions with the scroll delta
    for (AlgData& item : m_Data)
        item.UpdatePosition(sf::Vector2f(item.GetPosition().x, item.GetPosition().y + (scrollDelta)));
    for (TextBox& text : m_TextDisplay)
        text.SetPosition(sf::Vector2f(text.GetPosition().x, text.GetPosition().y + (scrollDelta)));
}
