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

// ������ �����ڵ�
// N����ŭ �ݺ�
// str1 ���ڿ� ���̿� str2 ���ڿ� ���̰�
// �ٸ� => false
// ���� => 
// str1[index] == str2[index]�� ��
// �ٸ� ���� �ִٸ� false ����
// ��ΰ� ���ٸ� true return
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
		cout << "�� ���ڿ��� �����ϴ�" << endl;
	}
	char* str3 = MyStrCat(str1, str2);
	cout << str3;
}