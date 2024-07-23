#pragma once

enum class SceneType // 18일차 강의 초반에 enum 설명 있음
{
	None,
	Dev2Scene,

	InGameScene,
	TowerDefenseScene,
};

//뒤에 둘수록 마지막에 그린다
enum class LayerType
{
	Background,
	Object,
	Character,
	End
};

enum CollisionLayerType : uint8 // :의 뜻. -> 이 enum은 최대 uint8까지만 수용하겠다.
{
	CLT_DEFAULT,
	CLT_ENEMY,
	CLT_BEHICLE,
	CLT_ITEM
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

enum eDirection
{
	DOWN,
	LEFT,
	RIGHT,
	UP,
	DOWN_LEFT,
	DOWN_RIGHT,
	UP_LEFT,
	UP_RIGHT,
	END
};