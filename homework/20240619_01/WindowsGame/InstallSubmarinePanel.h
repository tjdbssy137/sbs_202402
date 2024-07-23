#pragma once
#include "Panel.h"

class Button;

enum class InstallSubmarineButtonManagState
{
	Show,
	Hide,
	None
};
class InstallSubmarinePanel : public Panel
{
public:
	DECLARE_CHILD(InstallSubmarinePanel, Panel)
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
public:
	void LoadResource();
	void OnClick_GoToInstallSubmarine();
	void SetState(InstallSubmarineButtonManagState state) { _state = state; }
	bool Check_Astar(Vector2Int startPos, Vector2Int endPos, Vector2Int SubmarinePos);

private:
	vector<Button*> _buttons = {};
	InstallSubmarineButtonManagState _state = InstallSubmarineButtonManagState::Hide;
	
};

