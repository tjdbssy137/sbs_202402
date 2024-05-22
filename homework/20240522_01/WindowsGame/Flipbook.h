#pragma once
#include "ResourceBase.h"

struct FlipbookInfo//변수를 하나하나 getter setter 하기 힘들기 때문ㅇ
{
	Texture* texture;
	Vector2Int size;
	int start = 0;
	int end = 0;
	int line = 0;

	float duration = 1.0f; //이 flipbook 전체 실행하는 데 걸리는 시간
	bool loop = true; // 1회만 하고 멈출건지, 계속 반복할 건지 
};
class Flipbook : public ResourceBase
{
private:
	FlipbookInfo _info = {};
public:
	Flipbook();
	virtual ~Flipbook();//virtual소멸자 없으면 dynamic_cast안됨
public:
	void SetInfo(FlipbookInfo& info){ _info = info; }
	const FlipbookInfo& GetInfo() { return _info; }
};

