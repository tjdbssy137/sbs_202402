#pragma once
#include "Component.h"
class Collider : public Component
{
protected:
	ColliderType _colliderType;
	
	//나는 누구인지에 대한 변수
	CollisionLayerType _collisionLayer = CollisionLayerType::CLT_DEFAULT;
	//이 오브젝트가 충돌할 Layer은 무엇인지 기억하는 변수
	uint32 _collisionFlag = ~0; // not 0, 0xFFFFFFFF; (모든 레이어랑 충돌하겠다)

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
	//지금 충돌되었는지 체크.
	virtual bool CheckCollision(Collider* other);
	ColliderType GetColliderType() { return _colliderType; }

public: // Layer 체크
	uint32 GetCollisionFlag() { return _collisionFlag; }
	//void SetCollisionFlag(uint32 collisionFlag) { _collisionFlag = collisionFlag; } // 이렇게 쓸일이 없음
	void AddCollisionFlagLayer(CollisionLayerType layer);
	void RemoveCollisionFlagLayer(CollisionLayerType layer);
	void ResetCollisionFlag() { _collisionFlag = 0; }

	CollisionLayerType GetCollisionLayer() { return _collisionLayer; }
	void SetCollisionLayer(CollisionLayerType collisionLayer) { _collisionLayer = collisionLayer; }
public:
	Collider(ColliderType colliderType) { _colliderType = colliderType; }
	virtual ~Collider() {}
};

// 생성자 소멸자 순서
// Collider 생성자 소멸자 호출 순서

// 생성할 때는 부모가 먼저, 소멸자는 자식이 먼저

// Collider가 Component을 상속받기 때문
// Component 생성자 함수
// Collider 생성자 함수
// Collider 소멸자 함수
// Component 소멸자 함수

