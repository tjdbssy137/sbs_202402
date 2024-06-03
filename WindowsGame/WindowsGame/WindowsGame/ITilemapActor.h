#pragma once

// 인터페이스는 함수만 작성.
// 순수 가상 함수로만 구성
class ITilemapActor
{
public:
	// = 0; 은 이 클래스를 상속받고 override를 해야만 쓸수 있다라는 의미.
	virtual void SetCellPos(Vector2Int cellPos, bool teleport = false) = 0;
	virtual Vector2Int GetCellPos() = 0;
};

