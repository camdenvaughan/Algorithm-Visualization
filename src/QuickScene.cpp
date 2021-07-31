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

    m_Buttons.emplace_back("Start Search", SceneState::DEFAULT);
    m_Buttons.back().SetPosition(sf::Vector2f(windowWidth / 2, 1000.0f));
    m_Buttons.emplace_back("Back", SceneState::MENU);
    m_Buttons.back().SetPosition(sf::Vector2f(400.0f, 1000.0f));    
    m_Buttons.emplace_back("Randomize", SceneState::DEFAULT);
    m_Buttons.back().SetPosition(sf::Vector2f(windowWidth - 400.0f, 1000.0f));


    // Setting up Search
    m_Data.reserve(100);

    for (int i = 0; i < m_Data.capacity(); i++)
        m_Data.emplace_back(i, sf::Vector2f(0.0f, 10.f));

    std::shuffle(std::begin(m_Data), std::end(m_Data), std::default_random_engine());
    Helpers::OrganizePositions(m_Data, sf::Vector2f(0.0f, 100.f));
    m_CopyData = m_Data;

    m_AlgInfo.maxIterations = m_Data.size();
}

QuickScene::~QuickScene()
{

}

void QuickScene::OnUpdate(float deltaTime)
{
    if (isSearching)
    {
        m_CopyData = m_Data;
        if (m_AlgInfo.searchIterator != 0)
            Helpers::Wait(sf::milliseconds(600));

        m_SortedData = m_Search.RunAlgPass(m_AlgInfo);
        Helpers::OrganizePositions(m_SortedData, sf::Vector2f(0.0f, 300.f));
       // m_AlgInfo.searchIterator++;

        if (m_AlgInfo.done)
            isSearching = false;
    }
}

void QuickScene::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (const AlgData& item : m_CopyData)
        target.draw(item);    
    for (const AlgData& item : m_SortedData)
        target.draw(item);
    for (const sf::Text& text : m_TextDisplay)
        target.draw(text);
    for (const Button& button : m_Buttons)
        target.draw(button);
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
                if (button.name == "Start Search")
                    isSearching = true;
                else if (button.name == "Randomize")
                {
                    std::shuffle(std::begin(m_Data), std::end(m_Data), std::default_random_engine());
                    Helpers::OrganizePositions(m_Data, sf::Vector2f(0.0f, 100.f));
                    m_CopyData = m_Data;

                    m_SortedData.erase(std::begin(m_SortedData), std::end(m_SortedData));
                }
                return button.GetSceneState();
            }
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
