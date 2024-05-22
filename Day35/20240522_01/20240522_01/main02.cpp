#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	// C++ ½ºÅ¸ÀÏ
	// ifstream --> read
	// ofstream --> write
	
	if (false)
	{
		ofstream ofs;
		ofs.open("test2.txt");
		int a = 4;
		int b = 8;

		ofs << a;
		ofs << endl;
		ofs << b;
		ofs.close();
	}

	if(true)
	{
		ifstream ifs;
		ifs.open("test2.txt");
		int c;
		int d;
		ifs >> c;
		ifs >> d;
		ifs.close();
		cout << "c : " << c << endl;
		cout << "d : " << d << endl;
	}
}