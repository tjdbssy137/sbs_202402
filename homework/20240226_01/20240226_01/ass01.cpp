#include <iostream>
using namespace std;

//�ζ� ������
// 1) 1 ~ 45���� ���� array�� �����
// 2) array�� ���´�
// 3) ���� 7���� �̴´�
void main()
{
	int arr[45] = {};
	for (int i = 0; i < 45; i++)
	{
		arr[i] = i + 1;
	}

	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		int firstIndex = rand() % 45;
		int secondIndex = rand() % 45;

		int temp = arr[firstIndex];
		arr[firstIndex] = arr[secondIndex];
		arr[secondIndex] = temp;
	}

	cout << "�ζ� ��÷ ��ȣ��.. ";
	for (int i = 0; i < 7; i++)
	{
		cout << arr[rand() % 45] << " ";
	}
}