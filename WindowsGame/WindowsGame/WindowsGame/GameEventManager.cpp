#include "pch.h"
#include "GameEventManager.h"
#include "GameEvent.h"
void GameEventManager::Init()
{

}
void GameEventManager::Update()
{
	for (auto gameEvent : _gameEvents)
	{
		gameEvent.second->Update();
	}
}
void GameEventManager::Release()
{
	this->ClearEvent();
}

GameEvent* GameEventManager::GetEvent(string key)
{
	if (_gameEvents.contains(key) == false)
	{
		return nullptr;
	}
	return _gameEvents[key];
}
void GameEventManager::AddEvent(string key, GameEvent* gameEvent)
{
	assert(gameEvent != nullptr);
	if (_gameEvents.contains(key) == true)
	{
		return;
	}
	_gameEvents[key] = gameEvent;
}
void GameEventManager::RemoveEvent(string key)
{
	if (_gameEvents.contains(key) == false)
	{
		return;
	}
	_gameEvents[key]->Release();
	delete _gameEvents[key];
	_gameEvents.erase(key);
}

void GameEventManager::ClearEvent()
{
	for (auto gameEvent : _gameEvents)
	{
		gameEvent.second->Release();
	}
	_gameEvents.clear();
}
void GameEventManager::Invoke(string key)
{
	GameEvent* gameEvent = this->GetEvent(key);
	if (gameEvent != nullptr)
	{
		gameEvent->Invoke();
	}
}