#include "BinaryScene.h"
#include "Helpers.h"

BinaryScene::BinaryScene()
{
    //std::vector<AlgData> data;
    //int vectorSize = 30;
    //data.reserve(vectorSize);

    //std::vector<int> valueVector;
    //for (int i = 0; i < vectorSize; i++)
    //{
    //    valueVector.push_back(i);
    //}

    //// std::random_shuffle(valueVector.begin(), valueVector.end());

    ////for (int i = 0; i < 30; i++)
    //    //data.emplace_back(valueVector[i], sf::Vector2f(0.0f, 10.f), texture, font);
    //Helpers::OrganizePositions(data, sf::Vector2f(0.0f, 10.f));
}

BinaryScene::~BinaryScene()
{

}

void BinaryScene::Draw()
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);


}

void BinaryScene::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);
    target.draw(shape);
}

SceneState BinaryScene::PollEvents(sf::Event& event)
{
    if (event.type == sf::Event::Closed)
        return SceneState::CLOSE;
    if (event.type == sf::Event::KeyReleased)
    {
             //keyboard input
        if (event.key.code == sf::Keyboard::Space)
            return SceneState::MENU;
    }

    return SceneState::DEFAULT;
}
