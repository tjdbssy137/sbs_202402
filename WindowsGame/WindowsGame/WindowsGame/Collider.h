#pragma once
#include "Component.h"
class Collider : public Component
{
protected:
	ColliderType _colliderType;

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

