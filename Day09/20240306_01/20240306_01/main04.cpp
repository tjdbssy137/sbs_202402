#include <iostream>
#include <string>
using namespace std;

void main()
{
	char str1[128] = "hello World!"; // 교수 취향
	string str2 = "hello world!!"; // 현업 사용은 string

	cout << str1 << endl;
	cout << str2 << endl;

	string str3 = "Hello world!!";

	if (str2 == str3)
	{
		cout << "same" << endl;
	}
	else
	{
		cout << "not same" << endl;
	}

	// 문자열 입력
	string str4;
	cout << "str4에 들어갈 문장을 입력 >> ";
	getline(cin, str4);// space bar 공백도 쓸 수 있음.
	//cin은 띄어쓰기 기준으로 문장이 썰림.
	cout << "str4 : " << str4 << endl;

	cin.ignore();
	string str5;
	cout << "str5에 들어갈 문장을 입력 >> ";
	cin >> str5; // ?? what?
	cout << "str5 : " << str5 << endl;

	
	// getline은 line단위로 받는다
	// cin.ignore()은 방어코드
	// 엔터 -> \n
	// 사실 엔터는 -> \r\n임.

	// CRLF => 엔터를 \r\n로 취급하겠다. (주로 Window)
	// CR => 엔터를 \r로 취급하겠다. (주로 Mac)
	// LF => 엔터를 \n로 취급하겠다. (주로 Linux)

	// cin 문자열 할 다음 엔터를 치면 \r 여기까지만 받아지고 버퍼에는 \n은 버퍼에 남음
	// 안 버리면 다음 cin에 들어감
	// 그 버퍼를 버려주는 함수는 cin.ignore();사용
}