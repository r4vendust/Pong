#pragma once
#include <raylib.h>
#include "Button.h"

class MenuScreen
{
public:
	static MenuScreen* GetInstance();
	static void DestroyScreen();
	void Draw();
	void Control();
	void Update();
	bool IsExitClicked();
	bool IsOptionsClicked();
	bool IsStartClicked();
	void ResetExitClicked();
	void ResetOptionsClicked();
	void ResetStartClicked();
private:
	MenuScreen();
	static MenuScreen* instance;
	float width;
	float height;
	Button button;
	Button button2;
	Button button3;

	bool bStartClicked;
	bool bExitClicked;
	bool bOptionsClicked;
};

