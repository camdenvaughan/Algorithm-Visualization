#include "AlgData.h"
#include "Resources.h"
#include "Helpers.h"

AlgData::AlgData(int value, sf::Vector2f position)
    : m_Value(value), m_Position(position), m_Text(std::to_string(value))
{
    // Set up the texture coordinates for different textures that can be set with States
    m_EmptyTexCoords = sf::IntRect(0, 128, 32, 32);
    m_FilledTexCoords = sf::IntRect(32, 160, 32, 32);
    m_SuccessfullCoords = sf::IntRect(0, 160, 32, 32);

    // Setting up Textures
    m_Sprite.setTexture(Resources::GetTexture());
    SetSearchState(State::EMPTY);

    m_Sprite.setPosition(position);

    // Setting up Value text
    m_Text.SetCharacterSize(15.0f);
    m_Text.SetPosition(Helpers::GetCenterPositionOnBackgroundObject(position, m_Sprite.getGlobalBounds(), m_Text.GetLocalBounds()));

};

void AlgData::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(m_Sprite);
    target.draw(m_Text);
}

// Updates position and returns old position;
sf::Vector2f AlgData::UpdatePosition(sf::Vector2f position)
{
    sf::Vector2f oldPosition = m_Position;
    m_Position = position;
    m_Sprite.setPosition(position);
    m_Text.SetPosition(Helpers::GetCenterPositionOnBackgroundObject(position, m_Sprite.getGlobalBounds(), m_Text.GetLocalBounds()));
    return oldPosition;
}

sf::Vector2f AlgData::GetPosition() const
{
    return m_Position;
}

int AlgData::GetValue() const
{
    return m_Value;
}

// Sets which texture is active
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