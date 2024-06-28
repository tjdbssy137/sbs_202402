#pragma once
class BehicleActor;
class BehicleController
{
private:
	BehicleActor* _behicle = nullptr;
public:
	void SetLink(BehicleActor* behicle);
	void Update();
public:
	void InstallBehicle();
};

