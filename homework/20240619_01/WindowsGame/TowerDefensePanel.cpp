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
		_defaultLabel->SetFont(L"영덕바다체", 18);
		_defaultLabel->SetAlign(TA_CENTER);
		_defaultLabel->SetText(L"");

		this->AddChild(_defaultLabel);
	}

	{
		_gameInfoLabel = new Label();
		_gameInfoLabel->Init();
		_gameInfoLabel->SetRect(Shape::MakeCenterRectLTWH(20, WIN_SIZE_X / 2 - 600, 200, 100));
		_gameInfoLabel->SetFont(L"영덕바다체", 20);
		_gameInfoLabel->SetAlign(TA_LEFT);
		_gameInfoLabel->SetText(L"");

		this->AddChild(_gameInfoLabel);
	}

	{
		_infoLabel = new Label();
		_infoLabel->Init();
		_infoLabel->SetRect(Shape::MakeCenterRectLTWH(WIN_SIZE_X / 2 + 450, WIN_SIZE_Y / 2, 200, 300));
		_infoLabel->SetFont(L"영덕바다체", 15);
		_infoLabel->SetAlign(TA_CENTER);
		_infoLabel->SetText(L"");

		this->AddChild(_infoLabel);
	}

	{
		_timerLabel = new Label();
		_timerLabel->Init();
		_timerLabel->SetRect(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 300, 50));
		_timerLabel->SetFont(L"영덕바다체", 18);
		_timerLabel->SetAlign(TA_CENTER);
		_timerLabel->SetText(L"");

		this->AddChild(_timerLabel);
	}

	// Add Event
	Events->AddEvent("InstallInfo", new GameEvent<BehicleData, float>());
	Events->GetEvent<BehicleData, float>("InstallInfo")
		->AddListen(this, &TowerDefensePanel::SetInstallInfoText);

	Events->AddEvent("UpgradeInfo", new GameEvent<BehicleData, float>());
	Events->GetEvent<BehicleData, float>("UpgradeInfo")
		->AddListen(this, &TowerDefensePanel::SetUpgradeInfoText);

	Events->AddEvent("DeleteInfo", new GameEvent<BehicleData, float>());
	Events->GetEvent<BehicleData, float>("DeleteInfo")
		->AddListen(this, &TowerDefensePanel::SetDeleteInfoText);

	Events->AddEvent("TimerText", new GameEvent<wstring, float>());
	Events->GetEvent<wstring, float>("TimerText")
		->AddListen(this, &TowerDefensePanel::SetTimerText);
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
			_infoLabel->SetText(L"");
		}
	}

	if (0 < _textLabelTimer)
	{
		_infoLabel->SetText(L"");
		_textLabelTimer -= Time->GetDeltaTime();
		if (_textLabelTimer <= 0)
		{
			_timerLabel->SetText(L"");
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
		swprintf_s(str, L"Gold %d | Attack Cooldown %.f | Damage %.f", // \n하고 싶은데 안 됨
			data.InstallGold, data.AttackTime, data.BulletDamage);
		_infoLabel->SetText(wstring(str));
	}
	else
	{
		wchar_t str[20];
		swprintf_s(str, L"Gold %d (공격 불가)", // behicle Data.json에 behicle에 대한 설명칸이 있어도 ㄱㅊ을 듯
			data.InstallGold);
		_infoLabel->SetText(wstring(str));
		}
}

void TowerDefensePanel::SetUpgradeInfoText(BehicleData data, float textTimer)
{
	_textTimer = textTimer;
	if (data.Id < 7)
	{
		wchar_t str[50];
		swprintf_s(str, L"Gold %d | Attack Cooldown %.f | Damage %.f",
			data.UpgradeGold, data.AttackTime, data.BulletDamage);
		_infoLabel->SetText(wstring(str));
	}
	else
	{
		wchar_t str[20];
		swprintf_s(str, L"업그레이드 불가");
		_infoLabel->SetText(wstring(str));
	}
}

void TowerDefensePanel::SetDeleteInfoText(BehicleData data, float textTimer)
{
	_textTimer = textTimer;

	wchar_t str[20];
	swprintf_s(str, L"Gold %d",
		data.RefundGold);
	_infoLabel->SetText(wstring(str));
}

void TowerDefensePanel::SetTimerText(wstring text, float textTimer)
{
	_textLabelTimer = textTimer;
	_timerLabel->SetText(text);
}