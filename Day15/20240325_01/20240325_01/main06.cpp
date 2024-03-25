#include "pch.h"
#include "Defines.h"
class MySingleton
{
};

class GameManager
{
DECLARE_SINGLE(GameManager) // �ļ�
public:
	void GameStart()
	{
		cout << "������ �����մϴ�" << endl;
	}
};

/* // ���� ������ Ǯ��� �Ʒ���.
class GameManager
{
private:
	//������, �Ҹ��ڸ� ������ �ƴϸ� �� ����ϰ� private�� ����.
	GameManager() {}
	~GameManager() {}
public :
	static GameManager* GetInstance()
	{
		static GameManager gameManager;
		return &gameManager;
	}
	void GameStart()
	{
		cout << "������ �����մϴ�" << endl;
	}
};
*/

void Funtion()
{
	//static�� �� ���� �ʱ�ȭ �ǰ� �ٽ� ������ ���� �������� ����.
	// 10�� ȣ���ϸ� a�� ���� �Ź� 0���� �ʱ�ȭ ���� �ʰ� ������.
	static int a = 0;
	a++;
	cout << "a : " << a << endl;
}

void main()
{
	// �̱����̶�,
	// ���α׷����� �� �ϳ��� ��ü�� �����ϰ� ����� ����
	
	/*
	MySingleton* mySingleton = new MySingleton();
	MySingleton* mySingleton2 = new MySingleton();
	MySingleton* mySingleton3 = new MySingleton();
	MySingleton* mySingleton4 = new MySingleton();
	MySingleton* mySingleton5 = new MySingleton();
	*/

	// �̷��� ����� �ȴ�
	// ���α׷��Ӱ� ���ؼ� �� ���� ����� ������
	// ���������� �� ���� ����� ������ �� �� ������ �Ǽ��� ������ �� �����ϱ�.

	// GameManager ���� ������ �����ϴ� Ŭ������ ������ �־���� ������ ����.
	// GameManger�� �� �ϳ��� �����ϰ� �ϱ� ���� �̱��� ������ ����.
	// �ϴ� new�� ����ϸ� �� ��.

	for (int i = 0; i < 10; i++)
	{
		Funtion();
	}

	GameManager* gm = GameManager::GetInstance(); // ����
	

	// �̱����� ���������� ���� ����
	//�⺻������ ���������� ����ϴ� �� �� ���ٰ� ��.
	//�޸� �����̳� ���α׷��� �������� ����������..

	// <�޸� ����>
	// 1. �ڵ� ����
	// 2. �� ����
	// 3. ���� ����
	// 4. ������ ���� -> �뷮�� ����. (read�� ������, write�� ����)

	// GameManager�� ȣ���ϴ� ��
	// �ǰ� ���� ������ GameManager�� �����ϰ� ��.
	// ��𼭳� �� �� �ֱ⿡
	// ĸ��ȭ�� 100% �� �Ǿ� �ִ� �� �ƴ϶�� �ڵ尡 ���� ���ۿ�..
	
	// -> ���������� ���ڴ�
	// ���� �˾Ƽ� �� �����ϴ� �ڵ尡 ���� �ڵ��
	// ���̷����ϰԵ� ���������� ���꼺�� �÷���. (���ϱ� ������)

	// ������ �̱����� �� ���� ���Ӱ����� �� �� ����. ��
	// �̷��� �Ű� ���� ���� �̱��� ���� ���� ��.
}