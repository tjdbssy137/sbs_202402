#include "framework.h"
#include "WindowsGame.h"

typedef int 인트;

// typedef A B;
// 이름 자료형 명칭
// A를 B라고 칭한다.

void Test()
{
    인트 a = 0;
}

// *중요* HINSTANCE : 인스턴스 자료구조
// -> instance : 작업 관리자 켰을 때 나오는 것.
// 
// ATOM : typedef WORD ATOM; = typedef unsigned short WORD; => 결과적으로 정수
//
// BOOL : typedef int BOOL;
// 
// LRESULT : typedef LONG_PTR LRESULT; -> typedef __int64 LONG_PTR; => 결과적으로 정수
//
// *중요* HWND : 작업관리자 세부, 윈도우 핸들
// 
// UINT : unsigned int
// WPARAM : unsigned _int64
// LPARAM : _int64
// LPWSTR : typedef WCHAR LPWSTR; typedef wchar_t WCHAR;
// 
// <WCHAR, char 차이>
// char : 멀티 바이트
// WCHAR : 유니코드
// 
// 아스키코드 -> 문자를 적으면 숫자로 변환해주는 코드
// 아스키코드 문제
// 영어가 아닌 다른 언어는 표시 할 수가 없음
// 아스키코드 (1바이트) (멀티바이트) 0 ~ 127
//  
// 멀티바이트 (아스키코드) : 1바이트로 표현할 수 있는 건 1바이트로 표현하고, 안되면 2바이트 넘게 쓰지 뭐..
// 
// 유니코드 (2바이트)
//  -> 모든 문자를 같은 바이트로 표기할 수 있게 하자 (최소 2바이트)
//  -> visual studio 기준, UTF-16이리는 것을 사용
// UTF-16, UTF-32 등등


// 원래 다른 언어를 표기 못함
// 멀티바이트 즉, 아스키코드만 존재했음
// 아스키코드의 개념이 확장되면서,
// 1바이트가 아닌 n바이트(멀티바이트)로 문자열을 표기할 수 있게 하자.
// 멀티바이트로 만들어진 프로그램이 되게 많아짐. (UTF-8)

// 유니코드는 그럼 왜 생겼나?
//  -> 멀티바이트로 하니까, 되게 복잡.
//  -> 어느나라에서는 한글로 읽어야하고, 어느나라에서는 중국어가 되고..
// 메모장 저장했을 때 종종 나오는 궭뷁*@#이딴거. <- 멀티바이트를 여러가지로 변환하다보니 생긴 문제

// 유니코드 << 이거로 모든 문자를 아크시코드처럼 정해두자
// 세계표준으로 나온 코드들
// 단,, 정하는 사람이 없어서 유니코드 종류가 되게 많음.
// [UTF-16, UTF-32, CP949] etc


// C 같은 경우에는 함수 하나당 return 값을 하나밖에 못 받음
// 함수에 매개변수로 return을 받을 수 있는 매개변수를 따로 주는 형식으로 채택.
// 그리고 return값을 함수의 성공유무로 많이 사용
// C형식에선..

// _In_         => 이 매개변수가 주입만 하고, return 값으론 사용 안 한다.
// _Out_        => 이 매개변수를 return값으로는 사용 한다.
// _In_Opt_     => 이 매개변수가 필수사항은 아니다. 일단 주입될 수 있게끔은 구상해둔거다 
// _In_Out_     => 이 변수가 주입도 하고, return값으로 사용도 한다.


#include <string>
using namespace std;

void main()
{
    인트 a = 0;
    char c = 'a';

    // 멀티바이트
    string mystr = "my string";

    // 유니코드
    wstring myWString = L"My Stirng";
    wchar_t myWChar[128] = L"asdfdsfs";
    
    //멀티바이트와 유니코드를 둘 다 지원하기 위해서 만들어진 문자 자료형
    // 유니코드가 정의된 경우와 안 된 경우 두가지 버전으로 정의되어 있음.
    TCHAR tChar[128];
    
    //_T는 속성이 멀티바이트로 되어 있으면 멀티바이트로 적용하고
    // 유니코드로 되어 있으면 유니코드로 적용한다.
    wstring myString2 = _T("dfsd"); // _T가 보라색으로 표시되는데 <매크로> 라는 뜻.
    
    // **** 우리 프로젝트는 최대한 _T를 사용하되, 기본적으로 유니코드를 사용 ****
  
}