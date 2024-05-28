#pragma once
#include "Component.h"
class Collider : public Component
{
protected:
	ColliderType _colliderType;
	
	//���� ���������� ���� ����
	CollisionLayerType _collisionLayer = CollisionLayerType::CLT_DEFAULT;
	//�� ������Ʈ�� �浹�� Layer�� �������� ����ϴ� ����
	uint32 _collisionFlag = ~0; // not 0, 0xFFFFFFFF; (��� ���̾�� �浹�ϰڴ�)

public:
	unordered_set<Collider*> _collisionMap;
public:
	using Super = Component;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	//���� �浹�Ǿ����� üũ.
	virtual bool CheckCollision(Collider* other);
	ColliderType GetColliderType() { return _colliderType; }

public: // Layer üũ
	uint32 GetCollisionFlag() { return _collisionFlag; }
	//void SetCollisionFlag(uint32 collisionFlag) { _collisionFlag = collisionFlag; } // �̷��� ������ ����
	void AddCollisionFlagLayer(CollisionLayerType layer);
	void RemoveCollisionFlagLayer(CollisionLayerType layer);
	void ResetCollisionFlag() { _collisionFlag = 0; }

	CollisionLayerType GetCollisionLayer() { return _collisionLayer; }
	void SetCollisionLayer(CollisionLayerType collisionLayer) { _collisionLayer = collisionLayer; }
public:
	Collider(ColliderType colliderType) { _colliderType = colliderType; }
	virtual ~Collider() {}
};

// ������ �Ҹ��� ����
// Collider ������ �Ҹ��� ȣ�� ����

// ������ ���� �θ� ����, �Ҹ��ڴ� �ڽ��� ����

// Collider�� Component�� ��ӹޱ� ����
// Component ������ �Լ�
// Collider ������ �Լ�
// Collider �Ҹ��� �Լ�
// Component �Ҹ��� �Լ�

