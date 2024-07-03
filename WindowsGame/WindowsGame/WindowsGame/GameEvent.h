#pragma once
class GameEvent
{
public:
	GameEvent() {}
	virtual ~GameEvent() {}
public:
	//----------------------------
	// 이벤트 설정 (변수)
	//----------------------------
	vector<function<void()>> _onEvents;

	//----------------------------
	// 이벤트 설정 (함수)
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

	// 실행한다
	void Invoke();
};

