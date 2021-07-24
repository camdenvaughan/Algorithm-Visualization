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
    sf::Vector2f m_Position;

    sf::IntRect m_EmptyTexCoords;
    sf::IntRect m_FilledTexCoords;
    sf::IntRect m_SuccessfullCoords;

    sf::Sprite m_Sprite;
    sf::Text m_Text;

    State m_State;
public:
    AlgData(int value, sf::Vector2f position, sf::Texture& texture, sf::Font& font);

    void Draw();

    sf::Vector2f UpdatePositon(sf::Vector2f& position);

    sf::Vector2f GetPositon() const;

    int GetValue() const;

    int SetValue(int value);

    void SetSearchState(State state);
};

