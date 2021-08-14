#include "TextBox.h"
#include "Resources.h"

TextBox::TextBox()
{
}

TextBox::TextBox(sf::Text text)
	: m_Text(text)
{
}

TextBox::TextBox(std::string string, unsigned int size, sf::Vector2f position)
{
    m_Text.setFont(Resources::GetFont());
    m_Text.setCharacterSize(size);
    SetString(string);
    m_Text.setPosition(position);
}

void TextBox::SetString(std::string string)
{
    m_Text.setString(string);
    m_Text.setOrigin(sf::Vector2f(m_Text.getLocalBounds().width / 2, m_Text.getLocalBounds().height / 2));
}

void TextBox::SetPosition(sf::Vector2f position)
{
    m_Text.setPosition(position);
}

void TextBox::SetCharacterSize(unsigned int size)
{
    m_Text.setCharacterSize(size);
    m_Text.setOrigin(sf::Vector2f(m_Text.getLocalBounds().width / 2, m_Text.getLocalBounds().height / 2));
}

void TextBox::SetFont(sf::Font font)
{
    m_Text.setFont(font);
}

sf::Vector2f TextBox::GetPosition() const
{
    return m_Text.getPosition();
}

sf::FloatRect TextBox::GetLocalBounds() const
{
    return m_Text.getLocalBounds();
}

void TextBox::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(m_Text);
}
