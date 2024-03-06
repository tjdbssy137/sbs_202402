#include <iostream>
using namespace std;

void main()
{
	char c = 'a'; // 정수형
	cout <<"c : "<< c << endl;

	char c1 = 65;
	// ascii code
 	// programming에서 정해둔 문자 규약
	cout << "c1 : " << c1 << endl;

	char str1[128] = "orange";
	cout << str1 << endl;

	char str2[128] = "orange";
	cout << str2 << endl;

	// 배열 = 포인터
	// 문자열을 단순히 == 으로 비교하면 주소값으로 비교하는 것이다.
	// * 을 붙여서 비교하면 맨 앞글자만 비교하게 된다.

	// 문자열 비교 하는 법 -> 
	if (strcmp(str1, str2) == 0) // strcmp : string compare
	{
		cout << "same" <<endl;
	}
	//-1, 0, 1
	// -1 : str1의 값이 사전순으로 더 앞에 있다.
	// 0 : 같다
	// 1 : str2의 값이 사전순으로 더 앞에 있다.

	char str3[5] = "abcd";
	// "" => 문자열을 의미.
	// 문자열의 마지막엔 NULL값이 있음.
	// 그러므로 한 칸을 항상 확보해야한다.
	// 요즘 컴퓨터는 메모리 걱정 안 해도 됨.
	
	//strcmp
	for (int i = 0; i < sizeof(str1) / sizeof(char); i++)
	{
		if (str1[i] != str2[i])
		{
			cout << "두 문자열은 같지 않습니다.";
			break;
		}
		if (str1[i] == NULL && str2[i] == NULL)
		{
			cout << "두 문자열은 같습니다.";
			break;
		}
	}

}