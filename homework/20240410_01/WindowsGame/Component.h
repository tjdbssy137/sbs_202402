#pragma once
class Actor;

class Component
{
protected:
	Actor* _owner = nullptr;
private:
public:
	void SetOwner(Actor* owner) { _owner = owner; }
	Actor* GetOwner() { return _owner; }

public:
	// ���� ����
	// ���� Init, Render, Update, Release
	// �� �ȿ��� Actor���� Init, Render, Update, Release�� ������ ���� ���ۿ� ����
	// Actor���� ���� Component���� �ڿ������� Init, Render, Update, Release��� �Լ����� ���� �ֱ⸦ ���󰣴�.
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

