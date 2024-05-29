#include "pch.h"
#include "CameraComponent.h"
#include "Actor.h"
#include "Scene.h"
#include "Sprite.h"
void CameraComponent::Init()
{
	Super::Init();
	_sumTime = 0.0f;	// 현재 연출 진행중인 체크시간
	_duration = 0.3f;	// 연출하는데 걸린 시간,
	Vector2 _endPos = Vector2::Zero();
}
void CameraComponent::Render(HDC hdc)
{
	Super::Render(hdc);
}
void CameraComponent::Update()
{
	Super::Update();

	//수도코드
	// 1. 나의 액터를 가져온다.
	// 
	// 2. 카메라 좌표를 구성해준다.
	//    - newCameraPos = clamp(WIN_SIZE_X / 2 ~ 배경 width - WIN_SIZE_X / 2);
	// 3. [씬의 카메라 위치] 내 액터위치로 바꾼다.
	//  

	Actor* owner = this->GetOwner();
	if (owner)
	{
		Vector2 startPos = CurrentScene->GetCameraPos();
		Vector2 endPos = owner->GetPos();

		//캐릭터가 움직였다면,
		// 연출 다시시작.
		if (false == ((_endPos - endPos).Length() <= EPSILON))
		{
			_sumTime = 0.01f;
			_startPos = startPos;
			_endPos = endPos;
		}

		_sumTime += Time->GetDeltaTime();

		float clampSumTime = clamp<float>(_sumTime / _duration, 0.0f, 1.0f);

		//_sumTime : ?? = _duration : 1
		Vector2 newCameraPos = Vector2::Lerp(_startPos, _endPos, clampSumTime);

		int realMinX = min(_minX + WIN_SIZE_X / 2, _maxX - WIN_SIZE_X / 2);
		int realMaxX = max(_minX + WIN_SIZE_X / 2, _maxX - WIN_SIZE_X / 2);
		int realMinY = min(_minY + WIN_SIZE_Y / 2, _maxY - WIN_SIZE_Y / 2);
		int realMaxY = max(_minY + WIN_SIZE_Y / 2, _maxY - WIN_SIZE_Y / 2);

		newCameraPos.x = clamp<float>(newCameraPos.x, realMinX, realMaxX);
		newCameraPos.y = clamp<float>(newCameraPos.y, realMinY, realMaxY);

		CurrentScene->SetCameraPos(newCameraPos);
	}

}


void CameraComponent::Release()
{
	Super::Release();
}

void CameraComponent::SetLTWH(int left, int top, int width, int height)
{
	_minX = left;
	_minY = top;
	_maxX = width;
	_maxY = height;
}
void CameraComponent::SetLTWH(Sprite* backgroundSprite)
{
	_minX = 0;
	_minY = 0;
	_maxX = backgroundSprite->GetSize().x;
	_maxY = backgroundSprite->GetSize().y;
}
void CameraComponent::SetLTWH(CenterRect backgroundBody)
{
	RECT rc = backgroundBody.ToRect();
	_minX = rc.left;
	_minY = rc.top;
	_maxX = rc.right;
	_maxY = rc.bottom;
}