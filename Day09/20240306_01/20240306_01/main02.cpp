#include <iostream>
using namespace std;

void main()
{
	char c = 'a'; // ������
	cout <<"c : "<< c << endl;

	char c1 = 65;
	// ascii code
 	// programming���� ���ص� ���� �Ծ�
	cout << "c1 : " << c1 << endl;

	char str1[128] = "orange";
	cout << str1 << endl;

	char str2[128] = "orange";
	cout << str2 << endl;

	// �迭 = ������
	// ���ڿ��� �ܼ��� == ���� ���ϸ� �ּҰ����� ���ϴ� ���̴�.
	// * �� �ٿ��� ���ϸ� �� �ձ��ڸ� ���ϰ� �ȴ�.

	// ���ڿ� �� �ϴ� �� -> 
	if (strcmp(str1, str2) == 0) // strcmp : string compare
	{
		cout << "same" <<endl;
	}
	//-1, 0, 1
	// -1 : str1�� ���� ���������� �� �տ� �ִ�.
	// 0 : ����
	// 1 : str2�� ���� ���������� �� �տ� �ִ�.

	char str3[5] = "abcd";
	// "" => ���ڿ��� �ǹ�.
	// ���ڿ��� �������� NULL���� ����.
	// �׷��Ƿ� �� ĭ�� �׻� Ȯ���ؾ��Ѵ�.
	// ���� ��ǻ�ʹ� �޸� ���� �� �ص� ��.
	
	//strcmp
	for (int i = 0; i < sizeof(str1) / sizeof(char); i++)
	{
		if (str1[i] != str2[i])
		{
			cout << "�� ���ڿ��� ���� �ʽ��ϴ�.";
			break;
		}
		if (str1[i] == NULL && str2[i] == NULL)
		{
			cout << "�� ���ڿ��� �����ϴ�.";
			break;
		}
	}

}