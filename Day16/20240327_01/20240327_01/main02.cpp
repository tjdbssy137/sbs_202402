#include <iostream>
using namespace std;

void main()
{
	//형변환 캐스팅 세 가지
	// (하나 더 있는데, 그 건 C형식이라 제외)
	// 
	// 자료형과 변수
	// - C 형식 캐스팅
	float a = 3.3f;
	int e = (int)a;

	//주소값을 정수로 받는다
	int f = (int)&a;

	// - C++ 형식의 캐스팅 (C형식 보다 추천)
	// 1. static_cast (정적 캐스팅)
	// float -> int
	// string -> int 같은 얼토당토 없는 건 안 됨.
	int g = static_cast<int>(a);

	// - 2. dynamic_cast
	// 상속간 가지고 오는 캐스팅
	// 수업 다시 듣기.. 초반에 있음
	MasterKey* key = new MasterKey();
	Key* myKey1 = dynamic_cast<MasterKey*>(key);

	// -3. reinterpret_cast
	// 거의 안 씀
	// 메모리 그대로 캐스팅 해줄 때
	int bb = 123;
	int* ptr1 = reinterpret_cast<int*>(bb);


}