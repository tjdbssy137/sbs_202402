#include "pch.h"
#include "CollisionManager.h"
#include "Collider.h"
#include "Actor.h"

void CollisionManager::Init()
{

}
void CollisionManager::Update()
{
	// �������� �浹üũ ó��

	// ��� Collider�� �ѹ��� ���Ѵ�. (CheckCollision�Լ����)
	// �浹�Ǿ�����, 
	//		�浹 Map�ȿ� ������
	//			�浹 Map�� �־��ش�.
	//			�浹�Ǿ��ٰ� Actor�� �˸�.
	// �浹�� �ȵǾ�������
	//		�浹 Map�ȿ� ������
	//			�浹 Map���� �����ش�.
	//			�浹�����ٰ� Actor�� �˸�


	//_colliders
	for (int i = 0; i < _colliders.size(); i++)
	{
		Collider* c1 = _colliders[i];
		for (int j = i + 1; j < _colliders.size(); j++)
		{
			Collider* c2 = _colliders[j];
			//�浹�� �Ǿ�����
			if (c1->CheckCollision(c2))
			{
				//�浹 Map�ȿ� ������
				if (false == c1->_collisionMap.contains(c2))
				{
					//�浹 Map�� �־��ش�.
					c1->_collisionMap.insert(c2);
					c2->_collisionMap.insert(c1);
					//�浹�Ǿ��ٰ� Actor�� �˸�.
					c1->GetOwner()->OnTriggerEnter(c1, c2);
					c2->GetOwner()->OnTriggerEnter(c2, c1);
				}
			}
			//�浹�� �ȵǾ�������
			else
			{
				//�浹 Map�ȿ� ������
				if (true == c1->_collisionMap.contains(c2))
				{
					//�浹 Map���� �����ش�.
					c1->_collisionMap.erase(c2);
					c2->_collisionMap.erase(c1);
					//�浹�����ٰ� Actor�� �˸�
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