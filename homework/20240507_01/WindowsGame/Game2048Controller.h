#pragma once
class NumberBlockActor;

#define MAX_BLOCK_COUNT 16
class Game2048Controller
{
public:
	void Init(vector<NumberBlockActor*> numberBlocks);
	void Update();

public:
	void SumNumberBlocks();
	void ResetIsFull();
	void InitIsFull();

	void MoveDown();
	void MoveUp();
	void MoveLeft();
	void MoveRight();

	void CreateNumberBlock();
	void CanCreateNumberBlock();

	// 처음에 0으로 리셋하고, 랜덤한 위치의 두개만 2로
	void NumberBlockToZero();

private:
	vector<NumberBlockActor*> _numberBlocks;
	int _isFull[MAX_BLOCK_COUNT] = {};
	bool _canCreateNumberBlock = false;
};

