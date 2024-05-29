#include "pch.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
#include "Texture.h"
#include "Scene.h"
void FlipbookActor::Init()
{
	Super::Init();
}
void FlipbookActor::Render(HDC hdc)
{
	if (!_flipbook) return;

	const FlipbookInfo& info = _flipbook->GetInfo();

	Vector2Int cameraPos = CurrentScene->GetCameraPos();
	Vector2Int screenSizeHalf = Vector2Int(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
	Vector2Int renderPos = Vector2Int(
		static_cast<int>(_body.pos.x - info.size.x / 2 - cameraPos.x + screenSizeHalf.x),
		static_cast<int>(_body.pos.y - info.size.y / 2 - cameraPos.y + screenSizeHalf.y)
	);

	::TransparentBlt(hdc,
		renderPos.x,
		renderPos.y,
		info.size.x,
		info.size.y,
		info.texture->GetDC(),
		_index * info.size.x,
		info.line * info.size.y,
		info.size.x,
		info.size.y,
		info.texture->GetTransparent()
	);

	Super::Render(hdc);
}
void FlipbookActor::Update()
{
	Super::Update();

	if (!_flipbook) return;

	const FlipbookInfo& info = _flipbook->GetInfo();
	int frameAmount = (info.end - info.start + 1);

	_sumTime += Time->GetDeltaTime();

	//변경되는 원하는 시간
	// frameAmount장수만큼 실행시키는데 duration 시간이 걸린다.
	// 1장을 실행시킬때 몇초가 걸릴까?
	// frameAmount : duration = 1 : ??
	// ?? = duration / frameAmount

	float delta = info.duration / frameAmount;

	if (delta <= _sumTime)
	{
		_sumTime -= delta;

		if (false == (info.loop == false && _index == info.end))
		{
			_index++;
			_index %= frameAmount + info.start;
		}
	}
}
void FlipbookActor::Release()
{
	Super::Release();
}
void FlipbookActor::SetFlipbook(Flipbook* flipbook)
{
	if (!flipbook) return;
	if (_flipbook == flipbook) return;

	_flipbook = flipbook;
	Reset();
}
void FlipbookActor::Reset()
{
	_index = 0;
	_sumTime = 0.0f;
}