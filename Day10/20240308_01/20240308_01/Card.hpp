//��������Ӱ� ���ÿ� CPP�����̱⵵��. ������ ������ ��� ����.
#pragma once

// Main ���� Test2.hpp�� �Լ��� �ҷ�����
// Test2.hpp�� �Լ������� Card.hpp�� �ҷ�����
// Card.hpp������ Test2.hpp�� �Լ��� �ʿ��ϸ�!
// => ������ �߻�
// �����ΰ� �� �� ��ġ�� ������ ������ ��.

// �׻� ���α׷��� ������ main�� �ִ� cpp���� ����.
// main02.cpp
// #include "test2.hpp" => pragma once, #include "Card.hpp" (Function ����) Function2 ����, Function3 ����
// #include "Card.hpp" => pragma once�� ����, �̹� �� �� ���� ������ ����

// Function1ȣ��
// => Card.hpp�� ����
// => Card.hpp ������ �����Ϸ��� ���ϱ�
//			Function3�� ȣ���ؾ���.
//			Function3�� ã�� ���� include�� ������ ��
//			"Test2.hpp"�� �������� �ϴ�, pragma once�� ���� �� �� �о��� ������ �����ϰ� ��.
//			�׷��� ��������� �� ��𿡵� ã�� �� ���⿡ ���带 �ϸ�, �ĺ��ڸ� ã�� �� ���ٰ� ��.

// �׷��� ��� 
// ���̵�.
// .h �� .cpp�� ���� ���� �� �˰� Ŀ���� �� �ִ� �ϴ� �� �ƴ϶�� .hpp�� ������� �ʱ�
// �׸��� �ｼ, ������� ������ ���� ����� ��.
// ����� ���漱���̳� �ڷ��� ����.

struct Card {
	int Index;
	void Print();
	void Swap(Card &another);
};
void Card::Print()
{
	//cout << Index;
}
void Card::Swap(Card &another)
{
	int temp = this->Index;
	this->Index = another.Index;
	another.Index = temp;
}