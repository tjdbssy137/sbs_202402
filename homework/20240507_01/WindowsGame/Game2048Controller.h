#pragma once
#define RELEASE_TIME 0.5f
#define MAX_BLOCK_COUNT 16

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

	void SetGame2048State(Game2048State gameState);
	// 연출 중인지, 게임 중인지를 체크
	// 연출 중이라면 키 버튼 안 눌림.
	// 연출시에 껍데기를 만들어서 이동.
	// 이동이 다 되었다면 껍데기 삭제
	// 게임 재개
	
	// 좌표를 보내주고 좌표 찍은대로 이동.
	// 이동후 잠시 삭제 됐다가
	// 합쳐진 숫자로 생성
private:
	vector<NumberBlockActor*> _numberBlocks; // 블록
	vector<NumberBlockActor*> _tempNumberBlocks; // 애니메이션 이동용 블럭
	int _blocksInfo[4][4] = {}; // 블록 좌표 및 값

	// 새로운 블럭 생성&생성해도 되는지 체크
	bool _checkCreateNumberBlock = false;
	bool _isClick = true;

	// 게임 상태
	PressKey _state = PressKey::PK_END;
	Game2048State _gameState = Game2048State::GS_RELEASE;
	
private:
	float _time = 0.0f; // 게임 상태가 변경되는 시간
	int _gameScore = 0; // 게임 점수
};

