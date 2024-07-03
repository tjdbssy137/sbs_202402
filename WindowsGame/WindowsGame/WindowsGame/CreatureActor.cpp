#include "pch.h"
#include "CreatureActor.h"
#include "BoxCollider.h"
#include "Dev2Scene.h"
#include "GameEvent.h"
#include "GameEvent_CreatureChangeDir.h"
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

	// XXX : <- �̽� ����
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
	// 0���� Ű�� ������ ������ ���� ��ü �ӵ��� ������. �ִ� 1����

	// Input�� ���� �̵��ӵ�����(velocity)�� �����Ѵ�
	// state�� ���� �Ǵ��� ���ش�
	// velocity�� 0�̸�, Idle
	// �׷��� ������ Move ���·� �ٲ��ش�.
}

void CreatureActor::Release()
{
	Super::Release();
}

void CreatureActor::SetState(CreatureState state)
{
	//FSM ���ѻ��¸ӽ�
	//if (_state == state) return; << �̰� ������ �������� �ʴ� �̻� Creature�� �� ���� --

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
	// ���࿡ ������ �ٲ��, setFlipbook�� ���ش�/

	if (_dir == dir) return;

	GameEvent_CreatureChangeDir* gameEvent = 
		dynamic_cast<GameEvent_CreatureChangeDir*>(GET_SINGLE(GameEventManager)->GetEvent("PlayerChangeDir"));
	if (gameEvent != nullptr)
	{
		gameEvent->FromDir = _dir;
		gameEvent->ToDir = dir;
		gameEvent->Invoke();
	}
	
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
	// _destPos�� ���ؼ� �����̰� ��
	// ���� �� �������� _destPos�� �ٸ��� �� dir �������� ��� �����δ�.

	if (HasRechedDest())
	{
		this->SetState(CreatureState::Idle);
		this->SetPos(_destPos);// 10�ȼ� ���Ϸ� �ϸ� �����ǿ��� ��߳��ϱ� �ٽ� ����
	}
	else
	{
		Vector2 dirVec = _destPos - this->GetPos();
		dirVec = dirVec.Normalize();
		_body.pos += dirVec * 450 * Time->GetDeltaTime();

		// �����¿쿡 ���� ĳ���� ������ ������.
		float upDotValue = dirVec.Dot(Vector2::Up());
		float rightDotValue = dirVec.Dot(Vector2::Right());
		float downDotValue = dirVec.Dot(Vector2::Down());
		float leftDotValue = dirVec.Dot(Vector2::Left());
		float cos45 = cos(Deg2Rad(45));
		if (cos45 < upDotValue)
		{
			this->ChangeDirection(eCreatureDirection::UP);
		}
		if (cos45 < rightDotValue)
		{
			this->ChangeDirection(eCreatureDirection::RIGHT);
		}
		if (cos45 < downDotValue)
		{
			this->ChangeDirection(eCreatureDirection::DOWN);
		}
		if (cos45 < leftDotValue)
		{
			this->ChangeDirection(eCreatureDirection::LEFT);
		}
	}
}

void CreatureActor::UpdateIdle()
{
	if(_pathIndex != _path.size())
	{
		Vector2Int cellPos = _path[_pathIndex++];

		TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
		assert(scene != nullptr);
		if (scene == nullptr)
		{
			return;
		}

		if (scene->CanGo(this, cellPos))
		{
			this->SetCellPos(cellPos);
			this->SetState(CreatureState::Move);
		}
	}

	//Idle ���� ���� ����.
	else if (this->_isAttackInput == true)
	{
		this->SetState(CreatureState::Attack);
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
	//_destPos�� ��Ȯ�ϰ� ¤���� ��
	// ���� �ʿ� �ִ� Tilemap�� �ҷ��ͼ� �ش� ���� �ִ� 
	// _destPos = Tile ��ǥ�� �����´�.

	TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);

	if (scene == nullptr)
	{
		return;
	}
	// �̷л� ���� Ÿ�ϸ��� �ֱ⿡ ���� ������ �� �־�� ��.
	// Ư�� Ŭ������ Actor���� ���� �ְų� ��򰡿� �ִ� ���𰡸� ���;��ϴ� ��Ȳ�� �ǰ� ���� �߻�
	// �׶� �� �������� ������ �Ұ���.
	Vector2 destPos = scene->GetTilemapPos(cellPos);
	_destPos = destPos;

	// �ڿ������� �̵��ؼ� �� ���������� ��������, �����̵� ���Ѽ� 1�����Ӹ�(���)�� �̵���ų ���̳�.
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
	//_destPos�� �� ��ġ�� ���� < 10px���� �۴�.
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

void CreatureActor::SetPath(vector<Vector2Int> path)
{
	_path = path;
	_pathIndex = 0;

	// _path[0] �������� �ڷ���Ʈ
	if (0 < _path.size())
	{
		//this->SetCellPos(_path[0], true);
	}
}