#include <iostream>
using namespace std;

void main()
{
	// ������ - 2
	// &�� *�� ����

	// ������ = �迭
	// �����ϰ� �����ڸ� ���� �ٸ�.
	
	int arr[5] = {};
	arr[0] = 1;
	arr[4] = 4;
	cout << arr << endl;

	int* ptr = arr; // �迭 �༼ �����ϰ� ��.
	cout << ptr << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << *(ptr + i) << " ";
	}

	int arr2[10][10] = { {1, 7}, };
	int(*ptr2)[10] = arr2;
	cout << "\n{0, 0} : " << *(*ptr2 + 0) 
		<< "\n{0, 1} : " << *((*ptr2 + 0) + 1) << endl;
	
	int value = 3;
	int* ptr3 = &value; // ptr3�� value�� �ּҰ��� ���´�. (ptr3�� �ּҴ� ���� �ִ�)
	int* ptr3_1 = &value; // ptr3_1�� value�� �ּҰ��� ���´�. (ptr3�� ptr3_1�� �ּҴ� �ٸ���)
	int** ptr4 = &ptr3; // ptr4�� ptr3�� �ּҰ��� ���´�.
	// ������ �� �������� ���� �ڷ����� ����Ű�� �ּҰ�.
	// ptr4 = ptr3 = value ���� ��. ���� �ϳ��� �����ص� �� ���� ����.
}