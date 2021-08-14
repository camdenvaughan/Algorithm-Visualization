#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


enum class SceneState;

class Button : public sf::Drawable
{
public:
	Button(std::string text, sf::Vector2f position, SceneState sceneState, unsigned int fontSize = 25, sf::IntRect defaultTextureCoords = sf::IntRect(0, 0, 192, 64), sf::IntRect clickTextureCoords = sf::IntRect(0, 64, 192, 64), sf::IntRect hoverTextureCoords = sf::IntRect(192, 0, 192, 64), sf::Color textColor = sf::Color::White);
	
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

	void ClickButton();

	void SetFont(sf::Font& font);

	void SetDefaultTexCoords(sf::IntRect texCoords);
	void SetClickTexCoords(sf::IntRect texCoords);
	void SetHoverTexCoords(sf::IntRect texCoords);

	void SetTextFillColor(sf::Color color);

	void SetPosition(sf::Vector2f position);

	bool MouseIsOver(sf::Vector2i mousePos);

	SceneState GetSceneState() const;

public:
	const std::string name;
	bool hasBeenClicked = false;

private:
	SceneState m_SceneState;

	sf::IntRect m_DefaultTexCoord;
	sf::IntRect m_ClickTexCoord;
	sf::IntRect m_HoverTexCoord;

	sf::Sprite m_Sprite;
	sf::Text m_Text;


};

