#pragma once
#include "SFML/Graphics.hpp"

enum State
{
    EMPTY, SEARCHING, FOUND
};

class AlgData
{
private:
    int m_Value;
    sf::IntRect m_EmptyTexCoords;
    sf::IntRect m_FilledTexCoords;
    sf::IntRect m_SuccessfullCoords;


    sf::Vector2f m_Position;

    State m_State = State::EMPTY;
public:
    AlgData(int Value, sf::Vector2f Position);

    sf::IntRect GetTexCoords() const;

    sf::Vector2f GetPosition() const;


    int GetValue() const;


    void SetSearchState(State state);
};

