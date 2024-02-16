#include <iostream>
using namespace std;

void main() {
	//변수 -> 정수형 변수

	//1. 변수가 무엇인지?
	// -> 프로그램에서 기억해야하는 데이터.

	//2. 변수 사용하는 법
	// [1] 자료형 변수명 = 값;
	// [2] 자료형 변수명;
	
	// 자료형 => 정수 자료형
	//1 byte 정수 = 8bit (0 ~ 255), (-128 ~ 127)
	//2 byte 정수 = 16bit (2만)
	//4 byte 정수 = 32bit (-21억 ~ 21억)
	// => CPU적으로 접근이 빠르다
	//8 byte 정수 = 64bit 

	// 1 byte : char
	// 2 byte : short
	// 4 byte : int
	// 8 byte : long long

	int a = 1;
	printf("a : %d\n", a);
	printf("a : %10d\n", a);
	printf("a : -%10d\n", a);

	short b = 5000000; //2만을 초과하면 값이 알아서 잘림.
	printf("b : %d\n", b);
	// => 19264로 출력됨
	// 저장할 수 있는 비트가 한정되어있기 때문에 넘치는 내용은 담을 수 없음.
	
	long long c = 1;

	char d = 'a';
	string e = "apple";

	float f = 1.0f;
	double g = 1.0f;

	bool h = true;
}