#pragma once
class Scene
{
public:
	//---------------
	// 기본 함수
	//---------------
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

