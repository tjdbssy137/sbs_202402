#pragma once
#include "ResourceBase.h"
struct FlipbookInfo
{
	Texture* texture;
	Vector2Int size;
	int start = 0;
	int end = 0;
	int line = 0;


	float duration = 1.0f;	// �� flipbook ��ü �����ϴµ� �ɸ��� �ð�.
	bool loop = false;		// 1ȸ���ϰ� �������, ��� �ִϸ��̼� �ݺ��Ұ���
};

class Flipbook : public ResourceBase
{
protected:
	FlipbookInfo _info = {};

public:
	Flipbook();
	virtual ~Flipbook();

public:
	void SetInfo(const FlipbookInfo& info) { _info = info; }
	const FlipbookInfo& GetInfo() { return _info; }
};

