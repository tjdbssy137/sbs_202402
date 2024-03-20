#include "pch.h"

void main()
{
	// 프로젝트 세팅
	
	// <교양 지식>
	// .pdb => 코드에 대한 정보
	//		-> 그렇기에 절대 유저한테 배포되면 안 됨. (배포되는 순간, 유저는 코드를 다 까볼 수 있음)
	//		=> 라이브 디버깅을 할 수 있게 만드는 파일
	// 

	// .obj => cpp 파일 단위로, (빌드되는 파일 단위로) 내용물을 적어둔 것
	//		-> 빌드 : 바뀐 파일만 .obj로 변환하는 과정
	//		-> 다시 빌드 : 모든 파일을 다시 .obj로 변환하는 과정
	// .log => 로그파일(진행상황 같은 걸 적어둠)
	// .lik => 파일들이 어떻게 include되어있나?
	//		-> 정보 담아두는 곳

	// .vs => 지워도 다시 생김
	//		-> 현재 visual studio 정보를 담아 둠

	// .sln => solution 파일
	// .vcxproj => 프로젝트 파일
	//				-> ~proj면 전부 프젝 파일

	//---------------------------


	// 적은 것 => git에서 제외시키겠다.
	// *은 어떤 문자든 모두 포함
	// *.d 확장자가 .d인 것을 제외시킨다.

	// 결론
	// .gitignore 에
	// .vs
	// Binaries -> $(SolutionDir)Binaries\$(Platform)\$(Configuration)\
	// Intermediates -> $(SolutionDir)Intermediates\$(Platform)\$(Configuration)\
	
}