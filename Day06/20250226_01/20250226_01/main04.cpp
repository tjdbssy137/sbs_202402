#include <iostream>
using namespace std;

void main()
{
	// ����, swap
	int a = 3;
	int b = 5;

	int temp = a;
	a = b;
	b = temp;

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;

	// �ǽ�
	// �ζǻ�����
	// 1) 1 ~ 45���� ���� array�� �����
	// 2) array�� ���´�
	// 3) ���� 7���� �̴´�

	// A, B ������ 100000�� �ϸ� �����̴�
	int arr[100] = {};
	for (int i = 0; i < 100; i++)
	{
		arr[i] = i;
	}
	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		// ���� �� �Ǹ� �ϴ� �ܿ��
		// A, B�� 100000�� swap�Ұǵ�
		// A, B�� ���� ������
		// Random index
		
		int firstIndex = rand() % 100; //arr���� �ȿ��� ����
		int SecondIndex = rand() % 100;

		int temp = arr[firstIndex];
		arr[firstIndex] = arr[SecondIndex];
		arr[SecondIndex] = temp;
		//�ƹ��� �ص� ���ڰ� �ߺ��Ǵ� ���� ����.
	}
	for (int i = 0; i < 100; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}

	// homework
	// 1) ���������� �ϳ� ����(�迭���)
	// 2) �ζǻ�����
	// 3) 21�� ���� ��ȭ����
}