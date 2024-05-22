#pragma once
class SoundManager
{
	DECLARE_SINGLE(SoundManager);
public:
	void Init();
	/*
	void Draw(HDC hdc);
	void Update();
	*/
	void Release();

	void Play(const wstring& key, bool loop = false);
	LPDIRECTSOUND GetSoundDevice()
	{
		return _soundDevice;
	}

private:
	LPDIRECTSOUND _soundDevice = nullptr;
};

