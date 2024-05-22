#pragma once

enum class SceneType // 18���� ���� �ʹݿ� enum ���� ����
{
	None,
	Dev1Scene,
	Dev2Scene,

	Homework1Scene,
	Homework2Scene,

	InGameScene,
	MoleGameScene,
};

//�ڿ� �Ѽ��� �������� �׸���
enum class LayerType
{
	Background,
	Object,
	Character,
	End
};

enum CollisionLayerType : uint8 // :�� ��. -> �� enum�� �ִ� uint8������ �����ϰڴ�.
{
	CLT_CREATURE,
	CLT_ITEM,
	CLT_DEFAULT
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