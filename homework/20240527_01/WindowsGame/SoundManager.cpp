#include "pch.h"
#include "SoundManager.h"
#include "Sound.h"
void SoundManager::Init()
{
#ifdef USE_SOUND
	//���� ����̽� ���� (����ī�� �غ��ϱ�)
	HRESULT result1 = DirectSoundCreate(NULL, &_soundDevice, NULL);
	if (FAILED(result1))
	{
		Alert(L"Error", L"���� ����̽� ���� ����");
		return;
	}

	//���� ����̽� �������� ����
	HRESULT result2 = _soundDevice->SetCooperativeLevel(_hWnd, DSSCL_PRIORITY);
	if (FAILED(result2))
	{
		Alert(L"Error", L"���� ����̽� �������� ���� ����");
		return;
	}

#endif
}
void SoundManager::Release()
{
#ifdef USE_SOUND
	if (_soundDevice != nullptr)
	{
		_soundDevice->Release();
	}
#endif
}


void SoundManager::Play(const wstring& key, bool loop)
{
#ifdef USE_SOUND
	Sound* sound = Resource->GetSound(key);
	if (sound == nullptr)
	{
		return;
	}

	sound->Play(loop);
#endif
}