#include <iostream>
using namespace std;

#define MY_NUMBER = //��ũ��
#define ARRAY_SIZE 100 //��ũ��
#define ADD(a, b) a + b //��ũ��
#define ADD_AND_PRINT(a, b) printf("ADD start : %d, %d\n", a, b); \
                            printf("ADD Result : %d\n", a + b);
// "\" <- �����ؼ� ���� �ٱ��� ���ڴٴ� ��


void main()
{
	//��ũ��
	//c++���� �����ϴ� ����
	// ����
	// �빮�ڷ� ���� �� �⺻.

	int a MY_NUMBER 3; //MY_NUMBER�� = �� ������ ����
	
	int b = ADD(5, 12);
	cout << "b = " << b << endl;

	int arr[ARRAY_SIZE] = {  };
	
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		arr[i] = i + 1;
	}
	cout << a;
}