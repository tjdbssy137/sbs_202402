#include "pch.h"
#include "Image.h"
#include "Sprite.h"
#include "Panel.h"

void Image::Init()
{
	Super::Init();
}
void Image::Render(HDC hdc)
{
	if (_isShow == false) return;
	if (_sprite == nullptr) return;

	Vector2Int size = _sprite->GetSize();

	//부모의 부모의 부모의 .. position을 가져올 수 있음
	// 계층 구조 순환 프로그래밍 공식
	Panel* parent = this->GetParent();
	Vector2 parentPos = Vector2::Zero();
	while (parent != nullptr)
	{
		parentPos += parent->GetPos();
		parent = parent->GetParent();
	}

	Vector2Int renderPos = Vector2Int(
		static_cast<int>(parentPos.x + _pos.x - size.x / 2),
		static_cast<int>(parentPos.y + _pos.y - size.y / 2)
	);
	::TransparentBlt(hdc,
		renderPos.x,
		renderPos.y,
		size.x,
		size.y,
		_sprite->GetDC(),
		_sprite->GetPos().x,
		_sprite->GetPos().y,
		size.x,
		size.y,
		_sprite->GetTransparent()//투명색
	);
	Super::Render(hdc);
}
void Image::Update()
{
	Super::Update();
}
void Image::Release()
{
	Super::Release();
}