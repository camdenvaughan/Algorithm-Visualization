#include "QuickScene.h"
#include "Helpers.h"
#include <algorithm>
#include <random>


QuickScene::QuickScene(unsigned int windowWidth, unsigned int windowHeight)
    : m_Search(QuickSort(m_CopyData))
{
    // Set Up Text and Buttons
    sf::Text text;
    text.setFont(Renderer::GetFont());
    text.setCharacterSize(40);
    text.setString("Quick Sort");
    text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2));
    text.setPosition(sf::Vector2f(windowWidth / 2, 50.0f));
    m_TextDisplay.push_back(text);

    m_Buttons.emplace_back("Sort", SceneState::DEFAULT);
    m_Buttons.back().SetPosition(sf::Vector2f(windowWidth / 2, windowHeight - 100.0f));
    m_Buttons.emplace_back("Back", SceneState::MENU);
    m_Buttons.back().SetPosition(sf::Vector2f(windowWidth / 4, windowHeight - 100.0f));
    m_Buttons.emplace_back("Randomize", SceneState::QUICK);
    m_Buttons.back().SetPosition(sf::Vector2f(windowWidth - (windowWidth / 4), windowHeight - 100.0f));


    // Setting up Search
    m_Data.reserve(100);

    for (int i = 0; i < m_Data.capacity(); i++)
        m_Data.emplace_back(i, sf::Vector2f(0.0f, 10.f));


    std::shuffle(std::begin(m_Data), std::end(m_Data), std::default_random_engine(time(0)));
    Helpers::OrganizePositions(m_Data, sf::Vector2f(0.0f, 100.f));
    m_CopyData = m_Data;

    m_AlgInfo.maxIterations = m_Data.size();
}

void QuickScene::OnUpdate(float deltaTime)
{
    if (isSearching)
    {
        m_CopyData = m_Data;
        
        m_SortedData = m_Search.RunAlgPass(m_AlgInfo);

        isSearching = false;

        m_TextDisplay[0].setString("Sorted Data");

        sf::Text text;
        text.setFont(Renderer::GetFont());
        text.setCharacterSize(40);
        text.setString("Old Data");
        text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2));
        text.setPosition(sf::Vector2f(m_TextDisplay.back().getPosition().x, 250.0f));
        m_TextDisplay.push_back(text);
        text.setString("Sub Arrays and Pivots (Pivots are Red)");
        text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2));
        text.setPosition(sf::Vector2f(text.getPosition().x, 445.0f));
        m_TextDisplay.push_back(text);
        text.setCharacterSize(20);
        text.setString("Scroll to see all");
        text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2));
        text.setPosition(sf::Vector2f(text.getPosition().x, text.getPosition().y + 35));
        m_TextDisplay.push_back(text);

        for (AlgData& item : m_Data)
        {
            sf::Vector2f position(item.GetPosition().x, item.GetPosition().y + 200.0f);
            item.UpdatePosition(position);
            item.SetSearchState(State::EMPTY);
        }
        for (AlgData& item : m_CopyData)
        {
            m_Data.push_back(item);
            m_Data.back().SetSearchState(State::FOUND);
        }
        
    }
}

void QuickScene::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (const AlgData& item : m_SortedData)
        target.draw(item);
    for (const sf::Text& text : m_TextDisplay)
        target.draw(text);
    for (const Button& button : m_Buttons)
        target.draw(button);
    for (const AlgData& item : m_Data)
        target.draw(item);
}

SceneState QuickScene::PollEvents(sf::Event& event, sf::Vector2i mousePos)
{

    if (event.type == sf::Event::KeyReleased)
    {
        //keyboard input
        if (event.key.code == sf::Keyboard::M)
            return SceneState::MENU;        
        if (event.key.code == sf::Keyboard::Space)
            isSearching = true;
    }

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
                if (button.name == "Sort")
                    isSearching = true;
                return button.GetSceneState();
            }
        }
    }

    if (event.type == sf::Event::MouseWheelScrolled && m_AlgInfo.done)
    {
        if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
        {
            ScrollScreen(5 * event.mouseWheelScroll.delta);
        }
    }

    if (event.type == sf::Event::KeyReleased)
    {
        //keyboard input
        if (event.key.code == sf::Keyboard::Space)
            return SceneState::QUICK;
    }

    return SceneState::DEFAULT;
}

void QuickScene::ScrollScreen(float scrollDelta)
{
    for (AlgData& item : m_Data)
        item.UpdatePosition(sf::Vector2f(item.GetPosition().x, item.GetPosition().y + (scrollDelta)));
    for (AlgData& item : m_SortedData)
        item.UpdatePosition(sf::Vector2f(item.GetPosition().x, item.GetPosition().y + (scrollDelta)));
    for (sf::Text& text : m_TextDisplay)
        text.setPosition(sf::Vector2f(text.getPosition().x, text.getPosition().y + (scrollDelta)));
}
