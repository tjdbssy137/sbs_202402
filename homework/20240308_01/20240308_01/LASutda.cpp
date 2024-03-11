#include "LASutda.h"
#include <iostream>
#include <vector>
using namespace std;

void LASutda::Print()
{
	switch (Index / 10)
	{
	case 0:
		cout << "¢»"; // 0 1 2 3 4 5 6 7 8 9
		break;
	case 1:
		cout << "¡ß"; // 10 11 12 13 14 15 16 17 18 19
		break;
	}
	switch (Index % 10 + 1)
	{
	case 1:
		cout << " A ";
		break;
	default:
		printf(" %d ", Index % 10 + 1);
		break;
	}
}

void LASutda::Swap(LASutda& another)
{
	int temp = this->Index;
	this->Index = another.Index;
	another.Index = temp;

}