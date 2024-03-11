#pragma once
#include <iostream>
#include <vector>
#include "LASutda.h"
#define CARD_MAX 20
using namespace std;

class CardGame
{
private:
	LASutda _card[CARD_MAX] = {};
	int _money = 1000;
	int _betMoney = 0;
	vector<int> _playerCard;
	vector<int> _computerCard;
	int _order = 0;
public:
	CardGame();
	~CardGame();
	void CardSetting();
	void ReceiveCard();
	void Betting();
	int CardPedigree(vector<int> _cards);
	void Result();
};

