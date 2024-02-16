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
// time(NULL) -> 
#include <time.h>
void main() {
	srand(time(NULL));
	int r = rand() % 10;
	printf("random value : %d", r);
}