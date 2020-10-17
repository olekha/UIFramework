#include "Public/UFImage.h"

UFImage::UFImage()
{
	m_Sprite_RenderObject = std::make_shared<UFRenderObject_Sprite>();
}

UFImage::UFImage(const UFTexture* InTexture)
{
	m_Sprite_RenderObject = std::make_shared<UFRenderObject_Sprite>(InTexture);
}

UFImage::UFImage(const UFTexture* InTexture, UFVector2Df InPosition, UFVector2Df InScale, UFVector2Df InPivot)
{
	m_Position = InPosition;
	m_Scale = InScale;
	m_Pivot = InPivot;

	m_Sprite_RenderObject = std::make_shared<UFRenderObject_Sprite>(InTexture);
}

const UFTexture& UFImage::GetTexture() const
{
	return m_Sprite_RenderObject->GetTexture();
}

void UFImage::SetColor(const UFColor& InColor)
{
	m_Sprite_RenderObject->SetColor(InColor);
}

void UFImage::SetScale(const UFVector2Df& InScale)
{
	m_Sprite_RenderObject->SetScale(InScale);
}

UFVector2Df UFImage::CacheDesiredSize()
{
	m_DesiredSize = UFVector2Df(0.0f, 0.0f);
	
	m_DesiredSize.x = m_Sprite_RenderObject->GetTextureSize().x * m_Sprite_RenderObject->GetTextureScale().x;
	m_DesiredSize.y = m_Sprite_RenderObject->GetTextureSize().y * m_Sprite_RenderObject->GetTextureScale().y;

	return m_DesiredSize;
}

void UFImage::Draw(UFCanvas& InCanvas)
{
	InCanvas.draw(m_Sprite_RenderObject->GetSpriteToRender());
}
