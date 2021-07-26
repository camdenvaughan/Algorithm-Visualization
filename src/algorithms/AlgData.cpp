#include "AlgData.h"
#include "..\Renderer.h"
#include "..\Helpers.h"

AlgData::AlgData(int value, sf::Vector2f position)
    : m_Value(value), m_Position(position)
{
    m_EmptyTexCoords = sf::IntRect(0, 128, 32, 32);
    m_FilledTexCoords = sf::IntRect(32, 160, 32, 32);
    m_SuccessfullCoords = sf::IntRect(0, 160, 32, 32);


    m_Sprite.setTexture(Renderer::GetTexture());
    SetSearchState(State::EMPTY);
    m_Sprite.setPosition(position);

    m_Text.setFont(Renderer::GetFont());
    m_Text.setCharacterSize(15.0f);
    m_Text.setFillColor(sf::Color::White);
    m_Text.setString(std::to_string(value));
    m_Text.setOrigin(sf::Vector2f(m_Text.getLocalBounds().width / 2, m_Text.getLocalBounds().height / 2));
    m_Text.setPosition(Helpers::GetCenterObjectOnBackgroundPosition(position, m_Sprite.getGlobalBounds(), m_Text.getLocalBounds()));

};

void AlgData::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(m_Sprite);
    target.draw(m_Text);
}

sf::Vector2f AlgData::UpdatePositon(sf::Vector2f& position)
{
    sf::Vector2f oldPosition = m_Position;
    m_Position = position;
    m_Sprite.setPosition(position);
    m_Text.setPosition(Helpers::GetCenterObjectOnBackgroundPosition(position, m_Sprite.getGlobalBounds(), m_Text.getLocalBounds()));
    return oldPosition;
}

sf::Vector2f AlgData::GetPositon() const
{
    return m_Position;
}

int AlgData::GetValue() const
{
    return m_Value;
}
int AlgData::SetValue(int value)
{
    int oldValue = m_Value;
    m_Value = value;
    m_Text.setString(std::to_string(m_Value));
    return oldValue;
}

void AlgData::SetSearchState(State state)
{
    m_State = state;
    switch (m_State)
    {
    case State::EMPTY:
        m_Sprite.setTextureRect(m_EmptyTexCoords);
        break;

    case State::SEARCHING:
        m_Sprite.setTextureRect(m_FilledTexCoords);
        break;

    case State::FOUND:
        m_Sprite.setTextureRect(m_SuccessfullCoords);
        break;
    }
}