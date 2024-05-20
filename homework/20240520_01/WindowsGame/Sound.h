#pragma once
#include "ResourceBase.h"
class Sound : public ResourceBase
{
public:
	Sound() {}
	virtual ~Sound();

public:
	bool LoadWave(const wstring& path);
	void Play(bool loop = false);
	void Stop(bool reset = false);

private:
	LPDIRECTSOUNDBUFFER _soundBuffer = nullptr; // 사운드 카드
	DSBUFFERDESC _bufferDesc = {};
};

 
