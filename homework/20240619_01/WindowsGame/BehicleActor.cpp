#include "pch.h"
#include "BehicleActor.h"
#include "Dev2Scene.h"

void BehicleActor::Init()
{
	Super::Init();

	wstring direction[eBehicleDirection::END]
		= { L"Down", L"Left", L"Right", L"Up", L"DownNLeft", L"DownNRight", L"UpNLeft", L"UpNRight" };
	for (int i = 0; i < eBehicleDirection::END; i++)
	{
		_idleFlipbook[i] = Resource->GetFlipbook(GetBehicleType() + direction[i]);
	}

	this->SetState(_state);
}
void BehicleActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void BehicleActor::Update()
{
	Super::Update();

	// XXX : <- �̽� ����
	switch (_state)
	{
	case BehicleState::Attack:
		UpdateAttack();
		break;
	case BehicleState::Idle:
		UpdateIdle();
		break;
	default:
		break;
	}
}

void BehicleActor::Release()
{
	Super::Release();
}

void BehicleActor::SetState(BehicleState state)
{
	//FSM ���ѻ��¸ӽ�

	_state = state;

	this->SetFlipbook(_idleFlipbook[_dir]);
}

void BehicleActor::ChangeDirection(eBehicleDirection dir)
{
	// ���࿡ ������ �ٲ��, setFlipbook�� ���ش�/

	if (_dir == dir) return;

	_dir = dir;
	this->SetFlipbook(_idleFlipbook[_dir]);
}

void BehicleActor::UpdateIdle()
{
	
}

void BehicleActor::UpdateAttack()
{
	Vector2 dirVec = _targetPos - this->GetPos();
	dirVec = dirVec.Normalize();
	

}

void BehicleActor::LookAtTarget() // target�� �ٶ󺸱�
{
	// target�� ���� ����� �Ÿ��� �ִ� �� �ٶ󺸴� �ɷ�.
	// ������ �� �޾ƿͼ� ������� �Ÿ��� ���?
	// �ݶ��̴� ���?
	Vector2 dirVec = _targetPos - this->GetPos();
	dirVec = dirVec.Normalize();
	
	Vector2 direction[8] =
	{
		Vector2::Up(),				// UP
		Vector2::Right(),			// RIGHT
		Vector2::Down(),			// DOWN
		Vector2::Left(),			// LEFT
		Vector2::UpNLeft(),			// UP_RIGHT
		Vector2::UpNRight(),		// DOWN_RIGHT
		Vector2::DownNLeft(),		// DOWN_LEFT
		Vector2::DownNRight()		// UP_LEFT
	};

	int targetDir = 0;

	for (int dir = 0; dir < eBehicleDirection::END; dir++)
	{
		if (dirVec == direction[dir])
		{
			targetDir = dir;
		}
	}

	switch (targetDir) {
	case 0:
		this->ChangeDirection(eBehicleDirection::UP);
		break;
	case 1:
		this->ChangeDirection(eBehicleDirection::RIGHT);
		break;
	case 2:
		this->ChangeDirection(eBehicleDirection::DOWN);
		break;
	case 3:
		this->ChangeDirection(eBehicleDirection::LEFT);
		break;
	case 4:
		this->ChangeDirection(eBehicleDirection::UP_LEFT);
		break;
	case 5:
		this->ChangeDirection(eBehicleDirection::UP_RIGHT);
		break;
	case 6:
		this->ChangeDirection(eBehicleDirection::DOWN_LEFT);
		break;
	case 7:
		this->ChangeDirection(eBehicleDirection::DOWN_RIGHT);
		break;
	}
}