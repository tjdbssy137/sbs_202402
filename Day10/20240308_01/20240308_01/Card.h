//#pragma once
// �� ������ �� ���� �����ϰ� ����ڴ�. ��� �ڵ�.
// �� �ڵ带 ������� ������, ������ ���� error�� �� �� �ִ�.

//__CARD2_H__��� ��ũ�ΰ� ����Ǿ� ���� ������
#ifndef __CARD_H__
#define __CARD_H__
struct Card {
	int Index;
	void Print();
	void Swap(Card &another);
};

//���������� ������� �Ϸ��� extern Ű���带 �ٿ��� �Ѵ�.
// main�� �ִ� .cpp���Ͽ��� �� �� �� ������ ���־�� �Ѵ�.
extern int _a; //�ٸ� ���Ͽ����� _a��� ������ ����ϰڴٴ� ��.
// main �Լ����� ���� ���� >> int _a;
int _b;// include�� �ϴ��� �ٸ� ���Ͽ��� ��� �Ұ�.

//__CARD2_H__�� ���� �Ѵ�.
#endif // !__CARD2_H__
// �̷��� �ϹǷμ�, ��������� ������ �� ���� include�ȴ�. ��� ȿ���� ���� �� ����.

//������ 
#ifndef __CARD_H__
#define __CARD_H__
#endif // !__CARD_H__
//�� ���� �� ���ŷο�
// =>> #pragma once �̰� �� �ذ� å!!
// #pragma once�� �� ���� ���� �� ���� include��.


/*
#ifdef __CARD2_H__ // ������ �Ǿ� ������ �Ʒ� main�� ����
void main() {

}
#endif // __CARD2_H__

*/