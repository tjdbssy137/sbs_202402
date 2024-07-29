#include "pch.h"
#include "TowerDefensePanel.h"
#include "Label.h"
void TowerDefensePanel::Init()
{
	Super::Init();

	{
		_waveStatusLabel = new Label();
		_waveStatusLabel->Init();
		_waveStatusLabel->SetRect(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 300, 50));
		_waveStatusLabel->SetFont(L"¿µ´ö¹Ù´ÙÃ¼", 20);
		_waveStatusLabel->SetAlign(TA_CENTER);
		_waveStatusLabel->SetText(L"");

		this->AddChild(_waveStatusLabel);
	}

	{
		_gameInfoLabel = new Label();
		_gameInfoLabel->Init();
		_gameInfoLabel->SetRect(Shape::MakeCenterRectLTWH(WIN_SIZE_X - 100, WIN_SIZE_Y - 200, 100, 100));
		_gameInfoLabel->SetFont(L"¿µ´ö¹Ù´ÙÃ¼", 15);
		_gameInfoLabel->SetAlign(TA_RIGHT);
		_gameInfoLabel->SetText(L"");

		this->AddChild(_gameInfoLabel);
	}
}
void TowerDefensePanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void TowerDefensePanel::Update()
{
	Super::Update();
}
void TowerDefensePanel::Release()
{
	Super::Release();
}

void TowerDefensePanel::SetText(wstring text)
{
	_waveStatusLabel->SetText(text);
}

void TowerDefensePanel::SetGameInfoText(wstring text)
{
	_gameInfoLabel->SetText(text);
}