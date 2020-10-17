#pragma once
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

#define INDEX_NONE -1

using UFText = sf::Text;
using UFString = sf::String;

using UFSprite = sf::Sprite;
using UFTexture = sf::Texture;

using UFCanvas = sf::RenderTexture;

using UFFont = sf::Font;

using UFColor = sf::Color;

using UFDrawable = sf::Drawable;

struct UFMargin
{
	inline float left() const { return m_rect.left; };
	inline float right() const { return m_rect.width;  };
	inline float top() const { return m_rect.top; };
	inline float bottom() const { return m_rect.height; };

private:
	sf::FloatRect m_rect;
};

using  UFVector2Df = sf::Vector2f;
using  UFVector2Du = sf::Vector2u;

using int8 = sf::Int8;
using uint8 = sf::Uint8;

using int16 = sf::Int16;
using uint16 = sf::Uint16;

using int32 = sf::Int32;
using uint32 = sf::Uint32;

using int64 = sf::Int64;
using uint64 = sf::Uint64;
