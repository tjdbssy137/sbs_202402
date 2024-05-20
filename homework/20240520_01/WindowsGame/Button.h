#pragma once
#include "UI.h"
#include "Sprite.h"
enum class ButtonState
{	//버튼을 구성하는 요소
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


	// 	void AddOnClickDelegate(function<void()> onClick){	_onClick = onClick; } -> 가독성 측면에서 안 좋음
	template<typename T>
	void AddOnClickDelegate(T* owner, void (T::* func)())
	{
		_onClick = bind(func, owner);
	}

	void ChangeSceneFunc();

protected:
	//버튼을 구성하는 요소
	Sprite* _sprites[(int)ButtonState::End] = {};
	Sprite* _currentSprite = nullptr;

	ButtonState _state = ButtonState::Default;

	// 마우스를 올려놨을 때 이벤트
	function<void()> _onHover = nullptr;
	// 버튼을 눌렀을 때 이벤트
	function<void()> _onClick = nullptr;

};

