#include "pch.h"
#include "CreatureActor.h"
#include "BoxCollider.h"

void CreatureActor::Init()
{
	Super::Init();
	// IDLE
	_idleFlipbook[eCreatureDirection::PK_DOWN] = Resource->GetFlipbook(L"FB_CharacterDown_Idle");
	_idleFlipbook[eCreatureDirection::PK_UP] = Resource->GetFlipbook(L"FB_CharacterUp_Idle");
	_idleFlipbook[eCreatureDirection::PK_LEFT] = Resource->GetFlipbook(L"FB_CharacterLeft_Idle");
	_idleFlipbook[eCreatureDirection::PK_RIGHT] = Resource->GetFlipbook(L"FB_CharacterRight_Idle");

	// MOVE
	_moveFlipbook[eCreatureDirection::PK_DOWN] = Resource->GetFlipbook(L"FB_CharacterDown_Move");
	_moveFlipbook[eCreatureDirection::PK_UP] = Resource->GetFlipbook(L"FB_CharacterUp_Move");
	_moveFlipbook[eCreatureDirection::PK_LEFT] = Resource->GetFlipbook(L"FB_CharacterLeft_Move");
	_moveFlipbook[eCreatureDirection::PK_RIGHT] = Resource->GetFlipbook(L"FB_CharacterRight_Move");

	// ATTACK
	_attackFlipbook[eCreatureDirection::PK_DOWN] = Resource->GetFlipbook(L"FB_CharacterDown_Attack");
	_attackFlipbook[eCreatureDirection::PK_UP] = Resource->GetFlipbook(L"FB_CharacterUp_Attack");
	_attackFlipbook[eCreatureDirection::PK_LEFT] = Resource->GetFlipbook(L"FB_CharacterLeft_Attack");
	_attackFlipbook[eCreatureDirection::PK_RIGHT] = Resource->GetFlipbook(L"FB_CharacterRight_Attack");

	// ATTACK COLLISON POS
	_attackCollisionPos[eCreatureDirection::PK_DOWN] = CenterRect(Vector2(0, 60), 20, 40);
	_attackCollisionPos[eCreatureDirection::PK_UP] = CenterRect(Vector2(0, -60), 20, 40);
	_attackCollisionPos[eCreatureDirection::PK_LEFT] = CenterRect(Vector2(-60, 0), 40, 20);
	_attackCollisionPos[eCreatureDirection::PK_RIGHT] = CenterRect(Vector2(60, 0), 40, 20);

	collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 0, 0));
}
void CreatureActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void CreatureActor::Update()
{
	Super::Update();

	if (0.0f < _invokeTime)
	{
		_invokeTime -= Time->GetDeltaTime();
		if (_invokeTime <= 0.0f)
		{
			collider->SetEnable(false);
			collider->SetCollision(Shape::MakeCenterRect(0, 0, 0, 0));
			//enable을 만든다, component에서 Enable을 만들고, CollisionManager을 들어가서 충돌 처리 조건을 수정
			//BoxCollider들어가서 콜라이더 위치 조정 잊지 않고 하기
			this->SetState(CreatureState::Idle);
		}
	}
	// TODO : // Comment 작성
	UpdateInput();

	// XXX : <- 이슈 위험
	switch (_state)
	{
	case CreatureState::Attack:
		UpdateAttack();
		break;
	case CreatureState::Move:
		UpdateMove();
		break;
	case CreatureState::Idle:
		UpdateIdle();
		break;
	default:
		break;
	}

	// _velocity
	// 0부터 키를 누르고 있으면 점점 전체 속도가 증가함. 최대 1까지

	// Input에 따라서 이동속도벡터(velocity)를 제어한다
	// state가 최종 판단을 해준다
	// velocity가 0이면, Idle
	// 그렇지 않으면 Move 상태로 바꿔준다.
}

void CreatureActor::Release()
{
	Super::Release();
}

