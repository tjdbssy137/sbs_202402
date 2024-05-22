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
	// flag �˻�
	
	uint8 otherLayer = other->GetCollisionLayer();
	//_collisionFlag(���� �浹 üũ �� �� �ִ� ���̾�) is otherLayer
	if (0 < (_collisionFlag & (1 << otherLayer))) 	// �� => other�� �˻��� �ڰ��� �ִ���
	{
		uint8 myLayer = this->GetCollisionLayer(); 
		if (0 < (other->GetCollisionFlag() & (1 << myLayer)))	// other => ���� �˻��� �ڰ��� �ִ���
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
	
	_collisionFlag &= ~(1 << layer);// ~ �̰� �� ���̸� ���� layer���� ���� ������
}