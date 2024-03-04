#include <iostream>
#include <vector>
using namespace std;

// ������(���̹� ��Ģ) �빮�ڷ� ���� (Pascal Case)
// �Լ��� �빮��
// define�� ���� �빮��
// �������� �ҹ���


struct Student // �ϳ��� �ڷ��� �ȿ� ���� ���� ���� ����ų �� �ִ�.
{
	// �빮�ڷ� ����(Pascal Case)
	int English;
	int Math;
	int Korean;
};

void main()
{
	// ����ü
	// ��������, �ڷ���

	// �ڷ��� ����
	
	// �⺻ �ڷ���
	//	- C++ �������� �⺻������ �������ִ� �ڷ���
	// ����� ���� �ڷ���
	//	- ����ڰ� �ʿ��ؼ� Ŀ�����ؼ� ����� �ϴ� �ڷ���
	//	- ����ü�� ���⿡ ����
	//	- enum

	// ����ü�� ���� ���ϴ� �����ͼ��� ���� �� �ִ�.
	
	Student student = {};
	student.English = 90;
	student.Math = 89;
	student.Korean = 80;
	// �ϳ��� �ڷ��� �ȿ� ���� ���� ���� ����ų �� �ִ�.

	vector<Student> students;
	//students.push_back(student);

	//�ǽ�
	// 10���� �л� ���� �����͸� ���� ����Ʈ�� ���� (��������� ���� ������) ���.

	srand(time(NULL));


	int sum[10] = {};
	for (int i = 0; i < 10; i++)
	{
		Student student = {};
		student.English = rand() % 101;
		student.Math = rand() % 101;
		student.Korean = rand() % 101;
		sum[i] = (student.English + student.Math + student.Korean)/3;
		students.push_back(student);
	}

	vector<int> list;
	vector<int> temp;
	list.push_back(sum[0]);
	for (int i = 1; i < 10; i++)
	{
		if (sum[i - 1] < sum[i])
		{
			while (list.size() > 0)
			{
				int a = list[list.size() - 1];
				list.pop_back();
				temp.push_back(a);
			}
			list.push_back(sum[i]);
			while (temp.size() > 0)
			{
				int a = temp[temp.size() - 1];
				temp.pop_back();
				list.push_back(a);
			}
		}
	}
/*
	for (int i = 0; i < 10; i++)
	{
		cout << list[i] << endl;
	}
*/


	for (int i = 0; i < 10; i++)
	{
		cout << "students[" << i << "].English : " << students[i].English << endl;
		cout << "students[" << i << "].Math : " << students[i].Math << endl;
		cout << "students[" << i << "].Korean : " << students[i].Korean << endl;
		cout << endl;
	}
	
}