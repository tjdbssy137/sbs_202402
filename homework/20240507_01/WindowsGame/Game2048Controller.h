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
	void ChangeIsFull();

private:
	vector<NumberBlockActor*> _numberBlocks;
	bool _isFull[MAX_BLOCK_COUNT] = {};
};

