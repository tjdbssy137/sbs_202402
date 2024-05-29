#pragma once
#include "Component.h"
class Collider : public Component
{
protected:
	ColliderType _colliderType;

	//나는 누구인지?
	CollisionLayerType _collisionLayer = CLT_DEFAULT;
	//이 오브젝트가 충돌할 layer는 무엇인지?
	uint32 _collisionFlag = ~0; // 0xFFFFFFFF; (모든 레이어랑 충돌할거다.)
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
	//충돌되었는지 체크.
	virtual bool CheckCollision(Collider* other);
	ColliderType GetColliderType() { return _colliderType; }

public:
	uint32 GetCollisionFlag() { return _collisionFlag; }
	// 이거를 이렇게 쓸일이.. 
	void SetCollisionFlag(uint32 collisionFlag) { _collisionFlag = collisionFlag; }
	void AddCollisionFlagLayer(CollisionLayerType layer);
	void RemoveCollisionFlagLayer(CollisionLayerType layer);
	void ResetCollisionFlag() { _collisionFlag = 0; }

	CollisionLayerType GetCollisionLayer() { return _collisionLayer; }
	void SetCollisionLayer(CollisionLayerType collisionLayer) { _collisionLayer = collisionLayer; }

public:
	Collider(ColliderType colliderType) { _colliderType = colliderType; }
	virtual ~Collider() {}
};


//생성자 소멸자 순서
//Collider 생성자 소멸자 호출순서

// Component 생성자 함수
// Collider 생성자 함수
// Collider 소멸자 함수
// Component 소멸자 함수