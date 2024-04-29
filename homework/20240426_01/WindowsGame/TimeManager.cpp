#include "pch.h"
#include "TimeManager.h"


void TimeManager::Init()
{
	//초정밀고속타이머 사용
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));
}

void TimeManager::Update()
{
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
	_prevCount = currentCount;

	_frameCount++;
	_frameTime += _deltaTime;


	if (1.0f <= _frameTime)
	{
		_fps = static_cast<uint32>(_frameCount / _frameTime);

		_frameTime = 0.0f;
		_frameCount = 0;
	}
}
