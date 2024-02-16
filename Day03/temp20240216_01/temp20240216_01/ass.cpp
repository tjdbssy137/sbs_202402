/*
숫자 네 개를 입력 받아서
100, 200, 300, 400
처음 숫자 두 개 사이의 랜덤 숫자에서 세번째 숫자를 빼고
네번째 숫자를 곱한 값을 출력
*/
#include <iostream>
#include <time.h>
using namespace std;

void main() {
	srand(time(NULL));
	int a, b, c, d;
	printf("숫자 네 개 입력 >> ");
	scanf_s("%d %d %d %d", &a, &b, &c, &d);
	int random = rand() % (a - b + 1) + b;
	printf("두 수 사이의 랜덤 값은 %d\n", random);

	int subtract = random - c;
	printf("랜덤 값에서 세번째 숫자를 뺀 값은 %d\n", subtract);

	int multiply = subtract * d;
	printf("최종 결과는 %d", multiply);
}