#include "BinaryScene.h"
#include "Helpers.h"


BinaryScene::BinaryScene(unsigned int windowWidth, unsigned int windowHeight)
    : m_Search(BinarySearch(m_Data))
{
    // Set Up Text and Buttons
    sf::Text text;
    text.setFont(Renderer::GetFont());
    text.setCharacterSize(40);
    text.setString("Binary Search");
    text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2));
    text.setPosition(sf::Vector2f(windowWidth / 2, 50.0f));
    m_TextDisplay.push_back(text);

    m_Buttons.emplace_back("Start Search", SceneState::DEFAULT);
    m_Buttons.back().SetPosition(sf::Vector2f(windowWidth / 2, 1000.0f));
    m_Buttons.emplace_back("Back", SceneState::MENU);
    m_Buttons.back().SetPosition(sf::Vector2f(400.0f, 1000.0f));


    // Setting up Search
    m_Data.reserve(100);

    for (int i = 0; i < m_Data.capacity(); i++)
        m_Data.emplace_back(i, sf::Vector2f(0.0f, 10.f));
    Helpers::OrganizePositions(m_Data, sf::Vector2f(0.0f, 100.f));

    m_AlgInfo.low = 0;
    m_AlgInfo.high = m_Data.size();
    m_AlgInfo.value = 98;
}

BinaryScene::~BinaryScene()
{

}

void BinaryScene::OnUpdate(float deltaTime)
{
    
    if (isSearching)
    {
        if (m_AlgInfo.skipWait)
        {
            Helpers::Wait(sf::milliseconds(600));
            m_AlgInfo.skipWait = false;
        }
        m_Search.RunAlgPass(m_AlgInfo);
        if (m_AlgInfo.done)
            isSearching = false;
    }
    
}

void BinaryScene::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (const AlgData& item : m_Data)
        target.draw(item);
    for (const sf::Text& text : m_TextDisplay)
        target.draw(text);
    for (const Button& button : m_Buttons)
        target.draw(button);
}

SceneState BinaryScene::PollEvents(sf::Event& event, sf::Vector2i mousePos)
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
