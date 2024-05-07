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
	// ���� ����
	// ���� Init, Render, Update, Release
	// �� �ȿ��� Actor���� Init, Render, Update, Release�� ������ ���� ���ۿ� ����
	// Actor���� ���� Component���� �ڿ������� Init, Render, Update, Release��� �Լ����� ���� �ֱ⸦ ���󰣴�.
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

