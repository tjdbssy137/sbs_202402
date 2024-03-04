#include <iostream>
using namespace std;

void CallByValue(int value);
void CallByReference(int& value2);
void CallByAddress(int* value3); //비추
void main()
{
	//함수 호출하는 용도로 사용
	cout << "CallByValue()" << endl;
	int value = 4;
	CallByValue(value);
	{
		// 새롭게 메모리가 추가로 발생.
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
		// 자료형 뒤 &를 사용하면 새롭게 메모리가 추가로 발생하지 않음.
		// 참조한다.
		int& value2 = value;
		{
			value2++;
			cout << "main func value2 : " << value2 << endl;
		}
	}
	cout << "main & value2 : " << value << endl;


	cout << "\nCallByAddress()" << endl;
	CallByAddress(&value); //주소를 보냄
	{
		int* value3 = &value;
		{
			//value3는 주소값.
			//즉, 주소값의 값으로 가서 ++를 해야함.
			(*value3)++;//괄호 순서 중요
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
	//value3는 주소값.
	//즉, 주소값의 값으로 가서 ++를 해야함.
	(*value3)++;//괄호 순서 중요
	cout << "func value3 : " << *value3 << endl;
}