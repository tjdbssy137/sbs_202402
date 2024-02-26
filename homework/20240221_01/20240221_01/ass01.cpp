#include <iostream>
using namespace std;

void printStar01() 
{
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	cout << "\n";
}

void printStar02()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - (i + 1); j++)
		{
			cout << " ";
		}
		for (int k = 0; k < i + 1; k++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	cout << "\n";
}

void printStar03()
{
	for (int i = 5; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	cout << "\n";
}

void printStar04()
{
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < i; j++) 
		{
			cout << " ";
		}
		for (int k = 0; k < 5 - i; k++) 
		{
			cout << "*";
		}
		cout << "\n";
	}
}
void main() 
{
	printStar01();
	printStar02();
	printStar03();
	printStar04();
}