#include <iostream>
using namespace std;

// 난수 혹은 랜덤수
// 난수를 왜 배워야하는가?
// 게임에서는 랜덤 없이는 할 수 있는 게 없음.
// 캐릭터 데미지도 랜덤이 어느정도 들어간다. (스타듀밸리 광산)

//랜덤 쓰는 법(암기과정)
// 1. #include <time.h>
// 2. main문 안에서 바로 srand(time(null)); 명령을 실행
// 3. rand() 를 사용하면 랜덤수가 뽑힘

// rand() -> 컴퓨터에서 예정된 시드값을 뽑아온다.
// => 예정된 시드값을 섞어주는 함수가 srand()
// 값이 랜덤이 되어야하는게 아닌가?

// 시간으로 돌리자
// time(NULL)
// 현재 시간
// 1970년 1월 1일부터 현재까지 몇 틱이 지났는지.

// time(NULL) 자체만 쓰는 것엔 프로그램 보안에 취약하기 때문에.
// srand(time(NULL))을 씀.

#include <time.h>
void main() {
	srand(time(NULL));
	int r = rand() % 10;
	printf("random value : %d", r);
}