#pragma once
class MainGame
{
private:
	int _money = 1000;
	// ������ �����ϸ� ���� �̰���.
public :
	MainGame(); // ������	new�� �� ����(���� ���� 1��)
	~MainGame(); // �Ҹ���	delete�� �� ����(���� ���� 1��)
	void Bet();
};

