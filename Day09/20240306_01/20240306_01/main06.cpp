#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void main()
{
	// �ֿܼ����� ���� ����̰�
	// �ܼ��� �ٷ�� �� �����ϵ� �� ����
	// �ܼ� ���� ��.
	// ���� �� �Ǹ� �� �ص� ��.

	int oldGameTime = GetTickCount64(); // ���� ���� �ð��� ����Ѵ�. (0��)
	//GetTickCount() => ������ �����ϰ� �� ms�� ��������?
	
	while (true)
	{
		// 1�ʿ� �� ����
		int currentGameTime = GetTickCount64();
		if (1000 < currentGameTime - oldGameTime)
		{
			//system("cls");
			cout << "1�ʰ� �������ϴ�." << endl;
			oldGameTime = currentGameTime;
		}
	}
	// 2D �ִϸ��̼�
	// �̹��� �������� ü���� �ϴ� �������� �ִϸ��̼��� �ִµ�
	// �� �˰����� ���� ��.
}