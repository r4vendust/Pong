#pragma once
#include <raylib.h>
#include "Button.h"

class PauseScreen
{
public:
	static PauseScreen* GetInstance();
	static void DestroyInstance();
	void Draw();
	void Control();
	void Update();
	void SetVsync();
	void SetFullScreen();
	bool IsExitClicked();
	void ResetExitClick();
	bool IsBackClicked();
	void ResetBackClick();
private:
	PauseScreen();
	~PauseScreen();
	static PauseScreen* instance;
	float posX;
	float posY;
	const char* text;
	int textOffset;
	int pauseOffset;
	Button button;
	Button button2;
	Button button3;
	Button button4;
	bool bExitClicked;
	bool bBackClicked;
};