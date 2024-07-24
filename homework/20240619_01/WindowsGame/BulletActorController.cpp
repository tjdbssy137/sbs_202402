#include "pch.h"
#include "BulletActorController.h"
#include "BulletActor.h"
#include "BulletActor.h"
#include "TowerDefenseScene.h"

void BulletActorController::PushBullet(BulletActor* bullet)
{
	_bullets.push_back(bullet);
}
BulletActor* BulletActorController::PopBullet()
{
	if (_bullets.size() <= 0)
	{
		BulletActor* bullet = new BulletActor();
		bullet->SetLayer(LayerType::Object);
		TowerDefenseScene* towerDefenseScene = static_cast<TowerDefenseScene*>(CurrentScene);
		bullet->Init();
		towerDefenseScene->SpawnActor(bullet);
		return bullet;
	}
	BulletActor* bullet = new BulletActor();
	bullet = _bullets.back();
	_bullets.pop_back();
	return bullet;
}
int BulletActorController::BulletCount()
{
	return _bullets.size();
}