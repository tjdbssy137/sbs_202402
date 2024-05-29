#include "pch.h"
#include "SpriteActor.h"
#include "Sprite.h"
#include "Texture.h"
#include "Scene.h"

void SpriteActor::Init()
{
	Super::Init();
}
void SpriteActor::Render(HDC hdc)
{
	if (_sprite == nullptr) return;

	Vector2Int size = _sprite->GetSize();

	Vector2Int cameraPos = CurrentScene->GetCameraPos();
	Vector2Int screenSizeHalf = Vector2Int(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
	Vector2Int renderPos = Vector2Int(
		static_cast<int>(_body.pos.x - size.x / 2 - cameraPos.x + screenSizeHalf.x),
		static_cast<int>(_body.pos.y - size.y / 2 - cameraPos.y + screenSizeHalf.y)
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
		_sprite->GetTransparent()
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