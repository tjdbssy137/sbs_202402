#pragma once
class Actor;
class Component
{
protected:
	Actor* _owner = nullptr;

public:
	void SetOwner(Actor* owner) { _owner = owner; }
	Actor* GetOwner() { return _owner; }

public:
	//게임구조
	//씬을 Init, Render, Update, Release
	//씬안에서 Actor들이 Init, Render, Update, Release 이구조를 따라갈수밖에없음.
	//Actor들이 가진 Component들은 자연스럽게 Init, Render, Update, Release 함수들의 생명주기를 따라갑니다.
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

