#include <iostream>
using namespace std;

enum WeaponType
{
	WT_LASER,
	WT_SANTAN
};
void main()
{
	// 게임은 속도
	// 제일 빠른 연산 -> 비트연산!!

	// 파츠(무기 타입)
	//		(레이저총, 산탄총 etc) (이런 것들 종류가 32가지는 안 넘겠죠??)
	
	// 근데 비트 연산의 단점은
	// 32가지를 넘기면 구현에 문제가 생긴다는 점,,

	// 0000
	// 0001 => WT_LASER
	// 0010 => WT_SANTAN

	// 0011 -> 레이저총이면서 산탄총인 경우
	int weapon = (1 << WT_LASER) | (1 << WT_SANTAN);

	printf("weapon : %d\n", weapon);

	// C++ 
	// if(숫자) 숫자가 0만 아니면 true
	// 근데 C++이 아닌 언어에서는 if(숫자) --> 에러(비교연산자로 확실하게 해줘야함.)
	if (0 < (weapon & (1 << WeaponType::WT_LASER))) 
		// "0 < "이 없어도 되긴하지만, 다른 언어로 옮기게 된다면 에러를 줄이기 위해 "0 < "을 해줌
	{
		printf("레이저 옵션 추가\n");
		printf("공격력 증가 + 5\n");
	}
	
	if (0 < (weapon & (1 << WeaponType::WT_SANTAN)))
	{
		printf("산탄 옵션 추가\n");
		printf("공격력 증가 + 15\n");
	}
}