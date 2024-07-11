#include "pch.h"
#include "InstallBehicle.h"
#include "Dev2Scene.h"
#include "BehicleActor.h"
#include "BehicleController.h"
void InstallBehicle::Init()
{
	Super::Init();
}
void InstallBehicle::Render(HDC hdc)
{
	Super::Render(hdc);
}
void InstallBehicle::Update()
{
	Super::Update();
}
void InstallBehicle::Release()
{
	Super::Release();
}

void InstallBehicle::InstallBehicleFunc(Vector2Int pos)
{
	Dev2Scene* dev2Scene = dynamic_cast<Dev2Scene*>(CurrentScene);

	vector<BehicleController*> _behicleControllers = dev2Scene->GetBehicleController();

	BehicleController* behicleController = new BehicleController();
	{
		cout << "Create Behicle" << endl;
		BehicleActor* behicle = new BehicleActor();
		behicle->SetLayer(LayerType::Character);
		behicleController->SetLink(behicle);
		behicleController->SetBehicleTypeState(_type);
		behicle->Init();
		dev2Scene->SpawnActor(behicle);
		behicle->SetCellPos(pos, true);
		dev2Scene->SetBehicleActor(behicle);
	}
	dev2Scene->SetBehicleController(behicleController);
}

void InstallBehicle::UpgradeBehicleFunc(BehicleController* behicleController)
{
	Dev2Scene* dev2Scene = dynamic_cast<Dev2Scene*>(CurrentScene);
	behicleController->SetBehicleTypeState(_type);
}

void InstallBehicle::DeleteBehicleFunc(BehicleController* behicleController)
{
	Dev2Scene* dev2Scene = dynamic_cast<Dev2Scene*>(CurrentScene);
	
}