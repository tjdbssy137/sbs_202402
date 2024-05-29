#include "pch.h"

void Comment1()
{
	// 1. Collider Layer -> Example 실습
	// 2. 타일맵 (File Read, Write) (Data Save, Load)

	// - 타일맵은 기본적으로 2D Game에 쓰이는 방식
	//   - 소켓서버기반 위치연동 
	// - Windows API 포트폴리오 이번에 만들 타일맵게임.
	// - Game Engine (Unity, Unreal) Windows API 에서 만든거랑 똑같이 해서 Mobile로 만들면 취업커트라인은 충분히 넘깁니다.
}

void Comment2()
{
	// 타일맵

	// 대표적으로는 포켓몬스터

	// 타일맵을 안쓰는 다른개념
	//  - 통 맵 (메이플스토리)

	// - Background를 조각으로 잘라서 하나하나 붙일수있는가? (타일맵)
	// - 그냥 디자이너가 한통으로 다 그려주는 형식인가? (통맵)

	// 타일맵 구현


	//TileMap
	//	- vector<Tile>
	//	-CellSize
	//	- MapSize


	//	Tile
	//	- Position(Vector2Int)
	//	- Value


}
void Comment3()
{


	//웬만하면 하지마세요.

	// 새로운 룰을 적용하는건
	// "지금 코드부터" 하면됩니다.

	// 운영중인 코드 
	// 라이브서비스중인 코드

	// 새로운코드가 추가되면
	// 기존코드를 모두 지워야하는가?

	// -> 기존코드를 놨둬야함.
	//  --> 모든 변경사항을 체크할 여력이 없음.

	// -> 사이드이펙트 (이코드를 변경시킴으로써, 생길수있는 버그)
	//  -> 측정할수없음. (너무 광범위함)

	// 지금부터의 범위는
	//  -> 새로운 클래스를 만드는거  << 요건 당연하겠죠
	//  -> 옛날코드에서는 절대로 변경하면 안되나요?
	//    => 옛날코드에서 버그가 발견되면, 수정을 해야하잖아요?
	//     => 그떄 같이 수정하면됩니다. 수정하는김에.
}

void Comment4()
{
	// 타일맵정보는 어딘가에 저장해둡니다.
	// 그렇기 때문에 리소스.

	// 어떤형태로 어떻게 저장할것이냐??
	// 음악파일, 이미지파일
	//  + 텍스트파일

	// 텍스트파일 종류
	//  - txt
	//		 - 굳이 설명안하겠습니다.
	// 
	//  - ini 
	//		- 장점 : 사용편함. 읽기편함, 옛날에는 많이쓰는 데이터파일.
	//		- 단점 : 데이터 포맷이 한정되어있음. 
	// 
	//  [소분류]
	//    Variable = 값
	// 
	// [General]
	//	live_link_linkHQInterval = 4000
	//	live_link_linkDegradedResolution = 1024
	//	live_link_linkHQTreshold = 2048
	//	live_link_linkQuickInterval = 300
	//	live_link_initDelayOnProjectCreation = 5000

	//  - csv (엑셀을 셀마다 , 로 분리된 형태)
	//		- 장점 : 엑셀이라는 점. + 엑셀인데 용량이 작음.
	//		- 단점 : (엑셀에서 ,를쓰면, 의도치않게 열이 분리된것처럼 보인다.)
	//				(혹은, 불러오기가 힘든형태가 됨)
	//		- Comment : 요즘은 csv를 읽기보단 그냥 xlsx파일을 읽음. 
	//			(혹은 엑셀을 변형한 내부 커스텀데이터파일)

	//  - xml
	//<?xml version="1.0"?>
	//<CAT>
	//  <NAME>Izzy</NAME>
	//  <BREED>Siamese</BREED>
	//  <AGE>6</AGE>
	//  <ALTERED>yes</ALTERED>
	//  <DECLAWED>no</DECLAWED>
	//  <LICENSE>Izz138bod</LICENSE>
	//  <OWNER>Colin Wilcox</OWNER>
	//</CAT>
	// 
	// 장점 : 트리형태를 가지고있다., 여러가지 데이터 포맷을 포함할수있다.
	//			(Class를 다 Data로 저장시킬수있는 데이터포맷)
	// 단점 : 기획자가 쓰기어려워함. 
	//		  쓸데없이 문법이 까다로움.
	//		  데이터에 비해 용량이 조금 큼. (그래도 작은편)


	// - ★★★★★ json ★★★★★
	// - 얘는 모르면 안됩니다.
	// - 
	//{
	//	"menu": {
	//		"id": "file",
	//		"value" : "File",
	//		"popup" : {
	//			"menuitem": [
	//				{"value": "New", "onclick" : "CreateNewDoc()"},
	//				{ "value": "Open", "onclick" : "OpenDoc()" },
	//				{ "value": "Close", "onclick" : "CloseDoc()" }
	//			]
	//		}
	//	}
	//}

	//<Menu>
	//	<Id>file</Id>
	//	<Value>File</Value>
	//	<Popup>
	//		<MenuItem>
	//			<Value>New</Value>
	//			<onclick>CreateNewDoc()</onclick>
	//		</MenuItem>
	//		<MenuItem>
	//			<Value>Open</Value>
	//			<onclick>OpenDoc()</onclick>
	//		</MenuItem>
	//		<MenuItem>
	//			<Value>Close</Value>
	//			<onclick>CloseDoc()</onclick>
	//		</MenuItem>
	//	</Popup>
	//</Menu>

	// 딱보면, menu 라는 객체안에
	// id 라는 변수는 file 이라는 값이고
	// value 
	// 장점 : 모든 클래스데이터를 다 포함시킬수있다., XML보다 용량도 훨씬 작아요.
	// 단점 : 주석을 못써요.



	// txt 파일 Read Write
	// 파일입출력의 기본.
}

void Comment5()
{
	// 1. 리소스가 부족 
	// 그다음 진도가
	// TileMap생성해서 보여주는건데
	// 제가 이미지파일을 못구해왔어요.
}

void Comment6()
{
	//json 입출력
	// wifstream
	// wofstream 
	//사용

	// 다른사람이 잘만들어둔걸 사용합니다.
	// Library 를 사용.

	// 엔진, 프레임워크, 라이브러리 차이
	// 엔진, 프레임워크 : 무언가를 만들기위해 만들어진 코드뭉치 / 툴
	//		- 내 코드를 여기에 맞춰야한다.
	// 
	// 라이브러리 : 무언가를 다루기위해 만들어진 코드뭉치
	//		- 내 코드에서 라이브러리를 가져다 쓰는형태다.

	// json에서 되게 유명한 library가 있습니다.

	// Tencent - 가장큰 게임회사
	//   클래시오브클랜, 롤, 기타등등

	// 앞으로 라이브러리를 쓸일이 많아질건데,
	// 라이브러리 쓰는방법에 대해 간단하게 알아보겠습니다.
}