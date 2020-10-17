#pragma once
#include "Public/UFPanelWidget.h"
#include "Public/UFPanelSlot.h"

class UFHorizontalBox : public UFPanelWidget
{
public:
	virtual std::weak_ptr<class UFPanelSlot> AddChild(std::shared_ptr<UFBaseWidget> Content);

protected:
	virtual UFVector2Df CacheDesiredSize() override;

	virtual void ArrangeChildren() override;

	virtual void Draw(UFCanvas& InCanvas) override;
};
