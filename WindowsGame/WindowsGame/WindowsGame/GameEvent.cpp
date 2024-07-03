#include "pch.h"
#include "GameEvent.h"
void GameEvent::Init()
{

}
void GameEvent::Update()
{

}
void GameEvent::Release()
{

}
void GameEvent::Invoke()
{
	for (auto onEvent : _onEvents)
	{
		if (onEvent)
		{
			onEvent();
		}
	}
	
}
