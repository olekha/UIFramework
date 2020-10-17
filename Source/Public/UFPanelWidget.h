#pragma once

#include "UFBaseWidget.h"
#include "Public/TArray.h"

class UFPanelWidget : public UFBaseWidget
{

public:

	int32 GetChildrenCount() const;

	std::weak_ptr<UFBaseWidget> GetChildAt(int32 Index) const;

	TArray<std::weak_ptr<UFBaseWidget>> GetAllChildren() const;

	int32 GetChildIndex(const std::shared_ptr<UFBaseWidget> Content) const;

	bool HasChild(std::shared_ptr<UFBaseWidget> Content) const;

	virtual std::weak_ptr<class UFPanelSlot> AddChild(std::shared_ptr<UFBaseWidget> Content);

	bool RemoveChildAt(int32 Index);

	bool RemoveChild(std::shared_ptr<UFBaseWidget> Content);

	void ClearChildren();

	const TArray<std::weak_ptr<class UFPanelSlot>> GetSlots() const;

protected:
	template<typename SlotType>
	std::weak_ptr<SlotType> AddChild_Template(std::shared_ptr<UFBaseWidget> Content)
	{
		if (Content == nullptr)
		{
			return {};
		}

		Content->RemoveFromParent();

		std::shared_ptr<SlotType> NewPanelSlot = std::make_shared<SlotType>();
		NewPanelSlot->Content = Content;
		NewPanelSlot->Parent = getptr();

		Content->OnAddedToParent(NewPanelSlot);

		Slots.Add(NewPanelSlot);

		return NewPanelSlot;
	}

protected:

	TArray<std::shared_ptr<class UFPanelSlot>> Slots;
};