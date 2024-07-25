#pragma once
#include "GameEvent.h"

class GameEventManager
{
	DECLARE_SINGLE(GameEventManager);
public:
	void Init();
	void Update();
	void Release();

public:
	template<typename... Args>
	GameEvent<Args...>* GetEvent(string key);

	template<typename... Args>
	void AddEvent(string key, GameEvent<Args...>* gameEvent);

	void RemoveEvent(string key);
	void ClearEvent();

	template<typename... Args>
	void Invoke(string key, Args... args);

private:
	map<string, void*> _gameEvents;
};

template<typename... Args>
GameEvent<Args...>* GameEventManager::GetEvent(string key)
{
	// 이름에 맞는 함수를 반환
	auto it = _gameEvents.find(key);
	if (it != _gameEvents.end())
	{
		return static_cast<GameEvent<Args...>*>(it->second);
	}
}

template<typename... Args>
void GameEventManager::AddEvent(string key, GameEvent<Args...>* gameEvent)
{
	_gameEvents[key] = static_cast<void*>(gameEvent);
}


template<typename... Args>
void GameEventManager::Invoke(string key, Args... args)
{
	auto it = _gameEvents.find(key);
	if (it != _gameEvents.end())
	{
		auto gameEvent = static_cast<GameEvent<Args...>*>(it->second);
		if (gmaeEvent)
		{
			(*gameEvent)(args...);
		}
	}
}