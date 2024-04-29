#pragma once
#include "SpriteActor.h"

enum class MoleActorState
{
	Out, // ¶¥±¼¿¡¼­ ³ª¿È
	In, // ¶¥±¼·Î µé¾î°¨
	Die, // ÇØ¸Ó·Î ¸ÂÀº »óÅÂ

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
	// ¶¥±¼¿¡¼­ ³ª¿À´Ù
	void ComeOut();
	// ¶¥±¼·Î µé¾î°¡´Ù
	void ComeIn();
	// Á×´Ù
	void Die();

	void ChangeState(MoleActorState state);

private:
	float _comeInTimer = 0.0f;
	MoleActorState _state = MoleActorState::None;
};

