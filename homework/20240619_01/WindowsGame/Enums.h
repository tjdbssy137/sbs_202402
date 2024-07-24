#pragma once

enum class SceneType // 18���� ���� �ʹݿ� enum ���� ����
{
	None,

	TowerDefenseScene,
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

enum class ePanelState
{
	Show,
	Hide,
	None
};