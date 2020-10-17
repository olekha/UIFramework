#pragma once

#include "UFTypes.h"
#include "Public/UFLeafWidget.h"
#include "Public/UFRenderObjects.h"

class UFImage : public UFLeafWidget
{
public:

	UFImage();
	UFImage(const UFTexture* InTexture);
	UFImage(const UFTexture* InTexture, UFVector2Df InPosition, UFVector2Df InScale, UFVector2Df InPivot);

	const UFTexture& GetTexture() const;

	void SetColor(const UFColor& InColor);

	void SetScale(const UFVector2Df& InScale);
	
	virtual void Draw(UFCanvas& InCanvas);

protected:

	virtual UFVector2Df CacheDesiredSize();

private:
	std::shared_ptr<UFRenderObject_Sprite> m_Sprite_RenderObject;
};

