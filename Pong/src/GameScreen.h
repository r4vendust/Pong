#pragma once
#include <raylib.h>
#include "Button.h"
#include "DisplayManager.h"
#include "Ball.h"
#include "Paddle.h"
#include "CpuPaddle.h"
#include "Collision.h"

class GameScreen
{
public:
	static GameScreen* GetInstance();
	static void DestroyScreen();
	void Draw();
	void Control();
	void Update();

private:
	GameScreen();
	static GameScreen* instance;
	float width;
	float height;

	Ball ball;
	Paddle paddle;
	CpuPaddle cpuPaddle;
	Collision collision;
	DisplayManager& DM = DisplayManager::getInstance();
};

