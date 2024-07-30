#include "pch.h"
#include "TowerDefensePanel.h"
#include "Label.h"
void TowerDefensePanel::Init()
{
	Super::Init();

	{
		_defaultLabel = new Label();
		_defaultLabel->Init();
		_defaultLabel->SetRect(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 300, 50));
		_defaultLabel->SetFont(L"�����ٴ�ü", 18);
		_defaultLabel->SetAlign(TA_CENTER);
		_defaultLabel->SetText(L"");

		this->AddChild(_defaultLabel);
	}

	{
		_gameInfoLabel = new Label();
		_gameInfoLabel->Init();
		_gameInfoLabel->SetRect(Shape::MakeCenterRectLTWH(20, WIN_SIZE_X / 2 - 600, 200, 100));
		_gameInfoLabel->SetFont(L"�����ٴ�ü", 20);
		_gameInfoLabel->SetAlign(TA_LEFT);
		_gameInfoLabel->SetText(L"");

		this->AddChild(_gameInfoLabel);
	}

	{
		_infoLabel = new Label();
		_infoLabel->Init();
		_infoLabel->SetRect(Shape::MakeCenterRectLTWH(WIN_SIZE_X / 2 + 450, WIN_SIZE_Y / 2, 200, 300));
		_infoLabel->SetFont(L"�����ٴ�ü", 15);
		_infoLabel->SetAlign(TA_CENTER);
		_infoLabel->SetText(L"");

		this->AddChild(_infoLabel);
	}

	// Add Event
	Events->AddEvent("InstallInfo", new GameEvent<BehicleData, float>());
	Events->GetEvent<BehicleData, float>("InstallInfo")
		->AddListen(this, &TowerDefensePanel::SetInstallInfoText);

	// Add Event
	Events->AddEvent("UpgradeInfo", new GameEvent<BehicleData, float>());
	Events->GetEvent<BehicleData, float>("UpgradeInfo")
		->AddListen(this, &TowerDefensePanel::SetUpgradeInfoText);

	// Add Event
	Events->AddEvent("DeleteInfo", new GameEvent<BehicleData, float>());
	Events->GetEvent<BehicleData, float>("DeleteInfo")
		->AddListen(this, &TowerDefensePanel::SetDeleteInfoText);

}
void TowerDefensePanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void TowerDefensePanel::Update()
{
	Super::Update();

	if (0 < _textTimer)
	{
		_textTimer -= Time->GetDeltaTime();
		if (_textTimer <= 0)
		{
			_label->SetText(L"");
		}
	}
}
void TowerDefensePanel::Release()
{
	Super::Release();
}

void TowerDefensePanel::SetText(wstring text)
{
	_defaultLabel->SetText(text);
}

void TowerDefensePanel::SetGameInfoText(wstring text)
{
	_gameInfoLabel->SetText(text);
}

void TowerDefensePanel::SetInstallInfoText(BehicleData data, float textTimer)
{
	_textTimer = textTimer;
	if (data.Id != 7)
	{
		wchar_t str[50];
		swprintf_s(str, L"Gold %d | Attack Time %.f | Speed %.f", // \n�ϰ� ������ �� ��
			data.InstallGold, data.AttackTime, data.BulletSpeed);
		_infoLabel->SetText(wstring(str));
	}
	else
	{
		wchar_t str[20];
		swprintf_s(str, L"Gold %d (���� �Ұ�)", // behicle Data.json�� behicle�� ���� ����ĭ�� �־ ������ ��
			data.InstallGold);
		_infoLabel->SetText(wstring(str));
		}
	_label = _infoLabel;
}

void TowerDefensePanel::SetUpgradeInfoText(BehicleData data, float textTimer)
{
	_textTimer = textTimer;
	if (data.Id != 7)
	{
		wchar_t str[50];
		swprintf_s(str, L"Gold %d | Attack Time %.f | Speed %.f",
			data.UpgradeGold, data.AttackTime, data.BulletSpeed);
		_infoLabel->SetText(wstring(str));
	}
	else
	{
		wchar_t str[20];
		swprintf_s(str, L"���׷��̵� �Ұ�");
		_infoLabel->SetText(wstring(str));
	}
	_label = _infoLabel;
}

void TowerDefensePanel::SetDeleteInfoText(BehicleData data, float textTimer)
{
	wchar_t str[20];
	swprintf_s(str, L"Gold %d",
		data.RefundGold);
	_infoLabel->SetText(wstring(str));

	_textTimer = textTimer;
	_label = _infoLabel;
}