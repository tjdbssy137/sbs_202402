#pragma once
#include "Card.h"
#include <iostream>
#include <vector>
using namespace std;
#define CARD_MAX 52
#define CARD_SUM 21
class BlackJack
{
private:
	int _money = 1000;
	int _bettingMoney = 0;
	int _order = 0;
	Card _card[CARD_MAX] = {};
	vector<int> _playerCard;
	vector<int> _computerCard;
	int _playerCardSum = 0;
	int _computerCardSum = 0;
public:
	BlackJack();
	~BlackJack();
	void CardSetting();
	void BettingMoney();
	void ReceivePlayerCard();
	void ReceiveComputerCard();
	void Result();
	void Organize();
};

