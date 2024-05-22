#include "pch.h"

void Comment01()
{
	// 1. 숙제 풀이
	// - 버튼 누르면 씬 이동

	// 2. Layer
}

void Comment02()
{
	//Layer란
	// - Item이 장애물 뒤에 나오게 되면, 이상하게 보임
	// 이런 것들을 Layer로 정해주고
	// 이 요소들은 항상 얘 앞에, 항상 얘 뒤에 그린다.
	// 이런 것들을 정해주는 게 Layer.

	// -> 비슷한 애들끼리 모아서 그 친구들끼리 무언가를 해주는 게 Layer구나~
}

void Comment03()
{
	// 여태까지 배운 Layer 개념은 통상적으로 쓰이는 Layer.
	// 디자이너도 이렇게 부르고, 기획자도

	// 게임 프로그래머
	// - [Collision Layer]
	
	// Collision Layer
	// - 게임 프로그래밍에서 최적화를 해야한다면, [충돌체크]
	// - 충돌체크가 매프레임(1초에 144번)
	// - 그 계산로직이 생각보다 복잡함. (폴리곤, 3D Collider)
	// - 총알이 100개 있다고 치고, 몬스터가 30마리 있다고 치면
	// 총 130개의 오브젝트 130 * 130번 만큼 그 Collider Check 로직을 돌리게 됨
	// 대충 10000번을 1초에 144번
	// - 저 충돌로직을 개선할 수 있는 방법은 없음(이미 수학자들이 만들어낸 것이라서..)
	// - 그렇기 때문에 [충돌 횟수를 줄이는 것]
	
	// 게임 프로그래밍이 난이도가 제일 높다고하는 이유.. 144FPS -> 1프레임에 허락된 시간이 10ms도 안 됨.


	// 충돌 체크를 줄인 다는 것은 무슨 뜻일까?
	// -> Ex. 탄막 슈팅 게임
	//		총알끼리 충돌 체크를 하는 것이 의미가 있을까? -> XX
	//		총알 <-> Character 랑만 충돌체크를 하면 됨

	// 총알 100개
	// 캐릭터 : 30개
	// 130 * 130번이 아니라, 100 * 30번의 충돌 체크만 확인하면 됨
	// 즉, Collision Layer은 최적화의 일종이다.
}

void Comment04()
{
	// 비트연산자
	// 비트연산에 대하여 Console추가 -> Day34
}


void Comment05()
{

}