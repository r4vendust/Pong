#pragma once

#include "raylib.h"
#include "PauseScreen.h"
#include "MenuScreen.h"
#include "GameScreen.h"

class Run
{
public:
	Run();
	virtual ~Run();
private:
	Ball ball;
	Paddle paddle;
	CpuPaddle cpuPaddle;
	Collision collision;
	DisplayManager &DM = DisplayManager::getInstance();
	//PauseScreen pauseScreen;

	bool bIsRunning;
	enum screen;
	Image cursorDefaultImage;
	Image cursorSelectImage;
	Texture2D cursorDefaultTexture;
	Texture2D cursorSelectTexture;
};