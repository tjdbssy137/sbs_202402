#include "pch.h"
#include "UI.h"
#include "Panel.h"

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
	_isShow = false;
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
	rect.pos.x = _pos.x;
	rect.pos.y = _pos.y;
	//rect.pos = _pos;
	rect.width = static_cast<float>(_size.x);
	rect.height = static_cast<float>(_size.y);

	return rect;
}
bool UI::IsInMouse()
{
	//IsInMouse도 Parent의 좌표를 기준으로 측정해줘야한다.
	Panel* parent = this->GetParent();
	Vector2 parentPos = Vector2::Zero();
	while (parent != nullptr)
	{
		parentPos += parent->GetPos();
		parent = parent->GetParent();
	}

	return Collision::PtInRect(Input->GetMousePos(), 
		Shape::MakeCenterRect(
			parentPos.x + this->_pos.x, 
			parentPos.y + this->_pos.y,
			this->_size.x,
			this->_size.y
		)
		.ToRect());
}