#pragma once
class NumberBlockActor;
class Game2048Controller
{
public:
	void Init(vector<NumberBlockActor*> numberBlocks);
	void Update();

private:
	vector<NumberBlockActor*> _numberBlocks;
};

