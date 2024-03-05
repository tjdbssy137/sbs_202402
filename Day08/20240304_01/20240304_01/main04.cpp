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
	/*
	Student student = {};
	student.English = 90;
	student.Math = 89;
	student.Korean = 80;
	*/
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
		sum[i] = (student.English + student.Math + student.Korean) / 3;
		students.push_back(student);
	}

	vector<int> list;
	vector<int> temp;
	list.push_back(sum[0]);
	for (int i = 1; i < 10; i++)
	{
		list.push_back(sum[i]);
		for (int j = 0; j < i; j++)
		{
			if (list.at(j) < sum[i])
			{
				int temp = list.at(i);
				list.at(i) = list.at(j);
				list.at(j) = temp;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (sum[j] == list.at(i))
			{
				cout << i+1 << "�� �л��� " << j+1 << "�� �л��Դϴ�." << endl;
				cout << j + 1 << "�� English ���� : " << students[j].English << endl;
				cout << j + 1 << "�� Math ���� : " << students[j].Math << endl;
				cout << j + 1 << "�� Korean ���� : " << students[j].Korean << endl;
				cout << j + 1 << "�� ��� ���� : " << list.at(i) << endl;
				cout << endl;
			}
		}
	}
}