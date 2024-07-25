#pragma once

//가변 인자(Variable argument)란 말 그대로 고정되지 않은 인자를 말한다.
//printf() 함수처럼 정해지지 않은 개수의 인자를 받아야 할 때 사용한다.
//가변 인자는 아래와 같이 인자를 ... 표시로 나타낸다.

template<typename... Args>
class GameEvent
{
public:
	GameEvent() {}
	virtual ~GameEvent() {}
public:
	//-----------------------------------
	//	# 이벤트 설정 (변수)
	//-----------------------------------
	vector<function<void(Args...)>> _onEvents;

	//-----------------------------------
	//	# 이벤트 설정 (함수)
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

	// 실행한다.
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

