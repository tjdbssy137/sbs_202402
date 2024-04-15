#pragma once

enum class SceneType // 18일차 강의 초반에 enum 설명 있음
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