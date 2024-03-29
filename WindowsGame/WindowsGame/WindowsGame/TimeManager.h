#pragma once
class TimeManager
{
	DECLARE_SINGLE(TimeManager); // singleton
public:
	void Init();
	void Update();

	uint32 GetFps() { return _fps; }
	float GetDeltaTime() { return _deltaTime; }
private:
	uint32 _fps = 0; 
	float _deltaTime = 0.0f; // 이전 프레임부터 지금까지 몇 초 흘렀냐.

	uint64 _frequency = 0;
	uint64 _prevCount = 0;

	float _frameTime = 0.0f;
	uint32 _frameCount = 0; // 1초에 몇번 화면 갱신이 되었는지 보기위한 변수
};

