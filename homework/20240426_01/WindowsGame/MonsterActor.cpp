#include "pch.h"
#include "MonsterActor.h"
#include "Flipbook.h"

void MonsterActor::Init()
{
	Super::Init();

	{
		Resource->LoadTexture(L"T_Monster", L"FlipbookTest/Monster2.bmp", RGB(192, 192, 192));
		FlipbookInfo _info = {};
		_info.start = 0;
		_info.end = 6;
		_info.line = 0;
		_info.size = Vector2Int(62, 45);
		_info.duration = 1.0f;
		_info.loop = true;
		_info.texture = Resource->GetTexture(L"T_Monster");

		Resource->CreateFlipbook(L"FB_Monster_Down_Idle", _info);

		_info.line = 1;
		Resource->CreateFlipbook(L"FB_Monster_Left_Idle", _info);

		_info.line = 2;
		Resource->CreateFlipbook(L"FB_Monster_Right_Idle", _info);

		_info.end = 5;
		_info.line = 3;
		Resource->CreateFlipbook(L"FB_Monster_Up_Idle", _info);

		_info.end = 3;
		_info.line = 4;
		_info.loop = false;
		Resource->CreateFlipbook(L"FB_Monster_GetHit", _info);

		_info.end = 1;
		_info.line = 5;
		Resource->CreateFlipbook(L"FB_Monster_Die", _info);
	}

	// 기본
	this->SetFlipbook(Resource->GetFlipbook(L"FB_Monster_Down_Idle"));
}
void MonsterActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void MonsterActor::Update()
{
	Super::Update();

	if (0.0f <= _invokeTime)
	{
		_invokeTime -= Time->GetDeltaTime();

		if (_isDie == false)
		{
			if (_invokeTime < 0.0f)
			{
				ChangeState(MonsterState::Idle);
			}
		}
		else
		{
			if (_invokeTime < 0.0f)
			{
				this->SetFlipbook(nullptr);
			}
		}
	}
}
void MonsterActor::Release()
{
	Super::Release();
}

void MonsterActor::ChangeState(MonsterState state)
{
	switch (state)
	{
		case MonsterState::Idle:
			this->DoIdle();
			break;
		case MonsterState::Die:
			this->DoDie();
			_isDie = true;
			_invokeTime = 1.1f;
			break;
		case MonsterState::GetHit:
			this->DoGetHit();
			_invokeTime = 1.1f;
			break;
		case MonsterState::None:
			break;

		default:
			break;
	}
}

void MonsterActor::DoIdle()
{
	switch (_dirState)
	{
	case MonsterDirectionState::Down:
		this->SetFlipbook(Resource->GetFlipbook(L"FB_Monster_Down_Idle"));
		break;

	case MonsterDirectionState::Up:
		this->SetFlipbook(Resource->GetFlipbook(L"FB_Monster_Up_Idle"));
		break;

	case MonsterDirectionState::Left:
		this->SetFlipbook(Resource->GetFlipbook(L"FB_Monster_Left_Idle"));
		break;

	case MonsterDirectionState::Right:
		this->SetFlipbook(Resource->GetFlipbook(L"FB_Monster_Right_Idle"));
		break;
	}
}

void MonsterActor::DoGetHit()
{
	this->SetFlipbook(Resource->GetFlipbook(L"FB_Monster_GetHit"));
}

void MonsterActor::DoDie()
{
	this->SetFlipbook(Resource->GetFlipbook(L"FB_Monster_Die"));
}

void MonsterActor::LookAtPlayer(Vector2 playerPos)
{
	// player을 바라보기
	if (playerPos.x <= this->GetPos().x) // 플레이어가 좌측에 있을 경우
	{
		if (abs(this->GetPos().y - playerPos.y) < abs(this->GetPos().x - playerPos.x)) // x축으로 더 멀리 있을 경우
		{
			_dirState = MonsterDirectionState::Left;
		}
		else  // x축으로 더 가까이 있을 경우
		{
			if (playerPos.y <= this->GetPos().y) // 플레이어보다 위에 있을 경우
			{
				_dirState = MonsterDirectionState::Up;
			}
			if (this->GetPos().y < playerPos.y) // 플레이어보다 아래에 있을 경우
			{
				_dirState = MonsterDirectionState::Down;
			}
		}
	}
	if (this->GetPos().x < playerPos.x) // 플레이어가 우측에 있을 경우
	{
		if (abs(this->GetPos().y - playerPos.y) < abs(this->GetPos().x - playerPos.x))
		{
			_dirState = MonsterDirectionState::Right;
		}
		else
		{
			if (playerPos.y <= this->GetPos().y)
			{
				_dirState = MonsterDirectionState::Up;
			}
			if (this->GetPos().y < playerPos.y)
			{
				_dirState = MonsterDirectionState::Down;
			}
		}
	}
}

