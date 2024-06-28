#pragma once
#include "SpriteActor.h"
#include "ITilemapActor.h"

class RedBlockActor : public SpriteActor, public ITilemapActor
{
public:
	DECLARE_CHILD(RedBlockActor, SpriteActor);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public: // 상속받은 인터페이스의 함수를 만들지 않으면 오류가 남.
	virtual void SetCellPos(Vector2Int cellPos, bool teleport = false) override;
	virtual Vector2Int GetCellPos() override;

private:
	Vector2 _destPos = {};
	Vector2Int _cellPos = {};
};

