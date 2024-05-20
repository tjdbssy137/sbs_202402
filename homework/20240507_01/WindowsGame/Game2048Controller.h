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
	
	// 중복합을 피하려고 더한 10000을 다시 빼주는 함수
	void SubtractTenThousand();

	void CreateNumberBlock();
	void CheckCreateNumberBlock();

	// 처음에 0으로 리셋하고, 랜덤한 위치의 두개만 2로
	void NumberBlockToZero();

	void SetPressKeyState(PressKey state);
	// 배열의 가로 세로를 <임시>전환시켜주는 게 필요

	int** ReverseArray(int inputArr[][4], int rows);


	// 연출 중인지, 게임 중인지를 체크
	// 연출 중이라면 키 버튼 안 눌림.
	// 연출시에 껍데기를 만들어서 이동.
	// 이동이 다 되었다면 껍데기 삭제
	// 게임 재개
private:
	vector<NumberBlockActor*> _numberBlocks;
	int _blocksInfo[4][4] = {};

	bool _checkCreateNumberBlock = false;
	bool _isClick = true;

	PressKey _state = PressKey::None;
};

