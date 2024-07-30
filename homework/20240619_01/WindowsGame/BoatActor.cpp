#include "pch.h"
#include "BoatActor.h"
#include "CircleCollider.h"
#include "TowerDefenseScene.h"
#include "SpriteActor.h"
#include "Sprite.h"
#include "Texture.h"
#include "BulletActor.h"
#include "BulletActorController.h"
#include "GameWave.h"

void BoatActor::Init()
{	
	this->SetState(_state);
	this->SetName("Enemy");
	_collider = new CircleCollider();
	_collider->SetCollision(Vector2::Zero(), 10);
	_collider->Init(); 
	_collider->SetCollisionLayer(CollisionLayerType::CLT_ENEMY); // 다시 공부
	_collider->ResetCollisionFlag();
	_collider->AddCollisionFlagLayer(CollisionLayerType::CLT_BEHICLE);
	_collider->AddCollisionFlagLayer(CollisionLayerType::CLT_ITEM);
	this->AddComponent(_collider);

	// HP
	_hpBackground = Resource->GetSprite(L"S_HP_Background"); // HP 체력바 배경
	_bpBar = Resource->GetSprite(L"S_HP_Bar"); // HP 체력바

	{
		TowerDefenseScene* towerDefenseScene = static_cast<TowerDefenseScene*>(CurrentScene);
		_bulletActorController = towerDefenseScene->GetBulletActorController();
	}

	Super::Init();
}
void BoatActor::Render(HDC hdc)
{
	Super::Render(hdc); // Enemy Render

	// 여기부터 Sprite Render
	{//_hpBackground
		if (_hpBackground == nullptr) return;

		Vector2Int size = _hpBackground->GetSize();

		Vector2Int cameraPos = CurrentScene->GetCameraPos();
		Vector2Int ScreenSizeHalf = Vector2Int(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
		Vector2Int renderPos = Vector2Int(
			static_cast<int>(_body.pos.x - size.x / 2 - cameraPos.x + ScreenSizeHalf.x),
			static_cast<int>(_body.pos.y - 20 - size.y / 2 - cameraPos.y + ScreenSizeHalf.y)
		);
		::TransparentBlt(hdc,
			renderPos.x,
			renderPos.y,
			size.x,
			size.y,
			_hpBackground->GetDC(),
			_hpBackground->GetPos().x,
			_hpBackground->GetPos().y,
			size.x,
			size.y,
			_hpBackground->GetTransparent()//투명색
		);
	}

	{//_bpBar
		Vector2Int size = _bpBar->GetSize();

		Vector2Int cameraPos = CurrentScene->GetCameraPos();
		Vector2Int ScreenSizeHalf = Vector2Int(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
		Vector2Int renderPos = Vector2Int(
			static_cast<int>(_body.pos.x - size.x / 2 - cameraPos.x + ScreenSizeHalf.x),
			static_cast<int>(_body.pos.y - 20 - size.y / 2 - cameraPos.y + ScreenSizeHalf.y)
		);
		::TransparentBlt(hdc,
			renderPos.x,
			renderPos.y,
			size.x * (_hp / _staticHp),
			size.y,
			_bpBar->GetDC(),
			_bpBar->GetPos().x,
			_bpBar->GetPos().y,
			size.x,
			size.y,
			_bpBar->GetTransparent()//투명색
		);
	}

}
void BoatActor::Update()
{
	Super::Update();
	if (0 < _hp)
	{
		UpdateHpImage(_nextHp);
	}

	// XXX : <- 이슈 위험
	switch (_state)
	{
	case BoatState::Move:
		UpdateMove();
		break;
	case BoatState::Idle:
		UpdateIdle();
		break;
	default:
		break;
	}
}

void BoatActor::Release()
{
	Super::Release();
}

void BoatActor::SetActiveBoat()
{
	wstring direction[eDirection::END]
		= { L"Down", L"Left", L"Right", L"Up", L"DownNLeft", L"DownNRight", L"UpNLeft", L"UpNRight" };
	//cout << _data.Name << endl;
	wstring name = wstring().assign(_data.Name.begin(), _data.Name.end());
	for (int i = 0; i < eDirection::END; i++)
	{
		_moveFlipbook[i] = Resource->GetFlipbook(name + direction[i]);
	}
	_hp = _data.HP;
	_staticHp = _data.HP;
	_nextHp = _data.HP;
}
void BoatActor::ChangeDirection(eDirection dir)
{
	// 만약에 방향이 바뀌면, setFlipbook을 해준다/

	if (_dir == dir) return;

	_dir = dir;
	this->SetFlipbook(_moveFlipbook[_dir]);
}

void BoatActor::UpdateHpImage(float nextHp)
{
	// 피해량 비율을 계산하기
	if (nextHp <= _hp) // hp 와 tempHp가 완전히 같을 순 없음
	{
		_hp = _hp + (nextHp - _hp) * 0.2f;
		if (0 <= _hp - nextHp && _hp - nextHp < 1) // 오차의 범위가 이정도면 _hp = tempHp한다.
		{
			_hp = nextHp;
		}
	}
	if (_hp <= 0)
	{
		_state = BoatState::Die;
	}
}

void BoatActor::UpdateIdle()
{
	if (_pathIndex != _path.size())
	{
		Vector2Int cellPos = _path[_pathIndex++];

		TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
		assert(scene != nullptr);
		if (scene == nullptr)
		{
			return;
		}

		if (scene->CanGo(cellPos))
		{
			this->SetCellPos(cellPos);
			this->SetState(BoatState::Move);
		}
	}
}

void BoatActor::UpdateMove()
{
	// _destPos랑 비교해서 움직이게 끔
	// 현재 내 포지션이 _destPos와 다르면 내 dir 방향으로 계속 움직인다.

	if (HasRechedDest())
	{
		this->SetState(BoatState::Idle);
		this->SetPos(_destPos);// 10픽셀 이하로 하면 포지션에서 어긋나니까 다시 조정
	}
	else
	{
		Vector2 dirVec = (_destPos - this->GetPos()).Normalize();

		float angle = Vector2::SignedAngle(Vector2::Up(), dirVec);
		eDirection direction = eDirection::UP;

		if (-22.5f <= angle && angle < 22.5f)
		{
			direction = eDirection::UP;
		}
		else if (22.5 <= angle && angle < 67.5f)
		{
			direction = eDirection::UP_RIGHT;
		}
		else if (67.5f <= angle && angle < 112.5f)
		{
			direction = eDirection::RIGHT;
		}
		else if (112.5f <= angle && angle < 157.5f)
		{
			direction = eDirection::DOWN_RIGHT;
		}
		else if (157.5f <= angle || angle < -157.5f)
		{
			direction = eDirection::DOWN;
		}
		else if (-157.5f <= angle && angle < -112.5f)
		{
			direction = eDirection::DOWN_LEFT;
		}
		else if (-112.5f <= angle && angle < -67.5f)
		{
			direction = eDirection::LEFT;
		}
		else if (-67.5f <= angle && angle < -22.5f)
		{
			direction = eDirection::UP_LEFT;
		}
		this->ChangeDirection(direction);
		_body.pos += dirVec * _data.MoveSpeed * Time->GetDeltaTime();
	}
}

void BoatActor::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);

	if (other->GetOwner()->GetName() == "bullet")//bullet
	{
		BulletActor* behicleBullet = dynamic_cast<BulletActor*>(other->GetOwner());
		float getDamage = behicleBullet->GetBulletDamage();
		_nextHp = _hp - getDamage;
		behicleBullet->SetBulletState(BulletState::Done);
		_bulletActorController->PushBullet(behicleBullet);
	}
}

void BoatActor::SetCellPos(Vector2Int cellPos, bool teleport)
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
Vector2Int BoatActor::GetCellPos()
{
	return _cellPos;
}
bool BoatActor::HasRechedDest()
{
	return (_destPos - this->GetPos()).Length() < 2.0f;
}
bool BoatActor::CanMove()
{
	if (this->_state == BoatState::Move)
	{
		return false;
	}

	return true;
}
void BoatActor::SetPath(vector<Vector2Int> path)
{
	_path = path;
	_pathIndex = 0;
}