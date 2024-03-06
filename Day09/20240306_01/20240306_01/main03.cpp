#include <iostream>
using namespace std;

int MyStrlen(char* str)
{
	int index = 0;
	while (true)
	{
		if (str[index] != '\0')
		{
			index++;
		}
		else 
		{
			return index;
		}
	}
}

// 비교조건 수도코드
// N번만큼 반복
// str1 문자열 길이와 str2 문자열 길이가
// 다름 => false
// 같음 => 
// str1[index] == str2[index]를 비교
// 다른 것이 있다면 false 리턴
// 모두가 같다면 true return
bool MyStrCmp(char *str1, char *str2)
{
	int s1Length = MyStrlen(str1);
	int s2Length = MyStrlen(str2);

	if(s1Length == s2Length)
	{
		for (int i = 0; i < s1Length; i++)
		{
			if (str1[i] != str2[i])
			{
				return 1;
			}
		}
	}
	else 
	{
		return 1;
	}
	return 0;
}

char* MyStrCat(char* str1, char* str2)
{
	int s1Length = MyStrlen(str1);
	int s2Length = MyStrlen(str2);
	
	for (int i = 0; i < s2Length; i++)
	{
		str1[s1Length + i] = str2[i];
	}
	/*
	char _string[128] = {};
	char* temp = _string;

	int j = 0;
	for (int i = 0; i < s1Length; i++)
	{
		temp[i] = str1[i];
		j++;
	}
	for (int i = 0; i < s2Length; i++)
	{
		temp[i + j] = str2[i];
	}
	temp[s1Length + s2Length+1] = '\0';
	*/
	str1[s1Length + s2Length] = '\0';
	return str1;
}

void main(){
	
	char str1[128] = "Hello World!";
	char str2[128] = "Hello World!";

	if (MyStrCmp(str1, str2) == 0)
	{
		cout << "두 문자열은 같습니다" << endl;
	}
	char* str3 = MyStrCat(str1, str2);
	cout << str3;
}