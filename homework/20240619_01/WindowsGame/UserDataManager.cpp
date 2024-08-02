#include "pch.h"
#include "UserDataManager.h"
void UserDataManager::Init()
{
	// Add Event
	Events->AddEvent("ResetGameData", new GameEvent<>());
	Events->GetEvent<>("ResetGameData")
		->AddListen(this, &UserDataManager::ResetGameData);
}

void UserDataManager::Release()
{
}

void UserDataManager::ResetGameData()
{
	_wave = 1;
	_gold = 120;
	_enterEnemy = 0;

	GameEvent<bool>* geSetGameStart = Events->GetEvent<bool>("SetGameStart");
	geSetGameStart->Invoke(true);

	GameEvent<wstring>* geSetTreasure = Events->GetEvent<wstring>("SetTreasure");
	geSetTreasure->Invoke(L"S_Treasure_Closed");

	GameEvent<>* geResetInstallPos = Events->GetEvent<>("ResetInstallPos");
	geResetInstallPos->Invoke();

}