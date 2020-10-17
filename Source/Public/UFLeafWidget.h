#pragma once

#include "UFBaseWidget.h"

class UFLeafWidget : public UFBaseWidget
{
protected:

	virtual void ArrangeChildren() override;

	virtual UFVector2Df CacheDesiredSize() = 0;

	virtual void Draw(UFCanvas& InCanvas) = 0;
};