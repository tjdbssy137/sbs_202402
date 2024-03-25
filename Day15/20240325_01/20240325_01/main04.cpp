#include "pch.h"
#define Interface class

Interface IDoorOpener
{
public:
	virtual void OpenDoor() abstract;
};

Interface IDoorCloser
{
public:
	virtual void CloseDoor() abstract;
};

class Key : public IDoorOpener, IDoorCloser // ����� �ڷ� Ȯ�� �ʿ�
{
protected:// ��ӹ��� �ֵ��� ����� �� ����, ���� + ��ӹ��� �ָ� ���� ����
	string _name;
private: // ����ص� �̰� �� ��, ���θ� ���� ����
	//string _name;
public : // �ƹ��� ���� ����
	void SetName(string name)
	{
		_name = name;
	}
	void OpenDoor()
	{
		printf("[%s] ���� ���� �� �ߴ�\n", _name.c_str());
	}
	virtual void OpenDoor2()
	{
		printf("[%s] ���� ���� �� �ߴ�\n", _name.c_str());
	}
	void CloseDoor()
	{
		cout << "���� ���� ���ߴ�." << endl;
	}
};
// ��� ���� ( : public Ŭ������ )
class MasterKey : public Key
{
public:
	void OpenDoor()
	{
		
		printf("[%s] ���� ������\n", _name.c_str());
	}

	virtual void OpenDoor2() override // virtual�� �ᵵ ��, override�� ������ ��.
	{

		printf("[%s] ���� ������\n", _name.c_str());
	}

	void CloseDoor()
	{
		cout << "���� ���� ���ߴ�." << endl;
	}
};

//////////////// ////////////////

void main()
{
	// 2. Ŭ����
	// Ŭ������ �װ��� Ư¡
	// �߿��ѵ�, �ܿ�ű��� �ƴ�.

	// ���, ������, ĸ��ȭ, �߻�ȭ

	// Ŭ���� (��ü)
	// ����ü (������)

	// 1. ���
	// - �Լ��� ������ ��Ȱ�� �� �� �ִ�.
	{
		MasterKey* masterKey = new MasterKey();

		masterKey->SetName("������Ű");
		masterKey->OpenDoor();

		delete masterKey;
	}

	// 2. ������
	// - �θ� Ŭ������ �ڽ� Ŭ������ �������� ��
	//		=> �θ�Ŭ���� �ڷ������� �ڽ�Ŭ���� �Լ��� ȣ���� �� �ִ�.
	Key* key = new MasterKey();
	// MasterKey* masterKey = new Key(); // << �ȵ�
	key->SetName("������Ű2");
	key->OpenDoor2(); // �ڽ�Ŭ������ ������ �߾ ȣ���� �θ�(����) Ŭ���� �Լ��� ȣ��
	delete key;
	

	// 3. ĸ��ȭ
	// protected, private, public���� ������ ��
	// �⺻������ ������ �ܺο� ���� ��Ű�� �ʴ´�
	// Ŭ������ �⺻ ��Ģ
	// �ܺο� ���� ��Ű�� ������ ��ü � ������ �ֱ淡..
	// �� ���Ѱ� �����ϰ� ���⤩�� �� ��Ű�� ��?

	// Ŭ���� << �ϳ��� å���� ����ϴ� �ڷ���
	// Ŭ���� ���� ��
	// TimeManager >> �ð��� �������ִ� Ŭ����
	// �� ���κ������� ��Ʈ���� �ʿ䰡 ������?
	// �������� ������ private�� �ƿ� ������ ��Ű�� �ʴ´�
	// �ܺο����� �ܼ��ϰ�
	// ���� �ð�
	// ���� ������~ ���� ������ �ɸ��ð�


	// 4. �߻�ȭ
	// �ٸ� ������ interface��� ��
	// �߻�ȭ�� �Լ��� ����Ǿ� �ְ�, ���� ���Ǵ� �� �Ǿ��ִ� ����
	{
		Key* key1 = new Key();
		IDoorOpener* opener = key1;
		//key->SetKey();�� �� ��.
		opener->OpenDoor();

		IDoorCloser* closer = key1;
		closer->CloseDoor();
	}
	// interface���� ������ �͸� �ҷ��� �� ����.

}