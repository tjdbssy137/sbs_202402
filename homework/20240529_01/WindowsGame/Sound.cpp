#include "pch.h"
#include "Sound.h"

Sound::~Sound()
{
#ifdef USE_SOUND
	if (_soundBuffer)
	{
		_soundBuffer->Release();
	}
#endif
}

bool Sound::LoadWave(const wstring& path)
{
#ifdef USE_SOUND
	HMMIO file = mmioOpen((wchar_t *)path.c_str(), NULL, MMIO_READ);
	if (file == NULL)
	{
		Alert(L"Error", L"���� ���� / �ν� ����.");
		return false;
	}

	MMCKINFO parent;
	//�޸� �� (memset)
	memset(&parent, 0, sizeof(parent));
	//ZeroMemory(&parent, sizeof(parent));

	parent.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	mmioDescend(file, &parent, NULL, MMIO_FINDRIFF);

	MMCKINFO child;
	memset(&child, 0, sizeof(child));
	child.ckid = mmioFOURCC('f', 'm', 't', ' ');
	mmioDescend(file, &child, &parent, MMIO_FINDCHUNK);

	WAVEFORMATEX wft;
	memset(&wft, 0, sizeof(wft));
	mmioRead(file, (char*)&wft, sizeof(wft));

	mmioAscend(file, &child, 0);
	child.ckid = mmioFOURCC('d', 'a', 't', 'a');
	mmioDescend(file, &child, &parent, MMIO_FINDCHUNK);

	memset(&_bufferDesc, 0, sizeof(DSBUFFERDESC));
	_bufferDesc.dwBufferBytes = child.cksize;
	_bufferDesc.dwSize = sizeof(DSBUFFERDESC);
	_bufferDesc.dwFlags = DSBCAPS_STATIC;
	_bufferDesc.lpwfxFormat = &wft;

	//���� ���� ��������
	LPDIRECTSOUND soundDevice = GET_SINGLE(SoundManager)->GetSoundDevice();
	if (FAILED(soundDevice->CreateSoundBuffer(&_bufferDesc, &_soundBuffer, NULL)))
	{
		Alert(L"Error", L"���� ���� ���� ����");
		return false;
	}

	//C++ ���� ���̴¹���
	//C++ �� ��
	//������ => �ּҰ��� ����ϴ� �ڷ��� (��ΰ� �Ȱ��� ���� ���� 4����Ʈ)
	//int*, float*, Ŭ����* 
	//���� �����;տ� �ڷ����� ���� ����  :
	//  - �����̶�..
	//  - ���߿� ����Ҷ�, �갡 � ������ �˾ƾ��ϴϱ�.
	//
	//void* �� �׳� �ּҰ��� ����ְڴٶ�� �ǹ̿���.
	//�׸��� ���߿� ����� �ʿ��ϸ�
	//�׶� ����ȯ���ְڴ�.
	//���� �ٷ�ôºе��� ���� ���.

	void* write1 = NULL;
	void* write2 = NULL;
	DWORD len1;
	DWORD len2;

	//���ۿ� ���� ������ �׻� 
	//���� �ɰ�
	// ���� (���)
	//���� Ǯ��

	//���� �Ǵٴ°Ŵ�
	//�� ������ ���ݺ��� ���� ���Ŵϱ� �ǵ�����.
	// �ǵ�Ÿ� ���� �پ������� ��ٷ�.


	//���� �ɰ�
	_soundBuffer->Lock(0, child.cksize, &write1, &len1, &write2, &len2, 0);

	// ����
	if (write1)
	{
		mmioRead(file, (char*)write1, len1);
	}
	if (write2)
	{
		mmioRead(file, (char*)write2, len2);
	}

	//���� Ǭ��.
	_soundBuffer->Unlock(write1, len1, write2, len2);

	mmioClose(file, 0);
	_soundBuffer->SetCurrentPosition(0);
#endif
	return true;
}
void Sound::Play(bool loop)
{
#ifdef USE_SOUND
	if (loop)
	{
		_soundBuffer->Play(0, 0, DSBPLAY_LOOPING);
	}
	else
	{
		_soundBuffer->Play(0, 0, 0);
	}
#endif
}
void Sound::Stop(bool reset)
{
#ifdef USE_SOUND
	_soundBuffer->Stop();

	if (reset)
	{
		_soundBuffer->SetCurrentPosition(0);
	}
#endif
}