void CreatureActor::SetState(CreatureState state)
{
	//FSM 유한상태머신
	if (_state == state) return;

	_state = state;

	switch (_state)
	{
	case CreatureState::Idle:
		this->SetFlipbook(_idleFlipbook[_dir]);
		break;
	case CreatureState::Attack:
		this->SetFlipbook(_attackFlipbook[_dir]);
		_invokeTime = 1.05f;
		break;
	case CreatureState::Move:
		this->SetFlipbook(_moveFlipbook[_dir]);

		break;
	default:
		break;
	}
}

void CreatureActor::ChangeDirection(eCreatureDirection dir)
{
	// 만약에 방향이 바뀌면, setFlipbook을 해준다/

	if (_dir == dir) return;

	_dir = dir;
}

void CreatureActor::UpdateInput()
{
	this->SetIsAttackInput(false);
	Vector2 newVelocity = this->GetVelocity();
	bool isMoveKeyInput = false;

	if (Input->GetKey(KeyCode::Left))
	{
		isMoveKeyInput = true;
		ChangeDirection(eCreatureDirection::PK_LEFT);
		newVelocity.x -= Time->GetDeltaTime() * 1.0f; // 1초만에 변함.
		newVelocity.x = clamp(newVelocity.x, -1.0f, 1.0f); // newVelocity.x의 범위를 -1.0f ~ 1.0f로 한정시킨다.
		newVelocity.y = 0;
		SetVelocity(newVelocity);
	}

	else if (Input->GetKey(KeyCode::Right))
	{
		isMoveKeyInput = true;
		ChangeDirection(eCreatureDirection::PK_RIGHT);
		newVelocity.x += Time->GetDeltaTime() * 1.0f; // 1초만에 변함.
		newVelocity.x = clamp(newVelocity.x, -1.0f, 1.0f);
		newVelocity.y = 0;
		SetVelocity(newVelocity);
	}

	else if (Input->GetKey(KeyCode::Up))
	{
		isMoveKeyInput = true;
		ChangeDirection(eCreatureDirection::PK_UP);
		newVelocity.y -= Time->GetDeltaTime() * 1.0f; // 0.5초만에 변함.
		newVelocity.y = clamp(newVelocity.y, -1.0f, 1.0f);
		newVelocity.x = 0;
		SetVelocity(newVelocity);
	}

	else if (Input->GetKey(KeyCode::Down))
	{
		isMoveKeyInput = true;
		ChangeDirection(eCreatureDirection::PK_DOWN);
		newVelocity.y += Time->GetDeltaTime() * 1.0f; // 0.5초만에 변함.
		newVelocity.y = clamp(newVelocity.y, -1.0f, 1.0f);
		newVelocity.x = 0;
		SetVelocity(newVelocity);
	}

	if (Input->GetKeyDown(KeyCode::Space))
	{
		this->SetIsAttackInput(true);
	}

	if (isMoveKeyInput == false)
	{
		newVelocity = { 0,0 };
	}
	this->SetVelocity(newVelocity);
}

void CreatureActor::UpdateMove()
{
	if (_velocity.Length() < EPSILON)
	{
		SetState(CreatureState::Idle);
	}

	if (EPSILON < _velocity.Length())
	{
		Vector2 newPos = this->GetPos();
		newPos += _velocity * 200 * Time->GetDeltaTime();
		this->SetPos(newPos);
	}
}

void CreatureActor::UpdateIdle()
{
	//Idle 때만 공격 가능.
	if (this->_isAttackInput == true)
	{
		this->SetState(CreatureState::Attack);
	}
	else if (EPSILON < _velocity.Length())
	{
		SetState(CreatureState::Move);
	}

}

void CreatureActor::UpdateAttack()
{
	if (collider == nullptr)
	{
		collider = new BoxCollider();
	}
	collider->SetEnable(true);
	collider->SetCollision(_attackCollisionPos[_dir]);
	this->AddComponent(collider);
}
