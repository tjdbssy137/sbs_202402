#include "pch.h"
#include "Actor.h"
#include "Component.h"
#include "Collider.h"
#include "Scene.h"

void Actor::OnTriggerEnter(Collider* collider, Collider* other)
{
	cout << "�浹 ���� : " << collider->GetOwner()->GetName() << " -> " << other->GetOwner()->GetName() << endl;
	//printf("�浹 ���� : {%s} -> {%s}\n", collider->GetOwner()->GetName().c_str(), other->GetOwner()->GetName().c_str());
}
void Actor::OnTriggerExit(Collider* collider, Collider* other)
{
	cout << "�浹 �� : " << collider->GetOwner()->GetName() << " -> " << other->GetOwner()->GetName() << endl;
	//printf("�浹 �� : {%s} -> {%s}\n", collider->GetOwner()->GetName().c_str(), other->GetOwner()->GetName().c_str());
}


void Actor::Init()
{

}
void Actor::Render(HDC hdc)
{
	for (Component* component : _components)
	{
		component->Render(hdc);
	}
}
void Actor::Update()
{
	for (Component* component : _components)
	{
		component->Update();
	}


	if (_isEnable == false)
	{
		Scene* currentScene = GET_SINGLE(SceneManager)->GetCurrentScene();
		currentScene->DespawnActor(this);
	}
}
void Actor::Release()
{
	for (Component* component : _components)
	{
		component->Release();
		SAFE_DELETE(component);
	}
	_components.clear();
}
void Actor::AddComponent(Component* component)
{
	if (component == nullptr)	return;

	component->SetOwner(this);
	component->Init();
	_components.push_back(component);
}
void Actor::RemoveComponent(Component* component)
{
	//Iterator�� �Ⱦ��� �ʹ� ������� �׳� ���ϴ�.
	auto findIt = find(_components.begin(), _components.end(), component);

	if (findIt != _components.end())
	{
		Component* deleteComponent = *findIt;
		deleteComponent->Release();
		SAFE_DELETE(deleteComponent);
		_components.erase(findIt);
	}
}