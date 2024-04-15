#include "pch.h"
#include "WhacAMole.h"
#include "MoleActor.h"
#include "MoleHouseActor.h"
#include "HammerActor.h"

void WhacAMole::Init()
{
	Super::Init();
	{
		{//�δ��� ��
			for (int i = 1; i <= 3; i++)
			{
				for (int j = 1; j <= 4; j++)
				{
					MoleHouseActor* moleHouse = new MoleHouseActor();
					moleHouse->Init();
					moleHouse->SetName("moleHouse");
					moleHouse->SetBody(CenterRect(Vector2(200 + (j * 120), 150 + (i * 120)), 100, 100));
					_moleHouse.push_back(moleHouse);
					this->SpawnActor(_moleHouse.back());
				}
			}
		}

		{//�δ���
			for (int i = 1; i <= 3; i++)
			{
				for (int j = 1; j <= 4; j++)
				{
					MoleActor* mole = new MoleActor();
					mole->Init();
					mole->SetName("mole");
					mole->SetBody(CenterRect(Vector2(200 + (j * 120), 150 + (i * 120)), 100, 100));
					_mole.push_back(mole);
					this->SpawnActor(_mole.back());
				}
			}
		}

		{//��ġ
			_hammer = new HammerActor();
			_hammer->Init();
			_hammer->SetName("hammer");
			this->SpawnActor(_hammer);
		}
	}
	srand(time(NULL));
}
void WhacAMole::Render(HDC hdc) {
	Super::Render(hdc);
	wstring str = L"WhacAMole";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

	wstring pointStr = format(L"Caught Mole : {0}", _point);
	::TextOut(hdc, 0, 70, pointStr.c_str(), pointStr.length());
}
void WhacAMole::Update()
{
	Super::Update();

	_time += Time->GetDeltaTime();
	if (0.5f < _time)
	{
		//���ʵڿ����������
		//�δ��� ����� ����� �������ŭ �����ϰ� collider�� 0,0,0,0 ���� ����ų� ontriggerenter�� ���� �Լ��� �����.
		//���� �̻���? �˾Ƽ� ��ħ�� ��ġ����.
		int random = rand() % 12;
		_mole[random]->MoleGetsBigger(_mole[random]->GetBody().ToRect());

		if (0.9f < _time)
		{
			_mole[random]->MoleGetsSmaller(_mole[random]->GetBody().ToRect());
			_time = 0;
		}
	}

}
void WhacAMole::Release()
{
	Super::Release();
}