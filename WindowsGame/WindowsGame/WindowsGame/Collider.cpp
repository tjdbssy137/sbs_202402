#include "pch.h"
#include "Collider.h"

void Collider::Init()
{
	Super::Init();
	GET_SINGLE(CollisionManager)->AddCollider(this);
}
void Collider::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Collider::Update()
{
	Super::Update();
}
void Collider::Release()
{
	Super::Release();
	GET_SINGLE(CollisionManager)->RemoveCollider(this);
}

bool Collider::CheckCollision(Collider* other)
{
	// flag 검사
	
	uint8 otherLayer = other->GetCollisionLayer();
	//_collisionFlag(나를 충돌 체크 할 수 있는 레이어) is otherLayer
	if (0 < (_collisionFlag & (1 << otherLayer))) 	// 나 => other을 검사할 자격이 있는지
	{
		uint8 myLayer = this->GetCollisionLayer(); 
		if (0 < (other->GetCollisionFlag() & (1 << myLayer)))	// other => 나를 검사할 자격이 있는지
		{
			return true;
		}
	}
	return false;
}

void Collider::AddCollisionFlagLayer(CollisionLayerType layer)
{
	//CLT_DEFAULT (0x01) 0001
	//CLT_CREATURE (0x02) 0010
	//CLT_ITEM (0x04) 0100

	//_flag => 0010
	// layer => CLT_ITEM (0100)
	//_flag => 0110
	
	_collisionFlag |= (1 << layer);
}

void Collider::RemoveCollisionFlagLayer(CollisionLayerType layer)
{
	//CLT_DEFAULT (0x01) 0001
	//CLT_CREATURE (0x02) 0010
	//CLT_ITEM (0x04) 0100

	//_flag => 0011
	// layer => CLT_ITEM (0010)
	//_flag => 0001
	
	_collisionFlag &= ~(1 << layer);// ~ 이거 안 붙이면 현재 layer빼고 전부 지워짐
}