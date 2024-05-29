#include "pch.h"
#include "CollisionManager.h"
#include "Collider.h"
#include "Actor.h"

void CollisionManager::Init()
{

}
void CollisionManager::Update()
{
	// 실질적인 충돌체크 처리

	// 모든 Collider를 한번씩 비교한다. (CheckCollision함수사용)
	// 충돌되었으면, 
	//		충돌 Map안에 없으면
	//			충돌 Map에 넣어준다.
	//			충돌되었다고 Actor에 알림.
	// 충돌이 안되어있으면
	//		충돌 Map안에 있으면
	//			충돌 Map에서 꺼내준다.
	//			충돌끝났다고 Actor에 알림


	//_colliders
	for (int i = 0; i < _colliders.size(); i++)
	{
		Collider* c1 = _colliders[i];
		for (int j = i + 1; j < _colliders.size(); j++)
		{
			Collider* c2 = _colliders[j];
			//충돌이 되었으면
			if (c1->CheckCollision(c2))
			{
				//충돌 Map안에 없으면
				if (false == c1->_collisionMap.contains(c2))
				{
					//충돌 Map에 넣어준다.
					c1->_collisionMap.insert(c2);
					c2->_collisionMap.insert(c1);
					//충돌되었다고 Actor에 알림.
					c1->GetOwner()->OnTriggerEnter(c1, c2);
					c2->GetOwner()->OnTriggerEnter(c2, c1);
				}
			}
			//충돌이 안되어있으면
			else
			{
				//충돌 Map안에 있으면
				if (true == c1->_collisionMap.contains(c2))
				{
					//충돌 Map에서 꺼내준다.
					c1->_collisionMap.erase(c2);
					c2->_collisionMap.erase(c1);
					//충돌끝났다고 Actor에 알림
					c1->GetOwner()->OnTriggerExit(c1, c2);
					c2->GetOwner()->OnTriggerExit(c2, c1);
				}
			}
		}
	}

}

void CollisionManager::AddCollider(Collider* collider)
{
	_colliders.push_back(collider);
}

void CollisionManager::RemoveCollider(Collider* collider)
{
	auto findIt = find(_colliders.begin(), _colliders.end(), collider);

	if (findIt != _colliders.end())
	{
		_colliders.erase(findIt);
	}
}

void CollisionManager::ClearCollider()
{
	_colliders.clear();
}