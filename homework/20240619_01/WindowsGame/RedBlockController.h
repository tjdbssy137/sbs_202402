#pragma once
#include "RedBlockActor.h"
class RedBlockController
{
private:
	RedBlockActor* _block = nullptr;
public:
	void SetLink(RedBlockActor* block);
	void Update();
};

