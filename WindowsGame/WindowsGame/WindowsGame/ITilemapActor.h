#pragma once

// �������̽��� �Լ��� �ۼ�.
// ���� ���� �Լ��θ� ����
class ITilemapActor
{
public:
	// = 0; �� �� Ŭ������ ��ӹް� override�� �ؾ߸� ���� �ִٶ�� �ǹ�.
	virtual void SetCellPos(Vector2Int cellPos, bool teleport = false) = 0;
	virtual Vector2Int GetCellPos() = 0;
};

