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
	void CheckCreateNumberBlock();

	// ó���� 0���� �����ϰ�, ������ ��ġ�� �ΰ��� 2��
	void NumberBlockToZero();

	// �迭�� ���� ���θ� ��ȯ�����ִ� �� �ʿ�

private:
	vector<NumberBlockActor*> _numberBlocks;
	int _isFull[MAX_BLOCK_COUNT] = {};
	bool _checkCreateNumberBlock = false;
	bool _isClick = true;
};

