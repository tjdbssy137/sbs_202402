#include "pch.h"

void Comment01()
{
	// 1. Event ��� => Event Design Pattern
	//	- ���. ��, ���������� => ���ӵ��� �������� �� �̷� ������ �ϴϱ� ���ϴ���~ �ϴ� �ڵ� �ۼ� ���
	//
	//	- Event ������ ���� << Event�� ���𰡸� �ٷ�ϱ� ���� ���ϴ���
	
	// -----------------------------------------------------------------
	// Observer ���� 
	
	//	- Ư�� ���Ը� �����ϰ� �ִٰ�, �� ��ü�� ����Ǹ� �˷��ִ� ����
	// MyClass a;
	// a.AddListen(&OnListen_AValueChanged);
	// a.SetChangeValue(10);
	// Ư���Լ� ȣ��� (ex. OnListen_AValueChanged)
	// void OnListen_AValueChanged(){}

	// �����ϰ�, a ��ü�� OnListen_AValueChanged �Լ� �����͸� �������ְ�
	// SetChagneValue��� �Լ��� ȣ��Ǹ�, OnListen_AValueChanged�� ���� ȣ��ǰԲ� ������ �ش�.
	// -----------------------------------------------------------------

	// �׷���
	// Observer ������ ����
	//	- �ʱ�ȭ ������, ��� ������ �帧�� �ľ��� �� �ִ�.
	
	// �ʱ�ȭ�� : 
	// MyClass a;
	// a.AddListen(&OnListen_AValueChanged);

	// �ֿ� ���� : 
	// a.SetChangeValue(10);

	// <Observer ������ ����>
	// �ʱ�ȭ�� : 
	// User user;
	// user.AddListen(&OnListen_AValueChanged);

	// �ֿ� ���� : 
	// user.SetChangeValue(item);

	// <Observer ������ �̻���>
	// �ʱ�ȭ�� : 
	// User user;

	// �ֿ� ���� :
	// user.AddItem(item); 
	// AddLog(user, item);

	//-> �ֿ� ������ �ѵ����� �ƴ�
	//-> �������� ���� �ڵ�, ���̿� �ڵ� ��� �ǰ� ����.

	// Observer ������ ����
	//	- �ڵ� �����庮�� �� ����.
	//		- �Լ������͸� ����ϱ� ������..

}
void Comment02()
{

}
void Comment03()
{

}
