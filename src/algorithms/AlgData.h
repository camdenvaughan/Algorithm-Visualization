#pragma once
#include "SFML/Graphics.hpp"

enum class State
{
    EMPTY, SEARCHING, FOUND
};

class AlgData : public sf::Drawable
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
    AlgData(int value, sf::Vector2f position);

    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

    sf::Vector2f UpdatePositon(sf::Vector2f& position);

    sf::Vector2f GetPositon() const;

    int GetValue() const;

    int SetValue(int value);

    void SetSearchState(State state);
};

