#include "BinaryScene.h"
#include "Helpers.h"


BinaryScene::BinaryScene()
    : m_Search(BinarySearch(m_Data))
{
    m_Data.reserve(100);

    for (int i = 0; i < m_Data.capacity(); i++)
        m_Data.emplace_back(i, sf::Vector2f(0.0f, 10.f));
    Helpers::OrganizePositions(m_Data, sf::Vector2f(0.0f, 10.f));

    m_SearchBounds.low = 0;
    m_SearchBounds.high = m_Data.size();
}

BinaryScene::~BinaryScene()
{

}

void BinaryScene::OnUpdate(float deltaTime)
{
    if (isSearching)
        m_Search.RunSearchPass(10, m_SearchBounds);
    Helpers::Wait(sf::seconds(.5));
}

void BinaryScene::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    for (const AlgData& item : m_Data)
        target.draw(item);
}

SceneState BinaryScene::PollEvents(sf::Event& event, sf::Vector2i mousePos)
{
    if (event.type == sf::Event::Closed)
        return SceneState::CLOSE;
    if (event.type == sf::Event::KeyReleased)
    {
             //keyboard input
        if (event.key.code == sf::Keyboard::M)
            return SceneState::MENU;        
        if (event.key.code == sf::Keyboard::Space)
            isSearching = true;
    }

    return SceneState::DEFAULT;
}
