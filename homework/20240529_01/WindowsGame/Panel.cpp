#include "pch.h"
#include "Panel.h"
void Panel::Init()
{
	Super::Init();

	for (UI* child : _children)
	{
		child->Init();
	}
}
void Panel::Render(HDC hdc)
{
	if (_isShow == false) return;

	Super::Render(hdc);

	for (UI* child : _children)
	{
		child->Render(hdc);
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
	_children.push_back(ui);
	ui->SetParent(this);
}
bool Panel::RemoveChild(UI* ui)
{
	if (ui == nullptr) return false;

	auto findIt = find(_children.begin(), _children.end(), ui);

	if (findIt != _children.end())
	{
		(*findIt)->SetParent(nullptr);
		_children.erase(findIt);
		return true;
	}

	return false;
}