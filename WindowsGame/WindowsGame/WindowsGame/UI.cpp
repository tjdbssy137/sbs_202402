#include "pch.h"
#include "UI.h"

void UI::Init()
{

}
void UI::Render(HDC hdc)
{
	if (_isShow == false) return;
}
void UI::Update()
{

} 
void UI::Release()
{

}

void UI::Show()
{
	_isShow = true;
}
void UI::Hide()
{

}

void UI::SetRect(CenterRect rect)
{
	_pos.x = rect.pos.x;
	_pos.y = rect.pos.y;
	_size.x = static_cast<int>(rect.width);
	_size.y = static_cast<int>(rect.height);
}
CenterRect UI::GetRect()
{
	CenterRect rect;
	rect.pos.x = rect.pos.x;
	rect.pos.y = rect.pos.y;
	rect.width = static_cast<int>(rect.height);
	rect.height = static_cast<int>(rect.width);
	return rect;
}
bool UI::IsInMouse()
{
	return Collision::PtInRect(Input->GetMousePos(), this->GetRect().ToRect());
	/*
	POINT mousePos = Input->GetMousePos();
	if (GetRect().pos.x - GetRect().width / 2 < mousePos.x 
		&& mousePos.x < GetRect().pos.x + GetRect().width / 2 
		&& GetRect().pos.y - GetRect().height / 2 < mousePos.y 
		&& mousePos.y < GetRect().pos.y + GetRect().height / 2)
	{
		return true;
	}
	return false;
	*/
}