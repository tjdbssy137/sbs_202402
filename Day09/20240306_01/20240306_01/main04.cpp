#include <iostream>
#include <string>
using namespace std;

void main()
{
	char str1[128] = "hello World!"; // ���� ����
	string str2 = "hello world!!"; // ���� ����� string

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

	// ���ڿ� �Է�
	string str4;
	cout << "str4�� �� ������ �Է� >> ";
	getline(cin, str4);// space bar ���鵵 �� �� ����.
	//cin�� ���� �������� ������ �串.
	cout << "str4 : " << str4 << endl;

	cin.ignore();
	string str5;
	cout << "str5�� �� ������ �Է� >> ";
	cin >> str5; // ?? what?
	cout << "str5 : " << str5 << endl;

	
	// getline�� line������ �޴´�
	// cin.ignore()�� ����ڵ�
	// ���� -> \n
	// ��� ���ʹ� -> \r\n��.

	// CRLF => ���͸� \r\n�� ����ϰڴ�. (�ַ� Window)
	// CR => ���͸� \r�� ����ϰڴ�. (�ַ� Mac)
	// LF => ���͸� \n�� ����ϰڴ�. (�ַ� Linux)

	// cin ���ڿ� �� ���� ���͸� ġ�� \r ��������� �޾����� ���ۿ��� \n�� ���ۿ� ����
	// �� ������ ���� cin�� ��
	// �� ���۸� �����ִ� �Լ��� cin.ignore();���
}