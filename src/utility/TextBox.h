#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class TextBox : public sf::Drawable
{
public:
	TextBox();
	TextBox(sf::Text text);
	TextBox(std::string string, unsigned int size = 25, sf::Vector2f position = sf::Vector2f(0.0f, 0.0f));

	void SetString(std::string string);
	void SetPosition(sf::Vector2f position);
	void SetCharacterSize(unsigned int size);
	void SetFont(sf::Font font);

	sf::Vector2f GetPosition() const;

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

private:
	sf::Text m_Text;
};

