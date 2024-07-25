#pragma once

//���� ����(Variable argument)�� �� �״�� �������� ���� ���ڸ� ���Ѵ�.
//printf() �Լ�ó�� �������� ���� ������ ���ڸ� �޾ƾ� �� �� ����Ѵ�.
//���� ���ڴ� �Ʒ��� ���� ���ڸ� ... ǥ�÷� ��Ÿ����.

template<typename... Args>
class GameEvent
{
public:
	GameEvent() {}
	virtual ~GameEvent() {}
public:
	//-----------------------------------
	//	# �̺�Ʈ ���� (����)
	//-----------------------------------
	vector<function<void(Args...)>> _onEvents;

	//-----------------------------------
	//	# �̺�Ʈ ���� (�Լ�)
	//-----------------------------------
	template<typename T>
	void AddListen(T* owner, void(T::* func)(Args...))
	{
		_onEvents.push_back([=](Args... args)
			{
				(owner->*func)(args...);
			});
		//_onEvents.push_back(bind(func, owner, this));
	}

public:
	virtual void Init();
	virtual void Update();
	virtual void Release();

	// �����Ѵ�.
	void Invoke(Args... args);
};
template<typename... Args>
void GameEvent<Args...>::Init()
{

}

template<typename... Args>
void GameEvent<Args...>::Update()
{

}

template<typename... Args>
void GameEvent<Args...>::Release()
{

}

template<typename... Args>
void GameEvent<Args...>::Invoke(Args... args)
{
	for (function<void < Args...) > onEvent : _onEvents)
	{
		onEvent(std::forward<Args>(args)...);
	}
};

