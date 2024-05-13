#pragma once
#include "UI.h"
#include "Sprite.h"
enum class ButtonState
{	//��ư�� �����ϴ� ���
	Default,
	Hover,
	Pressed,
	Disabled,

	End
};
class Button : public UI
{
	DECLARE_CHILD(Button, UI)
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SetSprite(ButtonState state, Sprite* sprite) 
	{
		_sprites[(int)state] = sprite;
	}
	Sprite* GetSprite(ButtonState state) { return _sprites[(int)state]; }
	void SetState(ButtonState state);

protected:
	//��ư�� �����ϴ� ���
	Sprite* _sprites[(int)ButtonState::End] = {};
	Sprite* _currentSprite = nullptr;

	ButtonState _state = ButtonState::Default;

};

