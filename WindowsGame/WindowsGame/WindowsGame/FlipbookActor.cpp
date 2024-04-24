#include "pch.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
#include "Texture.h"

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
		info.texture->GetDC(),
		_index * info.size.x,
		info.line * info.size.y,
		info.size.x,
		info.size.y,
		info.texture->GetTransparent()
	);

	_frameDuration = info.duration / info.end;
	Super::Render(hdc);
}
void FlipbookActor::Update()
{
	Super::Update();

	const FlipbookInfo& info = _flipbook->GetInfo();

	if (_activeLoop == true)
	{
		_sumTime += Time->GetDeltaTime();

		if (_frameDuration <= _sumTime)
		{
			_index++;
			_sumTime = 0;
			//cout << _index << endl;
			if (info.loop == true)
			{
				if (info.end < _index)
				{
					_index = info.start;
				}
			}
			else
			{
				if (info.end < _index)
				{
					_index = info.end;
					_activeLoop = false;
				}
			}
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