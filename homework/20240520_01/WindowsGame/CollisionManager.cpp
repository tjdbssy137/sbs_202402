#include "pch.h"
#include "CollisionManager.h"
#include "Collider.h"
#include "Actor.h"
#include "Scene.h"

void CollisionManager::Init()
{

}
void CollisionManager::Update()
{
	// 실질적인 충돌체크 처리
	// 모든 Collider을 한번씩 비교. (CheckCollision함수 사용)
	//충돌되었으면
	//		충돌 Map 안에 없으면
	//			충돌 Map에 넣어준다
	//			충돌되었다고 Actor에게 알림.
	// 충돌이 안 되어 있으면 
	//		충돌 Map에 있는 지 확인한다
	//			충돌 Map에 있으면
	//				충돌 Map에서 꺼내준다.
	//				충돌 끝났다고 Actor에 알림.

	for (int i = 0; i < _colliders.size(); i++)
	{
		Collider* collider1 = _colliders[i];
		for (int j = i + 1; j < _colliders.size(); j++)
		{
			Collider* collider2 = _colliders[j];

			///
			if (collider1->GetEnable() == false || collider2->GetEnable() == false)
			{
				return;
			}
			///
			else
			{
				// 충돌 되었으면
				if (collider1->CheckCollision(collider2))
				{
					// 충돌 Map 안에 없으면
					if (false == collider1->_collisionMap.contains(collider2))
					{
						// 충돌 Map에 넣어준다
						collider1->_collisionMap.insert(collider2);
						collider2->_collisionMap.insert(collider1);
						// 충돌되었다고 Actor에 알림
						collider1->GetOwner()->OnTriggerEnter(collider1, collider2);
						collider2->GetOwner()->OnTriggerEnter(collider2, collider1);
					}
				}
				// 충돌 안되어있으면
				else
				{
					// 충돌 Map 안에 있으면
					if (true == collider1->_collisionMap.contains(collider2))
					{
						// // 충돌 Map에서 지워준다
						collider1->_collisionMap.erase(collider2);
						collider2->_collisionMap.erase(collider1);
						collider1->GetOwner()->OnTriggerExit(collider1, collider2);
						collider2->GetOwner()->OnTriggerExit(collider2, collider1);
					}
				}
			}

		}
	}
}
void CollisionManager::AddCollider(Collider* collider)
{
	// 변수를 그대로 가져다 쓰면 문제가 발생하더라도 추적이 안 돼서, 함수로 사용.
	// 변수는 외부에서 가져다 쓰지 않는 게 좋음
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