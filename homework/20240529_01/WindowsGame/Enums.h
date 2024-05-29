#pragma once

enum class SceneType
{
	None,
	Dev1Scene,
	Dev2Scene,

	InGameScene,
	MoleGameScene,
};

enum class ColliderType
{
	None,
	Box,
	Circle
};

//�ڿ� �Ѽ��� �������� �׸���.
enum class LayerType
{
	BackGround,
	Object,

	Character,

	End
};

enum CollisionLayerType : uint8
{
	CLT_DEFAULT,
	CLT_CREATURE,
	CLT_ITEM
};


enum class GameState
{
	None,
	Wait,
	Play
};
enum class MoleGameState
{
	None,
};