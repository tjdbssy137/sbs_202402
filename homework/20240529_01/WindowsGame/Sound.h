#pragma once
#include "ResourceBase.h"
class Sound : public ResourceBase
{
public:
	Sound() {}
	virtual ~Sound();

public:
	//사운드 기능
	bool LoadWave(const wstring& path);
	void Play(bool loop = false);
	void Stop(bool reset = false);

private:
	LPDIRECTSOUNDBUFFER _soundBuffer = nullptr; // 사운드카드 재료
	DSBUFFERDESC _bufferDesc = {};
};

