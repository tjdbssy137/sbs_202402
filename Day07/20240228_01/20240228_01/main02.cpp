#include <iostream>
using namespace std;
#define HAND_MAX 2
#define KIND_OF_HAND 3

//enum 선언
enum eRSP 
{
	RSP_SCISSOR,
	RSP_ROCK,
	RSP_PAPER,

	RSP_END // array와 for문을 사용할 때 사이즈로 사용하기 편리하다.
};

enum eHandName
{
	HAND_LEFT,
	HAND_RIGHT,

	HAND_END // array와 for문을 사용할 때 사이즈로 사용하기 편리하다.
};

// 함수 원형 구현
void chooseMyHand();
void chooseComHand();
void PrintHands();
void ChooseFinalMyHands();
void ChooseFinalComHand();
void PrintResult();
void PrintHand(int);

// 0과 1 외에는 모두 define이나 상수로 변경해주는 것이 좋음.
int _myHand[HAND_MAX] = {};
int _comHand[HAND_MAX] = {};
int _myFinalHand = 0;
int _comFinalHand = 0;
string _KindOfHand[KIND_OF_HAND] = {"가위", "바위", "보"};

void main()
{
	srand(time(NULL));
	chooseMyHand();
	chooseComHand();
	PrintHands();
	ChooseFinalMyHands();
	ChooseFinalComHand();
	PrintResult();

	// 가위바위보 하나 빼기
	// 함수 뒷내용 잠깐씩 사용

	// 가위바위보 하나 빼기 수도코드
	// 1. 내가 낼 것 두 개를 정한다.
	// chooseMyHand()
	// 2. 상대(컴퓨터)가 낼 것 두개를 정한다.
	// -> 이때 상대가 낼 것은 rand() % 3
	// chooseComHand()
	// 3. 내가 낸 것과 상대가 낸 것을 보여준다
	// PrintHands()
	// 4. 내가 최종적으로 낼 것을 고른다
	// ChooseFinalMyHands()
	// 5. 상대가 최종적으로 낼 것을 고른다
	// ChooseFinalComHand()
	// 6. 승패 비교를 한다.
	// PrintResult()

	// 수도코드 스탭당으로 함수를 짜는 것이 좋다.
	// -> 가독성 측면에서 굿.
}

void chooseMyHand()
{
	// 내 손 두개를 정해준다.
	cout << "왼쪽 손을 정해주세요 가위(0) 바위(1) 보(2) >> ";
	cin >> _myHand[HAND_LEFT];
	cout << "오른쪽 손을 정해주세요 가위(0) 바위(1) 보(2) >> ";
	cin >> _myHand[HAND_RIGHT];
}
void chooseComHand()
{
	for (int i = 0; i < HAND_END; i++)
	{
		_comHand[i] = rand() % RSP_END;
	}
}
void PrintHands()
{
	cout << "내가 낸 것은 " << endl;
	PrintHand(_myHand[HAND_LEFT]);
	PrintHand(_myHand[HAND_RIGHT]);
	cout << "이고," << endl;
	cout << "컴퓨터가 낸 것은 " << endl;
	PrintHand(_comHand[HAND_LEFT]);
	PrintHand(_comHand[HAND_RIGHT]);
	cout << "이다." << endl;

	//cout << "내가 낸 것은 " << _KindOfHand[_myHand[HAND_LEFT]] << "와 " << _KindOfHand[_myHand[HAND_RIGHT]] << endl;
	//cout << "컴퓨터가 낸 것은 " << _KindOfHand[_comHand[HAND_LEFT]] << "와 " << _KindOfHand[_comHand[HAND_RIGHT]] << endl;
}
void ChooseFinalMyHands()
{
	while (1)
	{
		cout << "나의 선택은 왼손(0) 오른손(1) >> ";
		cin >> _myFinalHand;
		if ((_myFinalHand == 0) || (_myFinalHand == 1)) break;
	}
	switch (_myFinalHand)
	{
	case HAND_LEFT:
		_myFinalHand = _myHand[HAND_LEFT];
		break;
	case HAND_RIGHT:
		_myFinalHand = _myHand[HAND_RIGHT];
		break;
	}
}
void ChooseFinalComHand()
{
	_comFinalHand = rand() % HAND_MAX;
	switch (_comFinalHand)
	{
	case HAND_LEFT:
		_comFinalHand = _comHand[HAND_LEFT];
		break;
	case HAND_RIGHT:
		_comFinalHand = _comHand[HAND_RIGHT];
		break;
	}
}
void PrintResult()
{
	cout << "내가 최종적으로 선택한 것은  >> " << _KindOfHand[_myFinalHand] << endl;
	cout << "컴퓨터가 최종적으로 선택한 것은 >> " << _KindOfHand[_comFinalHand] << endl;

	if (_KindOfHand[_myFinalHand] == _KindOfHand[_comFinalHand])
	{
		cout << "비겼습니다.";
	}
	else if (_KindOfHand[_myFinalHand] == _KindOfHand[0]) // 가위
	{
		if (_KindOfHand[_comFinalHand] == _KindOfHand[1]) // 바위
		{
			cout << "패배하였습니다";
		}
		else if(_KindOfHand[_comFinalHand] == _KindOfHand[2])// 보
		{
			cout << "승리하였습니다.";
		}
	} else if(_KindOfHand[_myFinalHand] == _KindOfHand[1]) // 바위
	{
		if (_KindOfHand[_comFinalHand] == _KindOfHand[0]) // 가위
		{
			cout << "승리하였습니다.";
		}
		else if (_KindOfHand[_comFinalHand] == _KindOfHand[2]) // 보
		{
			cout << "패배하였습니다";
		}
	}
	else // 보
	{
		if (_KindOfHand[_comFinalHand] == _KindOfHand[0]) // 가위
		{
			cout << "패배하였습니다";
		}
		else if (_KindOfHand[_comFinalHand] == _KindOfHand[1]) // 바위
		{
			cout << "승리하였습니다.";
		}
	}
}
void PrintHand(int hand)
{
	switch (hand)
	{
	case RSP_SCISSOR:
		cout << "가위" << endl;
		break;
	case RSP_ROCK:
		cout << "바위" << endl;
		break;
	case RSP_PAPER:
		cout << "보" << endl;
		break;
	default:
		cout << "아무것도 아님" << endl;
		break;
	}
};