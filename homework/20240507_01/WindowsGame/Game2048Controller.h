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

	// ó���� 0���� �����ϰ�, ������ ��ġ�� �ΰ��� 2��
	void NumberBlockToZero();

	void SetPressKeyState(PressKey state);
	// �迭�� ���� ���θ� ��ȯ�����ִ� �� �ʿ�

private:
	vector<NumberBlockActor*> _numberBlocks;
	int _blocksInfo[4][4] = {};

	bool _checkCreateNumberBlock = false;
	bool _isClick = true;

	PressKey _state = PressKey::None;
};

