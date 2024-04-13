#pragma once
class Component;
class Collider;
class Actor
{// �������� ������Ʈ�� ��� ���� �� �־�� ��.
protected:
	CenterRect _body = {};
	string _name;
	vector<Component*> _components;

public:
	//Getter, Setter
	CenterRect GetBody() { return _body; }
	void SetBody(CenterRect body) { _body = body; }

	string GetName() { return _name; }
	void SetName(string name) { _name = name; }
public:
	//Unity
	virtual void OnTriggerEnter(Collider* collider, Collider* other); // �浹 ����
	virtual void OnTriggerExit(Collider* collider, Collider* other); // �浹 ��

	//Unreal Engine
	// void OnComponentBeginOverlap(Collider* collder, Collider* other); �浹 ����
	// void OnComponentEndOverlap(Collider* collder, Collider* other); �浹 ��

public:
	void AddComponent(Component* component);
	void RemoveComponent(Component* component);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

