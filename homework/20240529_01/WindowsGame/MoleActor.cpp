#include "pch.h"
#include "MoleActor.h"


void MoleActor::Init()
{
	Super::Init();

	this->SetName("Mole");
	this->SetSprite(Resource->GetSprite(L"S_Mole_Idle"));


}
void MoleActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void MoleActor::Update()
{
	Super::Update();

	if (Input->GetKeyDown(KeyCode::Space))
	{
		//�ױ� ����
		ChangeState(MoleActorState::Die);
	}

	if (Input->GetKeyDown(KeyCode::Control))
	{
		//�ױ� ����
		ChangeState(MoleActorState::Out);
	}



	// Unity ������ Invoke
	if (0.0f <= _comeInTimer)
	{
		_comeInTimer -= Time->GetDeltaTime();

		if (_comeInTimer < 0.0f)
		{
			ChangeState(MoleActorState::In);
		}
	}
}
void MoleActor::Release()
{
	Super::Release();

}

void MoleActor::ComeOut()
{
	cout << "MoleActor::ComeOut()" << endl;
	this->SetSprite(Resource->GetSprite(L"S_Mole_Idle"));
	_comeInTimer = 1.5f;
}

//������ ����.
void MoleActor::ComeIn()
{
	cout << "MoleActor::ComeIn()" << endl;

	this->SetSprite(nullptr);
}
//�׾���.
void MoleActor::Die()
{
	cout << "MoleActor::Die()" << endl;

	this->SetSprite(Resource->GetSprite(L"S_Mole_Die"));
	_comeInTimer = 1.0f;
}

void MoleActor::ChangeState(MoleActorState state)
{
	//FSM ���ѻ��¸ӽ�

	if (_state == state) return;

	_state = state;

	switch (_state)
	{
	case MoleActorState::Out:
		this->ComeOut();
		break;
	case MoleActorState::In:
		this->ComeIn();
		break;
	case MoleActorState::Die:
		this->Die();
		break;
	case MoleActorState::None:
		break;
	default:
		break;
	}

}