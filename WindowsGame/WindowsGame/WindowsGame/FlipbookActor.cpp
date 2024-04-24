#include "pch.h"
#include "FlipbookActor.h"
#include "Flipbook.h"

void FlipbookActor::Init()
{
	Super::Init();
}
void FlipbookActor::Render(HDC hdc)
{
	if (!_flipbook) return;
	const FlipbookInfo& info = _flipbook->GetInfo();

	::TransparentBlt(hdc,
		static_cast<int>(_body.pos.x - info.size.x / 2),
		static_cast<int>(_body.pos.y - info.size.y / 2),
		info.size.x,
		info.size.y,
		info.texture->GetDc(),
		2 * info.size.x,
		0 * info.size.y,
		info.size.x,
		info.size.y,
		info.texture->GetTransparent()
	);
	Super::Render(hdc);
}
void FlipbookActor::Update()
{
	Super::Update();
	const FlipbookInfo& info = _flipbook->GetInfo();

	_sumTime += Time->GetDeltaTime();
	if (0.1f <= _sumTime)
	{
		_index++;
		if (info.end < _index)
		{
			_index = info.start;
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