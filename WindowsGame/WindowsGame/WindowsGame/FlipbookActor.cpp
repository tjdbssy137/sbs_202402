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

	Super::Render(hdc);
}
void FlipbookActor::Update()
{
	Super::Update();
	
	if (_flipbook == nullptr) return;

	const FlipbookInfo& info = _flipbook->GetInfo();

	_sumTime += Time->GetDeltaTime();
	int frameAmount = (info.end - info.start + 1);
	// frameAmount장수만큼 실행 시키는데 duration 시간이 걸린다
	// ?? : 1 = info.duration : frameAmount
	_frameDuration = info.duration / frameAmount;

	if (_frameDuration <= _sumTime)
	{
		_sumTime -= _frameDuration;
		//cout << _index << endl;

		if (false == (info.loop == false && info.end == _index))
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