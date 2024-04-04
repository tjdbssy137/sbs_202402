#include "pch.h"
#include "InputManager.h"


void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_CODE_COUNT, KeyState::None);
}

void InputManager::Update()
{
	::GetCursorPos(&_mousePos);
	::ScreenToClient(_hWnd, &_mousePos);

	BYTE asciiKeys[KEY_CODE_COUNT] = {};
	if (::GetKeyboardState(asciiKeys) == false)
	{
		return;
	}

	for (uint32 key = 0; key < KEY_CODE_COUNT; key++)
	{
		//key�� �������ִ�.
		if (0 < (asciiKeys[key] & 0x80))
		{
			KeyState& state = _states[key];

			//�������־���.
			if (state == KeyState::Press || state == KeyState::Down)
			{
				state = KeyState::Press;
			}
			else  // ������ ������.
			{
				state = KeyState::Down;
			}
		}
		//key�� �ȴ������ִ�.
		else 
		{
			KeyState& state = _states[key];

			//�������־��� ���¸�
			if (state == KeyState::Press || state == KeyState::Down)
			{
				state = KeyState::Up;
			}
			else
			{
				state = KeyState::None;
			}
		}
	}
	

}

bool InputManager::GetKey(KeyCode key)
{
	return GetState(key) == KeyState::Press;
}
bool InputManager::GetKeyDown(KeyCode key)
{
	return GetState(key) == KeyState::Down;
}
bool InputManager::GetKeyUp(KeyCode key)
{
	return GetState(key) == KeyState::Up;
}

POINT InputManager::GetMousePos()
{
	return _mousePos;
}