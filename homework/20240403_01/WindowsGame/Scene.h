#pragma once
class Scene
{
public:
	//---------------
	// �⺻ �Լ�
	//---------------
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

