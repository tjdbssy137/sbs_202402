#include <iostream>
using namespace std;

int** ReturnReverseTemp(int inputArray[][4], int rows)
{
	int** temp = new int* [rows];
	
	for (int i = 0; i < rows; i++) {
		temp[i] = new int[4];
		for (int j = 0; j < 4; j++) {
			temp[i][j] = inputArray[j][i];
		}
	}

	return temp;
}


void main()
{
	int _array[4][4];
	for (int i = 0; i < 16; i++)
	{
		_array[i / 4][i % 4] = i + 1;
	}
	int** resultArray = ReturnReverseTemp(_array, 4);

	cout << "ReturnReverseTemp(_array, 4)" << endl;

	for (int i = 0; i < 16; i++)
	{
		cout << resultArray[i / 4][i % 4] << endl;
	}
	cout << "_array" << endl;
	for (int i = 0; i < 16; i++)
	{
		cout << _array[i / 4][i % 4] << endl;
	}
}