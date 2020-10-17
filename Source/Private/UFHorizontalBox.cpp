#include "Public/UFHorizontalBox.h"

std::weak_ptr<class UFPanelSlot> UFHorizontalBox::AddChild(std::shared_ptr<UFBaseWidget> Content)
{
	return AddChild_Template<UFHorizontalBoxSlot>(Content);
}

UFVector2Df UFHorizontalBox::CacheDesiredSize()
{
	m_DesiredSize = UFVector2Df(0.0f, 0.0f);

	for(int32 i = 0; i < Slots.Num(); ++i)
	{
		std::shared_ptr<UFHorizontalBoxSlot> ChildSlot = std::dynamic_pointer_cast<UFHorizontalBoxSlot>(Slots[i]);

		if(ChildSlot == nullptr
			|| ChildSlot->Content == nullptr)
		{
			continue;
		}

		UFVector2Df ChildSize = ChildSlot->Content->CacheDesiredSize();
		ChildSize.x += (ChildSlot->Padding.left() + ChildSlot->Padding.right());
		ChildSize.y += (ChildSlot->Padding.top() + ChildSlot->Padding.bottom());

		m_DesiredSize.x += ChildSize.x;

		if(ChildSize.y > m_DesiredSize.y)
		{
			m_DesiredSize.y = ChildSize.y;
		}
	}

	return m_DesiredSize;
}

void UFHorizontalBox::ArrangeChildren()
{
	const float TopOffset = m_Position.y;
	float LeftOffset = m_Position.x;

	for (int32 i = 0; i < Slots.Num(); ++i)
	{
		std::shared_ptr<UFHorizontalBoxSlot> ChildSlot = std::dynamic_pointer_cast<UFHorizontalBoxSlot>(Slots[i]);

		if(ChildSlot->Content == nullptr)
		{
			continue;
		}

		LeftOffset += ChildSlot->Padding.left();

		ChildSlot->Content->SetPosition(UFVector2Df(LeftOffset, TopOffset + ChildSlot->Padding.top()));

		ChildSlot->Content->ArrangeChildren();

		LeftOffset += ChildSlot->Padding.right();
		LeftOffset += ChildSlot->Content->GetDesiredSize().x;
	}
}

void UFHorizontalBox::Draw(UFCanvas& InCanvas)
{

}

