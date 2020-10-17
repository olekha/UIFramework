#pragma once
#include "UFTypes.h"

struct UFRenderObject
{
	UFColor m_RenderColor = UFColor::White;

	UFVector2Df m_RenderPosition = UFVector2Df(0.0f, 0.0f);

	UFVector2Df m_RenderScale = UFVector2Df(1.0f, 1.0f);

	UFVector2Df m_RenderPivot = UFVector2Df(0.0f, 0.0f);

	float m_RenderOpacity = 1.0f;

	int8 m_RenderPriority = 0;

	bool m_bIsHidden = false;
};

struct UFRenderObject_Text : UFRenderObject
{
public:
	UFRenderObject_Text()
	{
		if (!m_Font.loadFromFile("Content/Fonts/Roboto/Roboto-Regular.ttf"))
		{
			return;
		}

		m_Text = UFText(UFString(""), m_Font, 30);
	}

	UFRenderObject_Text(const char* InString, const UFFont* InFont = nullptr, unsigned int InCharacterSize = 30)
	{
		if (InFont == nullptr)
		{
			if (!m_Font.loadFromFile("Content/Fonts/Roboto/Roboto-Regular.ttf"))
			{
				return;
			}
		}
		else
		{
			m_Font = *InFont;
		}

		m_Text = UFText(InString, m_Font, InCharacterSize);
	}

	inline const UFString& GetString() const
	{
		return m_Text.getString();
	}

	void SetString(const char* InString)
	{
		m_Text.setString(InString);
	}

	void SetFont(const UFFont& InFont)
	{
		m_Font = InFont;
		m_Text.setFont(m_Font);
	}

	inline void SetColor(const UFColor& InColor)
	{
		m_Text.setFillColor(InColor);
	}

	inline void SetPosition(const UFVector2Df InPosition)
	{
		m_Text.setPosition(InPosition);
	}

	inline void SetPivot(const UFVector2Df InPivot)
	{
		m_Text.setOrigin(InPivot);
	}

	inline const UFText& GetTextToRender() const { return m_Text; }

	inline UFVector2Df GetTextSize() const { return UFVector2Df(m_Text.getLocalBounds().width, m_Text.getLocalBounds().height); };

private:
	UFText m_Text;

	UFFont m_Font;
};

struct UFRenderObject_Sprite : UFRenderObject
{
public:
	UFRenderObject_Sprite()
	{
		if (!m_Texture.loadFromFile("Content/Textures/Defaults/DefaultIMG.png"))
		{
			return;
		}

		m_Sprite = UFSprite(m_Texture);
	}

	UFRenderObject_Sprite(const UFTexture* InTexture)
	{
		if (InTexture == nullptr)
		{
			if (!m_Texture.loadFromFile("Content/Textures/Defaults/DefaultIMG.png"))
			{
				return;
			}
		}
		else
		{
			m_Texture = *InTexture;
		}

		m_Sprite = UFSprite(m_Texture);
	}

	inline const UFTexture& GetTexture() const
	{
		return *m_Sprite.getTexture();
	}

	inline void SetTexture(const UFTexture& InTexture)
	{
		m_Texture = InTexture;
		m_Sprite.setTexture(m_Texture);
	}

	inline void SetColor(const UFColor& InColor)
	{
		m_Sprite.setColor(InColor);
	}

	inline void SetScale(const UFVector2Df& IsScale)
	{
		m_Sprite.setScale(IsScale);
	}

	inline UFVector2Df GetTextureSize() const
	{
		return UFVector2Df(m_Sprite.getLocalBounds().width, m_Sprite.getLocalBounds().height);
	};

	inline UFVector2Df GetTextureScale() const
	{
		return m_Sprite.getScale();
	}

	inline const UFSprite& GetSpriteToRender() const { return m_Sprite; }

private:
	UFSprite m_Sprite;

	UFTexture m_Texture;
};
