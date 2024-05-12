#include "pch.h"
#include "Panel.h"

void Panel::Init()
{
	Super::Init();
	for (UI* child : _children)
	{
		child->Init();
		//여기서만 사용됨..
	}
}
void Panel::Render(HDC hdc)
{
	if (_isShow == false) return;
	Super::Render(hdc);

	for (UI* child : _children)
	{
		//여기서 부르면 계속 더해짐
		child->Render(hdc);
		
		//cout << WIN_SIZE_X << endl;
		//cout << this->GetRect().pos.x << endl;
		//cout << child->GetRect().pos.x << endl;
	}
}
void Panel::Update()
{
	Super::Update();
	for (UI* child : _children)
	{
		child->Update();
	}
}
void Panel::Release()
{
	Super::Release();
	for (UI* child : _children)
	{
		child->Release();
		SAFE_DELETE(child);
	}
	_children.clear();
}

void Panel::AddChild(UI* ui)
{
	if (ui == nullptr) return;

	ui->SetRect(Shape::MakeCenterRect(this->GetRect().pos.x / 2 + ui->GetRect().pos.x,
		this->GetRect().pos.y / 2 + ui->GetRect().pos.y,
		ui->GetRect().width,
		ui->GetRect().height));
	_children.push_back(ui);
}
bool Panel::RemoveChild(UI* ui)
{
	if (ui == nullptr) return false;

	auto findIt = find(_children.begin(), _children.end(), ui);

	if (findIt != _children.end())
	{
		_children.erase(findIt);
		return true;
	}

	return false;
}