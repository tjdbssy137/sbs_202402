#pragma once
class Component;
class Collider;
class Actor
{// �������� ������Ʈ�� ��� ���� �� �־�� ��.
protected:
	CenterRect _body = {};
	string _name;
	vector<Component*> _components;

	bool _isEnable = true;
	LayerType _layer = LayerType::Object;
public:
	//Getter, Setter
	CenterRect GetBody() { return _body; }
	void SetBody(CenterRect body) { _body = body; }

	void SetPos(Vector2 pos) { _body.pos = pos; }
	Vector2 GetPos() { return _body.pos; }

	void SetWidth(float width) {_body.width = width;}
	float GetWidth() { return _body.width; }

	void SetHeight(float height) { _body.height = height; }
	float GetHeight() { return _body.height; }

	string GetName() { return _name; }
	void SetName(string name) { _name = name; }

	bool GetEnable() { return _isEnable; }
	void SetEnable(bool isEnable) { _isEnable = isEnable; }

	LayerType GetLayer() { return _layer; }
	void SetLayer(LayerType layer) { _layer = layer; }
	int GetLayerInt() { return static_cast<int>(_layer); }

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
	template<typename T>
	T* GetComponent()
	{
		for (Component* component : _components)
		{
			if (typeid(*component) == typeid(T))
			{
				//dynamic_cast -> Ư�� �̺�Ʈ���� �� �� ����ϴ� ������ ������.
				// �������Ӹ��� ȣ���� �ֹٰ�, ���콺 Ŭ�� �� ������ ���� 
				T* result = dynamic_cast<T*>(component);
				if (result != nullptr)
				{
					return result;
				}
			}
		}
		return nullptr;
	}

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	Actor() {}
	virtual ~Actor() {}
};

