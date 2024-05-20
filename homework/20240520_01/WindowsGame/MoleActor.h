#pragma once
#include "SpriteActor.h"

enum class MoleActorState
{
	Out, // �������� ����
	In, // ������ ��
	Die, // �ظӷ� ���� ����

	None
};

class MoleActor :  public SpriteActor
{
public:
	using Super = SpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

	MoleActorState GetGameState() { return _state; }

public:
	// �������� ������
	void ComeOut();
	// ������ ����
	void ComeIn();
	// �״�
	void Die();

	void ChangeState(MoleActorState state);

private:
	float _comeInTimer = 0.0f;
	MoleActorState _state = MoleActorState::None;
};

