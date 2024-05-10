#include "pch.h"
#include "Game2048Controller.h"
#include "NumberBlockActor.h"

void Game2048Controller::Init(vector<NumberBlockActor*> numberBlocks)
{
	_numberBlocks = numberBlocks;
}
void Game2048Controller::Update()
{
	{
		if (Input->GetKeyDown(KeyCode::Down))
		{
			_numberBlocks[0]->SetPos(Vector2(_numberBlocks[0]->GetPos().x, _numberBlocks[0]->GetPos().y + 100));
			_numberBlocks[1]->SetPos(Vector2(_numberBlocks[0]->GetPos().x, _numberBlocks[1]->GetPos().y + 100));

		}else if (Input->GetKeyDown(KeyCode::Up))
		{
			_numberBlocks[0]->SetPos(Vector2(_numberBlocks[0]->GetPos().x, _numberBlocks[0]->GetPos().y - 100));
			_numberBlocks[1]->SetPos(Vector2(_numberBlocks[0]->GetPos().x, _numberBlocks[1]->GetPos().y - 100));
		}
		else if (Input->GetKeyDown(KeyCode::Left))
		{
			_numberBlocks[0]->SetPos(Vector2(_numberBlocks[0]->GetPos().x - 100, _numberBlocks[0]->GetPos().y));
			_numberBlocks[1]->SetPos(Vector2(_numberBlocks[0]->GetPos().x - 100, _numberBlocks[1]->GetPos().y));
		}
		else if (Input->GetKeyDown(KeyCode::Right))
		{
			_numberBlocks[0]->SetPos(Vector2(_numberBlocks[0]->GetPos().x + 100, _numberBlocks[0]->GetPos().y));
			_numberBlocks[1]->SetPos(Vector2(_numberBlocks[0]->GetPos().x + 100, _numberBlocks[1]->GetPos().y));
		}
	}
}