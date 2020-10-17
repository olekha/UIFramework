#include "Public/UFTextLabel.h"

UFTextLabel::UFTextLabel()
{
	m_Text_RenderObject = std::make_shared<UFRenderObject_Text>();
}

UFTextLabel::UFTextLabel(const char* InText, const UFFont* InFont /*= nullptr*/, unsigned int InCharacterSize/* = 30*/)
{
	m_Text_RenderObject = std::make_shared<UFRenderObject_Text>(InText, InFont, InCharacterSize);
}

UFTextLabel::UFTextLabel(const char* InText, 
	const UFFont* InFont,
	unsigned int InCharacterSize,
	UFVector2Df InPosition, 
	UFVector2Df InSize, 
	UFVector2Df InScale,
	UFVector2Df InPivot)
{
	m_Position = InPosition;
	m_Size = InSize;
	m_Scale = InScale;
	m_Pivot = InPivot;

	m_Text_RenderObject = std::make_shared<UFRenderObject_Text>(InText, InFont, InCharacterSize);
}

const UFString& UFTextLabel::GetText() const
{
	return m_Text_RenderObject->GetString();
}

void UFTextLabel::SetText(const char* NewText)
{
	if(NewText != m_Text_RenderObject->GetString())
	{
		m_Text_RenderObject->SetString(NewText);
	}
}

void UFTextLabel::SetColor(const UFColor& NewColor)
{
	m_Text_RenderObject->SetColor(NewColor);
}

UFVector2Df UFTextLabel::CacheDesiredSize()
{
	m_DesiredSize = m_Text_RenderObject->GetTextSize();

	return m_DesiredSize;
}

void UFTextLabel::Draw(UFCanvas& InCanvas)
{
	InCanvas.draw(m_Text_RenderObject->GetTextToRender());
}

