#include "pch.h"

void Comment01()
{
	// 1. 타일맵 액터에 카메라 적용
	// 2. Culling - 안 보이는 부분은 굳이 그릴 필요가 없음
	// 3. 젤다 캐릭터 생성 & 이동
}

void Comment02()
{
	// 1. 타일맵 액터에 카메라 적용
	// 굳이 사용자가 보지도 못할 공간을 Render할 필요가 없음
	// Culling 이라고 카메라가 비추지 않는 영역은 Render을 안하도록 하는 기법
}

void Comment03()
{
	// 캐릭터 생성
	// TileActor

	// Actor, Controller 분리작업
	// Actor - > 배우(기능만 들고 있음)
	
	// Controller -> 게임 로직을 담당
	// 마우스, 키보드 입력
}

void Comment04()
{
	// - assert()
	// assert란, 개발중에만 오류를 표시해주는  rlsmd
	// assert(조건);
	// 조건이 참일 때만 코드를 통과하고, 조건이 거짓이면, 에러를 내보낸다(프로그램이 뻑난다)
	
	// 언제 쓰는지??
	// 유효성 체크 할 때 
}

void Comment05()
{
	// 실습
	// 캐릭터 움직이는 걸 타일맵 움직이는 거랑 동일하게 맞추기
	// (왼쪽키를 누르면, 왼쪽 타일로 한 칸)
	// 4방향 모두 완료
}

void Comment06()
{
	// 렌더링 파이프라인
	// Windows API 그림을 어떻게 그리는 가?
	// - 비트맵 그림을 그리는 함수를 사용해서 그림을 그림
	// - TransparentBlt, BilBlt 등
	// - CPU 를 사용해서 그림을 그림

	// CPU를 사용해서 그림을 그리다보니, 게임 최적화 -> 그림 그리는 것
	// CPU가 GPU 보다 못해도 50배는 느림
	// 상당히 비효율적이고 느려짐

	// GPU -> 그래픽 카드르 사용해서 빠르게 그림을 그리는 방법
	// [하드웨어 가속] 이것을 이제 코드로 컨트롤할 수있게 해주겠다
	// Direct X 개념
	// GPU를 내 마음대로 컨트롤 하겠다

	// Game Engine, Direct X러 만든 게임을 보면.
	// 뭔가 많이 그림을 그리는 데, 크게 안 느림

	// 그러면 어떻게 해야 GPU를 쓸 수 있는지??
	//  GPU는 하드웨어 영역 <- 그렇게 많이는 안 열어줌
	// 렌더링 파이프라인을 구축해서 이 순서대로 렌더링을 해라

	// 1. Vertex Shader
	// 2. Tessellation
	// 3. Geometry Shader
	// 4. Rasterization
	// 5. Pixel Shader(Fragment Shader)
	// 6. Frame Buffer

	// GPU를 쓰기 위해서는 CPU 에서 정리된 데이터를  GPU에 넘겨줘야 일을 할 수 있음

	// 크게 2가지/
	// Shader라는 코드(HLSL 문법), Vertex Data

	// Shader - C++, C# 이런 것처럼 고급 문법 (단지 GPU를 위한..)
	// 테크니컬 아티스트 << shader 코드를 짜는 사람
	// 요즘은 AI가 짜거나, Visual Shader

	// Direct X -> 3D 게임

	// Vertex Data (정점 위치)
	// 3D Model

	// ★1. Vertex Shader (★CPU)
	// - Vertex Data를 넘겨줌
	// - World, View, Projection 이라는 과정을 거침
	// World - (게임 세상에 존재하는 모든 모델들의 정점 데이터를 List로 만든다)
	// View - (World 에 있는 모든 정점 데이터들을 내 현재 카메라에 맞게 수정해준다) 
	// Projection - (View 까지 끝난 데이터를 실제로 스크린화면에 맞춰 재조정)
	//			  - 최적화 (안 그려도 되는 모델같은 경우엔 여기서 컷; Frustom Culling작업)
	
	// 2. Tessellation (최적화 작업)
	// - (화면 전체 크기는 보편적으로 1920 * 1080 -> 이거에 비해 정점수가 너무 많음)
	// - Level Of Detail (LOD)
	// - 멀리서 찍을 수록, Low Polygon 모델을 사용하도록 변경 (모델러가 작업)
	
	// 3. Geometry Shader (퀄리티 작업. 최적화 반대)
	// - 그림자를 만드는 작업.
	// - 먼저 object를 그림
	//		- 그 이후에 같은 object를 한 번 더 그리는 것.(먼저 그려진 것이 뒤에 그려지기 때문)
	//		-> 두 번 그림을 그리기 때문에. 그림자 on을 하면 부하가 2배가 됨. 
	
	// ★4. Rasterization (픽셀 대입) (GPU)
	// - 각 Pixel당 어떤 색으로 칠하면 될 지.
	// - GPU 내부에서 Lerp 연산을 해서 각 픽셀이 가진 색상을 보간함.
	// - Texture 입히기
	
	// ★5. Pixel Shader(Fragment Shader) (GPU)
	// - 1920 * 1080 만큼 계산을 함.
	// - 매프레임 2,073,600만큼 계산 진행
	// - (4K일 경우 1920 * 1080의 네 배로 계산량이 불어남)
	// - 조명 효과, 오브젝트끼리 조명을 방해할 수 있음,, 이런 걸 계산
	
	// 6. Frame Buffer
	// - Alpha Blending (Windows API도 가능)
	//		Alpha 끼리 만났을 때 다른 색상이 나와야함. (투명도끼리 겹쳤을 때)
	// - Stencil Buffer (최종 기믹 효과)
	//		[책상 안 쪽 확인하기] 돋보기로 가져다대면 (책상 모델은 그대로 있는데, 책상 안쪽 보여주는..)
	//		특정 부분만 보이거나 안 보이게 하는 효과.
	// - Z-Test
	//		누가 앞에 있는 모델인지
	//		Windows API에서도 Layer에 따라서 먼저 그려주는 순서가 달라지듯.. 
	//		카메라 앞에 있으면 나중에(맨 앞에) 그려줌 // 뭔말이지..

}