#include "pch.h"
#include "MonsterActor.h"
#include "Flipbook.h"
#include "CircleCollider.h"
#include "CreatureActor.h"
void MonsterActor::Init()
{
	Super::Init();
	_idleFlipbook[eMonsterDirection::MonsterDown] = Resource->GetFlipbook(L"FB_Monster_Down_Idle");
	_idleFlipbook[eMonsterDirection::MonsterUp] = Resource->GetFlipbook(L"FB_Monster_Up_Idle");
	_idleFlipbook[eMonsterDirection::MonsterLeft] = Resource->GetFlipbook(L"FB_Monster_Left_Idle");
	_idleFlipbook[eMonsterDirection::MonsterRight] = Resource->GetFlipbook(L"FB_Monster_Right_Idle");

	collider = new CircleCollider();
	collider->SetCollision(Vector2::Zero(), 14);
	this->AddComponent(collider);
}
void MonsterActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void MonsterActor::Update()
{
	Super::Update();
	
	switch (_state)
	{
	case MonsterState::GetHit:
		this->DoGetHit();
		break;
	case MonsterState::Die:
		this->DoDie();
		break;
	case MonsterState::Idle:
		this->DoIdle();
		break;
	default:
		break;
	}
}
void MonsterActor::Release()
{
	Super::Release();
}

void MonsterActor::SetState(MonsterState state)
{
	if (_state == state) return;
	_state = state;
	switch (state)
	{
		case MonsterState::Idle:
			this->SetFlipbook(_idleFlipbook[_dirState]);
			break;
		case MonsterState::Die:
			this->SetFlipbook(Resource->GetFlipbook(L"FB_Monster_Die"));
			break;
		case MonsterState::GetHit:
			this->SetFlipbook(Resource->GetFlipbook(L"FB_Monster_GetHit"));
			break;
		default:
			break;
	}
}

void MonsterActor::ChangeDirection(eMonsterDirection dirState)
{
	if (_dirState == dirState) return;

	_dirState = dirState;
}

void MonsterActor::DoIdle()
{
	this->SetFlipbook(_idleFlipbook[_dirState]);
}

void MonsterActor::DoGetHit()
{
	SetState(MonsterState::GetHit);
	//_invokeTime = 1.05f;
}

void MonsterActor::DoDie()
{
	_isDie = true;
	//_invokeTime = 1.05f;
}

void MonsterActor::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);
	CreatureActor* creature = dynamic_cast<CreatureActor*>(other->GetOwner());
	if (creature->GetIsAttackInput() == true)
	{
		if (other->GetOwner()->GetName() == "Creature")
		{
			SetState(MonsterState::Die);
		}
	}	
}

void MonsterActor::LookAtPlayer(Vector2 playerPos) // 이거 내가 설치하는 구조물에 들어가서 적을 봐야함
{
	// player을 바라보기
	if (playerPos.x <= this->GetPos().x) // 플레이어가 좌측에 있을 경우
	{
		if (abs(this->GetPos().y - playerPos.y) < abs(this->GetPos().x - playerPos.x)) // x축으로 더 멀리 있을 경우
		{
			ChangeDirection(eMonsterDirection::MonsterLeft);
		}
		else  // x축으로 더 가까이 있을 경우
		{
			if (playerPos.y <= this->GetPos().y) // 플레이어보다 위에 있을 경우
			{
				ChangeDirection(eMonsterDirection::MonsterUp);
			}
			if (this->GetPos().y < playerPos.y) // 플레이어보다 아래에 있을 경우
			{
				ChangeDirection(eMonsterDirection::MonsterDown);
			}
		}
	}
	if (this->GetPos().x < playerPos.x) // 플레이어가 우측에 있을 경우
	{
		if (abs(this->GetPos().y - playerPos.y) < abs(this->GetPos().x - playerPos.x))
		{
			ChangeDirection(eMonsterDirection::MonsterRight);
		}
		else
		{
			if (playerPos.y <= this->GetPos().y)
			{
				ChangeDirection(eMonsterDirection::MonsterUp);
			}
			if (this->GetPos().y < playerPos.y)
			{
				ChangeDirection(eMonsterDirection::MonsterDown);
			}
		}
	}
}

