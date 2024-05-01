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

	// static_cast<int>(_body.pos.x - info.size.x / 2), static_cast<int>(_body.pos.y - info.size.y / 2),
	// 요 위치에 그림을 그리겠다. 만약 100, 100 처럼 고정값을 주면 캐릭터는 더는 움직이지 않음
	
	Vector2Int cameraPos = CurrentScene->GetCameraPos();
	Vector2Int ScreenSizeHalf = Vector2Int(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
	Vector2Int renderPos = Vector2Int(
		static_cast<int>(_body.pos.x - info.size.x / 2 - cameraPos.x + ScreenSizeHalf.x),
		static_cast<int>(_body.pos.y - info.size.y - cameraPos.y + ScreenSizeHalf.y)
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