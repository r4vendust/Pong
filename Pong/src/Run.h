#pragma once

#include "raylib.h"
#include "DisplayManager.h"
#include "Ball.h"
#include "Paddle.h"
#include "CpuPaddle.h";

class Run
{
public:
	Run();
	virtual ~Run();
private:
	Ball ball;
	Paddle paddle;
	CpuPaddle cpuPaddle;
};