#include <iostream>
#include <functional>
using namespace std;

void Run1()
{
	cout << "Run1()" << endl;
}

void Run2(int a)
{
	cout << "Run2() " << a << endl;
}

int Run3(int a)
{
	return a*2;
}

class TestObject 
{
public:
	void DoSomething();
};
void main()
{
	// C++20 ���� ����ϴ� ���
	// visual studio 2019, 2017 << ���⼭�� �� ��

	// �Լ������� ����
	// ��ȯ�ڷ��� ���ӽ����̽�::*������(�Ű�����) = ��;
	
	// function<��ȯ�ڷ���(�Ű�����)> ������ = ��;
	function<void()> myFunction = &Run1;
	myFunction();

	function<void(int)> myFunction2 = &Run2;
	myFunction2(3);

	function<int(int)> myFunction3 = &Run3;
	cout << "Run3() " << myFunction3(3) << endl;

	// Ŭ���� �Լ�
	function<void(TestObject&)> myFunction4 = &TestObject::DoSomething;
	TestObject t1;
	//TestObject t2;
	//TestObject t3;
	myFunction4(t1);
	
	// �� �˰� ������ function, bind, mem_fn�� �˻�
	// ������ ������ Ŭ���� �Լ� �ڵ�
	function<void()> myFunction5 = nullptr;
	// bind(���ε� ��ų �Լ�, �����ų object);
	myFunction5 = bind(&TestObject::DoSomething, &t1);
	myFunction5();
}