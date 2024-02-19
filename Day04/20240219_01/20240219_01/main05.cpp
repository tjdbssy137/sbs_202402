#include <iostream>
#include <time.h>
using namespace std;
//cout과 cin을 std::를 사용하지 않고 사용 가능.

// 연산자
// 사칙연산 => 연산자
// +, -, *, /, %(나머지)

// 연산자끼리는 어떤 식이 먼저 이루어지는 지에 따라 결과가 달라진다.
// *, /가 항상 먼저 적용
// +, -가 항상 후에 적용

// 기본적인 사칙연산을 제외하고서는 항상 우선순위 연산을 정해준다.
// => () 소괄호를 이용.


// 함수 
// => 무조건 main 위에 작성. C와 CPP는 위에서 아래로 코드를 읽기 때문에.
//반환타입 함수명() // 함수명은 대문자로 시작
//{
//		실행할 코드
//}

int _myHand = 0;
int _comHand = 0;

void PrintGameStartScene() 
{
	printf(" _____________________________________\n");
	printf("|                                     |\n");
	printf("|    Rock Scissor Paper Game Start    |\n");
	printf("|_____________________________________|\n");
}

void ChooseMyHand() 
{
	cout << "가위(0)바위(1)보(2) 입력 >> ";
	cin >> _myHand;
}

void ChooseComHand() 
{
	_comHand = rand() % 3;
}

void PrintHand(int _hand) 
{
	switch (_hand) {
	case 0:
		cout << "가위";
		break;
	case 1:
		cout << "바위";
		break;
	case 2:
		cout << "보";
		break;
	default:
		cout << "잘못";
		break;
	}
	cout << " 입니다." << endl;
}

void PrintGameResult() 
{
	if (_myHand == _comHand)
		printf("비겼습니다");
	else if (_myHand == 2 && _comHand == 0)
		printf("패배했습니다");
	else if (_myHand > _comHand || (_myHand == 0 && _comHand == 2))
		printf("승리했습니다");
	else
		printf("패배했습니다");
}

void main()
{
	srand(time(NULL));//한번만 실행되게 끔 main에서 실행

	//수도 코드
	// 1. 게임시작화면을출력
	// 2. 내가 어떤 것을 뽑을 지 출력
	// 3. 상대방이 어떤 것을 뽑을 지 정함
	// 4. 내가 뽑은 것과 상대방이 뽑은 것을 출력
	// 5. 승패를 출력
	PrintGameStartScene();
	ChooseMyHand();
	ChooseComHand();
	cout << "_myHand가 낸 것은 ";
	PrintHand(_myHand);
	cout << "_comHand가 낸 것은 ";
	PrintHand(_comHand);
	PrintGameResult();
}