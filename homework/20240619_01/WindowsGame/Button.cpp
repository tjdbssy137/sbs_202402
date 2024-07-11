#include "pch.h"
#include "Button.h"
#include "Panel.h"
#include "Sprite.h"

void Button::Init()
{
	Super::Init();
	_state = ButtonState::Default;
	_currentSprite = _sprites[(int)_state];

}
void Button::Render(HDC hdc)
{
	if (_isShow == false) return;

	Super::Render(hdc);

	if (_currentSprite == nullptr) return;

	Vector2Int size = _currentSprite->GetSize();


	Panel* parent = this->GetParent();
	Vector2 parentPos = Vector2::Zero();
	while (parent != nullptr)
	{
		parentPos += parent->GetPos();
		parent = parent->GetParent();
	}

	Vector2Int renderPos = Vector2Int(
		static_cast<int>(parentPos.x + _pos.x - size.x / 2),
		static_cast<int>(parentPos.y + _pos.y - size.y / 2)
	);
	::TransparentBlt(hdc,
		renderPos.x,
		renderPos.y,
		size.x,
		size.y,
		_currentSprite->GetDC(),
		_currentSprite->GetPos().x,
		_currentSprite->GetPos().y,
		size.x,
		size.y,
		_currentSprite->GetTransparent()//투명색
	);
}
void Button::Update()
{
	Super::Update();
	if (_state == ButtonState::Disabled) return;
	POINT mousePos = Input->GetMousePos();
	if (this->IsInMouse())
	{
		if (Input->GetKey(KeyCode::LeftMouse))
		{
			this->SetState(ButtonState::Pressed);
		}
		else
		{
			if (_state == ButtonState::Pressed)
			{
				//딱 지금 클릭 했을 때 동작
				//웹페이지 이동 등등
				cout << "CLICK!!" << endl;
				// 새로운 문법 : 함수 포인터

				if (_onClick != nullptr)
				{
					_onClick();
					//Dev1Scene으로 넘어가도록 수정
					cout << "OnClick" << endl;
				}
			}
			this->SetState(ButtonState::Hover);
		}
	}
	else
	{
		this->SetState(ButtonState::Default);
	}
}

void Button::Release()
{
	Super::Release();
}

void Button::SetState(ButtonState state)
{
	_state = state;
	_currentSprite = _sprites[(int)_state];
}

void Button::ButtonMove()
{
	if (_state == ButtonState::Disabled) return;
	POINT mousePos = Input->GetMousePos();
	if (this->IsInMouse())
	{
		if (Input->GetKey(KeyCode::LeftMouse))
		{
			this->SetState(ButtonState::Pressed);
		}
		else
		{
			if (_state == ButtonState::Pressed)
			{
				//딱 지금 클릭 했을 때 동작
				//웹페이지 이동 등등
				cout << "CLICK!!" << endl;
				// 새로운 문법 : 함수 포인터

				if (_onClick != nullptr)
				{
					_onClick();
					//Dev1Scene으로 넘어가도록 수정
					cout << "OnClick" << endl;
				}
			}
			this->SetState(ButtonState::Hover);
		}
	}
	else
	{
		this->SetState(ButtonState::Default);
	}
}