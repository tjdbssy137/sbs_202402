#include <iostream>
// - input : 키보드 입력, 마우스 입력 등
// - output : 출력(수업에선 콘솔 위주)
using namespace std;
// 함수를 간단하게 쓸 수 있음

// 모든 프로그램 언어는 main이라는 함수를 찾아서 실행한다.
void main() {
	int a = 0;

	// if란, 모든 프로그래머가 제일 많이 사용하는 문법.

	if (a == 0) //조건에 맞을 때만 실행 시킬 수 있는 문법
		printf("a는 0입니다.\n");

	// 프로그래밍을 잘하려면 말을 코드로 바꿀 수 있어야 한다.
	
	// if문 사용법
	// if(조건식)
	// { 조건이 참일 때 실행하는 코드 }

	// 조건식
	// 참일 시 1 true
	// 거짓일 시 0 false
	int num1 = 10;
	int num2 = 20;

	printf("num1[%d] > num2[%d] : %d\n", num1, num2, num1 > num2);
	printf("num1[%d] < num2[%d] : %d\n", num1, num2, num1 < num2);
	
	// 비교연산자 (결과는 항상 0과 1로 나온다)
	// A > B : A가 B보다 크다
	// A < B : A가 B보다 작다
	// A >= B : A가 B보다 크거나 같다
	// A <= B : A가 B보다 작거나 같다
	// A != B : A가 B과 같지 않다
	// A == B : A가 B과 같다
	// A && B : A와 B => A와 B 둘 다 참일 때만 참을 반환
	// A || B : A 또는 B => A와 B 중에 하나만 참이어도 참을 반환


	// if문 => 만약 ~~라면
	// else if문 => 그렇지 않고 ~~면
	//  => if문 조건이 false + 새로운 조건이 true 일 때
	// else 문 => 그렇지 않으면
	int input1 = 0;

	printf("점수를 입력해주세요 : ");
	scanf_s("%d", &input1);

	if (90 < input1) {
		printf("A입니다.");
	}
	else if (80 < input1) {
		printf("B입니다.");
	}
	else if (70 < input1) {
		printf("C입니다.");
	}
	else if (60 < input1) {
		printf("D입니다.");
	}
	else {
		printf("F입니다.");
	}
}