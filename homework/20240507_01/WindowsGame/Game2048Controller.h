#pragma once
#define RELEASE_TIME 0.4f
#define MAX_BLOCK_COUNT 16

class NumberBlockActor;

enum class PressKey
{
	Down,
	Up,
	Left,
	Right,
	None
};

enum class Game2048State
{
	Release,
	Animation,
	None
};


class Game2048Controller
{
public:
	void Init(vector<NumberBlockActor*> numberBlocks);
	void Update();

private:
	void SumNumberBlocks();
	void InitIsFull();

	// �ߺ����� ���Ϸ��� ���� 10000�� �ٽ� ���ִ� �Լ�
	void SubtractTenThousand();

	// ���ο� ���� ����
	// �������� ������ �ÿ��� ������ �� ��
	void CheckCreateNumberBlock();
	void CreateNumberBlock();

	// ó���� 0���� �����ϰ�, ������ ��ġ�� �ΰ��� 2��
	void NumberBlockToZero();

	// �迭�� ���� ���θ� <�ӽ�>��ȯ�����ִ� �� �ʿ�
	int** ReverseArray(int inputArr[][4], int rows);

	// ���� ������, ���� �������� üũ
	// ���� ���̶�� Ű ��ư �� ����.
	void SetGame2048State(Game2048State gameState);

	// �̵�
	void SetPressKeyState(PressKey state);
	void MoveDown();
	void MoveUp();
	void MoveLeft();
	void MoveRight();

public://Scene���� ������ �Լ�
	void SetGameScore(int gameScore) { _gameScore = gameScore; }
	int GetGameScore() { return _gameScore; }
private:
	vector<NumberBlockActor*> _numberBlocks; // ���
	vector<NumberBlockActor*> _tempNumberBlocks; // �ִϸ��̼� �̵��� ��
	int _blocksInfo[4][4] = {}; // ��� ��ǥ �� ��

	// ���ο� �� ����&�����ص� �Ǵ��� üũ
	bool _checkCreateNumberBlock = false;
	bool _isClick = true;

	// ���� ����
	PressKey _state = PressKey::None;
	Game2048State _gameState = Game2048State::Release;

	// ���������� �Ǵ�
	bool _isMove = false;
	
private:
	float _time = 0.0f; // ���� ���°� ����Ǵ� �ð�
	int _gameScore = 0; // ���� ����
};

