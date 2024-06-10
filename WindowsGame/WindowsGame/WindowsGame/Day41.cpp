#include "pch.h"

void Comment01()
{
	// 1. Console에서 Astar 적용
	// 2. Windows API 에서 A* 적용
	
	// 3. data manager
}

void Comment02()
{
	// 우클릭을 누르면 플레이어가 해당 타일로 이동
	// 수도코드
	
	// Controller
	// if (마우스 우클릭을 누르면)
	//		Tile* tile = 누른 ㅈㅣ점의 타일을 구함
	//		Vector2Int startTilePos = 내가 현재 서 있는 타일.
	//		Vector2Int endTilePos = 누른 지점의 타일을 구함.
	//		Calculator_Astar(startTilePos, endTilePos);
	//		-> return vector<Vector2Int> _path(가야하는 내용 담도록 설정)

	// Controller
	//
	// if(_pathIndex != _path.size())
	//		플레이어 Move변경
	//		플레이어 EndPos = _path[_pathIndex++];
}

void Comment03()
{
	// 캐릭터의 데미지
	// 이동속도
	
	// 몬스터의 이동속도 데미지
	// 어떤 스킬을 가지고 있는지?

	// 코드에서 조절하는 것이 아님.

	// 따로 데이터를 뺴놔서, 기획자가 직접 수정할 수 있게끔..

	// 모든 프로그램은
	// [로직 + 데이터]
	// 이 데이터면 어떻게 동작 시킨다.

	// 데이터 매니저

	// 데이터
	// - 여러가지 형태로 게임의 데이터를 저장
	// 1. text or binary
	// 2. excel
	// 3. json (구조체를 text로 변환하는 방법 중에 하나)

	// 이동속도, 데미지, 이름
	// - 데이터 매니저
	// (플레이어)
	// (몬스터)
}