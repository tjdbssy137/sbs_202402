#pragma once
#include "ResourceBase.h"
struct FlipbookInfo
{
	Texture* texture;
	Vector2Int size;
	int start = 0;
	int end = 0;
	int line = 0;


	float duration = 1.0f;	// 이 flipbook 전체 실행하는데 걸리는 시간.
	bool loop = false;		// 1회만하고 멈출건지, 계속 애니메이션 반복할건지
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

