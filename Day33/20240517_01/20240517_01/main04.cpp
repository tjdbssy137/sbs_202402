#include <iostream>
using namespace std;

void Function01()
{

}

class TestObject
{
public:
	void operator()(int a) {cout << "a : " << a << endl; }
};
void main()
{
	// �Լ� ������ �� �� ����? -> NO
	// Callable ���õ� �� �� ����.
	// Callable�̶�?
	//	-> () �����ڸ� ����ϴ� �� Callable�̶�� ��.
	Function01(); // callable
	// �Լ��� callable������
	// callable�� �Լ��� �ƴ�.
	
	TestObject obj;
	obj(3); // ��� �Լ��� �ƴ�. Callable�̱� ��. ()�� ���ϱ�.
	// -> obj.operator()(3);

	// �Ʒ��� ������ ��� ������..
	// C++20�� ���Ӱ� ���� Callable ȣ�� ���
	// �ô븶�� �� ������ �����鼭 �� �� �ִ� �������� �߰� ��.

	// 
}