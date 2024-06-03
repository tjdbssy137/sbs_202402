#include "pch.h"
#include "CreatureActor.h"
#include "BoxCollider.h"
#include "Dev2Scene.h"

void CreatureActor::Init()
{
	Super::Init();
	// IDLE
	_idleFlipbook[eCreatureDirection::DOWN] = Resource->GetFlipbook(L"FB_CharacterDown_Idle");
	_idleFlipbook[eCreatureDirection::UP] = Resource->GetFlipbook(L"FB_CharacterUp_Idle");
	_idleFlipbook[eCreatureDirection::LEFT] = Resource->GetFlipbook(L"FB_CharacterLeft_Idle");
	_idleFlipbook[eCreatureDirection::RIGHT] = Resource->GetFlipbook(L"FB_CharacterRight_Idle");

	// MOVE
	_moveFlipbook[eCreatureDirection::DOWN] = Resource->GetFlipbook(L"FB_CharacterDown_Move");
	_moveFlipbook[eCreatureDirection::UP] = Resource->GetFlipbook(L"FB_CharacterUp_Move");
	_moveFlipbook[eCreatureDirection::LEFT] = Resource->GetFlipbook(L"FB_CharacterLeft_Move");
	_moveFlipbook[eCreatureDirection::RIGHT] = Resource->GetFlipbook(L"FB_CharacterRight_Move");

	// ATTACK
	_attackFlipbook[eCreatureDirection::DOWN] = Resource->GetFlipbook(L"FB_CharacterDown_Attack");
	_attackFlipbook[eCreatureDirection::UP] = Resource->GetFlipbook(L"FB_CharacterUp_Attack");
	_attackFlipbook[eCreatureDirection::LEFT] = Resource->GetFlipbook(L"FB_CharacterLeft_Attack");
	_attackFlipbook[eCreatureDirection::RIGHT] = Resource->GetFlipbook(L"FB_CharacterRight_Attack");

	// ATTACK COLLISON POS
	_attackCollisionPos[eCreatureDirection::DOWN] = CenterRect(Vector2(0, 60), 20, 40);
	_attackCollisionPos[eCreatureDirection::UP] = CenterRect(Vector2(0, -60), 20, 40);
	_attackCollisionPos[eCreatureDirection::LEFT] = CenterRect(Vector2(-60, 0), 40, 20);
	_attackCollisionPos[eCreatureDirection::RIGHT] = CenterRect(Vector2(60, 0), 40, 20);

	//cout << "_state : " << static_cast<int>(this->GetState()) << endl;
	this->SetState(_state);
}
void CreatureActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void CreatureActor::Update()
{
	Super::Update();

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
	//if (_state == state) return; << 이거 있으면 움직이지 않는 이상 Creature가 안 보임 --

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
	switch (_state)
	{
	case CreatureState::Idle:
		this->SetFlipbook(_idleFlipbook[_dir]);
		break;
	case CreatureState::Move:
		this->SetFlipbook(_moveFlipbook[_dir]);
		break;
	case CreatureState::Attack:
		this->SetFlipbook(_attackFlipbook[_dir]);
		break;
	}
}

void CreatureActor::UpdateMove()
{
	// _destPos랑 비교해서 움직이게 끔
	// 현재 내 포지션이 _destPos와 다르면 내 dir 방향으로 계속 움직인다.

	if (HasRechedDest())
	{
		this->SetState(CreatureState::Idle);
		this->SetPos(_destPos);// 10픽셀 이하로 하면 포지션에서 어긋나니까 다시 조정
	}
	else
	{
		switch (_dir)
		{
		case eCreatureDirection::DOWN:
			_body.pos.y += 400 * Time->GetDeltaTime();
			break;
		case eCreatureDirection::UP:
			_body.pos.y -= 400 * Time->GetDeltaTime();
			break;
		case eCreatureDirection::LEFT:
			_body.pos.x -= 400 * Time->GetDeltaTime();
			break;
		case eCreatureDirection::RIGHT:
			_body.pos.x += 400 * Time->GetDeltaTime();
			break;
		default:
			break;
		}
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

void CreatureActor::SetCellPos(Vector2Int cellPos, bool teleport)
{
	_cellPos = cellPos;
	//_destPos를 정확하게 짚어줄 것
	// 현재 맵에 있는 Tilemap을 불러와서 해당 셀에 있는 
	// _destPos = Tile 좌표를 가져온다.

	TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);

	if (scene == nullptr)
	{
		return;
	}
	// 이론상 씬에 타일맵이 있기에 값을 가져올 수 있어야 함.
	// 특정 클래스나 Actor에서 씬에 있거나 어딘가에 있는 무언가를 들고와야하는 상황이 되게 자주 발생
	// 그때 못 가져오면 개발이 불가능.
	Vector2 destPos = scene->GetTilemapPos(cellPos);
	_destPos = destPos;

	// 자연스럽게 이동해서 저 포지션으로 갈것인지, 순간이동 시켜서 1프레임만(즉시)에 이동시킬 것이냐.
	if (teleport)
	{
		this->SetPos(_destPos);
	}
}
Vector2Int CreatureActor::GetCellPos()
{
	return _cellPos;
}
bool CreatureActor::HasRechedDest()
{
	//_destPos와 내 위치의 길이 < 10px보다 작다.
	return (_destPos - this->GetPos()).Length() < 10.0f;
}

bool CreatureActor::CanMove()
{
	if (this->_state == CreatureState::Attack)
	{
		return false;
	}

	if (this->_state == CreatureState::Move)
	{
		return false;
	}

	return true;
}