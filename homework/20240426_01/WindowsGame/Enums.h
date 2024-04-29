#pragma once

enum class SceneType // 18���� ���� �ʹݿ� enum ���� ����
{
	None,
	Dev1Scene,
	Dev2Scene,

	Game2048Scene,
	MoleGameScene,
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

enum class MoleGameState
{
	None,
	Wait,
	Play
};