#include "Button.h"
#include "Helpers.h"
#include "Renderer.h"

Button::Button(std::string text, SceneState sceneState, unsigned int fontSize, sf::IntRect defaultTextureCoords, sf::IntRect clickTextureCoords, sf::IntRect hoverTextureCoords, sf::Color textColor)
	: name(text), m_SceneState(sceneState), m_DefaultTexCoord(defaultTextureCoords), m_ClickTexCoord(clickTextureCoords), m_HoverTexCoord(hoverTextureCoords)
{
	m_Sprite.setTexture(Renderer::GetTexture());
	m_Sprite.setTextureRect(defaultTextureCoords);
	m_Sprite.setOrigin(sf::Vector2f(m_Sprite.getLocalBounds().width / 2, m_Sprite.getLocalBounds().height / 2));

	m_Text.setFont(Renderer::GetFont());
	m_Text.setFillColor(textColor);
	m_Text.setCharacterSize(fontSize);
	m_Text.setString(text);
	m_Text.setOrigin(sf::Vector2f(m_Text.getLocalBounds().width / 2, m_Text.getLocalBounds().height / 2));
	m_Text.setPosition(m_Sprite.getPosition());
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(m_Sprite);
	target.draw(m_Text);
}

void Button::ClickButton()
{
	m_Sprite.setTextureRect(m_ClickTexCoord);
	hasBeenClicked = true;
}

void Button::SetFont(sf::Font& font)
{
	m_Text.setFont(font);
}

void Button::SetDefaultTexCoords(sf::IntRect texCoords)
{
	m_DefaultTexCoord = texCoords;
	m_Sprite.setTextureRect(texCoords);
}

void Button::SetClickTexCoords(sf::IntRect texCoords)
{
	m_ClickTexCoord = texCoords;
}

void Button::SetHoverTexCoords(sf::IntRect texCoords)
{
	m_HoverTexCoord = texCoords;
}

void Button::SetTextFillColor(sf::Color color)
{
	m_Text.setFillColor(color);
}

void Button::SetPosition(sf::Vector2f position)
{
	m_Sprite.setPosition(position);
	m_Text.setPosition(m_Sprite.getPosition());
}

bool Button::MouseIsOver(sf::Vector2i mousePos)
{
	float butLeft = m_Sprite.getPosition().x - (m_Sprite.getLocalBounds().width / 2);
	float butTop = m_Sprite.getPosition().y - (m_Sprite.getLocalBounds().height / 2);
	float butRight = butLeft + m_Sprite.getLocalBounds().width;
	float butBottom = butTop + m_Sprite.getLocalBounds().height;
	if (mousePos.x > butLeft && mousePos.x < butRight && mousePos.y > butTop && mousePos.y < butBottom)
	{
		m_Sprite.setTextureRect(m_HoverTexCoord);
		return true;
	}
	m_Sprite.setTextureRect(m_DefaultTexCoord);
	return false;
}

SceneState Button::GetSceneState() const
{
	return m_SceneState;
}
