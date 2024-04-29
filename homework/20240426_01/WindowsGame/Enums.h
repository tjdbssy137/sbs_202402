#pragma once

enum class SceneType // 18일차 강의 초반에 enum 설명 있음
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