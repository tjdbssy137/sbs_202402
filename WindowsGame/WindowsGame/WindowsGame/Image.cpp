#include "pch.h"
#include "Image.h"
#include "Sprite.h"

void Image::Init()
{
	Super::Init();
}
void Image::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_isShow == false) return;
	if (_sprite == nullptr) return;

	Vector2Int size = _sprite->GetSize();

	Vector2Int renderPos = Vector2Int(
		static_cast<int>(_pos.x - size.x / 2),
		static_cast<int>(_pos.y - size.y / 2)
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
		_sprite->GetTransparent()//Åõ¸í»ö
	);
}
void Image::Update()
{
	Super::Update();
}
void Image::Release()
{
	Super::Release();
}