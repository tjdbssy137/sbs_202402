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
	// �������� �浹üũ ó��
	// ��� Collider�� �ѹ��� ��. (CheckCollision�Լ� ���)
	//�浹�Ǿ�����
	//		�浹 Map �ȿ� ������
	//			�浹 Map�� �־��ش�
	//			�浹�Ǿ��ٰ� Actor���� �˸�.
	// �浹�� �� �Ǿ� ������ 
	//		�浹 Map�� �ִ� �� Ȯ���Ѵ�
	//			�浹 Map�� ������
	//				�浹 Map���� �����ش�.
	//				�浹 �����ٰ� Actor�� �˸�.

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
				// �浹 �Ǿ�����
				if (collider1->CheckCollision(collider2))
				{
					// �浹 Map �ȿ� ������
					if (false == collider1->_collisionMap.contains(collider2))
					{
						// �浹 Map�� �־��ش�
						collider1->_collisionMap.insert(collider2);
						collider2->_collisionMap.insert(collider1);
						// �浹�Ǿ��ٰ� Actor�� �˸�
						collider1->GetOwner()->OnTriggerEnter(collider1, collider2);
						collider2->GetOwner()->OnTriggerEnter(collider2, collider1);
					}
				}
				// �浹 �ȵǾ�������
				else
				{
					// �浹 Map �ȿ� ������
					if (true == collider1->_collisionMap.contains(collider2))
					{
						// // �浹 Map���� �����ش�
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
	// ������ �״�� ������ ���� ������ �߻��ϴ��� ������ �� �ż�, �Լ��� ���.
	// ������ �ܺο��� ������ ���� �ʴ� �� ����
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