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

	// 중복합을 피하려고 더한 10000을 다시 빼주는 함수
	void SubtractTenThousand();

	// 새로운 숫자 생성
	// 움직임이 없었을 시에는 생성도 안 됨
	void CheckCreateNumberBlock();
	void CreateNumberBlock();

	// 처음에 0으로 리셋하고, 랜덤한 위치의 두개만 2로
	void NumberBlockToZero();

	// 배열의 가로 세로를 <임시>전환시켜주는 게 필요
	int** ReverseArray(int inputArr[][4], int rows);

	// 연출 중인지, 게임 중인지를 체크
	// 연출 중이라면 키 버튼 안 눌림.
	void SetGame2048State(Game2048State gameState);

	// 이동
	void SetPressKeyState(PressKey state);
	void MoveDown();
	void MoveUp();
	void MoveLeft();
	void MoveRight();

public://Scene으로 보내는 함수
	void SetGameScore(int gameScore) { _gameScore = gameScore; }
	int GetGameScore() { return _gameScore; }
private:
	vector<NumberBlockActor*> _numberBlocks; // 블록
	vector<NumberBlockActor*> _tempNumberBlocks; // 애니메이션 이동용 블럭
	int _blocksInfo[4][4] = {}; // 블록 좌표 및 값

	// 새로운 블럭 생성&생성해도 되는지 체크
	bool _checkCreateNumberBlock = false;
	bool _isClick = true;

	// 게임 상태
	PressKey _state = PressKey::None;
	Game2048State _gameState = Game2048State::Release;

	// 움직였는지 판단
	bool _isMove = false;
	
private:
	float _time = 0.0f; // 게임 상태가 변경되는 시간
	int _gameScore = 0; // 게임 점수
};

