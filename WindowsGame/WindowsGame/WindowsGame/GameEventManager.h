#pragma once
class GameEvent;
class GameEventManager
{
	DECLARE_SINGLE(GameEventManager);

public:
	void Init();
	void Update();
	void Release();

	GameEvent* GetEvent(string key);
	void AddEvent(string key, GameEvent* gameEvent);
	void RemoveEvent(string key);
	void ClearEvent();

	void Invoke(string key);
private:
	map<string, GameEvent*> _gameEvents;
};

