#include <iostream>
using namespace std;

int Add(int num1, int num2)
{
	return num1 + num2;
}
int Subtract(int num1, int num2)
{
	return num1 - num2;
}
int Multiply(int num1, int num2)
{
	return num1 * num2;
}
int Divide(int num1, int num2)
{
	return num1 / num2;
}

void main()
{
	//함수
	// 함수의 형태
	// 반환자료형 함수명(매개변수(들)){}
	// void		 PrintHand(int Hand){}
	//함수명으로 이름을 짓고, 매개변수로 함수의 옵션을 줄 수 있다.
	
	// 반환값 return Value

	// 실습
	// 계산기에 쓰이는 함수를 제작
	// Add
	// Subtract
	// Multiply
	// Divide
	
	cout << "Add(2, 4) : " << Add(2, 4) << endl;
	cout << "Subtract(11, 123) : " << Subtract(11, 123) << endl;
	cout << "Multiply(19, 19) : " << Multiply(19, 19) << endl;
	cout << "Divide(6, 3) : " << Divide(6, 3) << endl;
	
	// 혹은 
	// int temp = Add(2, 4);
	// cout << << "Add(2, 4) : " << temp;
}