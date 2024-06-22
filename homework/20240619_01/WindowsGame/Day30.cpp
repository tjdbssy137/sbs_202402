#include "pch.h"
void Comment01()
{
	// 1. 사운드 매니저 (별로 안 중요한 내용)
	//		- 사운드 코드는 쓸 줄만 알면 됨.
	//		- 모든 엔진에서 사운드를 그렇게 깊게 다루지 않음.
	//		- 어떻게 시작하는 지. 어떻게 사운드 파일을 로드하는 지.(로드 하는 방법도 별로 안 중요함)
	
	// 사실 사운드 매니저는 따라치는 게 전부
	// 굳이 알 필요 없음.

	// 2. 충돌체크

	// 3. UI
}

void Commnet02()
{
	// 사운드 매니저
	
	// 사운드
	//	- 외부 리소스 파일
	//	- 리소스 매니저에서 관리
	
	// 버퍼 : byte array
	// 모든 파일은 byte array로 이루어져 있음



	//CPP에서 쓰이는 문법
	//CPP의 꽃
	//포인터 -> 주소값을 기억하는 자료형(모두가 똑같은 값의 형식 4바이트)

	//int*, float*, 클래스*
	//굳이 포인터 앞에 자료형을 붙인 이유
	// - 나중에 사용할 때, 얘가 어떤 형인지 알아야하니까.
	// void*는 그냥 주소값만 들고 있겠다라는 의미
	// 그리고 나중에 사용이 필요하면 그때 형변환 해주겠다.
	// 엔진 다루시는 분들이 많이 사용
	void* write1 = NULL;
	void* write2 = NULL;

	DWORD len1;
	DWORD len2;

	// 버퍼의 값을 쓸 때는 항상 락을 걸고 쓴다
	// 락을 건다는 건, 이 팡리을 지금부터 내가 쓸거니까 건들지마. 
	// 건들거면 내가 다 쓸때까지 기다리라는 의미

	//락을 걸고
	_soundBuffer->Lock(0, child.cksize, &write1, &len1, &write2, &len2, 0);

	// 쓰고
	if (write1)
	{
		mmioRead(file, (char*)write1, len1);
	}

	if (write2)
	{
		mmioRead(file, (char*)write2, len2);
	}

	//락을 푼다
	_soundBuffer->Unlock(write1, len1, write2, len2);


	// 컨트롤 + F5로 실행을 이미 한 상태에서 또 실행을 하지 못함. -> 락이 걸려 있기 때문
	// 실행한 창을 끄고 다시 실행해야함.
}

void Comment03()
{
	//콘텐츠 분리
	// LOL
	// 1. 아리 리메이크 (5월 1주차)
	// 2. 파이크 신규추가 (5월 2주차)

	// 5월 1주차와 5월 2주차 사이에는 코드를 업데이트 하면 안 되나?

	// 롤토체스
	// 버그가 100개

	// 기존 업데이트
	// [코드분리]
	// 신규업데이트
}

void Comment04()
{
	// 충돌 체크

	// 게임에서의 충돌체크(2D)
	// [원, 사각형]
	// 많이 쓰는 이유 : 제일 가벼움
	// 충돌 로직이 되게 계산할 게 많다.
	
	// 점과 직선 사이의 공식(수학) (다각형만큼) (십각형이다 -> 10번정도)

	// 계산 시간이 오래 걸림
	// - 매프레임. 체크를 해줘야하는 데
	// - 매프레임 호출 되는 것 중에서 계산 시간이 오래 걸리는 건 안 쓰려고 함.
	//	프레임이 튐
	// 철권하는 데 1프레임이 0.1초씩 걸린다고 하면
	// 사람들이 그 게임은..

	// 최적화는 리소스로 하지만
	// 충돌체크 만큼은.. 로직에서 한다.


	// CircleCollider
	// Box <-> Box (구현 완료)
	// Circle <-> Circle (구현 필요)
	//	- 게임 수학으로 알아둬야 함
	// - (중심점으로부터 원의 반지름) 사이의 거리
	// Box <-> Circle(구현)
	// - 얘는 안 물어봄

}

void Comment05()
{
	// 숙제는 2048이다..
	
	// Circle <-> Circle
	//	Circle1, Circle2 -> 중심좌표
	// 중심좌표 사이가 <= (Circle1의 반지름 + Circle2의 반지름)
	// -> 충돌
}

void Comment06()
{
	// 퍼포먼스 테스트
	// 특정 함수나 특정 코드가 얼마나 오래 걸리는 지 테스트 해보는 것
	// 단위 테스트, Unit Test

	// 이런 테스트의 경우에는
	// 백만번 실행
}