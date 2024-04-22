#include "pch.h"
#include "WhacAMole.h"
#include "SpriteActor.h"
#include "BoxCollider.h"
#include "MoleActor.h"
#include "HammerActor.h"
#include "BackgroundActor.h"
void WhacAMole::Init()
{
	Super::Init();

	{
		_background = new BackgroundActor();
		_background->Init();
		this->SpawnActor(_background);
	}
	
	{
		int a = 0;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				MoleActor* mole = new MoleActor();
				mole->Init();
				//mole->SetBody(CenterRect(Vector2(i * 560 + 410, j * 210 + 60), 20, 30));
				//_savedPos.push_back(CenterRect(Vector2(i * 560 + 410, j * 210 + 60), 20, 30));
				_mole.push_back(mole);
				this->SpawnActor(_mole.back());
				_mole[a]->GetMolePos(Shape::MakeCenterRect(i * 560 + 410, j * 210 + 60, 20, 30));
				a++;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			MoleActor* mole = new MoleActor();
			mole->Init();
			//mole->SetBody(CenterRect(Vector2(700, i * 210 + 160), 20, 30));
			//_savedPos.push_back(CenterRect(Vector2(700, i * 210 + 160), 20, 30));
			_mole.push_back(mole);
			this->SpawnActor(_mole.back());
			_mole[a]->GetMolePos(CenterRect(Vector2(700, i * 210 + 160), 20, 30));
			a++;
		}
	}

	{
		_hammer = new HammerActor();
		_hammer->Init();
		this->SpawnActor(_hammer);
	}

}
void WhacAMole::Render(HDC hdc) {
	Super::Render(hdc);

	wstring str = L"WhacAMole";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
	
}
void WhacAMole::Update()
{
	Super::Update();
	_time += Time->GetDeltaTime();

	MoleAppears();
}
void WhacAMole::Release()
{
	Super::Release();
}

void WhacAMole::MoleAppears()
{	
	if (2 < _time)
	{
		cout << "ihi" << endl;
		int random = Random->GetRandomInt(0, 7);//8°³
		_mole[random]->MoleAppears();
		_time = 0;
	}
}