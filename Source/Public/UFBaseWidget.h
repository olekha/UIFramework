#pragma once
#include "UFTypes.h"

class UFBaseWidget : public std::enable_shared_from_this<UFBaseWidget>
{
public:

	UFBaseWidget():
		m_Position{ UFVector2Df(0.0f, 0.0f) },
		m_Scale{ UFVector2Df(1.0f, 1.0f) },
		m_Pivot{ UFVector2Df(0.0f, 0.0f) },
		m_DesiredSize{ UFVector2Df(0.0f, 0.0f) },
		m_RenderPriority{ 0 }
	{}

	virtual ~UFBaseWidget() {}

	std::shared_ptr<const UFBaseWidget> getptr() const
	{
		return shared_from_this();
	}

	std::shared_ptr<UFBaseWidget> getptr()
	{
		return shared_from_this();
	}

	inline UFVector2Df GetPivot() const { return m_Pivot; }
	inline void SetPivot(UFVector2Df NewPivot)
	{
		if (NewPivot != m_Pivot)
		{
			m_Pivot = NewPivot;
		}
	}

	inline UFVector2Df GetPosition() const { return m_Position;	}
	inline void SetPosition(UFVector2Df NewPoisition)
	{
		if (NewPoisition != m_Position)
		{
			m_Position = NewPoisition;
		}
	}

	inline UFVector2Df GetScale() const { return m_Scale; }
	inline void SetScale(UFVector2Df NewScale)
	{
		if (NewScale != m_Scale)
		{
			m_Scale = NewScale;
		}
	}

	inline const UFVector2Df& GetDesiredSize() const { return m_DesiredSize; }

	std::weak_ptr<class UFPanelWidget> GetParent() const;

	void RemoveFromParent();

	virtual void OnAddedToParent(std::weak_ptr<class UFPanelSlot> InSlot);
	virtual void OnRemovedFromParent();

	virtual UFVector2Df CacheDesiredSize() = 0;

	virtual void ArrangeChildren() = 0;

	virtual void Draw(UFCanvas& InCanvas) = 0;

protected:
	UFVector2Df m_Position;

	UFVector2Df m_DesiredSize;

	UFVector2Df m_Scale;

	UFVector2Df m_Pivot;

	int8 m_RenderPriority;

private:

	std::weak_ptr<class UFPanelSlot> Slot;

};