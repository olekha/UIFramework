#pragma once
#include "UFLeafWidget.h"
#include "UFRenderObjects.h"

class UFTextLabel : public UFLeafWidget
{
public:

	UFTextLabel();
	UFTextLabel(const char* InText, const UFFont* InFont = nullptr, unsigned int InCharacterSize = 30);
	UFTextLabel(const char* InText, const UFFont* InFont, unsigned int InCharacterSize,
		UFVector2Df InPosition, UFVector2Df InSize, UFVector2Df InScale, UFVector2Df InPivot);

	const UFString& GetText() const;

	void SetText(const char* NewText);

	void SetColor(const UFColor& NewColor);

	virtual void Draw(UFCanvas& InCanvas);

protected:

	virtual UFVector2Df CacheDesiredSize();

private:
	std::shared_ptr<UFRenderObject_Text> m_Text_RenderObject;
};