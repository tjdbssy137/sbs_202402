#pragma once
class NumberRectActor;
class NumberRectController
{
public:
	void Init(vector<NumberRectActor*> numberRects);
	void Update();
public:
	//void MoveNumberRect(int x, int y, MoveDirectionState _dirState);
private:
	vector<NumberRectActor*> _numberRects;

};

