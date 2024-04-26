#include "pch.h"
#include "CreatureActor.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
void CreatureActor::Init()
{
	Super::Init();

	// PlayerDown
	Resource->LoadTexture(L"T_Character", L"FlipbookTest/PlayerDown.bmp", RGB(128, 128, 128));
	FlipbookInfo _downInfo = {};
	_downInfo.start = 0;
	_downInfo.end = 9;
	_downInfo.line = 0;
	_downInfo.size = Vector2Int(200, 200);
	_downInfo.duration = 1.0f;
	_downInfo.loop = true;
	_downInfo.texture = Resource->GetTexture(L"T_Character");

	Resource->CreateFlipbook(L"FB_CharacterDown_Idle", _downInfo);

	_downInfo.line = 1;
	Resource->CreateFlipbook(L"FB_CharacterDown_Move", _downInfo);

	_downInfo.line = 3;
	_downInfo.end = 7;
	Resource->CreateFlipbook(L"FB_CharacterDown_Attack", _downInfo);

	// PlayerUp
	Resource->LoadTexture(L"T_Character2", L"FlipbookTest/PlayerUp.bmp", RGB(128, 128, 128));
	FlipbookInfo _upInfo = {};
	_upInfo.start = 0;
	_upInfo.end = 9;
	_upInfo.line = 0;
	_upInfo.size = Vector2Int(200, 200);
	_upInfo.duration = 1.0f;
	_upInfo.loop = true;
	_upInfo.texture = Resource->GetTexture(L"T_Character2");

	Resource->CreateFlipbook(L"FB_CharacterUp_Idle", _upInfo);

	_upInfo.line = 1;
	Resource->CreateFlipbook(L"FB_CharacterUp_Move", _upInfo);

	_upInfo.line = 3;
	_upInfo.end = 7;
	Resource->CreateFlipbook(L"FB_CharacterUp_Attack", _upInfo);

	// PlayerLeft
	Resource->LoadTexture(L"T_Character3", L"FlipbookTest/PlayerLeft.bmp", RGB(128, 128, 128));
	FlipbookInfo _leftInfo = {};
	_leftInfo.start = 0;
	_leftInfo.end = 9;
	_leftInfo.line = 0;
	_leftInfo.size = Vector2Int(200, 200);
	_leftInfo.duration = 1.0f;
	_leftInfo.loop = true;
	_leftInfo.texture = Resource->GetTexture(L"T_Character3");

	Resource->CreateFlipbook(L"FB_CharacterLeft_Idle", _leftInfo);

	_leftInfo.line = 1;
	Resource->CreateFlipbook(L"FB_CharacterLeft_Move", _leftInfo);

	_leftInfo.line = 3;
	_leftInfo.end = 7;
	Resource->CreateFlipbook(L"FB_CharacterLeft_Attack", _leftInfo);

	// PlayerRight
	Resource->LoadTexture(L"T_Character4", L"FlipbookTest/PlayerRight.bmp", RGB(128, 128, 128));
	FlipbookInfo _rightInfo = {};
	_rightInfo.start = 0;
	_rightInfo.end = 9;
	_rightInfo.line = 0;
	_rightInfo.size = Vector2Int(200, 200);
	_rightInfo.duration = 1.0f;
	_rightInfo.loop = true;
	_rightInfo.texture = Resource->GetTexture(L"T_Character4");

	Resource->CreateFlipbook(L"FB_CharacterRight_Idle", _rightInfo);

	_rightInfo.line = 1;
	Resource->CreateFlipbook(L"FB_CharacterRight_Move", _rightInfo);

	_rightInfo.line = 3;
	_rightInfo.end = 7;
	Resource->CreateFlipbook(L"FB_CharacterRight_Attack", _rightInfo);

	// 기본
	this->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterDown_Idle"));
}
void CreatureActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void CreatureActor::Update()
{
	Super::Update();

	if (Input->GetKeyDown(KeyCode::A))
	{
		printf("%f, %f\n", this->_body.pos.x, this->_body.pos.y);
	}
	/*
	if ( 내 movement Vecotr가 0이고 공격중이 아니라면)
	{
		changeState(idle);
	}

	
	switch(state)
	{
		case idle:
			doidle();
	}


	//doidle
	switch(dir)
	{
		case down: 
			setFlipbook
	}

	*/
	
	
}
void CreatureActor::Release()
{
	Super::Release();
}
void CreatureActor::ChangeState(CreatureState state)
{
	//FSM 유한상태머신
	if (_state == state) return;

	_state = state;

	switch (_state)
	{
	case CreatureState::Idle:
		this->DoIdle();
		break;
	case CreatureState::Attack:
		this->DoAttack();
		break;
	case CreatureState::Move:
		this->DoMove();
		break;
	case CreatureState::None:
		break;
	default:
		break;
	}
}
void CreatureActor::DoIdle()
{
	switch (_dirState)
	{
	case CreatureDirectionState::Down:
		this->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterDown_Idle"));
		break;

	case CreatureDirectionState::Up:
		this->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterUp_Idle"));
		break;
	
	case CreatureDirectionState::Left:
		this->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterLeft_Idle"));
		break;
	
	case CreatureDirectionState::Right:
		this->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterRight_Idle"));
		break;
	}
}

void CreatureActor::DoAttack()
{
	switch (_dirState)
	{
	case CreatureDirectionState::Down:
		this->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterDown_Attack"));
		break;

	case CreatureDirectionState::Up:
		this->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterUp_Attack"));
		break;

	case CreatureDirectionState::Left:
		this->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterLeft_Attack"));
		break;

	case CreatureDirectionState::Right:
		this->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterRight_Attack"));
		break;
	}
}

void CreatureActor::DoMove()
{
	switch (_dirState)
	{
	case CreatureDirectionState::Down:
		this->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterDown_Move"));
		break;

	case CreatureDirectionState::Up:
		this->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterUp_Move"));
		break;

	case CreatureDirectionState::Left:
		this->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterLeft_Move"));
		break;

	case CreatureDirectionState::Right:
		this->SetFlipbook(Resource->GetFlipbook(L"FB_CharacterRight_Move"));
		break;
	}
}