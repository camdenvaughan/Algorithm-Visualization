#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
class Button : public sf::Drawable
{
public:
	Button(std::string text, unsigned int fontSize, sf::IntRect defaultTextureCoords = sf::IntRect(0, 0, 192, 64), sf::IntRect clickTextureCoords = sf::IntRect(0, 64, 192, 64), sf::IntRect hoverTextureCoords = sf::IntRect(192, 0, 192, 64), sf::Color textColor = sf::Color::White);
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

	void ClickButton();

	void SetFont(sf::Font& font);

	void SetDefaultTexCoords(sf::IntRect texCoords);
	void SetClickTexCoords(sf::IntRect texCoords);
	void SetHoverTexCoords(sf::IntRect texCoords);

	void SetTextFillColor(sf::Color color);

	void SetPosition(sf::Vector2f position);

	bool MouseIsOver(sf::Vector2i mousePos);
public:
	bool hasBeenClicked = false;
private:

	sf::IntRect m_DefaultTexCoord;
	sf::IntRect m_ClickTexCoord;
	sf::IntRect m_HoverTexCoord;

	sf::Sprite m_Sprite;
	sf::Text m_Text;


};

