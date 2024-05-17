#pragma once
class NumberBlockActor;

enum PressKey
{
	Down,
	Up,
	Left,
	Right,
	None
};

#define MAX_BLOCK_COUNT 16
class Game2048Controller
{
public:
	void Init(vector<NumberBlockActor*> numberBlocks);
	void Update();

public:
	void SumNumberBlocks();
	void InitIsFull();

	void MoveDown();
	void MoveUp();
	void MoveLeft();
	void MoveRight();

	void CreateNumberBlock();
	void CheckCreateNumberBlock();

	// 처음에 0으로 리셋하고, 랜덤한 위치의 두개만 2로
	void NumberBlockToZero();

	void SetPressKeyState(PressKey state);
	// 배열의 가로 세로를 전환시켜주는 게 필요

private:
	vector<NumberBlockActor*> _numberBlocks;
	int _blocksInfo[4][4] = {};

	bool _checkCreateNumberBlock = false;
	bool _isClick = true;

	PressKey _state = PressKey::None;
};

