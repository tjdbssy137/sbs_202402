#pragma once
class NumberBlockActor;

enum PressKey
{
	PK_DOWN,
	PK_UP,
	PK_LEFT,
	PK_RIGHT,
	PK_END
};

enum Game2048State
{
	GS_RELEASE,
	GS_ANIMATION,
	GS_END
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
	
	// �ߺ����� ���Ϸ��� ���� 10000�� �ٽ� ���ִ� �Լ�
	void SubtractTenThousand();

	void CreateNumberBlock();
	void CheckCreateNumberBlock();

	// ó���� 0���� �����ϰ�, ������ ��ġ�� �ΰ��� 2��
	void NumberBlockToZero();

	void SetPressKeyState(PressKey state);
	// �迭�� ���� ���θ� <�ӽ�>��ȯ�����ִ� �� �ʿ�

	int** ReverseArray(int inputArr[][4], int rows);

	void SetGame2048State(Game2048State gameState);
	// ���� ������, ���� �������� üũ
	// ���� ���̶�� Ű ��ư �� ����.
	// ����ÿ� �����⸦ ���� �̵�.
	// �̵��� �� �Ǿ��ٸ� ������ ����
	// ���� �簳

	// �̵��ϴ� �� �Ӹ� �ƴ϶� ���� �̵��ϴ� �Ѱ谡 ����..
private:
	vector<NumberBlockActor*> _numberBlocks;
	vector<NumberBlockActor*> _tempNumberBlocks;
	int _blocksInfo[4][4] = {};

	bool _checkCreateNumberBlock = false;
	bool _isClick = true;

	PressKey _state = PressKey::PK_END;
	Game2048State _gameState = Game2048State::GS_RELEASE;

private:
	float _time = 0;
};

