#include "Public/UFBaseWidget.h"
#include "Public/UFPanelSlot.h"
#include "Public/UFPanelWidget.h"

std::weak_ptr<class UFPanelWidget> UFBaseWidget::GetParent() const
{
	if(Slot.expired())
	{
		return {};
	}

	return Slot.lock()->Parent;
}

void UFBaseWidget::RemoveFromParent()
{
	std::weak_ptr<class UFPanelWidget> CurrentParent = GetParent();

	if(CurrentParent.expired())
	{
		return;
	}

	CurrentParent.lock()->RemoveChild(getptr());
}

void UFBaseWidget::OnAddedToParent(std::weak_ptr<class UFPanelSlot> InSlot)
{
	if(InSlot.expired()
		|| InSlot.lock()->Content != getptr())
	{
		return;
	}

	Slot = InSlot;
}

void UFBaseWidget::OnRemovedFromParent()
{
	Slot = std::weak_ptr<class UFPanelSlot>();
}
