#pragma once
#include "SpriteActor.h"

enum class MoleActorState
{
	Out,	//�������� ����
	In,		//������ ��
	Die,	//�ظӷ� ����
	None
};

class MoleActor : public SpriteActor
{
public:
	using Super = SpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

	void ChangeState(MoleActorState state);
	MoleActorState GetState() { return _state; }
private:
	//�������� ������
	void ComeOut();
	//������ ����.
	void ComeIn();
	//�׾���.
	void Die();

private:
	float _comeInTimer = 0.0f;
	MoleActorState _state = MoleActorState::Out;

};

