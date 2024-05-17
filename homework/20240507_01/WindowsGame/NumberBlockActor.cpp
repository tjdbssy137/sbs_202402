#include "pch.h"
#include "NumberBlockActor.h"

void NumberBlockActor::Init()
{
	Super::Init();
	this->SetName("NumberBlock");
	this->SetSprite(nullptr);

	_speed = 200;
}
void NumberBlockActor::Render(HDC hdc)
{
	Super::Render(hdc);

}
void NumberBlockActor::Update()
{
	Super::Update();
	//this->SlideActor();
}
void NumberBlockActor::Release()
{
	Super::Init();
}

void NumberBlockActor::SlideActor()
{
	this->SetPos(GetPos() + _direction * _speed * Time->GetDeltaTime());
	
	//�ٸ� block�� ������ ����


	//���� ������ ����
	if (this->GetPos().x <= -201)
	{
		this->SetPos(Vector2(-200, this->GetPos().y));
		this->ChangeDirectionState(NumberBlockDirState::None);
	}
	else if (101 <= this->GetPos().x)
	{
		this->SetPos(Vector2(100, this->GetPos().y));
		this->ChangeDirectionState(NumberBlockDirState::None);
	}

	if (this->GetPos().y <= -201)
	{
		this->SetPos(Vector2(this->GetPos().x, -200));
		this->ChangeDirectionState(NumberBlockDirState::None);
	}
	else if (101 <= this->GetPos().y)
	{
		this->SetPos(Vector2(this->GetPos().x, 100));
		this->ChangeDirectionState(NumberBlockDirState::None);
	}
}

void NumberBlockActor::ChangeImage(int sum)
{
	switch (sum)
	{
	case 2:
		this->SetSprite(Resource->GetSprite(L"S_Number_2"));
		break;
	case 4:
		this->SetSprite(Resource->GetSprite(L"S_Number_4"));
		break;
	case 8:
		this->SetSprite(Resource->GetSprite(L"S_Number_8"));
		break;
	case 16:
		this->SetSprite(Resource->GetSprite(L"S_Number_16"));
		break;
	case 32:
		this->SetSprite(Resource->GetSprite(L"S_Number_32"));
		break;
	case 64:
		this->SetSprite(Resource->GetSprite(L"S_Number_64"));
		break;
	case 128:
		this->SetSprite(Resource->GetSprite(L"S_Number_128"));
		break;
	case 256:
		this->SetSprite(Resource->GetSprite(L"S_Number_256"));
		break;
	case 512:
		this->SetSprite(Resource->GetSprite(L"S_Number_512"));
		break;
	case 1024:
		this->SetSprite(Resource->GetSprite(L"S_Number_1024"));
		break;
	case 2048:
		this->SetSprite(Resource->GetSprite(L"S_Number_2048"));
		break;
	default:
		this->SetSprite(nullptr);
		break;
	}
}

void NumberBlockActor::ChangeDirectionState(NumberBlockDirState directionState)
{
	switch (directionState)
	{
	case NumberBlockDirState::Down:
		_direction = Vector2::Down();
		break;

	case NumberBlockDirState::Up:
		_direction = Vector2::Up();
		break;

	case NumberBlockDirState::Left:
		_direction = Vector2::Left();
		break;

	case NumberBlockDirState::Right:
		_direction = Vector2::Right();
		break;
	case NumberBlockDirState::None:
		_direction = Vector2::Zero();
		break;
	}
}

