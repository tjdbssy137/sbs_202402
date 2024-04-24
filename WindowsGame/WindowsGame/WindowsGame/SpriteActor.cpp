#include "pch.h"
#include "SpriteActor.h"
#include "Sprite.h"

void SpriteActor::Init()
{
	Super::Init();
 }
void SpriteActor::Render(HDC hdc)
{
	if (_sprite == nullptr) return;
	Vector2Int size = _sprite->GetSize();
	::TransparentBlt(hdc,
		static_cast<int>(_body.pos.x - size.x / 2),
		static_cast<int>(_body.pos.y - size.y / 2),
		size.x,
		size.y,
		_sprite->GetDC(),
		_sprite->GetPos().x,
		_sprite->GetPos().y,
		size.x,
		size.y,
		_sprite->GetTransparent()//Åõ¸í»ö
	);
	Super::Render(hdc);

 }
void SpriteActor::Update()
{
	Super::Update();
}
void SpriteActor::Release()
{
	Super::Release();
}