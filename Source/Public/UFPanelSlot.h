#pragma once

enum class EUFHorizontalAlignment
{
	None,
	Left,
	Right,
	Center,
	Fill,
	Max
};

enum class EUFVerticalAlignment
{
	None,
	Top,
	Bottom,
	Center,
	Fill,
	Max
};

class UFPanelSlot
{
public:

	std::weak_ptr<class UFPanelWidget> Parent;

	std::shared_ptr<class UFBaseWidget> Content;
};

class UFHorizontalBoxSlot : public UFPanelSlot
{
public:
	UFMargin Padding;

	EUFHorizontalAlignment HAlign;

	EUFVerticalAlignment VAlign;
};