#include <iostream>
using namespace std;

#include <time.h>

void main() {
	srand(time(NULL));
	int random = rand() % 31;
	printf("random1 = %d\n", random);

	int random2 = rand() % 101;
	printf("random2 = %d\n", random2);

	// 25 ~ 40 사이의 랜덤 숫자를 출력하기
	// 0 ~ 15 사이의 랜덤숫자에서 +25를 하면 된다.
	int random3 = rand() % 16 + 25;
	printf("random3 = %d\n", random3);
	
	int random4 = rand() % 121 + 150;
	printf("random4 = %d\n", random4);

	//입력 input
	// -> 키보드, 마우스, 터치, 블루투스 등
	// -> 콘솔은 키보드만 사용.

	//scanf라고 하는 가장 간단한 변수 입력에 대해서 다룰 것.
	int input1 = 0;

	//사용법
	//scanf_s("%d", &변수명);
	
	//printf("input1 >> ");
	//scanf_s("%d", &input1);
	//printf("input1 : %d\n", input1);

	
	//주사용처
	//프로그램에 직접적인 개입이 가능함
	//선택지를 고를 수 있음.
	
	//printf("가위(0) 바위(1) 보(2) 중에 하나를 선택해주세요 >> ");
	//scanf_s("%d", &input1);

	//실습.
	//숫자 두 개를 입력받아서
	//그 두개 사이의 random 숫자를 출력하도록.
	int a = 0, b = 0;
	printf("input A and B >> ");
	scanf_s("%d %d", &a, &b);

	printf("%d와 %d 사이의 랜덤한 숫자 %d", a, b, rand() % (a - b + 1) + b);

}