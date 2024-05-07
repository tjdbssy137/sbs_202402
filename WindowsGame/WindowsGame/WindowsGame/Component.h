#pragma once
class Actor;

class Component
{
protected:
	Actor* _owner = nullptr;
	bool _isEnable = true;

private:
public:
	void SetOwner(Actor* owner) { _owner = owner; }
	Actor* GetOwner() { return _owner; }

	bool GetEnable() { return _isEnable; }
	void SetEnable(bool isEnable) { _isEnable = isEnable; }

public:
	// 게임 구조
	// 씬을 Init, Render, Update, Release
	// 씬 안에서 Actor들이 Init, Render, Update, Release이 구조를 따라갈 수밖에 없음
	// Actor들이 가진 Component들은 자연스럽게 Init, Render, Update, Release라는 함수들의 생명 주기를 따라간다.
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

