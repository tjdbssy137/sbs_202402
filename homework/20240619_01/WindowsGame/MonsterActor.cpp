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

void MonsterActor::LookAtPlayer(Vector2 playerPos) // �̰� ���� ��ġ�ϴ� �������� ���� ���� ������
{
	// player�� �ٶ󺸱�
	if (playerPos.x <= this->GetPos().x) // �÷��̾ ������ ���� ���
	{
		if (abs(this->GetPos().y - playerPos.y) < abs(this->GetPos().x - playerPos.x)) // x������ �� �ָ� ���� ���
		{
			ChangeDirection(eMonsterDirection::MonsterLeft);
		}
		else  // x������ �� ������ ���� ���
		{
			if (playerPos.y <= this->GetPos().y) // �÷��̾�� ���� ���� ���
			{
				ChangeDirection(eMonsterDirection::MonsterUp);
			}
			if (this->GetPos().y < playerPos.y) // �÷��̾�� �Ʒ��� ���� ���
			{
				ChangeDirection(eMonsterDirection::MonsterDown);
			}
		}
	}
	if (this->GetPos().x < playerPos.x) // �÷��̾ ������ ���� ���
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

