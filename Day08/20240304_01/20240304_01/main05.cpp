#include <iostream>
using namespace std;

void CallByValue(int value);
void CallByReference(int& value2);
void CallByAddress(int* value3); //����
void main()
{
	//�Լ� ȣ���ϴ� �뵵�� ���
	cout << "CallByValue()" << endl;
	int value = 4;
	CallByValue(value);
	{
		// ���Ӱ� �޸𸮰� �߰��� �߻�.
		int _value = value;
		{
			_value++;
			cout << "main func value : " << _value << endl;
		}
	}
	cout << "main value : " << value << endl;


	cout << "\nCallByReference()" << endl;
	CallByReference(value);
	{
		// �ڷ��� �� &�� ����ϸ� ���Ӱ� �޸𸮰� �߰��� �߻����� ����.
		// �����Ѵ�.
		int& value2 = value;
		{
			value2++;
			cout << "main func value2 : " << value2 << endl;
		}
	}
	cout << "main & value2 : " << value << endl;


	cout << "\nCallByAddress()" << endl;
	CallByAddress(&value); //�ּҸ� ����
	{
		int* value3 = &value;
		{
			//value3�� �ּҰ�.
			//��, �ּҰ��� ������ ���� ++�� �ؾ���.
			(*value3)++;//��ȣ ���� �߿�
			cout << "main func value3 : " << *value3 << endl;
		}
	}
	cout << "main * value3 : " << value << endl;
}
void CallByValue(int _value)
{
	_value++;
	cout << "func value : " << _value << endl;
}

void CallByReference(int& value2)
{
	value2++;
	cout << "func value2 : " << value2 << endl;
}

void CallByAddress(int* value3)
{
	//value3�� �ּҰ�.
	//��, �ּҰ��� ������ ���� ++�� �ؾ���.
	(*value3)++;//��ȣ ���� �߿�
	cout << "func value3 : " << *value3 << endl;
}