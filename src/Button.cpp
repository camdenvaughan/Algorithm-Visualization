#include "Button.h"
#include "Helpers.h"
#include "Renderer.h"

Button::Button(std::string text, SceneState sceneState, unsigned int fontSize, sf::IntRect defaultTextureCoords, sf::IntRect clickTextureCoords, sf::IntRect hoverTextureCoords, sf::Color textColor)
	: m_SceneState(sceneState), m_DefaultTexCoord(defaultTextureCoords), m_ClickTexCoord(clickTextureCoords), m_HoverTexCoord(hoverTextureCoords)
{
	m_Sprite.setTexture(Renderer::GetTexture());
	m_Sprite.setTextureRect(defaultTextureCoords);

	m_Text.setFont(Renderer::GetFont());
	m_Text.setFillColor(textColor);
	m_Text.setCharacterSize(fontSize);
	m_Text.setString(text);
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
	m_Text.setPosition(Helpers::GetCenterObjectOnBackgroundPosition(position, m_Sprite.getLocalBounds(), m_Text.getLocalBounds()));
}

bool Button::MouseIsOver(sf::Vector2i mousePos)
{
	float butLeft = m_Sprite.getPosition().x;
	float butTop = m_Sprite.getPosition().y;
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

SceneState Button::GetSceneState()
{
	return m_SceneState;
}
