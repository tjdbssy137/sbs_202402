#include "pch.h"
#include "UserDataManager.h"
#include "TowerDefensePanel.h"
#include "TowerDefenseScene.h"
void UserDataManager::Init()
{
	_mainPanel = new TowerDefensePanel();
	_mainPanel->Init();
	TowerDefenseScene* towerDefenseScene = dynamic_cast<TowerDefenseScene*>(CurrentScene);
	towerDefenseScene->AddUI(_mainPanel);
}
void UserDataManager::Update()
{
	/*wchar_t str[50];
	swprintf_s(str, L"현재 Wave 단계 | %d \nGold | %d \nEnter Enemy %d", _wave, _gold, _enterEnemy);
	_mainPanel->SetGameInfoText(wstring(str));*/
}
void UserDataManager::Release()
{

}