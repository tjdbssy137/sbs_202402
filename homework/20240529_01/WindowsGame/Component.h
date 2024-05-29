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
	//���ӱ���
	//���� Init, Render, Update, Release
	//���ȿ��� Actor���� Init, Render, Update, Release �̱����� ���󰥼��ۿ�����.
	//Actor���� ���� Component���� �ڿ������� Init, Render, Update, Release �Լ����� �����ֱ⸦ ���󰩴ϴ�.
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

