#pragma once
#include "ResourceBase.h"
class Sound : public ResourceBase
{
public:
	Sound() {}
	virtual ~Sound();

public:
	//���� ���
	bool LoadWave(const wstring& path);
	void Play(bool loop = false);
	void Stop(bool reset = false);

private:
	LPDIRECTSOUNDBUFFER _soundBuffer = nullptr; // ����ī�� ���
	DSBUFFERDESC _bufferDesc = {};
};

