#include "AlgData.h"

AlgData::AlgData(int Value, sf::Vector2f Position)
    : m_Value(Value), m_Position(Position)
{
    m_EmptyTexCoords = sf::IntRect(0, 128, 64, 64);
    m_FilledTexCoords = sf::IntRect(64, 128, 64, 64);
    m_SuccessfullCoords = sf::IntRect(128, 128, 64, 64);
};

sf::IntRect AlgData::GetTexCoords() const
{
    switch (m_State)
    {
    case EMPTY:
        return m_EmptyTexCoords;

    case SEARCHING:
        return m_FilledTexCoords;

    case FOUND:
        return m_SuccessfullCoords;
    }
}
sf::Vector2f AlgData::GetPosition() const
{
    return m_Position;
}

int AlgData::GetValue() const
{
    return m_Value;
}

void AlgData::SetSearchState(State state)
{
    m_State = state;
}