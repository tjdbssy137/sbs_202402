#pragma once
class GameEvent
{
public:
	GameEvent() {}
	virtual ~GameEvent() {}
public:
	//----------------------------
	// �̺�Ʈ ���� (����)
	//----------------------------
	vector<function<void()>> _onEvents;

	//----------------------------
	// �̺�Ʈ ���� (�Լ�)
	//----------------------------
	template<typename T>
	void AddListen(T* owner, void(T::* func)(GameEvent* gameEvent))
	{
		_onEvents.push_back(bind(func, owner, this));
	}

public:
	virtual void Init();
	virtual void Update();
	virtual void Release();

	// �����Ѵ�
	void Invoke();
};

