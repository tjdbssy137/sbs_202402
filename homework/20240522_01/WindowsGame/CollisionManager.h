#pragma once
class Collider;
class CollisionManager
{
	DECLARE_SINGLE(CollisionManager);

public:
	void Init();
	void Update();
	void AddCollider(Collider* collider);
	void RemoveCollider(Collider* collider);

	void ClearCollider();
private:
	vector<Collider*> _colliders;
};

