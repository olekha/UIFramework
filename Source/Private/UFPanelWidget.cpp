#include "Public/UFPanelWidget.h"
#include "Public/UFPanelSlot.h"

int32 UFPanelWidget::GetChildrenCount() const
{
	return Slots.Num();
}

std::weak_ptr<UFBaseWidget> UFPanelWidget::GetChildAt(int32 Index) const
{
	if(Slots.IsValidIndex(Index))
	{	
		if(std::shared_ptr<UFPanelSlot> ChildSlot = Slots[Index])
		{
			return ChildSlot->Content;
		}
	}

	return {};
}

TArray<std::weak_ptr<UFBaseWidget>> UFPanelWidget::GetAllChildren() const
{
	TArray<std::weak_ptr<UFBaseWidget>> Result(Slots.Num());

	for(int32 i = 0; i < Slots.Num(); ++i)
	{
		if(std::shared_ptr<UFPanelSlot> ChildSlot = Slots[i])
		{
			Result.Add(ChildSlot->Content);
		}
	}

	return Result;
}

int32 UFPanelWidget::GetChildIndex(const std::shared_ptr<UFBaseWidget> Content) const
{
	if(Content == nullptr)
	{
		return;
	}

	for(int32 i = 0; i < Slots.Num(); ++i)
	{
		std::weak_ptr<UFBaseWidget> PanelSlot = GetChildAt(i);

		if(PanelSlot.expired())
		{
			continue;
		}

		if(PanelSlot.lock() == Content)
		{
			return i;
		}
	}

	return INDEX_NONE;
}

bool UFPanelWidget::HasChild(std::shared_ptr<UFBaseWidget> Content) const
{
	if(Content == nullptr
		|| Content->GetParent().expired())
	{
		return false;
	}

	return Content->GetParent().lock() == getptr();
}

std::weak_ptr<class UFPanelSlot> UFPanelWidget::AddChild(std::shared_ptr<UFBaseWidget> Content)
{
	return AddChild_Template<UFPanelSlot>(Content);
}

bool UFPanelWidget::RemoveChildAt(int32 Index)
{
	if(!Slots.IsValidIndex(Index))
	{
		return false;
	}

	std::shared_ptr<UFPanelSlot> PanelSlot = Slots[Index];

	if(PanelSlot->Content != nullptr)
	{
		PanelSlot->Content->OnRemovedFromParent();
	}

	Slots.RemoveAt(Index);
}

bool UFPanelWidget::RemoveChild(std::shared_ptr<UFBaseWidget> Content)
{
	int32 Index = GetChildIndex(Content);

	return RemoveChildAt(Index);
}

void UFPanelWidget::ClearChildren()
{
	for(int32 Index = GetChildrenCount() - 1; Index >= 0; Index--)
	{
		RemoveChildAt(Index);
	}
}

const TArray<std::weak_ptr<UFPanelSlot>> UFPanelWidget::GetSlots() const
{
	TArray<std::weak_ptr<UFPanelSlot>> Result(Slots.Num());

	for (int32 i = 0; i < Slots.Num(); ++i)
	{
		Result.Add(Slots[i]);
	}

	return Result;
}
