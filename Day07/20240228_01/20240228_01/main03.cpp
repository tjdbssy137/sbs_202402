#include <iostream>
using namespace std;

enum eRSP
{
	RSP_SCISSOR,
	RSP_ROCK,
	RSP_PAPER,

	RSP_END // array와 for문을 사용할 때 사이즈로 사용하기 편리하다.
};

// 매개변수, 아규먼트, 파라멘터
void PrintHand(int hand);

void main()
{
	// 함수의 용도
	// 재사용성
	// 손을 출력해주는 함수
	PrintHand(1);
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