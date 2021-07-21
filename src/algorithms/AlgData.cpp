#include "AlgData.h"

AlgData::AlgData(int value, sf::Vector2f position, sf::Texture& texture, sf::Font& font)
    : m_Value(value), m_Position(position)
{
    m_EmptyTexCoords = sf::IntRect(0, 128, 64, 64);
    m_FilledTexCoords = sf::IntRect(64, 128, 64, 64);
    m_SuccessfullCoords = sf::IntRect(128, 128, 64, 64);

    m_State = State::EMPTY;

    m_Sprite.setTexture(texture);
    m_Sprite.setPosition(position);

    m_Text.setFont(font);
    m_Text.setFillColor(sf::Color::Black);
    m_Text.setPosition(position);
    m_Text.setString(std::to_string(value));

};

void AlgData::Draw(sf::RenderWindow& window)
{
    switch (m_State)
    {
    case EMPTY:
        m_Sprite.setTextureRect(m_EmptyTexCoords);
        break;

    case SEARCHING:
        m_Sprite.setTextureRect(m_FilledTexCoords);
        break;

    case FOUND:
        m_Sprite.setTextureRect(m_SuccessfullCoords);
        break;
    }
    m_Text.setString(std::to_string(m_Value));
    window.draw(m_Sprite);
    window.draw(m_Text);
}

sf::Vector2f AlgData::UpdatePositon(sf::Vector2f& position)
{
    sf::Vector2f oldPosition = m_Position;
    m_Position = position;
    m_Sprite.setPosition(position);
    m_Text.setPosition(position);
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
    return oldValue;
}

void AlgData::SetSearchState(State state)
{
    m_State = state;
}