#pragma once

enum class SceneType // 18���� ���� �ʹݿ� enum ���� ����
{
	None,
	PooGame,
	Dev2Scene,

	Homework1Scene,
	Homework2Scene,

	InGameScene,
};

enum class ColliderType
{
	None,
	Box,
	Circle
};

enum class GameState
{
	None,
	Wait,
	Play
};